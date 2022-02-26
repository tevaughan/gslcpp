/// @file       include/gslcpp/c/vector-view-array.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::c::vector_view_array.

#pragma once
#include "type-map.hpp"

namespace gsl::c {

template<typename E> struct vector_view_array;

template<> struct vector_view_array<double>: public vector_view<double> { vector_view_array(double *b, size_t s, size_t n): vector_view<double>(gsl_vector_view_array_with_stride(b, s, n)) {} };

template<> struct vector_view_array<double const>: public vector_view<double const> { vector_view_array(double const *b, size_t s, size_t n): vector_view<double const>( gsl_vector_const_view_array_with_stride(b, s, n)) {} };

template<> struct vector_view_array<float>: public vector_view<float> { vector_view_array(float *b, size_t s, size_t n): vector_view<float>(gsl_vector_float_view_array_with_stride(b, s, n)) {} };

template<> struct vector_view_array<float const>: public vector_view<float const> { vector_view_array(float const *b, size_t s, size_t n): vector_view<float const>( gsl_vector_float_const_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<long double>: public vector_view<long double> { vector_view_array(long double *b, size_t s, size_t n): vector_view<long double>( gsl_vector_long_double_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<long double const>: public vector_view<long double const> { vector_view_array(long double const *b, size_t s, size_t n): vector_view<long double const>( gsl_vector_long_double_const_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<int>: public vector_view<int> { vector_view_array(int *b, size_t s, size_t n): vector_view<int>( gsl_vector_int_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<int const>: public vector_view<int const> { vector_view_array(int const *b, size_t s, size_t n): vector_view<int const>( gsl_vector_int_const_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<unsigned>: public vector_view<unsigned> { vector_view_array(unsigned *b, size_t s, size_t n): vector_view<unsigned>( gsl_vector_uint_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<unsigned const>: public vector_view<unsigned const> { vector_view_array(unsigned const *b, size_t s, size_t n): vector_view<unsigned const>( gsl_vector_uint_const_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<long>: public vector_view<long> { vector_view_array(long *b, size_t s, size_t n): vector_view<long>( gsl_vector_long_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<long const>: public vector_view<long const> { vector_view_array(long const *b, size_t s, size_t n): vector_view<long const>( gsl_vector_long_const_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<unsigned long>: public vector_view<unsigned long> { vector_view_array(unsigned long *b, size_t s, size_t n): vector_view<unsigned long>( gsl_vector_ulong_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<unsigned long const>: public vector_view<unsigned long const> { vector_view_array(unsigned long const *b, size_t s, size_t n): vector_view<unsigned long const>( gsl_vector_ulong_const_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<short>: public vector_view<short> { vector_view_array(short *b, size_t s, size_t n): vector_view<short>( gsl_vector_short_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<short const>: public vector_view<short const> { vector_view_array(short const *b, size_t s, size_t n): vector_view<short const>( gsl_vector_short_const_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<unsigned short>: public vector_view<unsigned short> { vector_view_array(unsigned short *b, size_t s, size_t n): vector_view<unsigned short>( gsl_vector_ushort_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<unsigned short const>: public vector_view<unsigned short const> { vector_view_array(unsigned short const *b, size_t s, size_t n): vector_view<unsigned short const>( gsl_vector_ushort_const_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<char>: public vector_view<char> { vector_view_array(char *b, size_t s, size_t n): vector_view<char>( gsl_vector_char_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<char const>: public vector_view<char const> { vector_view_array(char const *b, size_t s, size_t n): vector_view<char const>( gsl_vector_char_const_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<unsigned char>: public vector_view<unsigned char> { vector_view_array(unsigned char *b, size_t s, size_t n): vector_view<unsigned char>( gsl_vector_uchar_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<unsigned char const>: public vector_view<unsigned char const> { vector_view_array(unsigned char const *b, size_t s, size_t n): vector_view<unsigned char const>( gsl_vector_uchar_const_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<gsl_complex>: public vector_view<gsl_complex> { vector_view_array(double *b, size_t s, size_t n): vector_view<gsl_complex>( gsl_vector_complex_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<gsl_complex const>: public vector_view<gsl_complex const> { vector_view_array(double const *b, size_t s, size_t n): vector_view<gsl_complex const>( gsl_vector_complex_const_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<gsl_complex_float>: public vector_view<gsl_complex_float> { vector_view_array(float *b, size_t s, size_t n): vector_view<gsl_complex_float>( gsl_vector_complex_float_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<gsl_complex_float const>: public vector_view<gsl_complex_float const> { vector_view_array(float const *b, size_t s, size_t n): vector_view<gsl_complex_float const>( gsl_vector_complex_float_const_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<gsl_complex_long_double>: public vector_view<gsl_complex_long_double> { vector_view_array(long double *b, size_t s, size_t n): vector_view<gsl_complex_long_double>( gsl_vector_complex_long_double_view_array_with_stride(b,s,n)) {} };

template<> struct vector_view_array<gsl_complex_long_double const>: public vector_view<gsl_complex_long_double const> { vector_view_array(long double const *b, size_t s, size_t n): vector_view<gsl_complex_long_double const>( gsl_vector_complex_long_double_const_view_array_with_stride(b,s,n)) {} };


} // namespace gsl::c

// EOF
