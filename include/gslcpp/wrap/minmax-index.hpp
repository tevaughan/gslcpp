/// \file       include/gslcpp/wrap/minmax-index.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_minmax_index().

#pragma once
#include "type-map.hpp" // vector

namespace gsl {


/// Return indices of minimum and maximum values in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_minmax_index
/// @param v  Pointer to vector.
/// @param min  Pointer to storage for offset of minimum value.
/// @param max  Pointer to storage ofo offset of maximum value.
inline void
w_minmax_index(w_vector<double const> *v, size_t *min, size_t *max) {
  return gsl_vector_minmax_index(v, min, max);
}


/// Return indices of minimum and maximum values in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_minmax_index
/// @param v  Pointer to vector.
/// @param min  Pointer to storage for offset of minimum value.
/// @param max  Pointer to storage ofo offset of maximum value.
inline void
w_minmax_index(w_vector<float const> *v, size_t *min, size_t *max) {
  return gsl_vector_float_minmax_index(v, min, max);
}


/// Return indices of minimum and maximum values in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_minmax_index
/// @param v  Pointer to vector.
/// @param min  Pointer to storage for offset of minimum value.
/// @param max  Pointer to storage ofo offset of maximum value.
inline void
w_minmax_index(w_vector<long double const> *v, size_t *min, size_t *max) {
  return gsl_vector_long_double_minmax_index(v, min, max);
}


/// Return indices of minimum and maximum values in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_minmax_index
/// @param v  Pointer to vector.
/// @param min  Pointer to storage for offset of minimum value.
/// @param max  Pointer to storage ofo offset of maximum value.
inline void w_minmax_index(w_vector<int const> *v, size_t *min, size_t *max) {
  return gsl_vector_int_minmax_index(v, min, max);
}


/// Return indices of minimum and maximum values in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_minmax_index
/// @param v  Pointer to vector.
/// @param min  Pointer to storage for offset of minimum value.
/// @param max  Pointer to storage ofo offset of maximum value.
inline void
w_minmax_index(w_vector<unsigned const> *v, size_t *min, size_t *max) {
  return gsl_vector_uint_minmax_index(v, min, max);
}


/// Return indices of minimum and maximum values in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_minmax_index
/// @param v  Pointer to vector.
/// @param min  Pointer to storage for offset of minimum value.
/// @param max  Pointer to storage ofo offset of maximum value.
inline void w_minmax_index(w_vector<long const> *v, size_t *min, size_t *max) {
  return gsl_vector_long_minmax_index(v, min, max);
}


/// Return indices of minimum and maximum values in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_minmax_index
/// @param v  Pointer to vector.
/// @param min  Pointer to storage for offset of minimum value.
/// @param max  Pointer to storage ofo offset of maximum value.
inline void
w_minmax_index(w_vector<unsigned long const> *v, size_t *min, size_t *max) {
  return gsl_vector_ulong_minmax_index(v, min, max);
}


/// Return indices of minimum and maximum values in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_minmax_index
/// @param v  Pointer to vector.
/// @param min  Pointer to storage for offset of minimum value.
/// @param max  Pointer to storage ofo offset of maximum value.
inline void
w_minmax_index(w_vector<short const> *v, size_t *min, size_t *max) {
  return gsl_vector_short_minmax_index(v, min, max);
}


/// Return indices of minimum and maximum values in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_minmax_index
/// @param v  Pointer to vector.
/// @param min  Pointer to storage for offset of minimum value.
/// @param max  Pointer to storage ofo offset of maximum value.
inline void
w_minmax_index(w_vector<unsigned short const> *v, size_t *min, size_t *max) {
  return gsl_vector_ushort_minmax_index(v, min, max);
}


/// Return indices of minimum and maximum values in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_minmax_index
/// @param v  Pointer to vector.
/// @param min  Pointer to storage for offset of minimum value.
/// @param max  Pointer to storage ofo offset of maximum value.
inline void w_minmax_index(w_vector<char const> *v, size_t *min, size_t *max) {
  return gsl_vector_char_minmax_index(v, min, max);
}


/// Return indices of minimum and maximum values in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_minmax_index
/// @param v  Pointer to vector.
/// @param min  Pointer to storage for offset of minimum value.
/// @param max  Pointer to storage ofo offset of maximum value.
inline void
w_minmax_index(w_vector<unsigned char const> *v, size_t *min, size_t *max) {
  return gsl_vector_uchar_minmax_index(v, min, max);
}

} // namespace gsl

// EOF
