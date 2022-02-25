/// @file       include/gslcpp/c/isnonneg.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::c::isnonneg.

#pragma once
#include "vector.hpp"

namespace gsl::c {

inline bool isnonneg(c::vector<double const> * v) { return gsl_vector_isnonneg(v); }

inline bool isnonneg(c::vector<float const> * v) { return gsl_vector_float_isnonneg(v); }

inline bool isnonneg(c::vector<long double const> * v) { return gsl_vector_long_double_isnonneg(v); }

inline bool isnonneg(c::vector<int const> * v) { return gsl_vector_int_isnonneg(v); }

inline bool isnonneg(c::vector<unsigned const> * v) { return gsl_vector_uint_isnonneg(v); }

inline bool isnonneg(c::vector<long const> * v) { return gsl_vector_long_isnonneg(v); }

inline bool isnonneg(c::vector<unsigned long const> * v) { return gsl_vector_ulong_isnonneg(v); }

inline bool isnonneg(c::vector<short const> * v) { return gsl_vector_short_isnonneg(v); }

inline bool isnonneg(c::vector<unsigned short const> * v) { return gsl_vector_ushort_isnonneg(v); }

inline bool isnonneg(c::vector<char const> * v) { return gsl_vector_char_isnonneg(v); }

inline bool isnonneg(c::vector<unsigned char const> * v) { return gsl_vector_uchar_isnonneg(v); }

inline bool isnonneg(c::vector<gsl_complex const> * v) { return gsl_vector_complex_isnonneg(v); }

inline bool isnonneg(c::vector<gsl_complex_float const> * v) { return gsl_vector_complex_float_isnonneg(v); }

inline bool isnonneg(c::vector<gsl_complex_long_double const> * v) { return gsl_vector_complex_long_double_isnonneg(v); }


} // namespace gsl::c

// EOF
