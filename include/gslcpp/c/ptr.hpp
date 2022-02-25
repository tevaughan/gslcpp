/// @file       include/gslcpp/c/subvector.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::c::subvector.

#pragma once
#include "vector.hpp"

namespace gsl::c {

inline double *ptr(c::vector<double> *v, size_t i) { return gsl_vector_ptr(v,i); }

inline double const *ptr(c::vector<double const> * v, size_t i) { return  gsl_vector_const_ptr(v,i); }

inline float *ptr(c::vector<float> * v, size_t i) { return gsl_vector_float_ptr(v,i); }

inline float const *ptr(c::vector<float const> * v, size_t i) {  return gsl_vector_float_const_ptr(v,i); }

inline long double *ptr(c::vector<long double> * v, size_t i) {  return gsl_vector_long_double_ptr(v,i); }

inline long double const *ptr(c::vector<long double const> * v, size_t i) {  return gsl_vector_long_double_const_ptr(v,i); }

inline int *ptr(c::vector<int> * v, size_t i) { return gsl_vector_int_ptr(v,i); }

inline int const *ptr(c::vector<int const> * v, size_t i) { return gsl_vector_int_const_ptr(v,i); }

inline unsigned *ptr(c::vector<unsigned> * v, size_t i) { return gsl_vector_uint_ptr(v,i); }

inline unsigned const *ptr(c::vector<unsigned const> * v, size_t i) { return gsl_vector_uint_const_ptr(v,i); }

inline long *ptr(c::vector<long> * v, size_t i) { return gsl_vector_long_ptr(v,i); }

inline long const *ptr(c::vector<long const> * v, size_t i) { return gsl_vector_long_const_ptr(v,i); }

inline unsigned long *ptr(c::vector<unsigned long> * v, size_t i) { return gsl_vector_ulong_ptr(v,i); }

inline unsigned long const *ptr(c::vector<unsigned long const> * v, size_t i) { return gsl_vector_ulong_const_ptr(v,i); }

inline short *ptr(c::vector<short> * v, size_t i) { return gsl_vector_short_ptr(v,i); }

inline short const *ptr(c::vector<short const> * v, size_t i) { return gsl_vector_short_const_ptr(v,i); }

inline unsigned short *ptr(c::vector<unsigned short> * v, size_t i) { return gsl_vector_ushort_ptr(v,i); }

inline unsigned short const *ptr(c::vector<unsigned short const> * v, size_t i) { return gsl_vector_ushort_const_ptr(v,i); }

inline char *ptr(c::vector<char> * v, size_t i) { return gsl_vector_char_ptr(v,i); }

inline char const *ptr(c::vector<char const> * v, size_t i) { return gsl_vector_char_const_ptr(v,i); }

inline unsigned char *ptr(c::vector<unsigned char> * v, size_t i) { return gsl_vector_uchar_ptr(v,i); }

inline unsigned char const *ptr(c::vector<unsigned char const> * v, size_t i) { return gsl_vector_uchar_const_ptr(v,i); }

inline gsl_complex *ptr(c::vector<gsl_complex> * v, size_t i) { return gsl_vector_complex_ptr(v,i); }

inline gsl_complex const *ptr(c::vector<gsl_complex const> * v, size_t i) { return gsl_vector_complex_const_ptr(v,i); }

inline gsl_complex_float *ptr(c::vector<gsl_complex_float> * v, size_t i) { return gsl_vector_complex_float_ptr(v,i); }

inline gsl_complex_float const *ptr(c::vector<gsl_complex_float const> * v, size_t i) { return gsl_vector_complex_float_const_ptr(v,i); }

inline gsl_complex_long_double *ptr(c::vector<gsl_complex_long_double> * v, size_t i) { return gsl_vector_complex_long_double_ptr(v,i); }

inline gsl_complex_long_double const *ptr(c::vector<gsl_complex_long_double const> * v, size_t i) { return gsl_vector_complex_long_double_const_ptr(v,i); }


} // namespace gsl::c

// EOF
