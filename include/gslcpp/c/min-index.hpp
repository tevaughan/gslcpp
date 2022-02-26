/// @file       include/gslcpp/c/min-index.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::c::min_index.

#pragma once
#include "vector.hpp" // vector

namespace gsl::c {

inline size_t min_index(c::vector<double const> *v) { return gsl_vector_min_index(v); }

inline size_t min_index(c::vector<float const> *v) { return gsl_vector_float_min_index(v); }

inline size_t min_index(c::vector<long double const> *v) { return gsl_vector_long_double_min_index(v); }

inline size_t min_index(c::vector<int const> *v) { return gsl_vector_int_min_index(v); }

inline size_t min_index(c::vector<unsigned const> *v) { return gsl_vector_uint_min_index(v); }

inline size_t min_index(c::vector<long const> *v) { return gsl_vector_long_min_index(v); }

inline size_t min_index(c::vector<unsigned long const> *v) { return gsl_vector_ulong_min_index(v); }

inline size_t min_index(c::vector<short const> *v) { return gsl_vector_short_min_index(v); }

inline size_t min_index(c::vector<unsigned short const> *v) { return gsl_vector_ushort_min_index(v); }

inline size_t min_index(c::vector<char const> *v) { return gsl_vector_char_min_index(v); }

inline size_t min_index(c::vector<unsigned char const> *v) { return gsl_vector_uchar_min_index(v); }

} // namespace gsl::c

// EOF