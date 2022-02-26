/// @file       include/gslcpp/c/swap-elements.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gsl::c::swap_elements.

#pragma once
#include "vector.hpp"

namespace gsl::c {

inline int swap_elements(c::vector<double> *v, size_t i, size_t j) { return gsl_vector_swap_elements(v,i,j); }

inline int swap_elements(c::vector<float> *v, size_t i, size_t j) { return gsl_vector_float_swap_elements(v,i,j); }

inline int swap_elements(c::vector<long double> *v, size_t i, size_t j) { return gsl_vector_long_double_swap_elements(v,i,j); }

inline int swap_elements(c::vector<int> *v, size_t i, size_t j) { return gsl_vector_int_swap_elements(v,i,j); }

inline int swap_elements(c::vector<unsigned> *v, size_t i, size_t j) { return gsl_vector_uint_swap_elements(v,i,j); }

inline int swap_elements(c::vector<long> *v, size_t i, size_t j) { return gsl_vector_long_swap_elements(v,i,j); }

inline int swap_elements(c::vector<unsigned long> *v, size_t i, size_t j) { return gsl_vector_ulong_swap_elements(v,i,j); }

inline int swap_elements(c::vector<short> *v, size_t i, size_t j) { return gsl_vector_short_swap_elements(v,i,j); }

inline int swap_elements(c::vector<unsigned short> *v, size_t i, size_t j) { return gsl_vector_ushort_swap_elements(v,i,j); }

inline int swap_elements(c::vector<char> *v, size_t i, size_t j) { return gsl_vector_char_swap_elements(v,i,j); }

inline int swap_elements(c::vector<unsigned char> *v, size_t i, size_t j) { return gsl_vector_uchar_swap_elements(v,i,j); }

inline int swap_elements(c::vector<gsl_complex> *v, size_t i, size_t j) { return gsl_vector_complex_swap_elements(v,i,j); }

inline int swap_elements(c::vector<gsl_complex_float> *v, size_t i, size_t j) { return gsl_vector_complex_float_swap_elements(v,i,j); }

inline int swap_elements(c::vector<gsl_complex_long_double> *v, size_t i, size_t j) { return gsl_vector_complex_long_double_swap_elements(v,i,j); }


} // namespace gsl::c

// EOF
