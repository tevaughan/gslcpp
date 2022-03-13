/// @file       include/gslcpp/wrap/real.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gsl::w_real().

#pragma once
#include "container.hpp" // w_vector

namespace gsl {


/// Real-part of complex vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_complex_real
/// @param u  Pointer to vector.
inline gsl_vector_view w_real(w_vector<complex<double>> *u) {
  return gsl_vector_complex_real(u);
}


/// Real-part of complex vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_complex_real
/// @param u  Pointer to vector.
inline gsl_vector_float_view w_real(w_vector<complex<float>> *u) {
  return gsl_vector_complex_float_real(u);
}


/// Real-part of complex vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_complex_real
/// @param u  Pointer to vector.
inline gsl_vector_long_double_view w_real(w_vector<complex<long double>> *u) {
  return gsl_vector_complex_long_double_real(u);
}


/// Real-part of complex vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_complex_real
/// @param u  Pointer to vector.
inline gsl_vector_const_view w_real(w_vector<complex<double>> const *u) {
  return gsl_vector_complex_const_real(u);
}


/// Real-part of complex vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_complex_real
/// @param u  Pointer to vector.
inline gsl_vector_float_const_view w_real(w_vector<complex<float>> const *u) {
  return gsl_vector_complex_float_const_real(u);
}


/// Real-part of complex vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_complex_real
/// @param u  Pointer to vector.
inline gsl_vector_long_double_const_view
w_real(w_vector<complex<long double>> const *u) {
  return gsl_vector_complex_long_double_const_real(u);
}


} // namespace gsl

// EOF
