/// \file       include/gslcpp/wrap/isnonneg.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_isnonneg().

#pragma once
#include "container.hpp" // w_vector

namespace gsl {


/// True only if every element of vector `v` be non-negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isnonneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be non-negative.
inline bool w_isnonneg(w_vector<double const> *v) {
  return gsl_vector_isnonneg(v);
}


/// True only if every element of vector `v` be non-negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isnonneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be non-negative.
inline bool w_isnonneg(w_vector<float const> *v) {
  return gsl_vector_float_isnonneg(v);
}


/// True only if every element of vector `v` be non-negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isnonneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be non-negative.
inline bool w_isnonneg(w_vector<long double const> *v) {
  return gsl_vector_long_double_isnonneg(v);
}


/// True only if every element of vector `v` be non-negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isnonneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be non-negative.
inline bool w_isnonneg(w_vector<int const> *v) {
  return gsl_vector_int_isnonneg(v);
}


/// True only if every element of vector `v` be non-negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isnonneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be non-negative.
inline bool w_isnonneg(w_vector<unsigned const> *v) {
  return gsl_vector_uint_isnonneg(v);
}


/// True only if every element of vector `v` be non-negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isnonneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be non-negative.
inline bool w_isnonneg(w_vector<long const> *v) {
  return gsl_vector_long_isnonneg(v);
}


/// True only if every element of vector `v` be non-negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isnonneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be non-negative.
inline bool w_isnonneg(w_vector<unsigned long const> *v) {
  return gsl_vector_ulong_isnonneg(v);
}


/// True only if every element of vector `v` be non-negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isnonneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be non-negative.
inline bool w_isnonneg(w_vector<short const> *v) {
  return gsl_vector_short_isnonneg(v);
}


/// True only if every element of vector `v` be non-negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isnonneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be non-negative.
inline bool w_isnonneg(w_vector<unsigned short const> *v) {
  return gsl_vector_ushort_isnonneg(v);
}


/// True only if every element of vector `v` be non-negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isnonneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be non-negative.
inline bool w_isnonneg(w_vector<char const> *v) {
  return gsl_vector_char_isnonneg(v);
}


/// True only if every element of vector `v` be non-negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isnonneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be non-negative.
inline bool w_isnonneg(w_vector<unsigned char const> *v) {
  return gsl_vector_uchar_isnonneg(v);
}


/// True only if every element of vector `v` be non-negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isnonneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be non-negative.
inline bool w_isnonneg(w_vector<gsl_complex const> *v) {
  return gsl_vector_complex_isnonneg(v);
}


/// True only if every element of vector `v` be non-negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isnonneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be non-negative.
inline bool w_isnonneg(w_vector<gsl_complex_float const> *v) {
  return gsl_vector_complex_float_isnonneg(v);
}


/// True only if every element of vector `v` be non-negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isnonneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be non-negative.
inline bool w_isnonneg(w_vector<gsl_complex_long_double const> *v) {
  return gsl_vector_complex_long_double_isnonneg(v);
}


} // namespace gsl

// EOF
