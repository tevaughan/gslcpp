/// \file       include/gslcpp/wrap/isneg.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_isneg().

#pragma once
#include "type-map.hpp"

namespace gsl {


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool w_isneg(w_vector<double const> *v) { return gsl_vector_isneg(v); }


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool w_isneg(w_vector<float const> *v) {
  return gsl_vector_float_isneg(v);
}


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool w_isneg(w_vector<long double const> *v) {
  return gsl_vector_long_double_isneg(v);
}


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool w_isneg(w_vector<int const> *v) { return gsl_vector_int_isneg(v); }


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool w_isneg(w_vector<unsigned const> *v) {
  return gsl_vector_uint_isneg(v);
}


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool w_isneg(w_vector<long const> *v) {
  return gsl_vector_long_isneg(v);
}


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool w_isneg(w_vector<unsigned long const> *v) {
  return gsl_vector_ulong_isneg(v);
}


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool w_isneg(w_vector<short const> *v) {
  return gsl_vector_short_isneg(v);
}


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool w_isneg(w_vector<unsigned short const> *v) {
  return gsl_vector_ushort_isneg(v);
}


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool w_isneg(w_vector<char const> *v) {
  return gsl_vector_char_isneg(v);
}


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool w_isneg(w_vector<unsigned char const> *v) {
  return gsl_vector_uchar_isneg(v);
}


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool w_isneg(w_vector<gsl_complex const> *v) {
  return gsl_vector_complex_isneg(v);
}


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool w_isneg(w_vector<gsl_complex_float const> *v) {
  return gsl_vector_complex_float_isneg(v);
}


/// True only if every element of vector `v` be negative.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_isneg
/// @param v  Pointer to vector.
/// @return  True only if every element of `v` be negative.
inline bool w_isneg(w_vector<gsl_complex_long_double const> *v) {
  return gsl_vector_complex_long_double_isneg(v);
}


} // namespace gsl

// EOF
