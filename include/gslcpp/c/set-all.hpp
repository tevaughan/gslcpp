/// @file       include/gslcpp/c/set-all.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::c::set_all().

#pragma once
#include "type-map.hpp"

namespace gsl::c {


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void set_all(c::vector<double> *v, double const &x) {
  return gsl_vector_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void set_all(c::vector<float> *v, float const &x) {
  return gsl_vector_float_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void set_all(c::vector<long double> *v, long double const &x) {
  return gsl_vector_long_double_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void set_all(c::vector<int> *v, int const &x) {
  return gsl_vector_int_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void set_all(c::vector<unsigned> *v, unsigned const &x) {
  return gsl_vector_uint_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void set_all(c::vector<long> *v, long const &x) {
  return gsl_vector_long_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void set_all(c::vector<unsigned long> *v, unsigned long const &x) {
  return gsl_vector_ulong_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void set_all(c::vector<short> *v, short const &x) {
  return gsl_vector_short_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void set_all(c::vector<unsigned short> *v, unsigned short const &x) {
  return gsl_vector_ushort_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void set_all(c::vector<char> *v, char const &x) {
  return gsl_vector_char_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void set_all(c::vector<unsigned char> *v, unsigned char const &x) {
  return gsl_vector_uchar_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void set_all(c::vector<gsl_complex> *v, gsl_complex const &x) {
  return gsl_vector_complex_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void
set_all(c::vector<gsl_complex_float> *v, gsl_complex_float const &x) {
  return gsl_vector_complex_float_set_all(v, x);
}


/// Set every element of vector `v` to same value `x`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_all
/// @param v  Pointer to vector.
/// @param x  Initializer for every element.
inline void set_all(
      c::vector<gsl_complex_long_double> *v,
      gsl_complex_long_double const &x) {
  return gsl_vector_complex_long_double_set_all(v, x);
}


} // namespace gsl::c

// EOF
