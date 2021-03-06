#
# Copyright (C) 2018-2020 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

cmake_minimum_required(VERSION 3.5)

set(CURRENT_PROJECT ${PROJECT_NAME})
include(../../../Site/QuasarAppLib/CMake/ProjectOut.cmake)
include(../../../Site/QuasarAppLib/CMake/Version.cmake)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DBASE_FRONT_LIBRARY)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

file(GLOB SOURCE_CPP
    "src/*.cpp"
    "src/*.qrc"

)

add_library(${CURRENT_PROJECT} ${SOURCE_CPP})

target_link_libraries(${CURRENT_PROJECT} PRIVATE Qt5::Core Qt5::Quick QuasarApp )
target_include_directories(${CURRENT_PROJECT} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(${CURRENT_PROJECT} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/Private")
