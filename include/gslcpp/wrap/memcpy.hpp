/// \file       include/gslcpp/wrap/memcpy.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_memcpy().

#pragma once
#include "type-map.hpp"

namespace gsl {


/// Copy elements of vector `v` into vector `u`.
/// Each vector must have same length.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_memcpy
/// @param u  Pointer to vector that is destination of copying.
/// @param v  Pointer to vector that is source of copying.
/// @return  TBD: GSL's documentation does not specify.
inline int w_memcpy(w_vector<double> *u, w_vector<double const> *v) {
  return gsl_vector_memcpy(u, v);
}


/// Copy elements of vector `v` into vector `u`.
/// Each vector must have same length.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_memcpy
/// @param u  Pointer to vector that is destination of copying.
/// @param v  Pointer to vector that is source of copying.
/// @return  TBD: GSL's documentation does not specify.
inline int w_memcpy(w_vector<float> *u, w_vector<float const> *v) {
  return gsl_vector_float_memcpy(u, v);
}


/// Copy elements of vector `v` into vector `u`.
/// Each vector must have same length.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_memcpy
/// @param u  Pointer to vector that is destination of copying.
/// @param v  Pointer to vector that is source of copying.
/// @return  TBD: GSL's documentation does not specify.
inline int w_memcpy(w_vector<long double> *u, w_vector<long double const> *v) {
  return gsl_vector_long_double_memcpy(u, v);
}


/// Copy elements of vector `v` into vector `u`.
/// Each vector must have same length.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_memcpy
/// @param u  Pointer to vector that is destination of copying.
/// @param v  Pointer to vector that is source of copying.
/// @return  TBD: GSL's documentation does not specify.
inline int w_memcpy(w_vector<int> *u, w_vector<int const> *v) {
  return gsl_vector_int_memcpy(u, v);
}


/// Copy elements of vector `v` into vector `u`.
/// Each vector must have same length.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_memcpy
/// @param u  Pointer to vector that is destination of copying.
/// @param v  Pointer to vector that is source of copying.
/// @return  TBD: GSL's documentation does not specify.
inline int w_memcpy(w_vector<unsigned> *u, w_vector<unsigned const> *v) {
  return gsl_vector_uint_memcpy(u, v);
}


/// Copy elements of vector `v` into vector `u`.
/// Each vector must have same length.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_memcpy
/// @param u  Pointer to vector that is destination of copying.
/// @param v  Pointer to vector that is source of copying.
/// @return  TBD: GSL's documentation does not specify.
inline int w_memcpy(w_vector<long> *u, w_vector<long const> *v) {
  return gsl_vector_long_memcpy(u, v);
}


/// Copy elements of vector `v` into vector `u`.
/// Each vector must have same length.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_memcpy
/// @param u  Pointer to vector that is destination of copying.
/// @param v  Pointer to vector that is source of copying.
/// @return  TBD: GSL's documentation does not specify.
inline int
w_memcpy(w_vector<unsigned long> *u, w_vector<unsigned long const> *v) {
  return gsl_vector_ulong_memcpy(u, v);
}


/// Copy elements of vector `v` into vector `u`.
/// Each vector must have same length.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_memcpy
/// @param u  Pointer to vector that is destination of copying.
/// @param v  Pointer to vector that is source of copying.
/// @return  TBD: GSL's documentation does not specify.
inline int w_memcpy(w_vector<short> *u, w_vector<short const> *v) {
  return gsl_vector_short_memcpy(u, v);
}


/// Copy elements of vector `v` into vector `u`.
/// Each vector must have same length.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_memcpy
/// @param u  Pointer to vector that is destination of copying.
/// @param v  Pointer to vector that is source of copying.
/// @return  TBD: GSL's documentation does not specify.
inline int
w_memcpy(w_vector<unsigned short> *u, w_vector<unsigned short const> *v) {
  return gsl_vector_ushort_memcpy(u, v);
}


/// Copy elements of vector `v` into vector `u`.
/// Each vector must have same length.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_memcpy
/// @param u  Pointer to vector that is destination of copying.
/// @param v  Pointer to vector that is source of copying.
/// @return  TBD: GSL's documentation does not specify.
inline int w_memcpy(w_vector<char> *u, w_vector<char const> *v) {
  return gsl_vector_char_memcpy(u, v);
}


/// Copy elements of vector `v` into vector `u`.
/// Each vector must have same length.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_memcpy
/// @param u  Pointer to vector that is destination of copying.
/// @param v  Pointer to vector that is source of copying.
/// @return  TBD: GSL's documentation does not specify.
inline int
w_memcpy(w_vector<unsigned char> *u, w_vector<unsigned char const> *v) {
  return gsl_vector_uchar_memcpy(u, v);
}


/// Copy elements of vector `v` into vector `u`.
/// Each vector must have same length.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_memcpy
/// @param u  Pointer to vector that is destination of copying.
/// @param v  Pointer to vector that is source of copying.
/// @return  TBD: GSL's documentation does not specify.
inline int w_memcpy(w_vector<gsl_complex> *u, w_vector<gsl_complex const> *v) {
  return gsl_vector_complex_memcpy(u, v);
}


/// Copy elements of vector `v` into vector `u`.
/// Each vector must have same length.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_memcpy
/// @param u  Pointer to vector that is destination of copying.
/// @param v  Pointer to vector that is source of copying.
/// @return  TBD: GSL's documentation does not specify.
inline int w_memcpy(
      w_vector<gsl_complex_float> *u, w_vector<gsl_complex_float const> *v) {
  return gsl_vector_complex_float_memcpy(u, v);
}


/// Copy elements of vector `v` into vector `u`.
/// Each vector must have same length.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_memcpy
/// @param u  Pointer to vector that is destination of copying.
/// @param v  Pointer to vector that is source of copying.
/// @return  TBD: GSL's documentation does not specify.
inline int w_memcpy(
      w_vector<gsl_complex_long_double> *u,
      w_vector<gsl_complex_long_double const> *v) {
  return gsl_vector_complex_long_double_memcpy(u, v);
}


} // namespace gsl

// EOF
