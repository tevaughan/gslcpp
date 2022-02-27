/// \file       include/gslcpp/wrap/compat.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
///
/// \brief      Definition for
///             \ref data_t,
///             gsl::sum_for_gsl_lt_2p7(),
///             gsl::axpby_for_gsl_lt_2p7().

#pragma once

#include "../version.hpp" // GSL_AT_LEAST()
#if !GSL_AT_LEAST(2, 7)
#  include <Eigen/Core> // Map, Matrix

namespace gsl {


using Eigen::Dynamic;
using Eigen::Map;
using Eigen::Matrix;
using Eigen::Stride;


/// \anchor data_t
/// Type of each element in gsl_vector of type V.
/// @tparam V  Type of gsl_vector (for example, gsl_vector_float).
template<typename V> using data_t= std::remove_reference_t<decltype(*V::data)>;


/// Sum of elements in vector, for use when GSL's version be less than 2.7.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// This implementation uses Eigen to compute the sum.
/// @tparam V  Type of gsl_vector.
/// @param v  Reference to vector.
/// @return  Sum of elements.
template<typename V> data_t<V> sum_for_gsl_lt_2p7(V const &v) {
  using E= data_t<V>;
  using S= Stride<Dynamic, Dynamic>;
  using map= Map<Matrix<E, Dynamic, Dynamic>, 0, S>;
  return map(v.data, v.size, 1, S(0, v.stride)).sum();
}


/// Linear combination with effect, `y = a*x + b*y`, for use when GSL's version
/// be less than 2.7.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_axpby
///
/// This implementation uses Eigen to produce the effect.
///
/// @tparam V  Type of vectors to be combined.
/// @param a  Coefficient of first vector.
/// @param x  Reference to first vector.
/// @param b  Coefficient of second vector.
/// @param y  Reference to second vector, which is updated.
/// @return  Zero; GSL's version has undocumented return-value.
template<typename V>
int axpby_for_gsl_lt_2p7(
      data_t<V> const &a, V const &x, data_t<V> const &b, V &y) {
  using E= data_t<V>;
  using S= Stride<Dynamic, Dynamic>;
  using map= Map<Matrix<E, Dynamic, Dynamic>, 0, S>;
  map ex(x.data, x.size, 1, S(0, x.stride));
  map ey(y.data, y.size, 1, S(0, y.stride));
  ey*= b;
  ey+= a * ex;
  return 0;
}


} // namespace gsl

#endif // !GSL_AT_LEAST(2, 7)
