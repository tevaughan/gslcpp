/// @file       include/gslcpp/c/scale.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gsl::c::scale.

#pragma once
#include "vector.hpp"

namespace gsl::c {

inline int scale(c::vector<double > *u, double const & v) { return gsl_vector_scale(u,v); }

inline int scale(c::vector<float > *u, float const & v) { return gsl_vector_float_scale(u,v); }

inline int scale(c::vector<long double > *u, long double const & v) { return gsl_vector_long_double_scale(u,v); }

inline int scale(c::vector<int > *u, int const & v) { return gsl_vector_int_scale(u,v); }

inline int scale(c::vector<unsigned > *u, unsigned const & v) { return gsl_vector_uint_scale(u,v); }

inline int scale(c::vector<long > *u, long const & v) { return gsl_vector_long_scale(u,v); }

inline int scale(c::vector<unsigned long > *u, unsigned long const & v) { return gsl_vector_ulong_scale(u,v); }

inline int scale(c::vector<short > *u, short const & v) { return gsl_vector_short_scale(u,v); }

inline int scale(c::vector<unsigned short > *u, unsigned short const & v) { return gsl_vector_ushort_scale(u,v); }

inline int scale(c::vector<char > *u, char const & v) { return gsl_vector_char_scale(u,v); }

inline int scale(c::vector<unsigned char > *u, unsigned char const & v) { return gsl_vector_uchar_scale(u,v); }

inline int scale(c::vector<gsl_complex > *u, gsl_complex const & v) { return gsl_vector_complex_scale(u,v); }

inline int scale(c::vector<gsl_complex_float > *u, gsl_complex_float const & v) { return gsl_vector_complex_float_scale(u,v); }

inline int scale(c::vector<gsl_complex_long_double > *u, gsl_complex_long_double const & v) { return gsl_vector_complex_long_double_scale(u,v); }


} // namespace gsl::c

// EOF
