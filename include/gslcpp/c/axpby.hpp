/// @file       include/gslcpp/c/axpby.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of c::axpby.

#pragma once
#include "vector.hpp"

namespace gsl::c {

#if GSL_AT_LEAST(2, 7)

inline int axpby(double const &a, c::vector<double const> *x, double const &b, c::vector<double> *y) { return gsl_vector_axpby(a,x,b,y); }

inline int axpby(float const &a, c::vector<float const> *x, float const &b, c::vector<float> *y) { return gsl_vector_float_axpby(a,x,b,y); }

inline int axpby(long double const &a, c::vector<long double const> *x, long double const &b, c::vector<long double> *y) { return gsl_vector_long_double_axpby(a,x,b,y); }

inline int axpby(int const &a, c::vector<int const> *x, int const &b, c::vector<int> *y) { return gsl_vector_int_axpby(a,x,b,y); }

inline int axpby(unsigned const &a, c::vector<unsigned const> *x, unsigned const &b, c::vector<unsigned> *y) { return gsl_vector_uint_axpby(a,x,b,y); }

inline int axpby(long const &a, c::vector<long const> *x, long const &b, c::vector<long> *y) { return gsl_vector_long_axpby(a,x,b,y); }

inline int axpby(unsigned long const &a, c::vector<unsigned long const> *x, unsigned long const &b, c::vector<unsigned long> *y) { return gsl_vector_ulong_axpby(a,x,b,y); }

inline int axpby(short const &a, c::vector<short const> *x, short const &b, c::vector<short> *y) { return gsl_vector_short_axpby(a,x,b,y); }

inline int axpby(unsigned short const &a, c::vector<unsigned short const> *x, unsigned short const &b, c::vector<unsigned short> *y) { return gsl_vector_ushort_axpby(a,x,b,y); }

inline int axpby(char const &a, c::vector<char const> *x, char const &b, c::vector<char> *y) { return gsl_vector_char_axpby(a,x,b,y); }

inline int axpby(unsigned char const &a, c::vector<unsigned char const> *x, unsigned char const &b, c::vector<unsigned char> *y) { return gsl_vector_uchar_axpby(a,x,b,y); }

inline int axpby(gsl_complex const &a, c::vector<gsl_complex const> *x, gsl_complex const &b, c::vector<gsl_complex> *y) { return gsl_vector_complex_axpby(a,x,b,y); }

inline int axpby(gsl_complex_float const &a, c::vector<gsl_complex_float const> *x, gsl_complex_float const &b, c::vector<gsl_complex_float> *y) { return gsl_vector_complex_float_axpby(a,x,b,y); }

inline int axpby(gsl_complex_long_double const &a, c::vector<gsl_complex_long_double const> *x, gsl_complex_long_double const &b, c::vector<gsl_complex_long_double> *y) { return gsl_vector_complex_long_double_axpby(a,x,b,y); }

#else

template<typename V> int axpby(vdata_t<V> const &a, V const *x, vdata_t<V> const &b, V *y) { return axpby_for_gsl_lt_2p7(a,*x,b,*y); }

#endif

} // namespace gsl::c

// EOF
