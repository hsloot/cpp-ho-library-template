cmake_minimum_required(VERSION 3.11...3.18)

project(examplelib
  VERSION 1.0.0
  DESCRIPTION "An example of a C++ header-only library using CMake, doxygen, and Catch."
  LANGUAGES CXX)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  set(CMAKE_CXX_EXTENSIONS OFF)

  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  include(CTest)

  find_package(Doxygen)
  if(Doxygen_FOUND)
    #if (CMAKE_BUILD_TYPE MATCHES "^[Rr]elease")
      add_subdirectory(docs)
    #endif()
  else()
    message(STATUS "Doxygen not found, not building docs")
  endif()

  add_library(examplelib INTERFACE)
  target_include_directories(examplelib
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
  )

endif()


include(FetchContent)
if(${CMAKE_VERSION} VERSION_LESS 3.14)
  include(cmake/add_FetchContent_MakeAvailable.cmake)
endif()


if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
  add_subdirectory(test)
endif()
