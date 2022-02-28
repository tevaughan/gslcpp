/// \file       include/gslcpp/wrap/swap.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_swap().

#pragma once
#include "container.hpp" // w_vector

namespace gsl {


/// Exchange elements of vector `u` and corresponding ones of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap(w_vector<double> *u, w_vector<double> *v) {
  return gsl_vector_swap(u, v);
}


/// Exchange elements of vector `u` and corresponding ones of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap(w_vector<float> *u, w_vector<float> *v) {
  return gsl_vector_float_swap(u, v);
}


/// Exchange elements of vector `u` and corresponding ones of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap(w_vector<long double> *u, w_vector<long double> *v) {
  return gsl_vector_long_double_swap(u, v);
}


/// Exchange elements of vector `u` and corresponding ones of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap(w_vector<int> *u, w_vector<int> *v) {
  return gsl_vector_int_swap(u, v);
}


/// Exchange elements of vector `u` and corresponding ones of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap(w_vector<unsigned> *u, w_vector<unsigned> *v) {
  return gsl_vector_uint_swap(u, v);
}


/// Exchange elements of vector `u` and corresponding ones of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap(w_vector<long> *u, w_vector<long> *v) {
  return gsl_vector_long_swap(u, v);
}


/// Exchange elements of vector `u` and corresponding ones of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap(w_vector<unsigned long> *u, w_vector<unsigned long> *v) {
  return gsl_vector_ulong_swap(u, v);
}


/// Exchange elements of vector `u` and corresponding ones of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap(w_vector<short> *u, w_vector<short> *v) {
  return gsl_vector_short_swap(u, v);
}


/// Exchange elements of vector `u` and corresponding ones of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap(w_vector<unsigned short> *u, w_vector<unsigned short> *v) {
  return gsl_vector_ushort_swap(u, v);
}


/// Exchange elements of vector `u` and corresponding ones of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap(w_vector<char> *u, w_vector<char> *v) {
  return gsl_vector_char_swap(u, v);
}


/// Exchange elements of vector `u` and corresponding ones of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap(w_vector<unsigned char> *u, w_vector<unsigned char> *v) {
  return gsl_vector_uchar_swap(u, v);
}


/// Exchange elements of vector `u` and corresponding ones of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap(w_vector<gsl_complex> *u, w_vector<gsl_complex> *v) {
  return gsl_vector_complex_swap(u, v);
}


/// Exchange elements of vector `u` and corresponding ones of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  TBD: GSL's documentation does not specify.
inline int
w_swap(w_vector<gsl_complex_float> *u, w_vector<gsl_complex_float> *v) {
  return gsl_vector_complex_float_swap(u, v);
}


/// Exchange elements of vector `u` and corresponding ones of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap
/// @param u  Pointer to one vector.
/// @param v  Pointer to other vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap(
      w_vector<gsl_complex_long_double> *u,
      w_vector<gsl_complex_long_double> *v) {
  return gsl_vector_complex_long_double_swap(u, v);
}


} // namespace gsl

// EOF
