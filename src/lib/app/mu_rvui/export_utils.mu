//
// Copyright (C) 2023  Autodesk, Inc. All Rights Reserved. 
// 
// SPDX-License-Identifier: Apache-2.0 
//
module: export_utils
{
    require system;
    require io;
    use commands;
    use rvtypes;
    use external_qprocess;
    use extra_commands;

    global int saveSessionCount=1;
    global float _tempExportFPS = 60.0; // Global variable to store temporary FPS for export

    \: tempSessionName (string; string extension="rv")
    {
        require qt;
        let path = qt.QDir.tempPath();
        return "%s/temp_%d_%d.%s" %  (path,
                           system.getpid(),
                           saveSessionCount++,
                           extension);
    }

    \: removeSession (VoidFunc; string name)
    {
        return \: (void;)
        {
            if (commandLineFlag("debug_export") neq nil)
            {
                print("DEBUG: Leaving '%s' for inspection\n" % name);
            }
            else
            {
                require qt;
                try
                {
                    if (!qt.QFile(name).remove())
                    {
                        print("ERROR: Unable to remove '%s'\n" % name);
                    }
                }
                catch (...)
                {
                    print("ERROR: Unable to remove '%s'\n" % name);
                }
            }
        };
    }

    \: getColorNode (string; string groupType)
    {
        for_each (node; nodesOfType("RVDisplayColor"))
        {
            let pipeGroup = nodeGroup(node),
                dispGroup = nodeGroup(pipeGroup);

            if (nodeType(dispGroup) == groupType)
            {
                return node;
            }
        }
        return nil;
    }

    \: setExportDisplayConvert (void; string conversion)
    {
        let outColorNode = getColorNode("RVOutputGroup");
        if (conversion == "pass" || outColorNode eq nil) return;

        if (conversion == "default")
        {
            string colorProf = "";
            string stereoProf = "";
            try
            {
                let dnodes  = nodesOfType("RVDisplayGroup"),
                    dstereo = nodesInGroupOfType(dnodes.front(), "RVDisplayStereo"),
                    dpipes  = nodesInGroupOfType(dnodes.front(), "RVDisplayPipelineGroup"),
                    opipes  = nodesInGroupOfType("defaultOutputGroup", "RVDisplayPipelineGroup"),
                    ostereo = nodesInGroupOfType("defaultOutputGroup", "RVDisplayStereo");

                colorProf = tempSessionName("profile");
                writeProfile(colorProf, dpipes.front());
                readProfile(colorProf, opipes.front(), false);
                stereoProf = tempSessionName("profile");
                writeProfile(stereoProf, dstereo.front());
                readProfile(stereoProf, ostereo.front(), false);

                removeSession(colorProf)();
                removeSession(stereoProf)();
            }
            catch (...)
            {
                print("ERROR: Failed to copy display settings to output\n");
                if (qt.QFile(colorProf).exists()) removeSession(colorProf)();
                if (qt.QFile(stereoProf).exists()) removeSession(stereoProf)();
            }
        }
        else
        {
            int s = 0;
            int r = 0;
            float g = 1.0;

            if (conversion == "") ; // Use default
            else if (conversion == "sRGB")      s = 1;
            else if (conversion == "Rec709")    r = 1;
            else if (conversion == "Gamma 2.0") g = 2.0;
            else if (conversion == "Gamma 2.2") g = 2.2;
            else if (conversion == "Gamma 2.4") g = 2.4;

            setIntProperty  (outColorNode + ".color.sRGB",   int[]   {s});
            setIntProperty  (outColorNode + ".color.Rec709", int[]   {r});
            setFloatProperty(outColorNode + ".color.gamma",  float[] {g});
        }
    }

    \: makeTempSession (string; string conversion="default")
    {
        setExportDisplayConvert(conversion);
        let name = tempSessionName();
        saveSession(name, true);
        return name;
    }

    \: removeTempSession(void;)
    {
        // Guess that the last session was the one we want to delete
        // NOTE: Adding this only for backwards compatibility
        saveSessionCount--;
        let name = tempSessionName();
        removeSession(name)();
    }

    \: rvio (ExternalProcess; string name, string[] inargs, (void;) cleanup = nil)
    {
        let cmd = system.getenv("RV_APP_RVIO");
        string[] args = {"-v", "-err-to-out" };
        [string] argList;
        let lic = system.getenv("RV_APP_USE_LICENSE_FILE", nil);
        if (lic neq nil) 
        {
            args.push_back("-lic");
            args.push_back(lic);
        }
        for_each (a; inargs) args.push_back(a);
        for_index (i; args) argList = args[args.size()-i-1] : argList;
        rvioSetup(); // Ensure this function exists or comment out if not critical for test
        return ExternalQProcess(name, cmd, argList, 1, ExternalProcess.Type.ReadOnly, cleanup);
    }

    \: rvio_blocking (void; string name, string[] args, (void;) cleanup = nil)
    {
        ExternalQProcess proc = rvio(name, args, cleanup);
        if (proc neq nil) proc._proc.waitForFinished(-1);
    }

    \: markedRegionBoundaries ([(int,int,int)];)
    {
        let a = markedFrames(), b = markedFrames();
        if (a.size() < 2) 
        {
            [(int,int,int)] emptyResult;
            return emptyResult;
        }
        a.pop_back();
        b.erase(0, 1);
        [(int,int,int)] ranges;
        for (int i=a.size()-1; i >= 0; i--)
        {
            ranges = (a[i], b[i]-1, i) : ranges;
        }
        return ranges;
    }

    \: exportImageSequenceOverRange (ExternalProcess; 
                                     int start,
                                     int end,
                                     string prefix="",
                                     string imagetype="tif",
                                     bool blocking=false,
                                     string conversion="default")
    {
        let name = "%s.#" % prefix,
            temp = makeTempSession(conversion);
        string[] args = { temp, "-o", "%s.%s" % (name, imagetype), "-t", "%d-%d" % (start, end) };
        if (blocking)
        {
            rvio_blocking("Export Image Sequence", args, removeSession(temp));
            return nil;
        }
        else
        {
            return rvio("Export Image Sequence", args, removeSession(temp));
        }
    }

    \: _getExportArgs (string[]; string temp, string outName, int startFrame, int endFrame, float fps, string conversionType)
    {
        if (conversionType == "gif")
        {
            // GIF export settings
            string[] gifArgs =
            {
                temp,
                "-o", outName,
                "-t",  "%d-%d" % (startFrame, endFrame),
                "-codec", "gif",
                "-outfps", "15.0",
                "-outparams",
                    "pix_fmt=rgb8",
                    "loop=0" // 0 for infinite loop, -1 for no loop, N for N loops
            };
            return gifArgs;
        }
        else // Default to MP4 (H.264) or other existing logic
        {
            string[] mp4Args =
            {
                temp,
                "-o", outName,
                "-t",  "%d-%d" % (startFrame, endFrame),
                "-codec", "libx264",
                "-outfps", "%f" % fps,
                "-outparams",
                    "pix_fmt=yuv420p",
                    "cc:crf=0",              // CRF는 cc: 접두사 유지
                    "color_primaries=bt709", // cc: 제거
                    "color_trc=srgb",       // cc: 제거
                    "colorspace=bt709",      // cc: 제거
                    "color_range=tv"         // cc: 제거
                //  "quality=1.0" // 기존 quality 파라미터 주석 처리 유지
            };
            return mp4Args;
        }
    }

    \: exportMovieOverRange(ExternalProcess; 
                            int start,
                            int end,
                            string name="out.mp4",
                            bool blocking=false,
                            string conversion="default")
    {
        let temp = makeTempSession("default");
        
        float currentExportFPS = 60.0; 
        try
        {
            currentExportFPS = fps(); 
            if (currentExportFPS <= 0.0)
            {
                currentExportFPS = 60.0;
            }
        }
        catch (exception e)
        {
            currentExportFPS = 60.0;
        }

        string[] args = _getExportArgs(temp, name, start, end, currentExportFPS, conversion);

        if (blocking)
        {
            rvio_blocking("Export Movie", args, removeSession(temp));
            return nil;
        }
        else
        {
            return rvio("Export Movie", args, removeSession(temp));
        }
    }

    \: exportMarkedFrames (ExternalProcess; string filepat, string conversion="default")
    {
        use io;
        osstream timestr;
        let frames = markedFrames();
        for_index (i; frames)
        {
            let f = frames[i];
            if (i > 0) print(timestr, ",");
            print(timestr, "%d" % f);
        }
        let temp = makeTempSession(conversion);
        string[] args = { temp, "-o", filepat, "-t", string(timestr) };
        return rvio("Export Annotated Frames", args, removeSession(temp));
    }

    \: exportMarkedRegionsAsMovies (void; string prefix="", string movietype="mov", string conversion="default")
    {
        if (prefix == "") prefix = sessionFileName().substr(0,-3);
        
        for_each (inout; markedRegionBoundaries())
        {
            let (start, end, i) = inout;
            exportMovieOverRange(start, end,
                                 "%s_cut%d.%s" % (prefix, i, movietype),
                                 true, conversion);
        }
    }

    \: exportMarkedRegionsAsImages (void; 
                                    string prefix="",
                                    string imagetype="tif",
                                    string conversion="default")
    {
        if (prefix == "") prefix = sessionFileName().substr(0,-3);
        for_each (inout; markedRegionBoundaries())
        {
            let (start, end, i) = inout,
                name = "%s_cut%d" % (prefix, i);
            exportImageSequenceOverRange(start, end, name, imagetype, true, conversion);
        }
    }
}
