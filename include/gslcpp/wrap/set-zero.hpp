/// \file       include/gslcpp/wrap/set-zero.hpp
/// \copyright  2022 Thomas E. Vaughan
/// \brief      Definition of gsl::w_set_zero().

#pragma once
#include "container.hpp" // w_vector

namespace gsl {


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void w_set_zero(w_vector<double> *v) { gsl_vector_set_zero(v); }


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void w_set_zero(w_vector<float> *v) { gsl_vector_float_set_zero(v); }


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void w_set_zero(w_vector<long double> *v) {
  gsl_vector_long_double_set_zero(v);
}


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void w_set_zero(w_vector<int> *v) { gsl_vector_int_set_zero(v); }


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void w_set_zero(w_vector<unsigned> *v) { gsl_vector_uint_set_zero(v); }


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void w_set_zero(w_vector<long> *v) { gsl_vector_long_set_zero(v); }


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void w_set_zero(w_vector<unsigned long> *v) {
  gsl_vector_ulong_set_zero(v);
}


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void w_set_zero(w_vector<short> *v) { gsl_vector_short_set_zero(v); }


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void w_set_zero(w_vector<unsigned short> *v) {
  gsl_vector_ushort_set_zero(v);
}


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void w_set_zero(w_vector<char> *v) { gsl_vector_char_set_zero(v); }


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void w_set_zero(w_vector<unsigned char> *v) {
  gsl_vector_uchar_set_zero(v);
}


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void w_set_zero(w_vector<complex<double>> *v) {
  gsl_vector_complex_set_zero(v);
}


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void w_set_zero(w_vector<complex<float>> *v) {
  gsl_vector_complex_float_set_zero(v);
}


/// Set every element of vector `v` to zero.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_zero
/// @param v  Pointer to vector.
inline void w_set_zero(w_vector<complex<long double>> *v) {
  gsl_vector_complex_long_double_set_zero(v);
}


} // namespace gsl

// EOF
