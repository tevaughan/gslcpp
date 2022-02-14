
# See http://www.stablecoder.ca/2018/10/30/full-cmake-helper-suite.html
# See https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html

cmake_minimum_required(VERSION 3.16) # Version that comes with Ubuntu 20.04.
project(gslcpp)

# Append ${PROJECT_SOURCE_DIR}/cmake to CMAKE_MODULE_PATH.
# Note that PROJECT_SOURCE_DIR is defined by the most recent project() command.
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

include(CodeCoverage)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD_DEBUG 20)
set(CMAKE_CXX_STANDARD_REQUIRED_DEBUG ON)
set(CMAKE_CXX_EXTENSIONS_DEBUG OFF)

set(CMAKE_CXX_STANDARD_COVERAGE 20)
set(CMAKE_CXX_STANDARD_REQUIRED_COVERAGE ON)
set(CMAKE_CXX_EXTENSIONS_COVERAGE OFF)

set(CMAKE_BUILD_TYPE Coverage)

set(CMAKE_VERBOSE_MAKEFILE ON)

# clang-tidy
find_program (CLANG_TIDY_EXE NAMES "clang-tidy")
if(CLANG_TIDY_EXE)
  message(STATUS "clang-tidy found!")
  set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE};-format-style=file;-header-filter='${CMAKE_SOURCE_DIR}/*'" CACHE STRING "" FORCE)
else()
  message(STATUS "clang-tidy NOT found!")
  set(CMAKE_CXX_CLANG_TIDY "" CACHE STRING "" FORCE) # clear it
endif()

add_subdirectory(test)

