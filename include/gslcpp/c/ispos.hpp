/// @file       include/gslcpp/c/ispos.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::c::ispos().

#pragma once
#include "type-map.hpp"

namespace gsl::c {


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool ispos(c::vector<double const> *v) { return gsl_vector_ispos(v); }


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool ispos(c::vector<float const> *v) {
  return gsl_vector_float_ispos(v);
}


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool ispos(c::vector<long double const> *v) {
  return gsl_vector_long_double_ispos(v);
}


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool ispos(c::vector<int const> *v) { return gsl_vector_int_ispos(v); }


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool ispos(c::vector<unsigned const> *v) {
  return gsl_vector_uint_ispos(v);
}


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool ispos(c::vector<long const> *v) {
  return gsl_vector_long_ispos(v);
}


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool ispos(c::vector<unsigned long const> *v) {
  return gsl_vector_ulong_ispos(v);
}


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool ispos(c::vector<short const> *v) {
  return gsl_vector_short_ispos(v);
}


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool ispos(c::vector<unsigned short const> *v) {
  return gsl_vector_ushort_ispos(v);
}


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool ispos(c::vector<char const> *v) {
  return gsl_vector_char_ispos(v);
}


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool ispos(c::vector<unsigned char const> *v) {
  return gsl_vector_uchar_ispos(v);
}


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool ispos(c::vector<gsl_complex const> *v) {
  return gsl_vector_complex_ispos(v);
}


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool ispos(c::vector<gsl_complex_float const> *v) {
  return gsl_vector_complex_float_ispos(v);
}


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool ispos(c::vector<gsl_complex_long_double const> *v) {
  return gsl_vector_complex_long_double_ispos(v);
}


} // namespace gsl::c

// EOF
