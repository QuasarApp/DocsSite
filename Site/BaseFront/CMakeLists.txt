#
# Copyright (C) 2018-2020 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

cmake_minimum_required(VERSION 3.5)

include(../../Site/QuasarAppLib/CMake/ccache.cmake)
# Add sub directories
project(BaseFront)
if(TARGET ${PROJECT_NAME})
  message("The ${PROJECT_NAME} arledy included in main Project")
  return()
endif()

add_subdirectory(Front)

include(../../Site/QuasarAppLib/CMake/QuasarAppCITargets.cmake)

#addDoc("Patronum" ${CMAKE_CURRENT_SOURCE_DIR}/doxygen.conf)

initAll()
