/// @file       include/gslcpp/c/subvector.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::c::subvector.

#pragma once
#include "vector-view.hpp"

namespace gsl::c {

template<typename E> struct subvector;

template<> struct subvector<double>: public vector_view<double> { subvector(c::vector<double> *v, size_t i, size_t s, size_t n): vector_view<double>(gsl_vector_subvector_with_stride(v, i, s, n)) {} };

template<> struct subvector<double const>: public vector_view<double const> { subvector(c::vector<double const> * v, size_t i, size_t s, size_t n): vector_view<double const>( gsl_vector_const_subvector_with_stride(v, i, s, n)) {} };

template<> struct subvector<float>: public vector_view<float> { subvector(c::vector<float> * v, size_t i, size_t s, size_t n): vector_view<float>(gsl_vector_float_subvector_with_stride(v, i, s, n)) {} };

template<> struct subvector<float const>: public vector_view<float const> { subvector(c::vector<float const> * v, size_t i, size_t s, size_t n): vector_view<float const>( gsl_vector_float_const_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<long double>: public vector_view<long double> { subvector(c::vector<long double> * v, size_t i, size_t s, size_t n): vector_view<long double>( gsl_vector_long_double_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<long double const>: public vector_view<long double const> { subvector(c::vector<long double const> * v, size_t i, size_t s, size_t n): vector_view<long double const>( gsl_vector_long_double_const_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<int>: public vector_view<int> { subvector(c::vector<int> * v, size_t i, size_t s, size_t n): vector_view<int>( gsl_vector_int_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<int const>: public vector_view<int const> { subvector(c::vector<int const> * v, size_t i, size_t s, size_t n): vector_view<int const>( gsl_vector_int_const_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<unsigned>: public vector_view<unsigned> { subvector(c::vector<unsigned> * v, size_t i, size_t s, size_t n): vector_view<unsigned>( gsl_vector_uint_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<unsigned const>: public vector_view<unsigned const> { subvector(c::vector<unsigned const> * v, size_t i, size_t s, size_t n): vector_view<unsigned const>( gsl_vector_uint_const_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<long>: public vector_view<long> { subvector(c::vector<long> * v, size_t i, size_t s, size_t n): vector_view<long>( gsl_vector_long_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<long const>: public vector_view<long const> { subvector(c::vector<long const> * v, size_t i, size_t s, size_t n): vector_view<long const>( gsl_vector_long_const_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<unsigned long>: public vector_view<unsigned long> { subvector(c::vector<unsigned long> * v, size_t i, size_t s, size_t n): vector_view<unsigned long>( gsl_vector_ulong_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<unsigned long const>: public vector_view<unsigned long const> { subvector(c::vector<unsigned long const> * v, size_t i, size_t s, size_t n): vector_view<unsigned long const>( gsl_vector_ulong_const_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<short>: public vector_view<short> { subvector(c::vector<short> * v, size_t i, size_t s, size_t n): vector_view<short>( gsl_vector_short_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<short const>: public vector_view<short const> { subvector(c::vector<short const> * v, size_t i, size_t s, size_t n): vector_view<short const>( gsl_vector_short_const_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<unsigned short>: public vector_view<unsigned short> { subvector(c::vector<unsigned short> * v, size_t i, size_t s, size_t n): vector_view<unsigned short>( gsl_vector_ushort_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<unsigned short const>: public vector_view<unsigned short const> { subvector(c::vector<unsigned short const> * v, size_t i, size_t s, size_t n): vector_view<unsigned short const>( gsl_vector_ushort_const_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<char>: public vector_view<char> { subvector(c::vector<char> * v, size_t i, size_t s, size_t n): vector_view<char>( gsl_vector_char_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<char const>: public vector_view<char const> { subvector(c::vector<char const> * v, size_t i, size_t s, size_t n): vector_view<char const>( gsl_vector_char_const_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<unsigned char>: public vector_view<unsigned char> { subvector(c::vector<unsigned char> * v, size_t i, size_t s, size_t n): vector_view<unsigned char>( gsl_vector_uchar_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<unsigned char const>: public vector_view<unsigned char const> { subvector(c::vector<unsigned char const> * v, size_t i, size_t s, size_t n): vector_view<unsigned char const>( gsl_vector_uchar_const_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<gsl_complex>: public vector_view<gsl_complex> { subvector(c::vector<gsl_complex> * v, size_t i, size_t s, size_t n): vector_view<gsl_complex>( gsl_vector_complex_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<gsl_complex const>: public vector_view<gsl_complex const> { subvector(c::vector<gsl_complex const> * v, size_t i, size_t s, size_t n): vector_view<gsl_complex const>( gsl_vector_complex_const_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<gsl_complex_float>: public vector_view<gsl_complex_float> { subvector(c::vector<gsl_complex_float> * v, size_t i, size_t s, size_t n): vector_view<gsl_complex_float>( gsl_vector_complex_float_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<gsl_complex_float const>: public vector_view<gsl_complex_float const> { subvector(c::vector<gsl_complex_float const> * v, size_t i, size_t s, size_t n): vector_view<gsl_complex_float const>( gsl_vector_complex_float_const_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<gsl_complex_long_double>: public vector_view<gsl_complex_long_double> { subvector(c::vector<gsl_complex_long_double> * v, size_t i, size_t s, size_t n): vector_view<gsl_complex_long_double>( gsl_vector_complex_long_double_subvector_with_stride(v, i,s,n)) {} };

template<> struct subvector<gsl_complex_long_double const>: public vector_view<gsl_complex_long_double const> { subvector(c::vector<gsl_complex_long_double const> * v, size_t i, size_t s, size_t n): vector_view<gsl_complex_long_double const>( gsl_vector_complex_long_double_const_subvector_with_stride(v, i,s,n)) {} };


} // namespace gsl::c

// EOF
