/// \file       include/gslcpp/wrap/sum.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_sum().

#pragma once
#include "container.hpp" // w_vector
#include "element.hpp" // element_t
#include <Eigen/Core> // Dynamic, Map, Matrix, Stride

namespace gsl {


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<double const> *v) { return gsl_vector_sum(v); }


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<float const> *v) { return gsl_vector_float_sum(v); }


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<long double const> *v) {
  return gsl_vector_long_double_sum(v);
}


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<int const> *v) { return gsl_vector_int_sum(v); }


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<unsigned const> *v) {
  return gsl_vector_uint_sum(v);
}


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<long const> *v) { return gsl_vector_long_sum(v); }


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<unsigned long const> *v) {
  return gsl_vector_ulong_sum(v);
}


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<short const> *v) { return gsl_vector_short_sum(v); }


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<unsigned short const> *v) {
  return gsl_vector_ushort_sum(v);
}


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<char const> *v) { return gsl_vector_char_sum(v); }


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<unsigned char const> *v) {
  return gsl_vector_uchar_sum(v);
}


/// Sum of elements in complex vector, not covered by GSL's sum.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// This implementation uses Eigen to compute the sum.
/// @tparam C  Complex type of vector's element.
/// @param v  Reference to vector.
/// @return  Sum of elements.
template<typename C> C complex_sum(w_vector<C const> *v) {
  using Eigen::Dynamic;
  using Eigen::Map;
  using Eigen::Matrix;
  using Eigen::Stride;
  using S= Stride<Dynamic, Dynamic>;
  using map= Map<Matrix<C, Dynamic, 1> const, 0, S>;
  S const s(v->size * v->stride, v->stride);
  return map((C const *)v->data, v->size, s).sum();
}


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<gsl::complex<double> const> *v) {
  return complex_sum<gsl::complex<double>>(v);
}


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<gsl::complex<float> const> *v) {
  return complex_sum<gsl::complex<float>>(v);
}


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<gsl::complex<long double> const> *v) {
  return complex_sum<gsl::complex<long double>>(v);
}


} // namespace gsl

// EOF
