/// @file       include/gslcpp/c/max-index.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::c::max_index.

#pragma once
#include "type-map.hpp" // vector

namespace gsl::c {

inline size_t max_index(c::vector<double const> *v) { return gsl_vector_max_index(v); }

inline size_t max_index(c::vector<float const> *v) { return gsl_vector_float_max_index(v); }

inline size_t max_index(c::vector<long double const> *v) { return gsl_vector_long_double_max_index(v); }

inline size_t max_index(c::vector<int const> *v) { return gsl_vector_int_max_index(v); }

inline size_t max_index(c::vector<unsigned const> *v) { return gsl_vector_uint_max_index(v); }

inline size_t max_index(c::vector<long const> *v) { return gsl_vector_long_max_index(v); }

inline size_t max_index(c::vector<unsigned long const> *v) { return gsl_vector_ulong_max_index(v); }

inline size_t max_index(c::vector<short const> *v) { return gsl_vector_short_max_index(v); }

inline size_t max_index(c::vector<unsigned short const> *v) { return gsl_vector_ushort_max_index(v); }

inline size_t max_index(c::vector<char const> *v) { return gsl_vector_char_max_index(v); }

inline size_t max_index(c::vector<unsigned char const> *v) { return gsl_vector_uchar_max_index(v); }

} // namespace gsl::c

// EOF
