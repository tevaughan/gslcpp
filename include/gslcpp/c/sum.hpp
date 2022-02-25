/// @file       include/gslcpp/c/sum.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::c::sum.

#pragma once
#include "vector.hpp" // vector, GSL_AT_LEAST(), sum_for_gsl_lt_2p7()

namespace gsl::c {

#if GSL_AT_LEAST(2, 7)

inline double sum(c::vector<double const> * v) { return gsl_vector_sum(v); }

inline float sum(c::vector<float const> * v) { return gsl_vector_float_sum(v); }

inline long double sum(c::vector<long double const> * v) { return gsl_vector_long_double_sum(v); }

inline int sum(c::vector<int const> * v) { return gsl_vector_int_sum(v); }

inline unsigned sum(c::vector<unsigned const> * v) { return gsl_vector_uint_sum(v); }

inline long sum(c::vector<long const> * v) { return gsl_vector_long_sum(v); }

inline unsigned long sum(c::vector<unsigned long const> * v) { return gsl_vector_ulong_sum(v); }

inline short sum(c::vector<short const> * v) { return gsl_vector_short_sum(v); }

inline unsigned short sum(c::vector<unsigned short const> * v) { return gsl_vector_ushort_sum(v); }

inline char sum(c::vector<char const> * v) { return gsl_vector_char_sum(v); }

inline unsigned char sum(c::vector<unsigned char const> * v) { return gsl_vector_uchar_sum(v); }

inline gsl_complex sum(c::vector<gsl_complex const> * v) { return gsl_vector_complex_sum(v); }

inline gsl_complex_float sum(c::vector<gsl_complex_float const> * v) { return gsl_vector_complex_float_sum(v); }

inline gsl_complex_long_double sum(c::vector<gsl_complex_long_double const> * v) { return gsl_vector_complex_long_double_sum(v); }

#else

template<typename V> auto sum(V *v) { return sum_for_gsl_lt_2p7(*v); }

#endif


} // namespace gsl::c

// EOF
