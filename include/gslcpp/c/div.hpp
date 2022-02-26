/// @file       include/gslcpp/c/div.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gsl::c::div.

#pragma once
#include "type-map.hpp"

namespace gsl::c {

inline int div(c::vector<double > *u,c::vector<double const> * v) { return gsl_vector_div(u,v); }

inline int div(c::vector<float > *u,c::vector<float const> * v) { return gsl_vector_float_div(u,v); }

inline int div(c::vector<long double > *u,c::vector<long double const> * v) { return gsl_vector_long_double_div(u,v); }

inline int div(c::vector<int > *u,c::vector<int const> * v) { return gsl_vector_int_div(u,v); }

inline int div(c::vector<unsigned > *u,c::vector<unsigned const> * v) { return gsl_vector_uint_div(u,v); }

inline int div(c::vector<long > *u,c::vector<long const> * v) { return gsl_vector_long_div(u,v); }

inline int div(c::vector<unsigned long > *u,c::vector<unsigned long const> * v) { return gsl_vector_ulong_div(u,v); }

inline int div(c::vector<short > *u,c::vector<short const> * v) { return gsl_vector_short_div(u,v); }

inline int div(c::vector<unsigned short > *u,c::vector<unsigned short const> * v) { return gsl_vector_ushort_div(u,v); }

inline int div(c::vector<char > *u,c::vector<char const> * v) { return gsl_vector_char_div(u,v); }

inline int div(c::vector<unsigned char > *u,c::vector<unsigned char const> * v) { return gsl_vector_uchar_div(u,v); }

inline int div(c::vector<gsl_complex > *u,c::vector<gsl_complex const> * v) { return gsl_vector_complex_div(u,v); }

inline int div(c::vector<gsl_complex_float > *u,c::vector<gsl_complex_float const> * v) { return gsl_vector_complex_float_div(u,v); }

inline int div(c::vector<gsl_complex_long_double > *u,c::vector<gsl_complex_long_double const> * v) { return gsl_vector_complex_long_double_div(u,v); }


} // namespace gsl::c

// EOF
