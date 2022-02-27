/// \file       include/gslcpp/c/set-zero.hpp
/// \copyright  2022 Thomas E. Vaughan
/// \brief      Definition of gsl::c::set_zero().

#pragma once
#include "type-map.hpp"

namespace gsl::c {


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void set_zero(c::vector<double> *v) { gsl_vector_set_zero(v); }


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void set_zero(c::vector<float> *v) { gsl_vector_float_set_zero(v); }


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void set_zero(c::vector<long double> *v) {
  gsl_vector_long_double_set_zero(v);
}


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void set_zero(c::vector<int> *v) { gsl_vector_int_set_zero(v); }


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void set_zero(c::vector<unsigned> *v) { gsl_vector_uint_set_zero(v); }


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void set_zero(c::vector<long> *v) { gsl_vector_long_set_zero(v); }


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void set_zero(c::vector<unsigned long> *v) {
  gsl_vector_ulong_set_zero(v);
}


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void set_zero(c::vector<short> *v) { gsl_vector_short_set_zero(v); }


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void set_zero(c::vector<unsigned short> *v) {
  gsl_vector_ushort_set_zero(v);
}


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void set_zero(c::vector<char> *v) { gsl_vector_char_set_zero(v); }


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void set_zero(c::vector<unsigned char> *v) {
  gsl_vector_uchar_set_zero(v);
}


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void set_zero(c::vector<gsl_complex> *v) {
  gsl_vector_complex_set_zero(v);
}


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void set_zero(c::vector<gsl_complex_float> *v) {
  gsl_vector_complex_float_set_zero(v);
}


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void set_zero(c::vector<gsl_complex_long_double> *v) {
  gsl_vector_complex_long_double_set_zero(v);
}


} // namespace gsl::c

// EOF
