/// \file       include/gslcpp/wrap/ptr.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_ptr().

#pragma once
#include "container.hpp" // w_vector

namespace gsl {


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto *w_ptr(w_vector<double> *v, size_t i) {
  return gsl_vector_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto const *w_ptr(w_vector<double const> *v, size_t i) {
  return gsl_vector_const_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto *w_ptr(w_vector<float> *v, size_t i) {
  return gsl_vector_float_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto const *w_ptr(w_vector<float const> *v, size_t i) {
  return gsl_vector_float_const_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto *w_ptr(w_vector<long double> *v, size_t i) {
  return gsl_vector_long_double_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto const *w_ptr(w_vector<long double const> *v, size_t i) {
  return gsl_vector_long_double_const_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto *w_ptr(w_vector<int> *v, size_t i) {
  return gsl_vector_int_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto const *w_ptr(w_vector<int const> *v, size_t i) {
  return gsl_vector_int_const_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto *w_ptr(w_vector<unsigned> *v, size_t i) {
  return gsl_vector_uint_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto const *w_ptr(w_vector<unsigned const> *v, size_t i) {
  return gsl_vector_uint_const_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto *w_ptr(w_vector<long> *v, size_t i) {
  return gsl_vector_long_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto const *w_ptr(w_vector<long const> *v, size_t i) {
  return gsl_vector_long_const_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto *w_ptr(w_vector<unsigned long> *v, size_t i) {
  return gsl_vector_ulong_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto const *w_ptr(w_vector<unsigned long const> *v, size_t i) {
  return gsl_vector_ulong_const_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto *w_ptr(w_vector<short> *v, size_t i) {
  return gsl_vector_short_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto const *w_ptr(w_vector<short const> *v, size_t i) {
  return gsl_vector_short_const_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto *w_ptr(w_vector<unsigned short> *v, size_t i) {
  return gsl_vector_ushort_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline unsigned short const *
w_ptr(w_vector<unsigned short const> *v, size_t i) {
  return gsl_vector_ushort_const_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto *w_ptr(w_vector<char> *v, size_t i) {
  return gsl_vector_char_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto const *w_ptr(w_vector<char const> *v, size_t i) {
  return gsl_vector_char_const_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto *w_ptr(w_vector<unsigned char> *v, size_t i) {
  return gsl_vector_uchar_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto const *w_ptr(w_vector<unsigned char const> *v, size_t i) {
  return gsl_vector_uchar_const_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto *w_ptr(w_vector<complex<double>> *v, size_t i) {
  return (complex<double> *)gsl_vector_complex_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto const *w_ptr(w_vector<complex<double> const> *v, size_t i) {
  return (complex<double> const *)gsl_vector_complex_const_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto *w_ptr(w_vector<complex<float>> *v, size_t i) {
  return (complex<float> *)gsl_vector_complex_float_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto const *w_ptr(w_vector<complex<float> const> *v, size_t i) {
  return (complex<float> const *)gsl_vector_complex_float_const_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto *w_ptr(w_vector<complex<long double>> *v, size_t i) {
  return (complex<long double> *)gsl_vector_complex_long_double_ptr(v, i);
}


/// Pointer to `i`th element of vector `v`, with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_ptr
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Pointer to element at offset `i` in `v`.
inline auto const *w_ptr(w_vector<complex<long double> const> *v, size_t i) {
  return (complex<long double> const *)
        gsl_vector_complex_long_double_const_ptr(v, i);
}


} // namespace gsl

// EOF
