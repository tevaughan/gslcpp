/// @file       include/gslcpp/c/set-basis.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::c::set_basis.

#pragma once
#include "type-map.hpp"

namespace gsl::c {

inline int set_basis(c::vector<double> *v, size_t i) { return gsl_vector_set_basis(v,i); }

inline int set_basis(c::vector<float> *v, size_t i, float const &x) { return gsl_vector_float_set_basis(v,i); }

inline int set_basis(c::vector<long double> *v, size_t i, long double const &x) { return gsl_vector_long_double_set_basis(v,i); }

inline int set_basis(c::vector<int> *v, size_t i, int const &x) { return gsl_vector_int_set_basis(v,i); }

inline int set_basis(c::vector<unsigned> *v, size_t i, unsigned const &x) { return gsl_vector_uint_set_basis(v,i); }

inline int set_basis(c::vector<long> *v, size_t i, long const &x) { return gsl_vector_long_set_basis(v,i); }

inline int set_basis(c::vector<unsigned long> *v, size_t i, unsigned long const &x) { return gsl_vector_ulong_set_basis(v,i); }

inline int set_basis(c::vector<short> *v, size_t i, short const &x) { return gsl_vector_short_set_basis(v,i); }

inline int set_basis(c::vector<unsigned short> *v, size_t i, unsigned short const &x) { return gsl_vector_ushort_set_basis(v,i); }

inline int set_basis(c::vector<char> *v, size_t i, char const &x) { return gsl_vector_char_set_basis(v,i); }

inline int set_basis(c::vector<unsigned char> *v, size_t i, unsigned char const &x) { return gsl_vector_uchar_set_basis(v,i); }

inline int set_basis(c::vector<gsl_complex> *v, size_t i, gsl_complex const &x) { return gsl_vector_complex_set_basis(v,i); }

inline int set_basis(c::vector<gsl_complex_float> *v, size_t i, gsl_complex_float const &x) { return gsl_vector_complex_float_set_basis(v,i); }

inline int set_basis(c::vector<gsl_complex_long_double> *v, size_t i, gsl_complex_long_double const &x) { return gsl_vector_complex_long_double_set_basis(v,i); }


} // namespace gsl::c

// EOF
