cmake_minimum_required(VERSION 3.1)

set(FZ_VERSION_MAJOR 1)
set(FZ_VERSION_MINOR 0)
set(FZ_VERSION_PATCH 0)
set(FZ_VERSION ${FZ_VERSION_MAJOR}.${FZ_VERSION_MINOR}.${FZ_VERSION_PATCH})

if(WIN32)
  project(fire-zombie CXX)
else()
  project(fire-zombie CXX)
endif()

include(GNUInstallDirs)
include(FindPkgConfig)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR})

set(sources src/Event.cpp)
set(public_headers src/Types.hpp)

if(ANDROID)
  list(APPEND sources src/android/platform_android.c)
endif()

if(IOS_PLATFORM)
  list(APPEND sources src/ios/platform_ios.m)
endif()


add_library(libfzombie SHARED ${sources})
add_library(libfzombieStatic STATIC ${sources})

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
  target_link_libraries(libfzombieStatic ws2_32 user32)
else()
  target_link_libraries(libfzombie m pthread)
  target_link_libraries(libfzombieStatic m pthread)
endif()

if(WIN32)
  set_target_properties(libfzombie
    PROPERTIES
    OUTPUT_NAME libfzombie
  )
  set_target_properties(libfzombieStatic
    PROPERTIES
    OUTPUT_NAME libfzombie
  )
else()
  set_target_properties(libfzombie
    PROPERTIES
    OUTPUT_NAME fzombie
  )
  set_target_properties(libfzombieStatic
    PROPERTIES
    OUTPUT_NAME fzombie
  )
endif()
