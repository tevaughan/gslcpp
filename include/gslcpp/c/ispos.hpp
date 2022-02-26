/// @file       include/gslcpp/c/ispos.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::c::ispos.

#pragma once
#include "type-map.hpp"

namespace gsl::c {

inline bool ispos(c::vector<double const> * v) { return gsl_vector_ispos(v); }

inline bool ispos(c::vector<float const> * v) { return gsl_vector_float_ispos(v); }

inline bool ispos(c::vector<long double const> * v) { return gsl_vector_long_double_ispos(v); }

inline bool ispos(c::vector<int const> * v) { return gsl_vector_int_ispos(v); }

inline bool ispos(c::vector<unsigned const> * v) { return gsl_vector_uint_ispos(v); }

inline bool ispos(c::vector<long const> * v) { return gsl_vector_long_ispos(v); }

inline bool ispos(c::vector<unsigned long const> * v) { return gsl_vector_ulong_ispos(v); }

inline bool ispos(c::vector<short const> * v) { return gsl_vector_short_ispos(v); }

inline bool ispos(c::vector<unsigned short const> * v) { return gsl_vector_ushort_ispos(v); }

inline bool ispos(c::vector<char const> * v) { return gsl_vector_char_ispos(v); }

inline bool ispos(c::vector<unsigned char const> * v) { return gsl_vector_uchar_ispos(v); }

inline bool ispos(c::vector<gsl_complex const> * v) { return gsl_vector_complex_ispos(v); }

inline bool ispos(c::vector<gsl_complex_float const> * v) { return gsl_vector_complex_float_ispos(v); }

inline bool ispos(c::vector<gsl_complex_long_double const> * v) { return gsl_vector_complex_long_double_ispos(v); }


} // namespace gsl::c

// EOF
