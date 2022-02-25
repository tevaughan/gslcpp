/// @file       include/gslcpp/c/set-zero.hpp
/// @copyright  2022 Thomas E. Vaughan
/// @brief      Definition of gslcpp::c::set_zero.

#pragma once
#include "vector.hpp"

namespace gsl::c {

inline void set_zero(c::vector<double> *v) { return gsl_vector_set_zero(v); }

inline void set_zero(c::vector<float> *v) { return gsl_vector_float_set_zero(v); }

inline void set_zero(c::vector<long double> *v) { return gsl_vector_long_double_set_zero(v); }

inline void set_zero(c::vector<int> *v) { return gsl_vector_int_set_zero(v); }

inline void set_zero(c::vector<unsigned> *v) { return gsl_vector_uint_set_zero(v); }

inline void set_zero(c::vector<long> *v) { return gsl_vector_long_set_zero(v); }

inline void set_zero(c::vector<unsigned long> *v) { return gsl_vector_ulong_set_zero(v); }

inline void set_zero(c::vector<short> *v) { return gsl_vector_short_set_zero(v); }

inline void set_zero(c::vector<unsigned short> *v) { return gsl_vector_ushort_set_zero(v); }

inline void set_zero(c::vector<char> *v) { return gsl_vector_char_set_zero(v); }

inline void set_zero(c::vector<unsigned char> *v) { return gsl_vector_uchar_set_zero(v); }

inline void set_zero(c::vector<gsl_complex> *v) { return gsl_vector_complex_set_zero(v); }

inline void set_zero(c::vector<gsl_complex_float> *v) { return gsl_vector_complex_float_set_zero(v); }

inline void set_zero(c::vector<gsl_complex_long_double> *v) { return gsl_vector_complex_long_double_set_zero(v); }


} // namespace gsl::c

// EOF
