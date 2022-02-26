/// @file       include/gslcpp/c/min.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::c::min.

#pragma once
#include "type-map.hpp" // vector

namespace gsl::c {

inline double min(c::vector<double const> * v) { return gsl_vector_min(v); }

inline float min(c::vector<float const> * v) { return gsl_vector_float_min(v); }

inline long double min(c::vector<long double const> * v) { return gsl_vector_long_double_min(v); }

inline int min(c::vector<int const> * v) { return gsl_vector_int_min(v); }

inline unsigned min(c::vector<unsigned const> * v) { return gsl_vector_uint_min(v); }

inline long min(c::vector<long const> * v) { return gsl_vector_long_min(v); }

inline unsigned long min(c::vector<unsigned long const> * v) { return gsl_vector_ulong_min(v); }

inline short min(c::vector<short const> * v) { return gsl_vector_short_min(v); }

inline unsigned short min(c::vector<unsigned short const> * v) { return gsl_vector_ushort_min(v); }

inline char min(c::vector<char const> * v) { return gsl_vector_char_min(v); }

inline unsigned char min(c::vector<unsigned char const> * v) { return gsl_vector_uchar_min(v); }

} // namespace gsl::c

// EOF
