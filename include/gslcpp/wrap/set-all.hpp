/// \file       include/gslcpp/wrap/set-all.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_set_all().

#pragma once
#include "type-map.hpp"

namespace gsl {


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void w_set_all(w_vector<double> *v, double const &x) {
  return gsl_vector_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void w_set_all(w_vector<float> *v, float const &x) {
  return gsl_vector_float_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void w_set_all(w_vector<long double> *v, long double const &x) {
  return gsl_vector_long_double_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void w_set_all(w_vector<int> *v, int const &x) {
  return gsl_vector_int_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void w_set_all(w_vector<unsigned> *v, unsigned const &x) {
  return gsl_vector_uint_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void w_set_all(w_vector<long> *v, long const &x) {
  return gsl_vector_long_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void w_set_all(w_vector<unsigned long> *v, unsigned long const &x) {
  return gsl_vector_ulong_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void w_set_all(w_vector<short> *v, short const &x) {
  return gsl_vector_short_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void w_set_all(w_vector<unsigned short> *v, unsigned short const &x) {
  return gsl_vector_ushort_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void w_set_all(w_vector<char> *v, char const &x) {
  return gsl_vector_char_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void w_set_all(w_vector<unsigned char> *v, unsigned char const &x) {
  return gsl_vector_uchar_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void w_set_all(w_vector<gsl_complex> *v, gsl_complex const &x) {
  return gsl_vector_complex_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void
w_set_all(w_vector<gsl_complex_float> *v, gsl_complex_float const &x) {
  return gsl_vector_complex_float_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void w_set_all(
      w_vector<gsl_complex_long_double> *v, gsl_complex_long_double const &x) {
  return gsl_vector_complex_long_double_set_all(v, x);
}


} // namespace gsl

// EOF
