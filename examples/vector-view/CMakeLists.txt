
add_executable(vector-view-example vector-view-example.cpp)

target_include_directories(vector-view-example PRIVATE ../../include)

# 'GSL::gsl' and 'GSL::gslcblas' are available if 'find_package(GSL ...)'
# succeed in top-level 'CMakeLists.txt'.
#
# 'Eigen3::Eigen' is available if 'find_package(Eigen3 ...)' succeed in
# top-level 'CMakeLists.txt'.
target_link_libraries(vector-view-example GSL::gsl GSL::gslcblas Eigen3::Eigen)

set(productsDir ${CMAKE_SOURCE_DIR}/docs/examples/vector-view)

add_custom_target(vector-view-example.out
  DEPENDS vector-view-example
  COMMAND mkdir -p ${productsDir}
  COMMAND ./vector-view-example > ${productsDir}/vector-view-example.out
  )

