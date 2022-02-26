/// @file       include/gslcpp/c/equal.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::c::equal.

#pragma once
#include "type-map.hpp"

namespace gsl::c {


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool equal(c::vector<double const> *u, c::vector<double const> *v) {
  return gsl_vector_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool equal(c::vector<float const> *u, c::vector<float const> *v) {
  return gsl_vector_float_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool
equal(c::vector<long double const> *u, c::vector<long double const> *v) {
  return gsl_vector_long_double_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool equal(c::vector<int const> *u, c::vector<int const> *v) {
  return gsl_vector_int_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool equal(c::vector<unsigned const> *u, c::vector<unsigned const> *v) {
  return gsl_vector_uint_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool equal(c::vector<long const> *u, c::vector<long const> *v) {
  return gsl_vector_long_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool
equal(c::vector<unsigned long const> *u, c::vector<unsigned long const> *v) {
  return gsl_vector_ulong_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool equal(c::vector<short const> *u, c::vector<short const> *v) {
  return gsl_vector_short_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool
equal(c::vector<unsigned short const> *u, c::vector<unsigned short const> *v) {
  return gsl_vector_ushort_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool equal(c::vector<char const> *u, c::vector<char const> *v) {
  return gsl_vector_char_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool
equal(c::vector<unsigned char const> *u, c::vector<unsigned char const> *v) {
  return gsl_vector_uchar_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool
equal(c::vector<gsl_complex const> *u, c::vector<gsl_complex const> *v) {
  return gsl_vector_complex_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool
equal(c::vector<gsl_complex_float const> *u,
      c::vector<gsl_complex_float const> *v) {
  return gsl_vector_complex_float_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool
equal(c::vector<gsl_complex_long_double const> *u,
      c::vector<gsl_complex_long_double const> *v) {
  return gsl_vector_complex_long_double_equal(u, v);
}


} // namespace gsl::c

// EOF
