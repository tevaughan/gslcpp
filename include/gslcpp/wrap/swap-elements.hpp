/// \file       include/gslcpp/wrap/swap-elements.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_swap_elements().

#pragma once
#include "type-map.hpp"

namespace gsl {


/// Exchange `i`th and `j`th elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap_elements
/// @param v  Pointer to vector.
/// @param i  Offset of one element to exchange.
/// @param j  Offset of other element to exchange.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap_elements(w_vector<double> *v, size_t i, size_t j) {
  return gsl_vector_swap_elements(v, i, j);
}


/// Exchange `i`th and `j`th elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap_elements
/// @param v  Pointer to vector.
/// @param i  Offset of one element to exchange.
/// @param j  Offset of other element to exchange.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap_elements(w_vector<float> *v, size_t i, size_t j) {
  return gsl_vector_float_swap_elements(v, i, j);
}


/// Exchange `i`th and `j`th elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap_elements
/// @param v  Pointer to vector.
/// @param i  Offset of one element to exchange.
/// @param j  Offset of other element to exchange.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap_elements(w_vector<long double> *v, size_t i, size_t j) {
  return gsl_vector_long_double_swap_elements(v, i, j);
}


/// Exchange `i`th and `j`th elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap_elements
/// @param v  Pointer to vector.
/// @param i  Offset of one element to exchange.
/// @param j  Offset of other element to exchange.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap_elements(w_vector<int> *v, size_t i, size_t j) {
  return gsl_vector_int_swap_elements(v, i, j);
}


/// Exchange `i`th and `j`th elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap_elements
/// @param v  Pointer to vector.
/// @param i  Offset of one element to exchange.
/// @param j  Offset of other element to exchange.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap_elements(w_vector<unsigned> *v, size_t i, size_t j) {
  return gsl_vector_uint_swap_elements(v, i, j);
}


/// Exchange `i`th and `j`th elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap_elements
/// @param v  Pointer to vector.
/// @param i  Offset of one element to exchange.
/// @param j  Offset of other element to exchange.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap_elements(w_vector<long> *v, size_t i, size_t j) {
  return gsl_vector_long_swap_elements(v, i, j);
}


/// Exchange `i`th and `j`th elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap_elements
/// @param v  Pointer to vector.
/// @param i  Offset of one element to exchange.
/// @param j  Offset of other element to exchange.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap_elements(w_vector<unsigned long> *v, size_t i, size_t j) {
  return gsl_vector_ulong_swap_elements(v, i, j);
}


/// Exchange `i`th and `j`th elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap_elements
/// @param v  Pointer to vector.
/// @param i  Offset of one element to exchange.
/// @param j  Offset of other element to exchange.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap_elements(w_vector<short> *v, size_t i, size_t j) {
  return gsl_vector_short_swap_elements(v, i, j);
}


/// Exchange `i`th and `j`th elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap_elements
/// @param v  Pointer to vector.
/// @param i  Offset of one element to exchange.
/// @param j  Offset of other element to exchange.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap_elements(w_vector<unsigned short> *v, size_t i, size_t j) {
  return gsl_vector_ushort_swap_elements(v, i, j);
}


/// Exchange `i`th and `j`th elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap_elements
/// @param v  Pointer to vector.
/// @param i  Offset of one element to exchange.
/// @param j  Offset of other element to exchange.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap_elements(w_vector<char> *v, size_t i, size_t j) {
  return gsl_vector_char_swap_elements(v, i, j);
}


/// Exchange `i`th and `j`th elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap_elements
/// @param v  Pointer to vector.
/// @param i  Offset of one element to exchange.
/// @param j  Offset of other element to exchange.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap_elements(w_vector<unsigned char> *v, size_t i, size_t j) {
  return gsl_vector_uchar_swap_elements(v, i, j);
}


/// Exchange `i`th and `j`th elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap_elements
/// @param v  Pointer to vector.
/// @param i  Offset of one element to exchange.
/// @param j  Offset of other element to exchange.
/// @return  TBD: GSL's documentation does not specify.
inline int w_swap_elements(w_vector<gsl_complex> *v, size_t i, size_t j) {
  return gsl_vector_complex_swap_elements(v, i, j);
}


/// Exchange `i`th and `j`th elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap_elements
/// @param v  Pointer to vector.
/// @param i  Offset of one element to exchange.
/// @param j  Offset of other element to exchange.
/// @return  TBD: GSL's documentation does not specify.
inline int
w_swap_elements(w_vector<gsl_complex_float> *v, size_t i, size_t j) {
  return gsl_vector_complex_float_swap_elements(v, i, j);
}


/// Exchange `i`th and `j`th elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_swap_elements
/// @param v  Pointer to vector.
/// @param i  Offset of one element to exchange.
/// @param j  Offset of other element to exchange.
/// @return  TBD: GSL's documentation does not specify.
inline int
w_swap_elements(w_vector<gsl_complex_long_double> *v, size_t i, size_t j) {
  return gsl_vector_complex_long_double_swap_elements(v, i, j);
}


} // namespace gsl

// EOF
