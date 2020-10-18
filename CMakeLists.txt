cmake_minimum_required(VERSION 3.14...3.18)

project(examplelib
  VERSION 1.0.0
  DESCRIPTION "An example of a C++ header-only library using CMake, doxygen, and Catch."
  LANGUAGES CXX)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  set(CMAKE_CXX_EXTENSIONS OFF)

  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  include(CTest)

  find_package(Doxygen)
  if(Doxygen_FOUND)
    add_subdirectory(docs)
  else()
    message(STATUS "Doxygen not found, not building docs")
  endif()

  add_library(examplelib INTERFACE)
  target_include_directories(examplelib
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
  )

  include(FetchContent)
  if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
    add_subdirectory(test)
  endif()

endif()
