#
# Copyright (C) 2022  Autodesk, Inc. All Rights Reserved.
#
# SPDX-License-Identifier: Apache-2.0
#

INCLUDE(cxx_defaults)

SET(_target
    "TwkQtBase"
)

SET(_sources
    QtUtil.cpp
)

ADD_LIBRARY(
  ${_target} STATIC
  ${_sources}
)

FIND_PACKAGE(
  ${RV_QT_PACKAGE_NAME}
  COMPONENTS Core
  REQUIRED
)

TARGET_INCLUDE_DIRECTORIES(
  ${_target}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

TARGET_LINK_LIBRARIES(
  ${_target}
  PRIVATE TwkUtil Qt::Core
)

RV_STAGE(TYPE "LIBRARY" TARGET ${_target})
