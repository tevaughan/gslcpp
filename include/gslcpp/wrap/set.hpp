/// \file       include/gslcpp/wrap/set.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_set().

#pragma once
#include "container.hpp" // w_vector

namespace gsl {


/// Set to `x` the value of `i`th element of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set
/// @param v  Pointer to vector.
/// @param i  Offset of element whose value should change.
/// @param x  New value for element at offset `i`.
inline void w_set(w_vector<double> *v, size_t i, double const &x) {
  return gsl_vector_set(v, i, x);
}


/// Set to `x` the value of `i`th element of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set
/// @param v  Pointer to vector.
/// @param i  Offset of element whose value should change.
/// @param x  New value for element at offset `i`.
inline void w_set(w_vector<float> *v, size_t i, float const &x) {
  return gsl_vector_float_set(v, i, x);
}


/// Set to `x` the value of `i`th element of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set
/// @param v  Pointer to vector.
/// @param i  Offset of element whose value should change.
/// @param x  New value for element at offset `i`.
inline void w_set(w_vector<long double> *v, size_t i, long double const &x) {
  return gsl_vector_long_double_set(v, i, x);
}


/// Set to `x` the value of `i`th element of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set
/// @param v  Pointer to vector.
/// @param i  Offset of element whose value should change.
/// @param x  New value for element at offset `i`.
inline void w_set(w_vector<int> *v, size_t i, int const &x) {
  return gsl_vector_int_set(v, i, x);
}


/// Set to `x` the value of `i`th element of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set
/// @param v  Pointer to vector.
/// @param i  Offset of element whose value should change.
/// @param x  New value for element at offset `i`.
inline void w_set(w_vector<unsigned> *v, size_t i, unsigned const &x) {
  return gsl_vector_uint_set(v, i, x);
}


/// Set to `x` the value of `i`th element of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set
/// @param v  Pointer to vector.
/// @param i  Offset of element whose value should change.
/// @param x  New value for element at offset `i`.
inline void w_set(w_vector<long> *v, size_t i, long const &x) {
  return gsl_vector_long_set(v, i, x);
}


/// Set to `x` the value of `i`th element of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set
/// @param v  Pointer to vector.
/// @param i  Offset of element whose value should change.
/// @param x  New value for element at offset `i`.
inline void
w_set(w_vector<unsigned long> *v, size_t i, unsigned long const &x) {
  return gsl_vector_ulong_set(v, i, x);
}


/// Set to `x` the value of `i`th element of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set
/// @param v  Pointer to vector.
/// @param i  Offset of element whose value should change.
/// @param x  New value for element at offset `i`.
inline void w_set(w_vector<short> *v, size_t i, short const &x) {
  return gsl_vector_short_set(v, i, x);
}


/// Set to `x` the value of `i`th element of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set
/// @param v  Pointer to vector.
/// @param i  Offset of element whose value should change.
/// @param x  New value for element at offset `i`.
inline void
w_set(w_vector<unsigned short> *v, size_t i, unsigned short const &x) {
  return gsl_vector_ushort_set(v, i, x);
}


/// Set to `x` the value of `i`th element of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set
/// @param v  Pointer to vector.
/// @param i  Offset of element whose value should change.
/// @param x  New value for element at offset `i`.
inline void w_set(w_vector<char> *v, size_t i, char const &x) {
  return gsl_vector_char_set(v, i, x);
}


/// Set to `x` the value of `i`th element of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set
/// @param v  Pointer to vector.
/// @param i  Offset of element whose value should change.
/// @param x  New value for element at offset `i`.
inline void
w_set(w_vector<unsigned char> *v, size_t i, unsigned char const &x) {
  return gsl_vector_uchar_set(v, i, x);
}


/// Set to `x` the value of `i`th element of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set
/// @param v  Pointer to vector.
/// @param i  Offset of element whose value should change.
/// @param x  New value for element at offset `i`.
inline void
w_set(w_vector<complex<double>> *v, size_t i, complex<double> const &x) {
  return gsl_vector_complex_set(v, i, x);
}


/// Set to `x` the value of `i`th element of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set
/// @param v  Pointer to vector.
/// @param i  Offset of element whose value should change.
/// @param x  New value for element at offset `i`.
inline void
w_set(w_vector<complex<float>> *v, size_t i, complex<float> const &x) {
  return gsl_vector_complex_float_set(v, i, x);
}


/// Set to `x` the value of `i`th element of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set
/// @param v  Pointer to vector.
/// @param i  Offset of element whose value should change.
/// @param x  New value for element at offset `i`.
inline void
w_set(w_vector<complex<long double>> *v,
      size_t i,
      complex<long double> const &x) {
  return gsl_vector_complex_long_double_set(v, i, x);
}


} // namespace gsl

// EOF
