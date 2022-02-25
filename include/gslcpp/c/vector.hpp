/// @file       include/gslcpp/c/vector.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::c::vec_ and gslcpp::c::vector.

#pragma once

// Use inline-definition of each accessor-function.
// - Define this before including `gsl_vector.h`.
#ifndef HAVE_INLINE
#  define HAVE_INLINE
#endif

#include <gsl/gsl_vector.h> // gsl_vector, gsl_vector_float, etc.

namespace gsl::c {


/// Template whose specialization defines dependent type, `vec_<E>::type`.
/// @tparam E  Type of element for vector.
template<typename E> struct vec_;


template<> struct vec_<double> { using type= gsl_vector; };

template<> struct vec_<double const> { using type= gsl_vector const; };

template<> struct vec_<float> { using type= gsl_vector_float; };

template<> struct vec_<float const> { using type= gsl_vector_float const; };

template<> struct vec_<long double> { using type= gsl_vector_long_double; };

template<> struct vec_<long double const> { using type= gsl_vector_long_double const; };

template<> struct vec_<int> { using type= gsl_vector_int; };

template<> struct vec_<int const> { using type= gsl_vector_int const; };

template<> struct vec_<unsigned> { using type= gsl_vector_uint; };

template<> struct vec_<unsigned const> { using type= gsl_vector_uint const; };

template<> struct vec_<long> { using type= gsl_vector_long; };

template<> struct vec_<long const> { using type= gsl_vector_long const; };

template<> struct vec_<unsigned long> { using type= gsl_vector_ulong; };

template<> struct vec_<unsigned long const> { using type= gsl_vector_ulong const; };

template<> struct vec_<short> { using type= gsl_vector_short; };

template<> struct vec_<short const> { using type= gsl_vector_short const; };

template<> struct vec_<unsigned short> { using type= gsl_vector_ushort; };

template<> struct vec_<unsigned short const> { using type= gsl_vector_ushort const; };

template<> struct vec_<char> { using type= gsl_vector_char; };

template<> struct vec_<char const> { using type= gsl_vector_char const; };

template<> struct vec_<unsigned char> { using type= gsl_vector_uchar; };

template<> struct vec_<unsigned char const> { using type= gsl_vector_uchar const; };

template<> struct vec_<gsl_complex> { using type= gsl_vector_complex; };

template<> struct vec_<gsl_complex const> { using type= gsl_vector_complex const; };

template<> struct vec_<gsl_complex_float> { using type= gsl_vector_complex_float; };

template<> struct vec_<gsl_complex_float const> { using type= gsl_vector_complex_float const; };

template<> struct vec_<gsl_complex_long_double> { using type= gsl_vector_complex_long_double; };

template<> struct vec_<gsl_complex_long_double const> { using type= gsl_vector_complex_long_double const; };


/// GSL's native vector-type corresponding to element-type `E`.
/// @tparam E  Type of element for vector.
template<typename E> using vector= typename vec_<E>::type;


} // namespace gsl::c

// EOF
