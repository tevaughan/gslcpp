/// \file       include/gslcpp/wrap/minmax.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_minmax().

#pragma once
#include "container.hpp" // w_vector // vector

namespace gsl {


/// Return minimum and maximum values in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_minmax
/// @param v  Pointer to vector.
/// @param min  Pointer to storage for minimum value.
/// @param max  Pointer to storage for maximum value.
inline void w_minmax(w_vector<double const> *v, double *min, double *max) {
  return gsl_vector_minmax(v, min, max);
}


/// Return minimum and maximum values in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_minmax
/// @param v  Pointer to vector.
/// @param min  Pointer to storage for minimum value.
/// @param max  Pointer to storage for maximum value.
inline void w_minmax(w_vector<float const> *v, float *min, float *max) {
  return gsl_vector_float_minmax(v, min, max);
}


/// Return minimum and maximum values in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_minmax
/// @param v  Pointer to vector.
/// @param min  Pointer to storage for minimum value.
/// @param max  Pointer to storage for maximum value.
inline void
w_minmax(w_vector<long double const> *v, long double *min, long double *max) {
  return gsl_vector_long_double_minmax(v, min, max);
}


/// Return minimum and maximum values in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_minmax
/// @param v  Pointer to vector.
/// @param min  Pointer to storage for minimum value.
/// @param max  Pointer to storage for maximum value.
inline void w_minmax(w_vector<int const> *v, int *min, int *max) {
  return gsl_vector_int_minmax(v, min, max);
}


/// Return minimum and maximum values in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_minmax
/// @param v  Pointer to vector.
/// @param min  Pointer to storage for minimum value.
/// @param max  Pointer to storage for maximum value.
inline void
w_minmax(w_vector<unsigned const> *v, unsigned *min, unsigned *max) {
  return gsl_vector_uint_minmax(v, min, max);
}


/// Return minimum and maximum values in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_minmax
/// @param v  Pointer to vector.
/// @param min  Pointer to storage for minimum value.
/// @param max  Pointer to storage for maximum value.
inline void w_minmax(w_vector<long const> *v, long *min, long *max) {
  return gsl_vector_long_minmax(v, min, max);
}


/// Return minimum and maximum values in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_minmax
/// @param v  Pointer to vector.
/// @param min  Pointer to storage for minimum value.
/// @param max  Pointer to storage for maximum value.
inline void w_minmax(
      w_vector<unsigned long const> *v,
      unsigned long *min,
      unsigned long *max) {
  return gsl_vector_ulong_minmax(v, min, max);
}


/// Return minimum and maximum values in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_minmax
/// @param v  Pointer to vector.
/// @param min  Pointer to storage for minimum value.
/// @param max  Pointer to storage for maximum value.
inline void w_minmax(w_vector<short const> *v, short *min, short *max) {
  return gsl_vector_short_minmax(v, min, max);
}


/// Return minimum and maximum values in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_minmax
/// @param v  Pointer to vector.
/// @param min  Pointer to storage for minimum value.
/// @param max  Pointer to storage for maximum value.
inline void w_minmax(
      w_vector<unsigned short const> *v,
      unsigned short *min,
      unsigned short *max) {
  return gsl_vector_ushort_minmax(v, min, max);
}


/// Return minimum and maximum values in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_minmax
/// @param v  Pointer to vector.
/// @param min  Pointer to storage for minimum value.
/// @param max  Pointer to storage for maximum value.
inline void w_minmax(w_vector<char const> *v, char *min, char *max) {
  return gsl_vector_char_minmax(v, min, max);
}


/// Return minimum and maximum values in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_minmax
/// @param v  Pointer to vector.
/// @param min  Pointer to storage for minimum value.
/// @param max  Pointer to storage for maximum value.
inline void w_minmax(
      w_vector<unsigned char const> *v,
      unsigned char *min,
      unsigned char *max) {
  return gsl_vector_uchar_minmax(v, min, max);
}


} // namespace gsl

// EOF
