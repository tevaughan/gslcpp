
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

# This generates 'compile_commands.json' that Doxygen can use.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# clang-tidy
find_program (CLANG_TIDY_EXE NAMES "clang-tidy")
if(CLANG_TIDY_EXE)
  message(STATUS "clang-tidy found!")
  set(CMAKE_CXX_CLANG_TIDY
    "${CLANG_TIDY_EXE};-format-style=file;-header-filter='${CMAKE_SOURCE_DIR}/*'"
    CACHE STRING "" FORCE)
else()
  message(STATUS "clang-tidy NOT found!")
  set(CMAKE_CXX_CLANG_TIDY "" CACHE STRING "" FORCE) # clear it
endif()

# eigen
#
find_package(Eigen3 REQUIRED)
message("-- Found Eigen-${Eigen3_VERSION}")
string(REGEX REPLACE "^([0-9]+)\..*" "\\1" EIGEN_MAJOR ${Eigen3_VERSION})
string(REGEX REPLACE
  "^[0-9]+\.([0-9]+)(\..*)?" "\\1" EIGEN_MINOR ${Eigen3_VERSION})
message("--   Using ${EIGEN_MAJOR} as major version-number")
message("--   Using ${EIGEN_MINOR} as minor version-number")
add_definitions(-DEIGEN_MAJOR=${EIGEN_MAJOR})
add_definitions(-DEIGEN_MINOR=${EIGEN_MINOR})
# TODO: Add this flag to the right declaration (not add_definitions!).
# This is needed in case the installed version of Eigen causes this warning to
# be emitted.
add_definitions(-Wno-deprecated-anon-enum-enum-conversion)

# doxygen
#
# doxygen-1.9.2 is not require here, but version below 1.9.2 will not document
# C++-20 concepts correctly.
find_package(Doxygen REQUIRED dot dia OPTIONAL_COMPONENTS mscgen)
#
# The function that is supposed to add a target for generating docs via
# `doxygen` has failed for me when I use Doxygen-1.9.3.  It stubbornly makes
# `doxygen` look for `dot` under `/usr/sbin`!
#doxygen_add_docs(doc)
#
# Instead, manually add the target.
if(DOXYGEN_FOUND)
  set(doxyfile ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
  # This invokes 'doxygen', which runs at the top of the source-tree and puts
  # output under 'html' for github-pages.
  add_custom_target(doc
    bash -c "\
      rm -fr html;\
      if ${DOXYGEN_EXECUTABLE} ${doxyfile}; then\
        echo disabled: git add html;\
      fi"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "generating API-documentation with Doxygen"
    VERBATIM)
  # This deletes the directory 'build/html' in case the Doxygen-generated files
  # were to go there.  This will end up doing nothing at the moment, though,
  # because the Doxygen-generated files go to 'docs/html' relative to the
  # top-level source-directory (for github-pages) according to 'Doxyfile'.
  set_directory_properties(PROPERIES ADDITIONAL_MAKE_CLEAN_FILES html)
endif()

# gsl
#
find_package(GSL REQUIRED)
string(REGEX REPLACE "^([0-9]+)\..*" "\\1" GSL_MAJOR ${GSL_VERSION})
string(REGEX REPLACE "^[0-9]+\.([0-9]+)(\..*)?" "\\1" GSL_MINOR ${GSL_VERSION})
message("--   Using ${GSL_MAJOR} as major version-number")
message("--   Using ${GSL_MINOR} as minor version-number")
add_definitions(-DGSL_MAJOR=${GSL_MAJOR})
add_definitions(-DGSL_MINOR=${GSL_MINOR})

add_subdirectory(test)

