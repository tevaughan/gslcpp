/// @file       include/gslcpp/wrap/real.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gsl::w_real().

#pragma once
#include "container.hpp" // w_vector

namespace gsl {


/// Real part (identity-view) of real vector.
/// @param v  Pointer to vector.
/// @return  Identity-view of real vector.
inline auto w_real(w_vector<double> *v) {
  return gsl_vector_subvector_with_stride(v, 0, 1, v->size);
}


/// Real part (identity-view) of real vector.
/// @param v  Pointer to vector.
/// @return  Identity-view of real vector.
inline auto w_real(w_vector<double const> *v) {
  return gsl_vector_const_subvector_with_stride(v, 0, 1, v->size);
}


/// Real part (identity-view) of real vector.
/// @param v  Pointer to vector.
/// @return  Identity-view of real vector.
inline auto w_real(w_vector<float> *v) {
  return gsl_vector_float_subvector_with_stride(v, 0, 1, v->size);
}


/// Real part (identity-view) of real vector.
/// @param v  Pointer to vector.
/// @return  Identity-view of real vector.
inline auto w_real(w_vector<float const> *v) {
  return gsl_vector_float_const_subvector_with_stride(v, 0, 1, v->size);
}


/// Real part (identity-view) of real vector.
/// @param v  Pointer to vector.
/// @return  Identity-view of real vector.
inline auto w_real(w_vector<long double> *v) {
  return gsl_vector_long_double_subvector_with_stride(v, 0, 1, v->size);
}


/// Real part (identity-view) of real vector.
/// @param v  Pointer to vector.
/// @return  Identity-view of real vector.
inline auto w_real(w_vector<long double const> *v) {
  return gsl_vector_long_double_const_subvector_with_stride(v, 0, 1, v->size);
}


/// Real part (identity-view) of real vector.
/// @param v  Pointer to vector.
/// @return  Identity-view of real vector.
inline auto w_real(w_vector<int> *v) {
  return gsl_vector_int_subvector_with_stride(v, 0, 1, v->size);
}


/// Real part (identity-view) of real vector.
/// @param v  Pointer to vector.
/// @return  Identity-view of real vector.
inline auto w_real(w_vector<int const> *v) {
  return gsl_vector_int_const_subvector_with_stride(v, 0, 1, v->size);
}


/// Real part (identity-view) of real vector.
/// @param v  Pointer to vector.
/// @return  Identity-view of real vector.
inline auto w_real(w_vector<unsigned> *v) {
  return gsl_vector_uint_subvector_with_stride(v, 0, 1, v->size);
}


/// Real part (identity-view) of real vector.
/// @param v  Pointer to vector.
/// @return  Identity-view of real vector.
inline auto w_real(w_vector<unsigned const> *v) {
  return gsl_vector_uint_const_subvector_with_stride(v, 0, 1, v->size);
}


/// Real part (identity-view) of real vector.
/// @param v  Pointer to vector.
/// @return  Identity-view of real vector.
inline auto w_real(w_vector<long> *v) {
  return gsl_vector_long_subvector_with_stride(v, 0, 1, v->size);
}


/// Real part (identity-view) of real vector.
/// @param v  Pointer to vector.
/// @return  Identity-view of real vector.
inline auto w_real(w_vector<long const> *v) {
  return gsl_vector_long_const_subvector_with_stride(v, 0, 1, v->size);
}


/// Real part (identity-view) of real vector.
/// @param v  Pointer to vector.
/// @return  Identity-view of real vector.
inline auto w_real(w_vector<unsigned long> *v) {
  return gsl_vector_ulong_subvector_with_stride(v, 0, 1, v->size);
}


/// Real part (identity-view) of real vector.
/// @param v  Pointer to vector.
/// @return  Identity-view of real vector.
inline auto w_real(w_vector<unsigned long const> *v) {
  return gsl_vector_ulong_const_subvector_with_stride(v, 0, 1, v->size);
}


/// Real part (identity-view) of real vector.
/// @param v  Pointer to vector.
/// @return  Identity-view of real vector.
inline auto w_real(w_vector<short> *v) {
  return gsl_vector_short_subvector_with_stride(v, 0, 1, v->size);
}


/// Real part (identity-view) of real vector.
/// @param v  Pointer to vector.
/// @return  Identity-view of real vector.
inline auto w_real(w_vector<short const> *v) {
  return gsl_vector_short_const_subvector_with_stride(v, 0, 1, v->size);
}


/// Real part (identity-view) of real vector.
/// @param v  Pointer to vector.
/// @return  Identity-view of real vector.
inline auto w_real(w_vector<unsigned short> *v) {
  return gsl_vector_ushort_subvector_with_stride(v, 0, 1, v->size);
}


/// Real part (identity-view) of real vector.
/// @param v  Pointer to vector.
/// @return  Identity-view of real vector.
inline auto w_real(w_vector<unsigned short const> *v) {
  return gsl_vector_ushort_const_subvector_with_stride(v, 0, 1, v->size);
}


/// Real part (identity-view) of real vector.
/// @param v  Pointer to vector.
/// @return  Identity-view of real vector.
inline auto w_real(w_vector<char> *v) {
  return gsl_vector_char_subvector_with_stride(v, 0, 1, v->size);
}


/// Real part (identity-view) of real vector.
/// @param v  Pointer to vector.
/// @return  Identity-view of real vector.
inline auto w_real(w_vector<char const> *v) {
  return gsl_vector_char_const_subvector_with_stride(v, 0, 1, v->size);
}


/// Real part (identity-view) of real vector.
/// @param v  Pointer to vector.
/// @return  Identity-view of real vector.
inline auto w_real(w_vector<unsigned char> *v) {
  return gsl_vector_uchar_subvector_with_stride(v, 0, 1, v->size);
}


/// Real part (identity-view) of real vector.
/// @param v  Pointer to vector.
/// @return  Identity-view of real vector.
inline auto w_real(w_vector<unsigned char const> *v) {
  return gsl_vector_uchar_const_subvector_with_stride(v, 0, 1, v->size);
}


/// Real-part of complex vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_complex_real
/// @param u  Pointer to vector.
/// @return  View of real-part of complex vector.
inline auto w_real(w_vector<complex<double>> *u) {
  return gsl_vector_complex_real(u);
}


/// Real-part of complex vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_complex_real
/// @param u  Pointer to vector.
/// @return  View of real-part of complex vector.
inline auto w_real(w_vector<complex<float>> *u) {
  return gsl_vector_complex_float_real(u);
}


/// Real-part of complex vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_complex_real
/// @param u  Pointer to vector.
/// @return  View of real-part of complex vector.
inline auto w_real(w_vector<complex<long double>> *u) {
  return gsl_vector_complex_long_double_real(u);
}


/// Real-part of complex vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_complex_real
/// @param u  Pointer to vector.
/// @return  View of real-part of complex vector.
inline auto w_real(w_vector<complex<double>> const *u) {
  return gsl_vector_complex_const_real(u);
}


/// Real-part of complex vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_complex_real
/// @param u  Pointer to vector.
/// @return  View of real-part of complex vector.
inline auto w_real(w_vector<complex<float>> const *u) {
  return gsl_vector_complex_float_const_real(u);
}


/// Real-part of complex vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_complex_real
/// @param u  Pointer to vector.
/// @return  View of real-part of complex vector.
inline auto w_real(w_vector<complex<long double>> const *u) {
  return gsl_vector_complex_long_double_const_real(u);
}


} // namespace gsl

// EOF
