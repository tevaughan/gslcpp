/// @file       include/gslcpp/c/vector.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::c::vec_ and gslcpp::c::vector.

#pragma once

// Use inline-definition of each accessor-function.
// - Define this before including `gsl_vector.h`.
#ifndef HAVE_INLINE
#  define HAVE_INLINE
#endif

#include <gsl/gsl_vector.h> // gsl_vector, gsl_vector_float, etc.

namespace gsl::c {


/// Template whose specialization defines dependent type, `vec_<E>::type`.
/// @tparam E  Type of element for vector.
template<typename E> struct vec_;


template<> struct vec_<double> { using type= gsl_vector; };

template<> struct vec_<double const> { using type= gsl_vector const; };

template<> struct vec_<float> { using type= gsl_vector_float; };

template<> struct vec_<float const> { using type= gsl_vector_float const; };

template<> struct vec_<long double> { using type= gsl_vector_long_double; };

template<> struct vec_<long double const> { using type= gsl_vector_long_double const; };

template<> struct vec_<int> { using type= gsl_vector_int; };

template<> struct vec_<int const> { using type= gsl_vector_int const; };

template<> struct vec_<unsigned> { using type= gsl_vector_uint; };

template<> struct vec_<unsigned const> { using type= gsl_vector_uint const; };

template<> struct vec_<long> { using type= gsl_vector_long; };

template<> struct vec_<long const> { using type= gsl_vector_long const; };

template<> struct vec_<unsigned long> { using type= gsl_vector_ulong; };

template<> struct vec_<unsigned long const> { using type= gsl_vector_ulong const; };

template<> struct vec_<short> { using type= gsl_vector_short; };

template<> struct vec_<short const> { using type= gsl_vector_short const; };

template<> struct vec_<unsigned short> { using type= gsl_vector_ushort; };

template<> struct vec_<unsigned short const> { using type= gsl_vector_ushort const; };

template<> struct vec_<char> { using type= gsl_vector_char; };

template<> struct vec_<char const> { using type= gsl_vector_char const; };

template<> struct vec_<unsigned char> { using type= gsl_vector_uchar; };

template<> struct vec_<unsigned char const> { using type= gsl_vector_uchar const; };

template<> struct vec_<gsl_complex> { using type= gsl_vector_complex; };

template<> struct vec_<gsl_complex const> { using type= gsl_vector_complex const; };

template<> struct vec_<gsl_complex_float> { using type= gsl_vector_complex_float; };

template<> struct vec_<gsl_complex_float const> { using type= gsl_vector_complex_float const; };

template<> struct vec_<gsl_complex_long_double> { using type= gsl_vector_complex_long_double; };

template<> struct vec_<gsl_complex_long_double const> { using type= gsl_vector_complex_long_double const; };


/// GSL's native vector-type corresponding to element-type `E`.
/// @tparam E  Type of element for vector.
template<typename E> using vector= typename vec_<E>::type;


} // namespace gsl::c

#include "../version.hpp" // GSL_AT_LEAST()
#if !GSL_AT_LEAST(2, 7)
#  include <Eigen/Core> // Map, Matrix

namespace gsl::c {


using Eigen::Dynamic;
using Eigen::Map;
using Eigen::Matrix;
using Eigen::Stride;


/// Type of each element in gsl_vector of type V.
/// @tparam V  Type of gsl_vector (for example, gsl_vector_float).
template<typename V>
using vdata_t= std::remove_reference_t<decltype(*V::data)>;


/// Sum of elements in vector, for use when GSL's version be less than 2.7.
/// This function uses Eigen to compute the sum.
/// @tparam V  Type of gsl_vector.
/// @param v  Reference to vector.
/// @return  Sum of elements.
template<typename V> vdata_t<V> sum_for_gsl_lt_2p7(V const &v) {
  using E= vdata_t<V>;
  using S= Stride<Dynamic, Dynamic>;
  using map= Map<Matrix<E, Dynamic, Dynamic>, 0, S>;
  return map(v.data, v.size, 1, S(0, v.stride)).sum();
}


/// Linear combination with effect, `y = a*x + b*y`.
/// @tparam V  Type of vectors to be combined.
/// @param a  Coefficient of first vector.
/// @param x  Reference to first vector.
/// @param b  Coefficient of second vector.
/// @param y  Reference to second vector, which is updated.
/// @return  Zero; GSL's version has undocumented return-value.
template<typename V>
int axpby_for_gsl_lt_2p7(
      vdata_t<V> const &a, V const &x, vdata_t<V> const &b, V &y) {
  using E= vdata_t<V>;
  using S= Stride<Dynamic, Dynamic>;
  using map= Map<Matrix<E, Dynamic, Dynamic>, 0, S>;
  map ex(x.data, x.size, 1, S(0, x.stride));
  map ey(y.data, y.size, 1, S(0, y.stride));
  ey*= b;
  ey+= a * ex;
  return 0;
}


} // namespace gsl::c

#endif // !GSL_AT_LEAST(2, 7)

// EOF
