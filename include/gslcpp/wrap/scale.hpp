/// \file       include/gslcpp/wrap/scale.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_scale().

#pragma once
#include "container.hpp" // w_vector

namespace gsl {


/// For vector `u` and scalar `v`, produce effect of `u = u * v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_scale
/// @param u  Pointer to vector.
/// @param v  Scalar.
/// @return  TBD: GSL's documentation does not specify.
inline int w_scale(w_vector<double> *u, double const &v) {
  return gsl_vector_scale(u, v);
}


/// For vector `u` and scalar `v`, produce effect of `u = u * v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_scale
/// @param u  Pointer to vector.
/// @param v  Scalar.
/// @return  TBD: GSL's documentation does not specify.
inline int w_scale(w_vector<float> *u, float const &v) {
  return gsl_vector_float_scale(u, v);
}


/// For vector `u` and scalar `v`, produce effect of `u = u * v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_scale
/// @param u  Pointer to vector.
/// @param v  Scalar.
/// @return  TBD: GSL's documentation does not specify.
inline int w_scale(w_vector<long double> *u, long double const &v) {
  return gsl_vector_long_double_scale(u, v);
}


/// For vector `u` and scalar `v`, produce effect of `u = u * v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_scale
/// @param u  Pointer to vector.
/// @param v  Scalar.
/// @return  TBD: GSL's documentation does not specify.
inline int w_scale(w_vector<int> *u, int const &v) {
  return gsl_vector_int_scale(u, v);
}


/// For vector `u` and scalar `v`, produce effect of `u = u * v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_scale
/// @param u  Pointer to vector.
/// @param v  Scalar.
/// @return  TBD: GSL's documentation does not specify.
inline int w_scale(w_vector<unsigned> *u, unsigned const &v) {
  return gsl_vector_uint_scale(u, v);
}


/// For vector `u` and scalar `v`, produce effect of `u = u * v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_scale
/// @param u  Pointer to vector.
/// @param v  Scalar.
/// @return  TBD: GSL's documentation does not specify.
inline int w_scale(w_vector<long> *u, long const &v) {
  return gsl_vector_long_scale(u, v);
}


/// For vector `u` and scalar `v`, produce effect of `u = u * v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_scale
/// @param u  Pointer to vector.
/// @param v  Scalar.
/// @return  TBD: GSL's documentation does not specify.
inline int w_scale(w_vector<unsigned long> *u, unsigned long const &v) {
  return gsl_vector_ulong_scale(u, v);
}


/// For vector `u` and scalar `v`, produce effect of `u = u * v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_scale
/// @param u  Pointer to vector.
/// @param v  Scalar.
/// @return  TBD: GSL's documentation does not specify.
inline int w_scale(w_vector<short> *u, short const &v) {
  return gsl_vector_short_scale(u, v);
}


/// For vector `u` and scalar `v`, produce effect of `u = u * v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_scale
/// @param u  Pointer to vector.
/// @param v  Scalar.
/// @return  TBD: GSL's documentation does not specify.
inline int w_scale(w_vector<unsigned short> *u, unsigned short const &v) {
  return gsl_vector_ushort_scale(u, v);
}


/// For vector `u` and scalar `v`, produce effect of `u = u * v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_scale
/// @param u  Pointer to vector.
/// @param v  Scalar.
/// @return  TBD: GSL's documentation does not specify.
inline int w_scale(w_vector<char> *u, char const &v) {
  return gsl_vector_char_scale(u, v);
}


/// For vector `u` and scalar `v`, produce effect of `u = u * v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_scale
/// @param u  Pointer to vector.
/// @param v  Scalar.
/// @return  TBD: GSL's documentation does not specify.
inline int w_scale(w_vector<unsigned char> *u, unsigned char const &v) {
  return gsl_vector_uchar_scale(u, v);
}


/// For vector `u` and scalar `v`, produce effect of `u = u * v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_scale
/// @param u  Pointer to vector.
/// @param v  Scalar.
/// @return  TBD: GSL's documentation does not specify.
inline int w_scale(w_vector<gsl_complex> *u, gsl_complex const &v) {
  return gsl_vector_complex_scale(u, v);
}


/// For vector `u` and scalar `v`, produce effect of `u = u * v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_scale
/// @param u  Pointer to vector.
/// @param v  Scalar.
/// @return  TBD: GSL's documentation does not specify.
inline int
w_scale(w_vector<gsl_complex_float> *u, gsl_complex_float const &v) {
  return gsl_vector_complex_float_scale(u, v);
}


/// For vector `u` and scalar `v`, produce effect of `u = u * v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_scale
/// @param u  Pointer to vector.
/// @param v  Scalar.
/// @return  TBD: GSL's documentation does not specify.
inline int w_scale(
      w_vector<gsl_complex_long_double> *u, gsl_complex_long_double const &v) {
  return gsl_vector_complex_long_double_scale(u, v);
}


} // namespace gsl

// EOF
