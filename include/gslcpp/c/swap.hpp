/// @file       include/gslcpp/c/swap.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gsl::c::swap.

#pragma once
#include "vector.hpp"

namespace gsl::c {

inline int swap(c::vector<double > *u,c::vector<double> * v) { return gsl_vector_swap(u,v); }

inline int swap(c::vector<float > *u,c::vector<float> * v) { return gsl_vector_float_swap(u,v); }

inline int swap(c::vector<long double > *u,c::vector<long double> * v) { return gsl_vector_long_double_swap(u,v); }

inline int swap(c::vector<int > *u,c::vector<int> * v) { return gsl_vector_int_swap(u,v); }

inline int swap(c::vector<unsigned > *u,c::vector<unsigned> * v) { return gsl_vector_uint_swap(u,v); }

inline int swap(c::vector<long > *u,c::vector<long> * v) { return gsl_vector_long_swap(u,v); }

inline int swap(c::vector<unsigned long > *u,c::vector<unsigned long> * v) { return gsl_vector_ulong_swap(u,v); }

inline int swap(c::vector<short > *u,c::vector<short> * v) { return gsl_vector_short_swap(u,v); }

inline int swap(c::vector<unsigned short > *u,c::vector<unsigned short> * v) { return gsl_vector_ushort_swap(u,v); }

inline int swap(c::vector<char > *u,c::vector<char> * v) { return gsl_vector_char_swap(u,v); }

inline int swap(c::vector<unsigned char > *u,c::vector<unsigned char> * v) { return gsl_vector_uchar_swap(u,v); }

inline int swap(c::vector<gsl_complex > *u,c::vector<gsl_complex> * v) { return gsl_vector_complex_swap(u,v); }

inline int swap(c::vector<gsl_complex_float > *u,c::vector<gsl_complex_float> * v) { return gsl_vector_complex_float_swap(u,v); }

inline int swap(c::vector<gsl_complex_long_double > *u,c::vector<gsl_complex_long_double> * v) { return gsl_vector_complex_long_double_swap(u,v); }


} // namespace gsl::c

// EOF
