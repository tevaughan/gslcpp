/// \file       include/gslcpp/wrap/vector-view-array.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_vector_view_array().

#pragma once
#include "container.hpp" // w_vector

namespace gsl {


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<double>
w_vector_view_array(double *b, size_t s, size_t n) {
  return gsl_vector_view_array_with_stride(b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<double const>
w_vector_view_array(double const *b, size_t s, size_t n) {
  return gsl_vector_const_view_array_with_stride(b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<float> w_vector_view_array(float *b, size_t s, size_t n) {
  return gsl_vector_float_view_array_with_stride(b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<float const>
w_vector_view_array(float const *b, size_t s, size_t n) {
  return gsl_vector_float_const_view_array_with_stride(b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<long double>
w_vector_view_array(long double *b, size_t s, size_t n) {
  return gsl_vector_long_double_view_array_with_stride(b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<long double const>
w_vector_view_array(long double const *b, size_t s, size_t n) {
  return gsl_vector_long_double_const_view_array_with_stride(b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<int> w_vector_view_array(int *b, size_t s, size_t n) {
  return gsl_vector_int_view_array_with_stride(b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<int const>
w_vector_view_array(int const *b, size_t s, size_t n) {
  return gsl_vector_int_const_view_array_with_stride(b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<unsigned>
w_vector_view_array(unsigned *b, size_t s, size_t n) {
  return gsl_vector_uint_view_array_with_stride(b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<unsigned const>
w_vector_view_array(unsigned const *b, size_t s, size_t n) {
  return gsl_vector_uint_const_view_array_with_stride(b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<long> w_vector_view_array(long *b, size_t s, size_t n) {
  return gsl_vector_long_view_array_with_stride(b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<long const>
w_vector_view_array(long const *b, size_t s, size_t n) {
  return gsl_vector_long_const_view_array_with_stride(b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<unsigned long>
w_vector_view_array(unsigned long *b, size_t s, size_t n) {
  return gsl_vector_ulong_view_array_with_stride(b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<unsigned long const>
w_vector_view_array(unsigned long const *b, size_t s, size_t n) {
  return gsl_vector_ulong_const_view_array_with_stride(b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<short> w_vector_view_array(short *b, size_t s, size_t n) {
  return gsl_vector_short_view_array_with_stride(b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<short const>
w_vector_view_array(short const *b, size_t s, size_t n) {
  return gsl_vector_short_const_view_array_with_stride(b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<unsigned short>
w_vector_view_array(unsigned short *b, size_t s, size_t n) {
  return gsl_vector_ushort_view_array_with_stride(b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<unsigned short const>
w_vector_view_array(unsigned short const *b, size_t s, size_t n) {
  return gsl_vector_ushort_const_view_array_with_stride(b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<char> w_vector_view_array(char *b, size_t s, size_t n) {
  return gsl_vector_char_view_array_with_stride(b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<char const>
w_vector_view_array(char const *b, size_t s, size_t n) {
  return gsl_vector_char_const_view_array_with_stride(b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<unsigned char>
w_vector_view_array(unsigned char *b, size_t s, size_t n) {
  return gsl_vector_uchar_view_array_with_stride(b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<unsigned char const>
w_vector_view_array(unsigned char const *b, size_t s, size_t n) {
  return gsl_vector_uchar_const_view_array_with_stride(b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<complex<double>>
w_vector_view_array(complex<double> *b, size_t s, size_t n) {
  return gsl_vector_complex_view_array_with_stride((double *)b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<complex<double> const>
w_vector_view_array(complex<double> const *b, size_t s, size_t n) {
  return gsl_vector_complex_const_view_array_with_stride(
        (double const *)b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<complex<float>>
w_vector_view_array(complex<float> *b, size_t s, size_t n) {
  return gsl_vector_complex_float_view_array_with_stride((float *)b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<complex<float> const>
w_vector_view_array(complex<float> const *b, size_t s, size_t n) {
  return gsl_vector_complex_float_const_view_array_with_stride(
        (float const *)b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<complex<long double>>
w_vector_view_array(complex<long double> *b, size_t s, size_t n) {
  return gsl_vector_complex_long_double_view_array_with_stride(
        (long double *)b, s, n);
}


/// Initialize view of C-style array as vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
/// @param b  Pointer to first element of view.
/// @param s  Stride of successive elements in view relative to array.
/// @param n  Number of elements in view.
/// @return  View of C-style array as vector.
inline w_vector_view<complex<long double> const>
w_vector_view_array(complex<long double> const *b, size_t s, size_t n) {
  return gsl_vector_complex_long_double_const_view_array_with_stride(
        (long double const *)b, s, n);
}


} // namespace gsl

// EOF
