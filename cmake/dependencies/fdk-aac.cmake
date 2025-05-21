#
# Copyright (C) 2024 ASWF. All Rights Reserved.
#
# SPDX-License-Identifier: Apache-2.0
#

INCLUDE(ProcessorCount)
PROCESSORCOUNT(_cpu_count)

SET(_target "RV_DEPS_FDK_AAC")
SET(_version "v2.0.3") # Specific release tag
SET(_download_url "https://github.com/mstorsjo/fdk-aac.git")

SET(_base_dir ${RV_DEPS_BASE_DIR}/${_target})
SET(_install_dir ${_base_dir}/install)

SET(${_target}_ROOT_DIR ${_install_dir})
SET(FDK_AAC_INCLUDE_DIR ${_install_dir}/include)
SET(FDK_AAC_LIBRARY_DIR ${_install_dir}/lib)
SET(FDK_AAC_BIN_DIR ${_install_dir}/bin) # For DLL location on Windows

# Default commands
SET(_autogen_command "sh ./autogen.sh")
SET(_configure_shell_command sh)
SET(_configure_script ./configure)
SET(_make_command make)

# Convert install_dir to MSYS/MinGW path for configure script
SET(_install_dir_msys ${_install_dir})
IF(RV_TARGET_WINDOWS)
    STRING(REPLACE "\\" "/" _install_dir_unix "${_install_dir}")
    IF(_install_dir_unix MATCHES "^([A-Za-z]):/(.*)$")
        STRING(SUBSTRING "${_install_dir_unix}" 0 1 _drive_letter)
        STRING(TOLOWER "${_drive_letter}" _drive_letter_lower)
        STRING(SUBSTRING "${_install_dir_unix}" 2 -1 _rest_of_path)
        SET(_install_dir_msys "/${_drive_letter_lower}${_rest_of_path}")
    ELSE()
        SET(_install_dir_msys "${_install_dir_unix}")
    ENDIF()
ENDIF()

# Base fdk-aac config options
SET(_fdk_aac_base_config_options
    "--prefix=${_install_dir_msys}" # Use MSYS path for prefix
    "--enable-shared"
    "--disable-static" # Typically only shared is needed for ffmpeg plugins
    "--disable-examples"
)

# Append global/custom options if any
SET(_final_fdk_aac_config_options ${_fdk_aac_base_config_options})
IF(RV_FDK_AAC_CONFIG_OPTIONS)
    LIST(APPEND _final_fdk_aac_config_options ${RV_FDK_AAC_CONFIG_OPTIONS})
ENDIF()
# Note: RV_FDK_AAC_EXTRA_C_OPTIONS and RV_FDK_AAC_EXTRA_LIBPATH_OPTIONS are not standard configure options for fdk-aac.
# If needed, they should be passed as environment variables (CFLAGS, LDFLAGS) for the configure step.

STRING(REPLACE ";" " " _final_fdk_aac_config_options_str "${_final_fdk_aac_config_options}")

SET(_configure_env "")
IF(RV_TARGET_WINDOWS)
    # For MinGW64 environment on Windows, use make (or mingw32-make)
    SET(_make_command "make") 
    # Remove MSVC specific environment variables. Configure script should detect MinGW GCC.
    # SET(_configure_env "CC=gcc CXX=g++ LD=ld AR=ar") # Explicitly set if needed
    # LIST(APPEND _final_fdk_aac_config_options "--host=x86_64-w64-mingw32") # Consider adding if needed
ELSE()
    SET(_make_command "make") # Default for other platforms
ENDIF()

# Need to run autogen.sh first, then configure
SET(_full_configure_sequence "${_autogen_command} && ${_configure_env} ${_configure_shell_command} ${_configure_script} ${_final_fdk_aac_config_options_str}")

MESSAGE(STATUS "FDK_AAC CONFIGURE_COMMAND will be: bash -c \"${_full_configure_sequence}\"")

SET(_build_command_options "")
IF(NOT RV_TARGET_WINDOWS)
    SET(_build_command_options "-j${_cpu_count}")
ENDIF()

EXTERNALPROJECT_ADD(
    ${_target}
    GIT_REPOSITORY ${_download_url}
    GIT_TAG ${_version}
    GIT_SHALLOW TRUE
    DOWNLOAD_DIR ${RV_DEPS_DOWNLOAD_DIR}
    INSTALL_DIR ${_install_dir}
    SOURCE_DIR ${RV_DEPS_BASE_DIR}/${_target}/src
    CONFIGURE_COMMAND bash -c "${_full_configure_sequence}"
    BUILD_COMMAND ${_make_command} ${_build_command_options}
    INSTALL_COMMAND 
        bash -c "${_make_command} install && \
        mkdir -p '${_install_dir_msys}/lib/pkgconfig' && \
        echo 'prefix=${_install_dir_msys}' > '${_install_dir_msys}/lib/pkgconfig/fdk-aac.pc' && \
        echo 'exec_prefix=\${prefix}' >> '${_install_dir_msys}/lib/pkgconfig/fdk-aac.pc' && \
        echo 'libdir=\${exec_prefix}/lib' >> '${_install_dir_msys}/lib/pkgconfig/fdk-aac.pc' && \
        echo 'includedir=\${prefix}/include' >> '${_install_dir_msys}/lib/pkgconfig/fdk-aac.pc' && \
        echo '' >> '${_install_dir_msys}/lib/pkgconfig/fdk-aac.pc' && \
        echo 'Name: Fraunhofer FDK AAC Codec Library' >> '${_install_dir_msys}/lib/pkgconfig/fdk-aac.pc' && \
        echo 'Description: AAC codec library' >> '${_install_dir_msys}/lib/pkgconfig/fdk-aac.pc' && \
        echo 'Version: ${_version}' >> '${_install_dir_msys}/lib/pkgconfig/fdk-aac.pc' && \
        echo 'Libs: -L\${libdir} -lfdk-aac' >> '${_install_dir_msys}/lib/pkgconfig/fdk-aac.pc' && \
        echo 'Libs.private:' >> '${_install_dir_msys}/lib/pkgconfig/fdk-aac.pc' && \
        echo 'Cflags: -I\${includedir}' >> '${_install_dir_msys}/lib/pkgconfig/fdk-aac.pc'"
    BUILD_IN_SOURCE TRUE
    BUILD_BYPRODUCTS 
        ${FDK_AAC_BIN_DIR}/libfdk-aac-2${CMAKE_SHARED_LIBRARY_SUFFIX} # DLL name with SO version for v2.0.3 is 2
        ${FDK_AAC_LIBRARY_DIR}/libfdk-aac.dll.a # Import library for MinGW
        # ${_FDK_AAC_LIBRARY_DIR}/libfdk-aac${CMAKE_STATIC_LIBRARY_SUFFIX} # If static is enabled and needed
    USES_TERMINAL_BUILD TRUE
)

# Add custom command to copy DLL to stage bin directory on Windows
IF(RV_TARGET_WINDOWS)
  ADD_CUSTOM_COMMAND(
    TARGET ${_target}
    POST_BUILD
    COMMENT "Installing ${_target}'s DLL into ${RV_STAGE_BIN_DIR}"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${FDK_AAC_BIN_DIR}/libfdk-aac-2${CMAKE_SHARED_LIBRARY_SUFFIX} ${RV_STAGE_BIN_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${FDK_AAC_LIBRARY_DIR}/libfdk-aac.dll.a ${RV_STAGE_LIB_DIR} # Also copy import lib
  )
ENDIF()

ADD_LIBRARY(ffmpeg::fdk-aac SHARED IMPORTED GLOBAL)

IF(RV_TARGET_WINDOWS)
    # FDK-AAC DLL for v2.0.3 is typically libfdk-aac-2.dll (SO_VERSION 2)
    SET_PROPERTY(TARGET ffmpeg::fdk-aac PROPERTY IMPORTED_LOCATION "${FDK_AAC_BIN_DIR}/libfdk-aac-2${CMAKE_SHARED_LIBRARY_SUFFIX}")
    SET_PROPERTY(TARGET ffmpeg::fdk-aac PROPERTY IMPORTED_IMPLIB ${FDK_AAC_LIBRARY_DIR}/libfdk-aac.dll.a) # MinGW import library
ELSE()
    SET_PROPERTY(TARGET ffmpeg::fdk-aac PROPERTY IMPORTED_LOCATION ${FDK_AAC_LIBRARY_DIR}/libfdk-aac-2${CMAKE_SHARED_LIBRARY_SUFFIX})
ENDIF()

TARGET_INCLUDE_DIRECTORIES(ffmpeg::fdk-aac INTERFACE ${FDK_AAC_INCLUDE_DIR})
ADD_DEPENDENCIES(ffmpeg::fdk-aac ${_target})

LIST(APPEND RV_DEPS_LIST ffmpeg::fdk-aac) 