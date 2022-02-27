/// @file       include/gslcpp/wrap/add.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gsl::w_add().

#pragma once
#include "type-map.hpp"

namespace gsl {


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int w_add(w_vector<double> *u, w_vector<double const> *v) {
  return gsl_vector_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int w_add(w_vector<float> *u, w_vector<float const> *v) {
  return gsl_vector_float_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int w_add(w_vector<long double> *u, w_vector<long double const> *v) {
  return gsl_vector_long_double_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int w_add(w_vector<int> *u, w_vector<int const> *v) {
  return gsl_vector_int_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int w_add(w_vector<unsigned> *u, w_vector<unsigned const> *v) {
  return gsl_vector_uint_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int w_add(w_vector<long> *u, w_vector<long const> *v) {
  return gsl_vector_long_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int
w_add(w_vector<unsigned long> *u, w_vector<unsigned long const> *v) {
  return gsl_vector_ulong_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int w_add(w_vector<short> *u, w_vector<short const> *v) {
  return gsl_vector_short_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int
w_add(w_vector<unsigned short> *u, w_vector<unsigned short const> *v) {
  return gsl_vector_ushort_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int w_add(w_vector<char> *u, w_vector<char const> *v) {
  return gsl_vector_char_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int
w_add(w_vector<unsigned char> *u, w_vector<unsigned char const> *v) {
  return gsl_vector_uchar_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int w_add(w_vector<gsl_complex> *u, w_vector<gsl_complex const> *v) {
  return gsl_vector_complex_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int
w_add(w_vector<gsl_complex_float> *u, w_vector<gsl_complex_float const> *v) {
  return gsl_vector_complex_float_add(u, v);
}


/// Element by element, accumulate `v` into `u`.
/// `add` is overloaded to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add
/// @param u  Pointer to vector to be modified.
/// @param v  Pointer to vector to be added in to `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int
w_add(w_vector<gsl_complex_long_double> *u,
      w_vector<gsl_complex_long_double const> *v) {
  return gsl_vector_complex_long_double_add(u, v);
}


} // namespace gsl

// EOF
