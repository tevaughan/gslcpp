/// @file       include/gslcpp/c/add.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gsl::c::add().

#pragma once
#include "type-map.hpp"

namespace gsl::c {


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int add(c::vector<double> *u, c::vector<double const> *v) {
  return gsl_vector_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int add(c::vector<float> *u, c::vector<float const> *v) {
  return gsl_vector_float_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int add(c::vector<long double> *u, c::vector<long double const> *v) {
  return gsl_vector_long_double_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int add(c::vector<int> *u, c::vector<int const> *v) {
  return gsl_vector_int_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int add(c::vector<unsigned> *u, c::vector<unsigned const> *v) {
  return gsl_vector_uint_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int add(c::vector<long> *u, c::vector<long const> *v) {
  return gsl_vector_long_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int
add(c::vector<unsigned long> *u, c::vector<unsigned long const> *v) {
  return gsl_vector_ulong_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int add(c::vector<short> *u, c::vector<short const> *v) {
  return gsl_vector_short_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int
add(c::vector<unsigned short> *u, c::vector<unsigned short const> *v) {
  return gsl_vector_ushort_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int add(c::vector<char> *u, c::vector<char const> *v) {
  return gsl_vector_char_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int
add(c::vector<unsigned char> *u, c::vector<unsigned char const> *v) {
  return gsl_vector_uchar_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int add(c::vector<gsl_complex> *u, c::vector<gsl_complex const> *v) {
  return gsl_vector_complex_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int
add(c::vector<gsl_complex_float> *u, c::vector<gsl_complex_float const> *v) {
  return gsl_vector_complex_float_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int
add(c::vector<gsl_complex_long_double> *u,
    c::vector<gsl_complex_long_double const> *v) {
  return gsl_vector_complex_long_double_add(u, v);
}


} // namespace gsl::c

// EOF
