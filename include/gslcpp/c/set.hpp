/// @file       include/gslcpp/c/set.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::c::set.

#pragma once
#include "type-map.hpp"

namespace gsl::c {

inline void set(c::vector<double> *v, size_t i, double const &x) { return gsl_vector_set(v,i,x); }

inline void set(c::vector<float> *v, size_t i, float const &x) { return gsl_vector_float_set(v,i,x); }

inline void set(c::vector<long double> *v, size_t i, long double const &x) { return gsl_vector_long_double_set(v,i,x); }

inline void set(c::vector<int> *v, size_t i, int const &x) { return gsl_vector_int_set(v,i,x); }

inline void set(c::vector<unsigned> *v, size_t i, unsigned const &x) { return gsl_vector_uint_set(v,i,x); }

inline void set(c::vector<long> *v, size_t i, long const &x) { return gsl_vector_long_set(v,i,x); }

inline void set(c::vector<unsigned long> *v, size_t i, unsigned long const &x) { return gsl_vector_ulong_set(v,i,x); }

inline void set(c::vector<short> *v, size_t i, short const &x) { return gsl_vector_short_set(v,i,x); }

inline void set(c::vector<unsigned short> *v, size_t i, unsigned short const &x) { return gsl_vector_ushort_set(v,i,x); }

inline void set(c::vector<char> *v, size_t i, char const &x) { return gsl_vector_char_set(v,i,x); }

inline void set(c::vector<unsigned char> *v, size_t i, unsigned char const &x) { return gsl_vector_uchar_set(v,i,x); }

inline void set(c::vector<gsl_complex> *v, size_t i, gsl_complex const &x) { return gsl_vector_complex_set(v,i,x); }

inline void set(c::vector<gsl_complex_float> *v, size_t i, gsl_complex_float const &x) { return gsl_vector_complex_float_set(v,i,x); }

inline void set(c::vector<gsl_complex_long_double> *v, size_t i, gsl_complex_long_double const &x) { return gsl_vector_complex_long_double_set(v,i,x); }


} // namespace gsl::c

// EOF
