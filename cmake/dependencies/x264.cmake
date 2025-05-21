#
# Copyright (C) 2024 ASWF. All Rights Reserved.
#
# SPDX-License-Identifier: Apache-2.0
#

INCLUDE(ProcessorCount)
PROCESSORCOUNT(_cpu_count)

SET(_target "RV_DEPS_X264")
# Use specific commit hash for stability, corresponding to version 0.164.3108.a0483d1
SET(_version "stable") 
SET(_download_url "https://code.videolan.org/videolan/x264.git")

SET(_base_dir ${RV_DEPS_BASE_DIR}/${_target})
SET(_install_dir ${_base_dir}/install)

SET(${_target}_ROOT_DIR ${_install_dir})
SET(X264_INCLUDE_DIR ${_install_dir}/include)
SET(X264_LIBRARY_DIR ${_install_dir}/lib)
SET(X264_BIN_DIR ${_install_dir}/bin) # For DLL location on Windows

# Default commands
SET(_configure_shell_command sh)
SET(_configure_script ./configure)
SET(_make_command make)

# Convert install_dir to MSYS/MinGW path for configure script if on Windows
SET(_install_dir_msys ${_install_dir})
IF(RV_TARGET_WINDOWS)
    STRING(REPLACE "\\" "/" _install_dir_unix "${_install_dir}")
    IF(_install_dir_unix MATCHES "^([A-Za-z]):/(.*)$")
        STRING(SUBSTRING "${_install_dir_unix}" 0 1 _drive_letter)
        STRING(TOLOWER "${_drive_letter}" _drive_letter_lower)
        STRING(SUBSTRING "${_install_dir_unix}" 2 -1 _rest_of_path)
        SET(_install_dir_msys "/${_drive_letter_lower}${_rest_of_path}")
    ELSE()
        SET(_install_dir_msys "${_install_dir_unix}") # Should not happen with absolute paths
    ENDIF()
ENDIF()

SET(_x264_config_options
    "--prefix=${_install_dir_msys}" # Use MSYS path for prefix
    "--enable-shared"
    "--enable-static"
    "--disable-cli"
    "--enable-pic"
    # For MinGW64, explicitly set host if auto-detection is problematic
    # "--host=x86_64-w64-mingw32" 
)

IF(RV_TARGET_WINDOWS)
    # For MinGW64 environment on Windows, use make (or mingw32-make)
    SET(_make_command "make") 
    # Remove --toolchain=msvc as we are targeting MinGW64
    # LIST(APPEND _x264_config_options "--host=x86_64-w64-mingw32") # Consider adding if needed
ELSE()
    SET(_make_command "make") # Default for other platforms
ENDIF()

STRING(REPLACE ";" " " _x264_config_options_str "${_x264_config_options}")
SET(_final_configure_command "${_configure_shell_command} ${_configure_script} ${_x264_config_options_str}")

EXTERNALPROJECT_ADD(
    ${_target}
    GIT_REPOSITORY ${_download_url}
    GIT_TAG ${_version}
    GIT_SHALLOW TRUE
    DOWNLOAD_DIR ${RV_DEPS_DOWNLOAD_DIR}
    INSTALL_DIR ${_install_dir} # This is for ExternalProject_Add internal use, not for --prefix
    SOURCE_DIR ${RV_DEPS_BASE_DIR}/${_target}/src
    CONFIGURE_COMMAND ${CMAKE_COMMAND} -E echo "Running x264 configure: ${_final_configure_command}" && bash -c "${_final_configure_command}"
    BUILD_COMMAND ${_make_command} -j${_cpu_count}
    INSTALL_COMMAND 
        bash -c "${_make_command} install && \
        mkdir -p '${_install_dir_msys}/lib/pkgconfig' && \
        echo 'prefix=${_install_dir_msys}' > '${_install_dir_msys}/lib/pkgconfig/x264.pc' && \
        echo 'exec_prefix=\${prefix}' >> '${_install_dir_msys}/lib/pkgconfig/x264.pc' && \
        echo 'libdir=\${exec_prefix}/lib' >> '${_install_dir_msys}/lib/pkgconfig/x264.pc' && \
        echo 'includedir=\${prefix}/include' >> '${_install_dir_msys}/lib/pkgconfig/x264.pc' && \
        echo '' >> '${_install_dir_msys}/lib/pkgconfig/x264.pc' && \
        echo 'Name: x264' >> '${_install_dir_msys}/lib/pkgconfig/x264.pc' && \
        echo 'Description: H.264 (MPEG4 AVC) encoder library' >> '${_install_dir_msys}/lib/pkgconfig/x264.pc' && \
        echo 'Version: ${_version}' >> '${_install_dir_msys}/lib/pkgconfig/x264.pc' && \
        echo 'Libs: -L\${libdir} -lx264' >> '${_install_dir_msys}/lib/pkgconfig/x264.pc' && \
        echo 'Libs.private:' >> '${_install_dir_msys}/lib/pkgconfig/x264.pc' && \
        echo 'Cflags: -I\${includedir} -DX264_API_IMPORTS' >> '${_install_dir_msys}/lib/pkgconfig/x264.pc'"
    BUILD_IN_SOURCE TRUE
    BUILD_BYPRODUCTS 
        ${X264_BIN_DIR}/libx264-164${CMAKE_SHARED_LIBRARY_SUFFIX} # DLL name with SO version
        ${X264_LIBRARY_DIR}/libx264.dll.a # Import library for MinGW
        ${X264_LIBRARY_DIR}/libx264${CMAKE_STATIC_LIBRARY_SUFFIX}
    USES_TERMINAL_BUILD TRUE
)

# Add custom command to copy DLL to stage bin directory on Windows
IF(RV_TARGET_WINDOWS)
  ADD_CUSTOM_COMMAND(
    TARGET ${_target}
    POST_BUILD
    COMMENT "Installing ${_target}'s DLL into ${RV_STAGE_BIN_DIR}"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${X264_BIN_DIR}/libx264-164${CMAKE_SHARED_LIBRARY_SUFFIX} ${RV_STAGE_BIN_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${X264_LIBRARY_DIR}/libx264.dll.a ${RV_STAGE_LIB_DIR} # Also copy import lib
  )
ENDIF()

ADD_LIBRARY(ffmpeg::x264 SHARED IMPORTED GLOBAL)

IF(RV_TARGET_WINDOWS)
    # x264 names its DLL libx264-SO_VERSION.dll, e.g. libx264-164.dll
    # The SO_VERSION for 0.164.3108.a0483d1 is 164.
    SET_PROPERTY(TARGET ffmpeg::x264 PROPERTY IMPORTED_LOCATION "${X264_BIN_DIR}/libx264-164${CMAKE_SHARED_LIBRARY_SUFFIX}")
    SET_PROPERTY(TARGET ffmpeg::x264 PROPERTY IMPORTED_IMPLIB ${X264_LIBRARY_DIR}/libx264.dll.a) # MinGW import library
ELSE()
    SET_PROPERTY(TARGET ffmpeg::x264 PROPERTY IMPORTED_LOCATION ${X264_LIBRARY_DIR}/libx264-164${CMAKE_SHARED_LIBRARY_SUFFIX})
ENDIF()

TARGET_INCLUDE_DIRECTORIES(ffmpeg::x264 INTERFACE ${X264_INCLUDE_DIR})
ADD_DEPENDENCIES(ffmpeg::x264 ${_target})

LIST(APPEND RV_DEPS_LIST ffmpeg::x264) 