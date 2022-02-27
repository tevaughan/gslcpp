/// \file       include/gslcpp/wrap/equal.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_equal().

#pragma once
#include "type-map.hpp"

namespace gsl {


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool w_equal(w_vector<double const> *u, w_vector<double const> *v) {
  return gsl_vector_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool w_equal(w_vector<float const> *u, w_vector<float const> *v) {
  return gsl_vector_float_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool
w_equal(w_vector<long double const> *u, w_vector<long double const> *v) {
  return gsl_vector_long_double_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool w_equal(w_vector<int const> *u, w_vector<int const> *v) {
  return gsl_vector_int_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool w_equal(w_vector<unsigned const> *u, w_vector<unsigned const> *v) {
  return gsl_vector_uint_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool w_equal(w_vector<long const> *u, w_vector<long const> *v) {
  return gsl_vector_long_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool
w_equal(w_vector<unsigned long const> *u, w_vector<unsigned long const> *v) {
  return gsl_vector_ulong_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool w_equal(w_vector<short const> *u, w_vector<short const> *v) {
  return gsl_vector_short_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool
w_equal(w_vector<unsigned short const> *u, w_vector<unsigned short const> *v) {
  return gsl_vector_ushort_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool w_equal(w_vector<char const> *u, w_vector<char const> *v) {
  return gsl_vector_char_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool
w_equal(w_vector<unsigned char const> *u, w_vector<unsigned char const> *v) {
  return gsl_vector_uchar_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool
w_equal(w_vector<gsl_complex const> *u, w_vector<gsl_complex const> *v) {
  return gsl_vector_complex_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool w_equal(
      w_vector<gsl_complex_float const> *u,
      w_vector<gsl_complex_float const> *v) {
  return gsl_vector_complex_float_equal(u, v);
}


/// True if every element in `u` be equal to corrending element in `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_equal
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  True if vectors be equal.
inline bool w_equal(
      w_vector<gsl_complex_long_double const> *u,
      w_vector<gsl_complex_long_double const> *v) {
  return gsl_vector_complex_long_double_equal(u, v);
}


} // namespace gsl

// EOF
