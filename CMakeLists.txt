#
# Copyright (C) 2018-2020 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

cmake_minimum_required(VERSION 3.5)

set(BUILD_SHARED_LIBS ON)

include(Site/QuasarAppLib/CMake/ccache.cmake)
include(Site/QuasarAppLib/CMake/crossplatform/crossplatform.cmake)

project(DocsSite)

# Add sub directories
add_subdirectory(Site)

include(Site/QuasarAppLib/CMake/QuasarAppCITargets.cmake)

#addDoc("Patronum" ${CMAKE_CURRENT_SOURCE_DIR}/doxygen.conf)

initAll()
