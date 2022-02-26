/// @file       include/gslcpp/c/isnull.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::c::isnull.

#pragma once
#include "type-map.hpp"

namespace gsl::c {

inline bool isnull(c::vector<double const> * v) { return gsl_vector_isnull(v); }

inline bool isnull(c::vector<float const> * v) { return gsl_vector_float_isnull(v); }

inline bool isnull(c::vector<long double const> * v) { return gsl_vector_long_double_isnull(v); }

inline bool isnull(c::vector<int const> * v) { return gsl_vector_int_isnull(v); }

inline bool isnull(c::vector<unsigned const> * v) { return gsl_vector_uint_isnull(v); }

inline bool isnull(c::vector<long const> * v) { return gsl_vector_long_isnull(v); }

inline bool isnull(c::vector<unsigned long const> * v) { return gsl_vector_ulong_isnull(v); }

inline bool isnull(c::vector<short const> * v) { return gsl_vector_short_isnull(v); }

inline bool isnull(c::vector<unsigned short const> * v) { return gsl_vector_ushort_isnull(v); }

inline bool isnull(c::vector<char const> * v) { return gsl_vector_char_isnull(v); }

inline bool isnull(c::vector<unsigned char const> * v) { return gsl_vector_uchar_isnull(v); }

inline bool isnull(c::vector<gsl_complex const> * v) { return gsl_vector_complex_isnull(v); }

inline bool isnull(c::vector<gsl_complex_float const> * v) { return gsl_vector_complex_float_isnull(v); }

inline bool isnull(c::vector<gsl_complex_long_double const> * v) { return gsl_vector_complex_long_double_isnull(v); }


} // namespace gsl::c

// EOF
