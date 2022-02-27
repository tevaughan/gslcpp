/// \file       include/gslcpp/wrap/div.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_div().

#pragma once
#include "type-map.hpp"

namespace gsl {


/// Perform the logical operation `u = u/v` element by element.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_div
/// @param u  Pointer to matrix whose elements should be divided into.
/// @param v  Pointer to matrix whose elements divide into.
/// @return  TBD: GSL's documentation does not specify.
inline int w_div(w_vector<double> *u, w_vector<double const> *v) {
  return gsl_vector_div(u, v);
}


/// Perform the logical operation `u = u/v` element by element.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_div
/// @param u  Pointer to matrix whose elements should be divided into.
/// @param v  Pointer to matrix whose elements divide into.
/// @return  TBD: GSL's documentation does not specify.
inline int w_div(w_vector<float> *u, w_vector<float const> *v) {
  return gsl_vector_float_div(u, v);
}


/// Perform the logical operation `u = u/v` element by element.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_div
/// @param u  Pointer to matrix whose elements should be divided into.
/// @param v  Pointer to matrix whose elements divide into.
/// @return  TBD: GSL's documentation does not specify.
inline int w_div(w_vector<long double> *u, w_vector<long double const> *v) {
  return gsl_vector_long_double_div(u, v);
}


/// Perform the logical operation `u = u/v` element by element.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_div
/// @param u  Pointer to matrix whose elements should be divided into.
/// @param v  Pointer to matrix whose elements divide into.
/// @return  TBD: GSL's documentation does not specify.
inline int w_div(w_vector<int> *u, w_vector<int const> *v) {
  return gsl_vector_int_div(u, v);
}


/// Perform the logical operation `u = u/v` element by element.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_div
/// @param u  Pointer to matrix whose elements should be divided into.
/// @param v  Pointer to matrix whose elements divide into.
/// @return  TBD: GSL's documentation does not specify.
inline int w_div(w_vector<unsigned> *u, w_vector<unsigned const> *v) {
  return gsl_vector_uint_div(u, v);
}


/// Perform the logical operation `u = u/v` element by element.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_div
/// @param u  Pointer to matrix whose elements should be divided into.
/// @param v  Pointer to matrix whose elements divide into.
/// @return  TBD: GSL's documentation does not specify.
inline int w_div(w_vector<long> *u, w_vector<long const> *v) {
  return gsl_vector_long_div(u, v);
}


/// Perform the logical operation `u = u/v` element by element.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_div
/// @param u  Pointer to matrix whose elements should be divided into.
/// @param v  Pointer to matrix whose elements divide into.
/// @return  TBD: GSL's documentation does not specify.
inline int
w_div(w_vector<unsigned long> *u, w_vector<unsigned long const> *v) {
  return gsl_vector_ulong_div(u, v);
}


/// Perform the logical operation `u = u/v` element by element.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_div
/// @param u  Pointer to matrix whose elements should be divided into.
/// @param v  Pointer to matrix whose elements divide into.
/// @return  TBD: GSL's documentation does not specify.
inline int w_div(w_vector<short> *u, w_vector<short const> *v) {
  return gsl_vector_short_div(u, v);
}


/// Perform the logical operation `u = u/v` element by element.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_div
/// @param u  Pointer to matrix whose elements should be divided into.
/// @param v  Pointer to matrix whose elements divide into.
/// @return  TBD: GSL's documentation does not specify.
inline int
w_div(w_vector<unsigned short> *u, w_vector<unsigned short const> *v) {
  return gsl_vector_ushort_div(u, v);
}


/// Perform the logical operation `u = u/v` element by element.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_div
/// @param u  Pointer to matrix whose elements should be divided into.
/// @param v  Pointer to matrix whose elements divide into.
/// @return  TBD: GSL's documentation does not specify.
inline int w_div(w_vector<char> *u, w_vector<char const> *v) {
  return gsl_vector_char_div(u, v);
}


/// Perform the logical operation `u = u/v` element by element.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_div
/// @param u  Pointer to matrix whose elements should be divided into.
/// @param v  Pointer to matrix whose elements divide into.
/// @return  TBD: GSL's documentation does not specify.
inline int
w_div(w_vector<unsigned char> *u, w_vector<unsigned char const> *v) {
  return gsl_vector_uchar_div(u, v);
}


/// Perform the logical operation `u = u/v` element by element.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_div
/// @param u  Pointer to matrix whose elements should be divided into.
/// @param v  Pointer to matrix whose elements divide into.
/// @return  TBD: GSL's documentation does not specify.
inline int w_div(w_vector<gsl_complex> *u, w_vector<gsl_complex const> *v) {
  return gsl_vector_complex_div(u, v);
}


/// Perform the logical operation `u = u/v` element by element.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_div
/// @param u  Pointer to matrix whose elements should be divided into.
/// @param v  Pointer to matrix whose elements divide into.
/// @return  TBD: GSL's documentation does not specify.
inline int
w_div(w_vector<gsl_complex_float> *u, w_vector<gsl_complex_float const> *v) {
  return gsl_vector_complex_float_div(u, v);
}


/// Perform the logical operation `u = u/v` element by element.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_div
/// @param u  Pointer to matrix whose elements should be divided into.
/// @param v  Pointer to matrix whose elements divide into.
/// @return  TBD: GSL's documentation does not specify.
inline int
w_div(w_vector<gsl_complex_long_double> *u,
      w_vector<gsl_complex_long_double const> *v) {
  return gsl_vector_complex_long_double_div(u, v);
}


} // namespace gsl

// EOF
