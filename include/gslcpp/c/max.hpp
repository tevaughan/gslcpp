/// \file       include/gslcpp/c/max.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::c::max().

#pragma once
#include "type-map.hpp" // vector

namespace gsl::c {


/// Maximum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max
/// @param v  Pointer to vector.
/// @return  Maximum value in `v`.
inline double max(c::vector<double const> *v) { return gsl_vector_max(v); }


/// Maximum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max
/// @param v  Pointer to vector.
/// @return  Maximum value in `v`.
inline float max(c::vector<float const> *v) { return gsl_vector_float_max(v); }


/// Maximum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max
/// @param v  Pointer to vector.
/// @return  Maximum value in `v`.
inline long double max(c::vector<long double const> *v) {
  return gsl_vector_long_double_max(v);
}


/// Maximum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max
/// @param v  Pointer to vector.
/// @return  Maximum value in `v`.
inline int max(c::vector<int const> *v) { return gsl_vector_int_max(v); }


/// Maximum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max
/// @param v  Pointer to vector.
/// @return  Maximum value in `v`.
inline unsigned max(c::vector<unsigned const> *v) {
  return gsl_vector_uint_max(v);
}


/// Maximum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max
/// @param v  Pointer to vector.
/// @return  Maximum value in `v`.
inline long max(c::vector<long const> *v) { return gsl_vector_long_max(v); }


/// Maximum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max
/// @param v  Pointer to vector.
/// @return  Maximum value in `v`.
inline unsigned long max(c::vector<unsigned long const> *v) {
  return gsl_vector_ulong_max(v);
}


/// Maximum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max
/// @param v  Pointer to vector.
/// @return  Maximum value in `v`.
inline short max(c::vector<short const> *v) { return gsl_vector_short_max(v); }


/// Maximum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max
/// @param v  Pointer to vector.
/// @return  Maximum value in `v`.
inline unsigned short max(c::vector<unsigned short const> *v) {
  return gsl_vector_ushort_max(v);
}


/// Maximum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max
/// @param v  Pointer to vector.
/// @return  Maximum value in `v`.
inline char max(c::vector<char const> *v) { return gsl_vector_char_max(v); }


/// Maximum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max
/// @param v  Pointer to vector.
/// @return  Maximum value in `v`.
inline unsigned char max(c::vector<unsigned char const> *v) {
  return gsl_vector_uchar_max(v);
}


} // namespace gsl::c

// EOF
