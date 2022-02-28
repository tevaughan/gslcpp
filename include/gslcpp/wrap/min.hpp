/// \file       include/gslcpp/wrap/min.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_min().

#pragma once
#include "container.hpp" // w_vector // vector

namespace gsl {


/// Minimum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min
/// @param v  Pointer to vector.
/// @return  Minimum value in `v`.
inline double w_min(w_vector<double const> *v) { return gsl_vector_min(v); }


/// Minimum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min
/// @param v  Pointer to vector.
/// @return  Minimum value in `v`.
inline float w_min(w_vector<float const> *v) {
  return gsl_vector_float_min(v);
}


/// Minimum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min
/// @param v  Pointer to vector.
/// @return  Minimum value in `v`.
inline long double w_min(w_vector<long double const> *v) {
  return gsl_vector_long_double_min(v);
}


/// Minimum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min
/// @param v  Pointer to vector.
/// @return  Minimum value in `v`.
inline int w_min(w_vector<int const> *v) { return gsl_vector_int_min(v); }


/// Minimum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min
/// @param v  Pointer to vector.
/// @return  Minimum value in `v`.
inline unsigned w_min(w_vector<unsigned const> *v) {
  return gsl_vector_uint_min(v);
}


/// Minimum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min
/// @param v  Pointer to vector.
/// @return  Minimum value in `v`.
inline long w_min(w_vector<long const> *v) { return gsl_vector_long_min(v); }


/// Minimum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min
/// @param v  Pointer to vector.
/// @return  Minimum value in `v`.
inline unsigned long w_min(w_vector<unsigned long const> *v) {
  return gsl_vector_ulong_min(v);
}


/// Minimum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min
/// @param v  Pointer to vector.
/// @return  Minimum value in `v`.
inline short w_min(w_vector<short const> *v) {
  return gsl_vector_short_min(v);
}


/// Minimum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min
/// @param v  Pointer to vector.
/// @return  Minimum value in `v`.
inline unsigned short w_min(w_vector<unsigned short const> *v) {
  return gsl_vector_ushort_min(v);
}


/// Minimum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min
/// @param v  Pointer to vector.
/// @return  Minimum value in `v`.
inline char w_min(w_vector<char const> *v) { return gsl_vector_char_min(v); }


/// Minimum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min
/// @param v  Pointer to vector.
/// @return  Minimum value in `v`.
inline unsigned char w_min(w_vector<unsigned char const> *v) {
  return gsl_vector_uchar_min(v);
}

} // namespace gsl

// EOF
