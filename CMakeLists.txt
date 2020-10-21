cmake_minimum_required(VERSION 3.11...3.18)

project(examplelib
  VERSION 1.0.0
  DESCRIPTION "An example of a C++ header-only library using CMake, doxygen, and Catch."
  HOMEPAGE_URL "https://github.com/hsloot/cpp-ho-library-template"
  LANGUAGES CXX
)

option(BUILD_DOCS "Build and Install Documents (Requires Doxygen)" OFF)
option(${CMAKE_PROJECT_NAME}_BUILD_TESTING "Build and run tests" OFF)

## Make sure that custom modules like FindXYZ are found
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

include(GNUInstallDirs)

## Define Target
## =============

add_library(${CMAKE_PROJECT_NAME} INTERFACE)
target_include_directories(${CMAKE_PROJECT_NAME}
  INTERFACE
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
      $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/include>
)
target_compile_features(${CMAKE_PROJECT_NAME} INTERFACE cxx_std_14)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_DOCS)
  find_package(Doxygen REQUIRED dot)
  if(Doxygen_FOUND)
    add_subdirectory(docs)
  else()
    message(STATUS "Doxygen not found, not building docs")
  endif()
endif()

## Testing
## =======

include(FetchContent)
if(${CMAKE_VERSION} VERSION_LESS 3.14)
  include(cmake/add_FetchContent_MakeAvailable.cmake)
endif()


if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include(CTest)
endif()

## flag RMOLIB_BUILD_TESTING for enable testing anyway
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR ${CMAKE_PROJECT_NAME}_BUILD_TESTING) AND BUILD_TESTING)
  add_subdirectory(test)
endif()
