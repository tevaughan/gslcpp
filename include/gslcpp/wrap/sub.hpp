/// \file       include/gslcpp/wrap/sub.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_sub().

#pragma once
#include "type-map.hpp"

namespace gsl {


/// For vectors `u` and `v`, obtain effect `u = u - v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sub
/// @param u  Pointer to vector from which `u` will be subtracted.
/// @param v  Pointer to vector to subtract from `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int w_sub(w_vector<double> *u, w_vector<double const> *v) {
  return gsl_vector_sub(u, v);
}


/// For vectors `u` and `v`, obtain effect `u = u - v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sub
/// @param u  Pointer to vector from which `u` will be subtracted.
/// @param v  Pointer to vector to subtract from `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int w_sub(w_vector<float> *u, w_vector<float const> *v) {
  return gsl_vector_float_sub(u, v);
}


/// For vectors `u` and `v`, obtain effect `u = u - v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sub
/// @param u  Pointer to vector from which `u` will be subtracted.
/// @param v  Pointer to vector to subtract from `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int w_sub(w_vector<long double> *u, w_vector<long double const> *v) {
  return gsl_vector_long_double_sub(u, v);
}


/// For vectors `u` and `v`, obtain effect `u = u - v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sub
/// @param u  Pointer to vector from which `u` will be subtracted.
/// @param v  Pointer to vector to subtract from `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int w_sub(w_vector<int> *u, w_vector<int const> *v) {
  return gsl_vector_int_sub(u, v);
}


/// For vectors `u` and `v`, obtain effect `u = u - v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sub
/// @param u  Pointer to vector from which `u` will be subtracted.
/// @param v  Pointer to vector to subtract from `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int w_sub(w_vector<unsigned> *u, w_vector<unsigned const> *v) {
  return gsl_vector_uint_sub(u, v);
}


/// For vectors `u` and `v`, obtain effect `u = u - v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sub
/// @param u  Pointer to vector from which `u` will be subtracted.
/// @param v  Pointer to vector to subtract from `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int w_sub(w_vector<long> *u, w_vector<long const> *v) {
  return gsl_vector_long_sub(u, v);
}


/// For vectors `u` and `v`, obtain effect `u = u - v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sub
/// @param u  Pointer to vector from which `u` will be subtracted.
/// @param v  Pointer to vector to subtract from `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int
w_sub(w_vector<unsigned long> *u, w_vector<unsigned long const> *v) {
  return gsl_vector_ulong_sub(u, v);
}


/// For vectors `u` and `v`, obtain effect `u = u - v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sub
/// @param u  Pointer to vector from which `u` will be subtracted.
/// @param v  Pointer to vector to subtract from `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int w_sub(w_vector<short> *u, w_vector<short const> *v) {
  return gsl_vector_short_sub(u, v);
}


/// For vectors `u` and `v`, obtain effect `u = u - v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sub
/// @param u  Pointer to vector from which `u` will be subtracted.
/// @param v  Pointer to vector to subtract from `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int
w_sub(w_vector<unsigned short> *u, w_vector<unsigned short const> *v) {
  return gsl_vector_ushort_sub(u, v);
}


/// For vectors `u` and `v`, obtain effect `u = u - v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sub
/// @param u  Pointer to vector from which `u` will be subtracted.
/// @param v  Pointer to vector to subtract from `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int w_sub(w_vector<char> *u, w_vector<char const> *v) {
  return gsl_vector_char_sub(u, v);
}


/// For vectors `u` and `v`, obtain effect `u = u - v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sub
/// @param u  Pointer to vector from which `u` will be subtracted.
/// @param v  Pointer to vector to subtract from `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int
w_sub(w_vector<unsigned char> *u, w_vector<unsigned char const> *v) {
  return gsl_vector_uchar_sub(u, v);
}


/// For vectors `u` and `v`, obtain effect `u = u - v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sub
/// @param u  Pointer to vector from which `u` will be subtracted.
/// @param v  Pointer to vector to subtract from `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int w_sub(w_vector<gsl_complex> *u, w_vector<gsl_complex const> *v) {
  return gsl_vector_complex_sub(u, v);
}


/// For vectors `u` and `v`, obtain effect `u = u - v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sub
/// @param u  Pointer to vector from which `u` will be subtracted.
/// @param v  Pointer to vector to subtract from `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int
w_sub(w_vector<gsl_complex_float> *u, w_vector<gsl_complex_float const> *v) {
  return gsl_vector_complex_float_sub(u, v);
}


/// For vectors `u` and `v`, obtain effect `u = u - v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sub
/// @param u  Pointer to vector from which `u` will be subtracted.
/// @param v  Pointer to vector to subtract from `u`.
/// @return  TBD: GSL's documentation does not specify.
inline int
w_sub(w_vector<gsl_complex_long_double> *u,
      w_vector<gsl_complex_long_double const> *v) {
  return gsl_vector_complex_long_double_sub(u, v);
}


} // namespace gsl

// EOF
