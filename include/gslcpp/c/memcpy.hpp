/// @file       include/gslcpp/c/memcpy.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gsl::c::memcpy.

#pragma once
#include "vector.hpp"

namespace gsl::c {

inline int memcpy(c::vector<double > *u,c::vector<double const> * v) { return gsl_vector_memcpy(u,v); }

inline int memcpy(c::vector<float > *u,c::vector<float const> * v) { return gsl_vector_float_memcpy(u,v); }

inline int memcpy(c::vector<long double > *u,c::vector<long double const> * v) { return gsl_vector_long_double_memcpy(u,v); }

inline int memcpy(c::vector<int > *u,c::vector<int const> * v) { return gsl_vector_int_memcpy(u,v); }

inline int memcpy(c::vector<unsigned > *u,c::vector<unsigned const> * v) { return gsl_vector_uint_memcpy(u,v); }

inline int memcpy(c::vector<long > *u,c::vector<long const> * v) { return gsl_vector_long_memcpy(u,v); }

inline int memcpy(c::vector<unsigned long > *u,c::vector<unsigned long const> * v) { return gsl_vector_ulong_memcpy(u,v); }

inline int memcpy(c::vector<short > *u,c::vector<short const> * v) { return gsl_vector_short_memcpy(u,v); }

inline int memcpy(c::vector<unsigned short > *u,c::vector<unsigned short const> * v) { return gsl_vector_ushort_memcpy(u,v); }

inline int memcpy(c::vector<char > *u,c::vector<char const> * v) { return gsl_vector_char_memcpy(u,v); }

inline int memcpy(c::vector<unsigned char > *u,c::vector<unsigned char const> * v) { return gsl_vector_uchar_memcpy(u,v); }

inline int memcpy(c::vector<gsl_complex > *u,c::vector<gsl_complex const> * v) { return gsl_vector_complex_memcpy(u,v); }

inline int memcpy(c::vector<gsl_complex_float > *u,c::vector<gsl_complex_float const> * v) { return gsl_vector_complex_float_memcpy(u,v); }

inline int memcpy(c::vector<gsl_complex_long_double > *u,c::vector<gsl_complex_long_double const> * v) { return gsl_vector_complex_long_double_memcpy(u,v); }


} // namespace gsl::c

// EOF
