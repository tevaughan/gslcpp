/// \file       include/gslcpp/wrap/subvector.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_subvector().

#pragma once
#include "type-map.hpp"

namespace gsl {


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<double>
w_subvector(w_vector<double> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<double const>
w_subvector(w_vector<double const> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_const_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<float>
w_subvector(w_vector<float> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_float_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<float const>
w_subvector(w_vector<float const> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_float_const_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<long double>
w_subvector(w_vector<long double> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_long_double_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<long double const>
w_subvector(w_vector<long double const> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_long_double_const_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<int>
w_subvector(w_vector<int> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_int_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<int const>
w_subvector(w_vector<int const> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_int_const_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<unsigned>
w_subvector(w_vector<unsigned> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_uint_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<unsigned const>
w_subvector(w_vector<unsigned const> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_uint_const_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<long>
w_subvector(w_vector<long> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_long_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<long const>
w_subvector(w_vector<long const> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_long_const_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<unsigned long>
w_subvector(w_vector<unsigned long> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_ulong_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<unsigned long const>
w_subvector(w_vector<unsigned long const> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_ulong_const_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<short>
w_subvector(w_vector<short> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_short_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<short const>
w_subvector(w_vector<short const> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_short_const_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<unsigned short>
w_subvector(w_vector<unsigned short> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_ushort_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<unsigned short const>
w_subvector(w_vector<unsigned short const> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_ushort_const_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<char>
w_subvector(w_vector<char> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_char_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<char const>
w_subvector(w_vector<char const> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_char_const_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<unsigned char>
w_subvector(w_vector<unsigned char> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_uchar_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<unsigned char const>
w_subvector(w_vector<unsigned char const> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_uchar_const_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<gsl_complex>
w_subvector(w_vector<gsl_complex> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_complex_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<gsl_complex const>
w_subvector(w_vector<gsl_complex const> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_complex_const_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<gsl_complex_float>
w_subvector(w_vector<gsl_complex_float> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_complex_float_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<gsl_complex_float const> w_subvector(
      w_vector<gsl_complex_float const> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_complex_float_const_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<gsl_complex_long_double> w_subvector(
      w_vector<gsl_complex_long_double> *v, size_t i, size_t s, size_t n) {
  return gsl_vector_complex_long_double_subvector_with_stride(v, i, s, n);
}


/// View of subvector of vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_subvector_with_stride
/// @param v  Pointer to vector.
/// @param i  Offset in `v` of view's first element.
/// @param s  Stride of successive elements in view relative to offsets in `v`.
/// @param n  Number of elements in view.
/// @return  View of subvector.
inline w_vector_view<gsl_complex_long_double const> w_subvector(
      w_vector<gsl_complex_long_double const> *v,
      size_t i,
      size_t s,
      size_t n) {
  return gsl_vector_complex_long_double_const_subvector_with_stride(
        v, i, s, n);
}


} // namespace gsl

// EOF