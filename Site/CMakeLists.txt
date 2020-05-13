#
# Copyright (C) 2018-2020 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

cmake_minimum_required(VERSION 3.5)

project(Site LANGUAGES CXX)
if(TARGET ${PROJECT_NAME})
  message("The ${PROJECT_NAME} arledy included in main Project")
  return()
endif()

add_subdirectory(QuasarAppLib)
add_subdirectory(ViewSolutions)
add_subdirectory(BaseFront)

include(QuasarAppLib/CMake/ProjectOut.cmake)
include(QuasarAppLib/CMake/Version.cmake)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core REQUIRED)

file(GLOB SOURCE_CPP
    "src/*.cpp"
    "src/Models/*.cpp"
    "src/*.qrc"

)

if(ANDROID)
    add_library(${PROJECT_NAME} SHARED ${SOURCE_CPP})
else()
    add_executable(${PROJECT_NAME} ${SOURCE_CPP})
endif()

target_compile_definitions(${PROJECT_NAME}
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core ViewSolutions QuasarApp BaseFront)
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/Models")
