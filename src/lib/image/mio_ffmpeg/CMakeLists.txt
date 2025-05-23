#
# Copyright (C) 2022  Autodesk, Inc. All Rights Reserved.
#
# SPDX-License-Identifier: Apache-2.0
#

# Note: This cache variable can be overriden to FALSE in a super-project if a custom mio_ffmpeg is built as part of that super-project.
SET(RV_BUILD_MIO_FFMPEG
    TRUE
    CACHE BOOL "Whether or not to build the Open RV mio_ffmpeg movie plugin"
)

IF(RV_BUILD_MIO_FFMPEG)

  INCLUDE(cxx_defaults)

  SET(_target
      "mio_ffmpeg"
  )

  LIST(APPEND _sources init.cpp)

  ADD_LIBRARY(
    ${_target} SHARED
    ${_sources}
  )

  TARGET_LINK_LIBRARIES(
    ${_target}
    PRIVATE MovieFFMpeg Boost::program_options TwkFB
  )

  IF(RV_TARGET_WINDOWS)
    TARGET_COMPILE_OPTIONS(
      ${_target}
      PRIVATE "-D__STDC_CONSTANT_MACROS"
    )
  ENDIF()

  FOREACH(
    RV_FFMPEG_NON_FREE_DECODER_TO_ENABLE
    ${RV_FFMPEG_NON_FREE_DECODERS_TO_ENABLE}
  )
    TARGET_COMPILE_OPTIONS(
      ${_target}
      PRIVATE "-D__FFMPEG_ENABLE_NON_FREE_DECODER_${RV_FFMPEG_NON_FREE_DECODER_TO_ENABLE}"
    )
  ENDFOREACH()

  RV_STAGE(TYPE "MOVIE_FORMAT" TARGET ${_target})

  IF(RV_TARGET_WINDOWS)
    # 프로젝트 내부에 저장된 DLL 파일 목록
    SET(_project_local_dlls
      "libcrypto-3-x64.dll"
      "liblzma-5.dll"
      "libssl-3-x64.dll"
      "libwinpthread-1.dll"
      "zlib1.dll"
    )

    # DLL 파일이 위치한 프로젝트 내 상대 경로
    # CMAKE_CURRENT_SOURCE_DIR는 현재 CMakeLists.txt 파일이 있는 디렉토리를 가리킵니다.
    SET(_dll_source_dir "${CMAKE_CURRENT_SOURCE_DIR}/external_dlls")

    FOREACH(_dll_file ${_project_local_dlls})
      SET(_dll_file_full_path "${_dll_source_dir}/${_dll_file}")
      IF(EXISTS "${_dll_file_full_path}")
        ADD_CUSTOM_COMMAND(
          TARGET ${_target}
          POST_BUILD
          COMMAND ${CMAKE_COMMAND} -E copy_if_different
          "${_dll_file_full_path}"
          $<TARGET_FILE_DIR:${_target}> # ${_target}.dll 이 생성되는 디렉토리
          COMMENT "Copying project-local DLL: ${_dll_file} to output directory"
        )
      ELSE()
        MESSAGE(WARNING "Project-local DLL file not found: ${_dll_file_full_path}. It will not be copied.")
      ENDIF()
    ENDFOREACH()
  ENDIF()

ENDIF() # IF (RV_BUILD_MIO_FFMPEG)
