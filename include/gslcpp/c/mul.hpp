/// @file       include/gslcpp/c/mul.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gsl::c::mul.

#pragma once
#include "vector.hpp"

namespace gsl::c {

inline int mul(c::vector<double > *u,c::vector<double const> * v) { return gsl_vector_mul(u,v); }

inline int mul(c::vector<float > *u,c::vector<float const> * v) { return gsl_vector_float_mul(u,v); }

inline int mul(c::vector<long double > *u,c::vector<long double const> * v) { return gsl_vector_long_double_mul(u,v); }

inline int mul(c::vector<int > *u,c::vector<int const> * v) { return gsl_vector_int_mul(u,v); }

inline int mul(c::vector<unsigned > *u,c::vector<unsigned const> * v) { return gsl_vector_uint_mul(u,v); }

inline int mul(c::vector<long > *u,c::vector<long const> * v) { return gsl_vector_long_mul(u,v); }

inline int mul(c::vector<unsigned long > *u,c::vector<unsigned long const> * v) { return gsl_vector_ulong_mul(u,v); }

inline int mul(c::vector<short > *u,c::vector<short const> * v) { return gsl_vector_short_mul(u,v); }

inline int mul(c::vector<unsigned short > *u,c::vector<unsigned short const> * v) { return gsl_vector_ushort_mul(u,v); }

inline int mul(c::vector<char > *u,c::vector<char const> * v) { return gsl_vector_char_mul(u,v); }

inline int mul(c::vector<unsigned char > *u,c::vector<unsigned char const> * v) { return gsl_vector_uchar_mul(u,v); }

inline int mul(c::vector<gsl_complex > *u,c::vector<gsl_complex const> * v) { return gsl_vector_complex_mul(u,v); }

inline int mul(c::vector<gsl_complex_float > *u,c::vector<gsl_complex_float const> * v) { return gsl_vector_complex_float_mul(u,v); }

inline int mul(c::vector<gsl_complex_long_double > *u,c::vector<gsl_complex_long_double const> * v) { return gsl_vector_complex_long_double_mul(u,v); }


} // namespace gsl::c

// EOF
