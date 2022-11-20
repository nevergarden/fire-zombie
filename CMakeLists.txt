cmake_minimum_required(VERSION 3.1)

set(FZ_VERSION_MAJOR 1)
set(FZ_VERSION_MINOR 0)
set(FZ_VERSION_PATCH 0)
set(FZ_VERSION ${FZ_VERSION_MAJOR}.${FZ_VERSION_MINOR}.${FZ_VERSION_PATCH})

if(WIN32)
  project(fire-zombie C CXX)
else()
  project(fire-zombie C)
endif()

include(GNUInstallDirs)
include(FindPkgConfig)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR})

set(sources)
set(public_headers src/firezombie.h)

if(ANDROID)
  list(APPEND sources src/android/platform_android.c)
endif()

if(IOS_PLATFORM)
  list(APPEND sources src/ios/platform_ios.m)
endif()

add_library(libfzombie ${sources})

set_target_properties(libfzombie
  PROPERTIES
  PUBLIC_HEADER ${public_headers}
)

set_target_properties(libfzombie
  PROPERTIES
  VERSION ${FZ_VERSION}
  SOVERSION ${FZ_VERSION_MAJOR}
)

if(WIN32)
  target_link_libraries(libfzombie ws2_32 user32)
else()
  target_link_libraries(libfzombie m pthread)
endif()
