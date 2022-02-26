/// @file       include/gslcpp/c/isneg.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::c::isneg().

#pragma once
#include "type-map.hpp"

namespace gsl::c {


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool isneg(c::vector<double const> *v) { return gsl_vector_isneg(v); }


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool isneg(c::vector<float const> *v) {
  return gsl_vector_float_isneg(v);
}


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool isneg(c::vector<long double const> *v) {
  return gsl_vector_long_double_isneg(v);
}


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool isneg(c::vector<int const> *v) { return gsl_vector_int_isneg(v); }


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool isneg(c::vector<unsigned const> *v) {
  return gsl_vector_uint_isneg(v);
}


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool isneg(c::vector<long const> *v) {
  return gsl_vector_long_isneg(v);
}


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool isneg(c::vector<unsigned long const> *v) {
  return gsl_vector_ulong_isneg(v);
}


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool isneg(c::vector<short const> *v) {
  return gsl_vector_short_isneg(v);
}


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool isneg(c::vector<unsigned short const> *v) {
  return gsl_vector_ushort_isneg(v);
}


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool isneg(c::vector<char const> *v) {
  return gsl_vector_char_isneg(v);
}


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool isneg(c::vector<unsigned char const> *v) {
  return gsl_vector_uchar_isneg(v);
}


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool isneg(c::vector<gsl_complex const> *v) {
  return gsl_vector_complex_isneg(v);
}


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool isneg(c::vector<gsl_complex_float const> *v) {
  return gsl_vector_complex_float_isneg(v);
}


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool isneg(c::vector<gsl_complex_long_double const> *v) {
  return gsl_vector_complex_long_double_isneg(v);
}


} // namespace gsl::c

// EOF
