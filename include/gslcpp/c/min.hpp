/// \file       include/gslcpp/c/min.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::c::min().

#pragma once
#include "type-map.hpp" // vector

namespace gsl::c {


/// Minimum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min
/// @param v  Pointer to vector.
/// @return  Minimum value in `v`.
inline double min(c::vector<double const> *v) { return gsl_vector_min(v); }


/// Minimum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min
/// @param v  Pointer to vector.
/// @return  Minimum value in `v`.
inline float min(c::vector<float const> *v) { return gsl_vector_float_min(v); }


/// Minimum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min
/// @param v  Pointer to vector.
/// @return  Minimum value in `v`.
inline long double min(c::vector<long double const> *v) {
  return gsl_vector_long_double_min(v);
}


/// Minimum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min
/// @param v  Pointer to vector.
/// @return  Minimum value in `v`.
inline int min(c::vector<int const> *v) { return gsl_vector_int_min(v); }


/// Minimum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min
/// @param v  Pointer to vector.
/// @return  Minimum value in `v`.
inline unsigned min(c::vector<unsigned const> *v) {
  return gsl_vector_uint_min(v);
}


/// Minimum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min
/// @param v  Pointer to vector.
/// @return  Minimum value in `v`.
inline long min(c::vector<long const> *v) { return gsl_vector_long_min(v); }


/// Minimum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min
/// @param v  Pointer to vector.
/// @return  Minimum value in `v`.
inline unsigned long min(c::vector<unsigned long const> *v) {
  return gsl_vector_ulong_min(v);
}


/// Minimum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min
/// @param v  Pointer to vector.
/// @return  Minimum value in `v`.
inline short min(c::vector<short const> *v) { return gsl_vector_short_min(v); }


/// Minimum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min
/// @param v  Pointer to vector.
/// @return  Minimum value in `v`.
inline unsigned short min(c::vector<unsigned short const> *v) {
  return gsl_vector_ushort_min(v);
}


/// Minimum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min
/// @param v  Pointer to vector.
/// @return  Minimum value in `v`.
inline char min(c::vector<char const> *v) { return gsl_vector_char_min(v); }


/// Minimum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min
/// @param v  Pointer to vector.
/// @return  Minimum value in `v`.
inline unsigned char min(c::vector<unsigned char const> *v) {
  return gsl_vector_uchar_min(v);
}

} // namespace gsl::c

// EOF
