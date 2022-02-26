/// @file       include/gslcpp/c/max.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::c::max.

#pragma once
#include "type-map.hpp" // vector

namespace gsl::c {

inline double max(c::vector<double const> * v) { return gsl_vector_max(v); }

inline float max(c::vector<float const> * v) { return gsl_vector_float_max(v); }

inline long double max(c::vector<long double const> * v) { return gsl_vector_long_double_max(v); }

inline int max(c::vector<int const> * v) { return gsl_vector_int_max(v); }

inline unsigned max(c::vector<unsigned const> * v) { return gsl_vector_uint_max(v); }

inline long max(c::vector<long const> * v) { return gsl_vector_long_max(v); }

inline unsigned long max(c::vector<unsigned long const> * v) { return gsl_vector_ulong_max(v); }

inline short max(c::vector<short const> * v) { return gsl_vector_short_max(v); }

inline unsigned short max(c::vector<unsigned short const> * v) { return gsl_vector_ushort_max(v); }

inline char max(c::vector<char const> * v) { return gsl_vector_char_max(v); }

inline unsigned char max(c::vector<unsigned char const> * v) { return gsl_vector_uchar_max(v); }

} // namespace gsl::c

// EOF
