
add_executable(tests test-main.cpp
  vec-iface-test.cpp
  vec-iterator-test.cpp
  vector-test.cpp
  )

target_include_directories(tests PRIVATE ../include)

# 'GSL::gsl' and 'GSL::gslcblas' are available if 'find_package(GSL ...)'
# succeed in top-level 'CMakeLists.txt'.
target_link_libraries(tests GSL::gsl GSL::gslcblas)

SETUP_TARGET_FOR_COVERAGE_LLVM_COV(
  NAME tests_cov
  EXECUTABLE tests
  DEPENDENCIES tests)

