/// \file       include/gslcpp/wrap/ispos.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_ispos().

#pragma once
#include "container.hpp" // w_vector

namespace gsl {


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool w_ispos(w_vector<double const> *v) { return gsl_vector_ispos(v); }


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool w_ispos(w_vector<float const> *v) {
  return gsl_vector_float_ispos(v);
}


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool w_ispos(w_vector<long double const> *v) {
  return gsl_vector_long_double_ispos(v);
}


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool w_ispos(w_vector<int const> *v) { return gsl_vector_int_ispos(v); }


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool w_ispos(w_vector<unsigned const> *v) {
  return gsl_vector_uint_ispos(v);
}


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool w_ispos(w_vector<long const> *v) {
  return gsl_vector_long_ispos(v);
}


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool w_ispos(w_vector<unsigned long const> *v) {
  return gsl_vector_ulong_ispos(v);
}


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool w_ispos(w_vector<short const> *v) {
  return gsl_vector_short_ispos(v);
}


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool w_ispos(w_vector<unsigned short const> *v) {
  return gsl_vector_ushort_ispos(v);
}


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool w_ispos(w_vector<char const> *v) {
  return gsl_vector_char_ispos(v);
}


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool w_ispos(w_vector<unsigned char const> *v) {
  return gsl_vector_uchar_ispos(v);
}


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool w_ispos(w_vector<gsl_complex const> *v) {
  return gsl_vector_complex_ispos(v);
}


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool w_ispos(w_vector<gsl_complex_float const> *v) {
  return gsl_vector_complex_float_ispos(v);
}


/// True only if every element in vector `v` be positive.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ispos
/// @param v  Pointer to vector.
/// @return  True only if every element in `v` be positive.
inline bool w_ispos(w_vector<gsl_complex_long_double const> *v) {
  return gsl_vector_complex_long_double_ispos(v);
}


} // namespace gsl

// EOF
