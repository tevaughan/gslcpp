/// \file       include/gslcpp/wrap/compat.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
///
/// \brief      Definition for
///             \ref elem_generic,
///             elem<gsl_vector_complex>,
///             elem<gsl_vector_complex_float>,
///             elem<gsl_vector_complex_long_double>,
///             \ref elem_t,
///             gsl::sum_for_gsl_lt_2p7(),
///             gsl::axpby_for_gsl_lt_2p7().

#pragma once

#include "../version.hpp" // GSL_AT_LEAST()
#include "container.hpp" // gsl_vector_complex

#if !GSL_AT_LEAST(2, 7)
#  include <Eigen/Core> // Map, Matrix

namespace gsl {


using Eigen::Dynamic;
using Eigen::Map;
using Eigen::Matrix;
using Eigen::Stride;
using std::remove_reference_t;


/// \anchor elem_generic
/// Define type of each element in non-complex gsl_vector of type V.
/// Specialization defines type of each element in complex gsl_vector.
/// \sa elem<gsl_vector_complex>
/// \sa elem<gsl_vector_complex_float>
/// \sa elem<gsl_vector_comples_long_double>
/// \sa elem<gsl_vector_complex const>
/// \sa elem<gsl_vector_complex_float const>
/// \sa elem<gsl_vector_comples_long_double const>
/// @tparam V  Type of gsl_vector (for example, gsl_vector_float).
template<typename V> struct elem {
  /// Type of each element in non-complex gsl_vector of type V.
  using type= remove_reference_t<decltype(*V::data)>;
};


/// Specialization for gsl_vector_complex.
/// \sa \ref elem_generic
template<> struct elem<gsl_vector_complex> {
  /// Type of each element in gsl_vector_complex.
  using type= std::complex<double>;
};


/// Specialization for gsl_vector_complex_float.
/// \sa \ref elem_generic
template<> struct elem<gsl_vector_complex_float> {
  /// Type of each element in gsl_vector_complex_float.
  using type= std::complex<float>;
};


/// Specialization for gsl_vector_complex_long_double.
/// \sa \ref elem_generic
template<> struct elem<gsl_vector_complex_long_double> {
  /// Type of each element in gsl_vector_complex_long_double.
  using type= std::complex<long double>;
};


/// \anchor elem_t
/// Type of element (e.g., float) in vector of type V.
/// \tparam V  Type of gsl_vector (e.g., gsl_vector_float).
template<typename V> using elem_t= typename elem<V>::type;


/// Sum of elements in vector, for use when GSL's version be less than 2.7.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// This implementation uses Eigen to compute the sum.
/// @tparam V  Type of gsl_vector.
/// @param v  Reference to vector.
/// @return  Sum of elements.
template<typename V> elem_t<V> sum_for_gsl_lt_2p7(V const &v) {
  using E= elem_t<V>;
  using S= Stride<Dynamic, Dynamic>;
  using map= Map<Matrix<E, Dynamic, 1> const, 0, S>;
  return map((E const *)v.data, v.size, S(v.size * v.stride, v.stride)).sum();
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
      elem_t<V> const &a, V const &x, elem_t<V> const &b, V &y) {
  using E= elem_t<V>;
  using S= Stride<Dynamic, Dynamic>;
  using xmap= Map<Matrix<E, Dynamic, 1> const, 0, S>;
  using ymap= Map<Matrix<E, Dynamic, 1>, 0, S>;
  xmap ex((E const*)x.data, x.size, S(x.size * x.stride, x.stride));
  ymap ey((E *)y.data, y.size, S(x.size * x.stride, y.stride));
  ey*= b;
  ey+= a * ex;
  return 0;
}


} // namespace gsl

#endif // !GSL_AT_LEAST(2, 7)
