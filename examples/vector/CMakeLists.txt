
add_executable(vector-example vector-example.cpp)

target_include_directories(vector-example PRIVATE ../../include)

# 'GSL::gsl' and 'GSL::gslcblas' are available if 'find_package(GSL ...)'
# succeed in top-level 'CMakeLists.txt'.
#
# 'Eigen3::Eigen' is available if 'find_package(Eigen3 ...)' succeed in
# top-level 'CMakeLists.txt'.
target_link_libraries(vector-example GSL::gsl GSL::gslcblas Eigen3::Eigen)

set(productsDir ${CMAKE_SOURCE_DIR}/docs/examples/vector)

add_custom_target(vector-example.out
  DEPENDS vector-example
  COMMAND mkdir -p ${productsDir}
  COMMAND ./vector-example > ${productsDir}/vector-example.out
  )

