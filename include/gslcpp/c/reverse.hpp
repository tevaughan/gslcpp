/// @file       include/gslcpp/c/reverse.hpp
/// @copyright  2022 Thomas E. Vaughan
/// @brief      Definition of gsl::c::reverse.

#pragma once
#include "type-map.hpp"

namespace gsl::c {

inline int reverse(c::vector<double> *v) { return gsl_vector_reverse(v); }

inline int reverse(c::vector<float> *v) { return gsl_vector_float_reverse(v); }

inline int reverse(c::vector<long double> *v) { return gsl_vector_long_double_reverse(v); }

inline int reverse(c::vector<int> *v) { return gsl_vector_int_reverse(v); }

inline int reverse(c::vector<unsigned> *v) { return gsl_vector_uint_reverse(v); }

inline int reverse(c::vector<long> *v) { return gsl_vector_long_reverse(v); }

inline int reverse(c::vector<unsigned long> *v) { return gsl_vector_ulong_reverse(v); }

inline int reverse(c::vector<short> *v) { return gsl_vector_short_reverse(v); }

inline int reverse(c::vector<unsigned short> *v) { return gsl_vector_ushort_reverse(v); }

inline int reverse(c::vector<char> *v) { return gsl_vector_char_reverse(v); }

inline int reverse(c::vector<unsigned char> *v) { return gsl_vector_uchar_reverse(v); }

inline int reverse(c::vector<gsl_complex> *v) { return gsl_vector_complex_reverse(v); }

inline int reverse(c::vector<gsl_complex_float> *v) { return gsl_vector_complex_float_reverse(v); }

inline int reverse(c::vector<gsl_complex_long_double> *v) { return gsl_vector_complex_long_double_reverse(v); }


} // namespace gsl::c

// EOF
