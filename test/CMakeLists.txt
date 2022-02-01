
add_executable(tests test-main.cpp vec-base-test.cpp vector-test.cpp)
target_include_directories(tests PRIVATE ../include)
target_link_libraries(tests gsl)

SETUP_TARGET_FOR_COVERAGE_LLVM_COV(
  NAME tests_cov
  EXECUTABLE tests
  DEPENDENCIES tests)

