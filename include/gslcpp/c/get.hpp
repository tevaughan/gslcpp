/// @file       include/gslcpp/c/get.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::c::get.

#pragma once

namespace gsl::c {

inline double get(c::vector<double const> * v, size_t i) { return gsl_vector_get(v,i); }

inline float get(c::vector<float const> * v, size_t i) { return gsl_vector_float_get(v,i); }

inline long double get(c::vector<long double const> * v, size_t i) { return gsl_vector_long_double_get(v,i); }

inline int get(c::vector<int const> * v, size_t i) { return gsl_vector_int_get(v,i); }

inline unsigned get(c::vector<unsigned const> * v, size_t i) { return gsl_vector_uint_get(v,i); }

inline long get(c::vector<long const> * v, size_t i) { return gsl_vector_long_get(v,i); }

inline unsigned long get(c::vector<unsigned long const> * v, size_t i) { return gsl_vector_ulong_get(v,i); }

inline short get(c::vector<short const> * v, size_t i) { return gsl_vector_short_get(v,i); }

inline unsigned short get(c::vector<unsigned short const> * v, size_t i) { return gsl_vector_ushort_get(v,i); }

inline char get(c::vector<char const> * v, size_t i) { return gsl_vector_char_get(v,i); }

inline unsigned char get(c::vector<unsigned char const> * v, size_t i) { return gsl_vector_uchar_get(v,i); }

inline gsl_complex get(c::vector<gsl_complex const> * v, size_t i) { return gsl_vector_complex_get(v,i); }

inline gsl_complex_float get(c::vector<gsl_complex_float const> * v, size_t i) { return gsl_vector_complex_float_get(v,i); }

inline gsl_complex_long_double get(c::vector<gsl_complex_long_double const> * v, size_t i) { return gsl_vector_complex_long_double_get(v,i); }


} // namespace gsl::c

// EOF
