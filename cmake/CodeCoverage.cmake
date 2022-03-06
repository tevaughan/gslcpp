# Copyright 2022 Thomas E. Vaughan, all rights reserved.
# Loosely based on Lars Bilke's script of 2017.

# USAGE:
#
# 1. Copy this file into your cmake-modules path.
#
# 2. Add the following line to your CMakeLists.txt:
#    ```
#    include(CodeCoverage)
#    ```
#
# 3. Edit code below (if necessary) to make custom target which runs executable
#    and produces coverage-report.

include(CMakeParseArguments)

# Check prereqs
# Note that following replacements leave intact any numeric suffix.
# For example, 'clang++-12' becomes 'llvm-cov-12'.
# This ensures consistency between executable and analyzer.
string(REPLACE "clang++" "llvm-cov" desired_llvm_cov ${CMAKE_CXX_COMPILER})
find_program(LLVM_COV_PATH NAMES ${desired_llvm_cov} PATHS ENV PATH)
string(REPLACE "clang++" "llvm-profdata" desired_llvm_profdata
  ${CMAKE_CXX_COMPILER})
find_program(LLVM_PROFDATA_PATH NAMES ${desired_llvm_profdata} PATHS ENV PATH)

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(Apple)?[Cc]lang")
  if("${CMAKE_CXX_COMPILER_VERSION}" VERSION_LESS 3)
    message(FATAL_ERROR "Clang-version must be 3 or greater for coverage.")
  endif()
else()
  message(FATAL_ERROR "C++-compiler must be clang for coverage.")
endif()

# See Step 1 at 'https://clang.llvm.org/docs/SourceBasedCodeCoverage.html'.
# Also see
# 'https://stackoverflow.com/questions/11437692/how-to-add-a-custom-build-type-to-cmake-targeting-make'.
set(COVERAGE_COMPILER_FLAGS
  "-O0 -g -fprofile-instr-generate -fcoverage-mapping" CACHE INTERNAL "")

set(COVERAGE_LINKER_FLAGS "-fprofile-instr-generate" CACHE INTERNAL "")

set(CMAKE_CXX_FLAGS_COVERAGE ${COVERAGE_COMPILER_FLAGS}
  CACHE STRING "Flags used by the C++ compiler during coverage builds."
  FORCE)
set(CMAKE_C_FLAGS_COVERAGE ${COVERAGE_COMPILER_FLAGS}
  CACHE STRING "Flags used by the C compiler during coverage builds."
  FORCE)
set(CMAKE_EXE_LINKER_FLAGS_COVERAGE ${COVERAGE_LINKER_FLAGS}
  CACHE STRING "Flags used for linking binaries during coverage builds."
  FORCE)
set(CMAKE_SHARED_LINKER_FLAGS_COVERAGE ""
  CACHE STRING "Flags used by shared-library linker during coverage builds."
  FORCE)

mark_as_advanced(
  CMAKE_CXX_FLAGS_COVERAGE
  CMAKE_C_FLAGS_COVERAGE
  CMAKE_EXE_LINKER_FLAGS_COVERAGE
  CMAKE_SHARED_LINKER_FLAGS_COVERAGE)

# Define target for running and collecting code-coverage information.
# - Build dependencies.
# - Run executable and output reports.
#
# NOTE! Executable should have ZERO as exit-code; otherwise,
# coverage-generation will not complete.
#
# For example:
#
# SETUP_TARGET_FOR_COVERAGE_LLVM_COV(
#   NAME tests_coverage  # name of make-target
#   EXECUTABLE tests     # name of executable
#   DEPENDENCIES tests   # dependencies to build
#   )
function(SETUP_TARGET_FOR_COVERAGE_LLVM_COV)

  set(options NONE)
  set(oneValueArgs NAME) # Note: NAME not NONE!
  set(multiValueArgs EXECUTABLE EXECUTABLE_ARGS DEPENDENCIES)
  cmake_parse_arguments(
    Coverage "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

  if(NOT LLVM_PROFDATA_PATH)
    message(FATAL_ERROR "llvm-profdata not found.")
  endif() # NOT LLVM_PROFDATA_PATH

  if(NOT LLVM_COV_PATH)
    message(FATAL_ERROR "llvm-cov not found.")
  endif() # NOT LLVM_COV_PATH

  # Products of coverage-analysis go directly into the `docs`-directory, just
  # under the top level of the source-tree.
  set(productsDir ${CMAKE_SOURCE_DIR}/docs)

  # Setup target
  add_custom_target(
    ${Coverage_NAME}
    # Run tests
    COMMAND ${Coverage_EXECUTABLE} ${Coverage_EXECUTABLE_ARGS}
    COMMENT "Tests run for coverage."
    COMMAND ${LLVM_PROFDATA_PATH}
            merge
            -sparse
            -o ${Coverage_NAME}.profdata
            default.profraw
    # Without the '..' at the end of the next command (just before the
    # pipe-symbol indicating how to process the command's output), the
    # following error shows up when '-show-functions' be included in the
    # command:
    #
    # "error: source files must be specified when -show-functions=true is
    # specified"
    #
    # I found the solution, given by briansmith, here:
    #
    #   https://github.com/rust-lang/rust/issues/34701#issuecomment-740237332
    #   https://github.com/rust-lang/rust/issues/34701#issuecomment-740238223
    #
    # briansmith recommended using '.' to solve frazerk's problem.
    #
    #   https://github.com/rust-lang/rust/issues/34701#issuecomment-739561826
    #
    # '.' did not work for me because '.' was not the right directory for
    # resolving relative paths.  I tried '..', and it worked!
    COMMAND ${LLVM_COV_PATH}
            report
            -show-functions
            -instr-profile=${Coverage_NAME}.profdata
            -ignore-filename-regex='.*test/.*'
            ${CMAKE_CURRENT_BINARY_DIR}/${Coverage_EXECUTABLE}
            ..
            | c++filt > ${productsDir}/${Coverage_NAME}-summary.txt
    COMMAND ${LLVM_COV_PATH}
            show
            -instr-profile=${Coverage_NAME}.profdata
            -ignore-filename-regex='.*test/.*'
            ${CMAKE_CURRENT_BINARY_DIR}/${Coverage_EXECUTABLE}
            | c++filt > ${productsDir}/${Coverage_NAME}.txt
    COMMAND ${LLVM_COV_PATH}
            show
            --format=html
            -instr-profile=${Coverage_NAME}.profdata
            -ignore-filename-regex='.*test/.*'
            ${CMAKE_CURRENT_BINARY_DIR}/${Coverage_EXECUTABLE}
            | c++filt > ${productsDir}/${Coverage_NAME}.html
    # Clean up
    COMMAND ${CMAKE_COMMAND} -E remove
    ${Coverage_NAME}.profdata default.profraw
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    DEPENDS ${Coverage_DEPENDENCIES}
    )

  # Show where to find the lcov info report
  add_custom_command(
    TARGET ${Coverage_NAME} POST_BUILD
    COMMAND ;
    COMMENT "Reports saved in ${Coverage_NAME}.txt and ${Coverage_NAME}.html.")

endfunction() # SETUP_TARGET_FOR_COVERAGE_LLVM_COV

