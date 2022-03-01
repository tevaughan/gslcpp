
add_executable(tests test-main.cpp
  v-iface-test.cpp
  v-iterator-test.cpp
  static-vector-test.cpp
  vector-view-test.cpp
  )

target_include_directories(tests PRIVATE ../include)

# 'GSL::gsl' and 'GSL::gslcblas' are available if 'find_package(GSL ...)'
# succeed in top-level 'CMakeLists.txt'.
#
# 'Eigen3::Eigen' is available if 'find_package(Eigen3 ...)' succeed in
# top-level 'CMakeLists.txt'.
target_link_libraries(tests GSL::gsl GSL::gslcblas Eigen3::Eigen)

SETUP_TARGET_FOR_COVERAGE_LLVM_COV(
  NAME tests_cov
  EXECUTABLE tests
  DEPENDENCIES tests)

