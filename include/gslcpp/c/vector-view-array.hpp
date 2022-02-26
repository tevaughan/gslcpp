/// @file       include/gslcpp/c/vector-view-array.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::c::vector_view_array().

#pragma once
#include "type-map.hpp"

namespace gsl::c {


/// Generic struct whose every specialization for element-type `E` provides by
/// descent from vector_view<> a constructor for vector_view<> from C-style
/// array of elements of fundamental type.
///
/// Simle overloading of a function named `%vector_view_array` would not work
/// because a view of complex vector is constructed, not from a C-style array
/// of instances of a complex-element type, but rather from an array of
/// `float`, of `double`, or of `long double`.  So the type `E` of the vector's
/// elements must be distinguished from the type of the elements in the C-style
/// array used to initialize the view of such a vector.
///
/// @tparam E  Type of each element in vector.
template<typename E> struct vector_view_array;


/// Specialization for element-type `double`.
template<> struct vector_view_array<double>: public vector_view<double> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(double *b, size_t s, size_t n):
      vector_view<double>(gsl_vector_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `double const`.
template<>
struct vector_view_array<double const>: public vector_view<double const> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(double const *b, size_t s, size_t n):
      vector_view<double const>(
            gsl_vector_const_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `float`.
template<> struct vector_view_array<float>: public vector_view<float> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(float *b, size_t s, size_t n):
      vector_view<float>(gsl_vector_float_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `float const`.
template<>
struct vector_view_array<float const>: public vector_view<float const> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(float const *b, size_t s, size_t n):
      vector_view<float const>(
            gsl_vector_float_const_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `long double`.
template<>
struct vector_view_array<long double>: public vector_view<long double> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(long double *b, size_t s, size_t n):
      vector_view<long double>(
            gsl_vector_long_double_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `long double const`.
template<>
struct vector_view_array<long double const>:
    public vector_view<long double const> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(long double const *b, size_t s, size_t n):
      vector_view<long double const>(
            gsl_vector_long_double_const_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `int`.
template<> struct vector_view_array<int>: public vector_view<int> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(int *b, size_t s, size_t n):
      vector_view<int>(gsl_vector_int_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `int const`.
template<> struct vector_view_array<int const>: public vector_view<int const> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(int const *b, size_t s, size_t n):
      vector_view<int const>(
            gsl_vector_int_const_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `unsigned`.
template<> struct vector_view_array<unsigned>: public vector_view<unsigned> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(unsigned *b, size_t s, size_t n):
      vector_view<unsigned>(gsl_vector_uint_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `unsigned const`.
template<>
struct vector_view_array<unsigned const>: public vector_view<unsigned const> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(unsigned const *b, size_t s, size_t n):
      vector_view<unsigned const>(
            gsl_vector_uint_const_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `long`.
template<> struct vector_view_array<long>: public vector_view<long> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(long *b, size_t s, size_t n):
      vector_view<long>(gsl_vector_long_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `long const`.
template<>
struct vector_view_array<long const>: public vector_view<long const> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(long const *b, size_t s, size_t n):
      vector_view<long const>(
            gsl_vector_long_const_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `unsigned long`.
template<>
struct vector_view_array<unsigned long>: public vector_view<unsigned long> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(unsigned long *b, size_t s, size_t n):
      vector_view<unsigned long>(
            gsl_vector_ulong_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `unsigned long const`.
template<>
struct vector_view_array<unsigned long const>:
    public vector_view<unsigned long const> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(unsigned long const *b, size_t s, size_t n):
      vector_view<unsigned long const>(
            gsl_vector_ulong_const_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `short`.
template<> struct vector_view_array<short>: public vector_view<short> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(short *b, size_t s, size_t n):
      vector_view<short>(gsl_vector_short_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `short const`.
template<>
struct vector_view_array<short const>: public vector_view<short const> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(short const *b, size_t s, size_t n):
      vector_view<short const>(
            gsl_vector_short_const_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `unsigned short`.
template<>
struct vector_view_array<unsigned short>: public vector_view<unsigned short> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(unsigned short *b, size_t s, size_t n):
      vector_view<unsigned short>(
            gsl_vector_ushort_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `unsigned short const`.
template<>
struct vector_view_array<unsigned short const>:
    public vector_view<unsigned short const> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(unsigned short const *b, size_t s, size_t n):
      vector_view<unsigned short const>(
            gsl_vector_ushort_const_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `char`.
template<> struct vector_view_array<char>: public vector_view<char> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(char *b, size_t s, size_t n):
      vector_view<char>(gsl_vector_char_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `char const`.
template<>
struct vector_view_array<char const>: public vector_view<char const> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(char const *b, size_t s, size_t n):
      vector_view<char const>(
            gsl_vector_char_const_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `unsigned char`.
template<>
struct vector_view_array<unsigned char>: public vector_view<unsigned char> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(unsigned char *b, size_t s, size_t n):
      vector_view<unsigned char>(
            gsl_vector_uchar_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `unsigned char const`.
template<>
struct vector_view_array<unsigned char const>:
    public vector_view<unsigned char const> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(unsigned char const *b, size_t s, size_t n):
      vector_view<unsigned char const>(
            gsl_vector_uchar_const_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `gsl_complex`.
template<>
struct vector_view_array<gsl_complex>: public vector_view<gsl_complex> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(double *b, size_t s, size_t n):
      vector_view<gsl_complex>(
            gsl_vector_complex_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `gsl_complex const`.
template<>
struct vector_view_array<gsl_complex const>:
    public vector_view<gsl_complex const> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(double const *b, size_t s, size_t n):
      vector_view<gsl_complex const>(
            gsl_vector_complex_const_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `gsl_complex_float`.
template<>
struct vector_view_array<gsl_complex_float>:
    public vector_view<gsl_complex_float> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(float *b, size_t s, size_t n):
      vector_view<gsl_complex_float>(
            gsl_vector_complex_float_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `gsl_complex_float const`.
template<>
struct vector_view_array<gsl_complex_float const>:
    public vector_view<gsl_complex_float const> {
  /// Initialize view of
  /// C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(float const *b, size_t s, size_t n):
      vector_view<gsl_complex_float const>(
            gsl_vector_complex_float_const_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `gsl_complex_long_double`.
template<>
struct vector_view_array<gsl_complex_long_double>:
    public vector_view<gsl_complex_long_double> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(long double *b, size_t s, size_t n):
      vector_view<gsl_complex_long_double>(
            gsl_vector_complex_long_double_view_array_with_stride(b, s, n)) {}
};


/// Specialization for element-type `gsl_complex_long_double const`.
template<>
struct vector_view_array<gsl_complex_long_double const>:
    public vector_view<gsl_complex_long_double const> {
  /// Initialize view of C-style array as vector.
  /// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_view_array_with_stride
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements in view relative to array.
  /// @param n  Number of elements in view.
  vector_view_array(long double const *b, size_t s, size_t n):
      vector_view<gsl_complex_long_double const>(
            gsl_vector_complex_long_double_const_view_array_with_stride(
                  b, s, n)) {}
};


} // namespace gsl::c

// EOF
