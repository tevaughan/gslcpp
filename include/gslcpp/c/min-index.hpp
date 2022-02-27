/// \file       include/gslcpp/c/min-index.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::c::min_index().

#pragma once
#include "type-map.hpp" // vector

namespace gsl::c {


/// Index of minimum value in vector `v`.
/// When several equal minimum elements are found, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min_index
/// @param v  Pointer to vector.
/// @return  Index of minimum value in `v`.
inline size_t min_index(c::vector<double const> *v) {
  return gsl_vector_min_index(v);
}


/// Index of minimum value in vector `v`.
/// When several equal minimum elements are found, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min_index
/// @param v  Pointer to vector.
/// @return  Index of minimum value in `v`.
inline size_t min_index(c::vector<float const> *v) {
  return gsl_vector_float_min_index(v);
}


/// Index of minimum value in vector `v`.
/// When several equal minimum elements are found, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min_index
/// @param v  Pointer to vector.
/// @return  Index of minimum value in `v`.
inline size_t min_index(c::vector<long double const> *v) {
  return gsl_vector_long_double_min_index(v);
}


/// Index of minimum value in vector `v`.
/// When several equal minimum elements are found, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min_index
/// @param v  Pointer to vector.
/// @return  Index of minimum value in `v`.
inline size_t min_index(c::vector<int const> *v) {
  return gsl_vector_int_min_index(v);
}


/// Index of minimum value in vector `v`.
/// When several equal minimum elements are found, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min_index
/// @param v  Pointer to vector.
/// @return  Index of minimum value in `v`.
inline size_t min_index(c::vector<unsigned const> *v) {
  return gsl_vector_uint_min_index(v);
}


/// Index of minimum value in vector `v`.
/// When several equal minimum elements are found, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min_index
/// @param v  Pointer to vector.
/// @return  Index of minimum value in `v`.
inline size_t min_index(c::vector<long const> *v) {
  return gsl_vector_long_min_index(v);
}


/// Index of minimum value in vector `v`.
/// When several equal minimum elements are found, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min_index
/// @param v  Pointer to vector.
/// @return  Index of minimum value in `v`.
inline size_t min_index(c::vector<unsigned long const> *v) {
  return gsl_vector_ulong_min_index(v);
}


/// Index of minimum value in vector `v`.
/// When several equal minimum elements are found, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min_index
/// @param v  Pointer to vector.
/// @return  Index of minimum value in `v`.
inline size_t min_index(c::vector<short const> *v) {
  return gsl_vector_short_min_index(v);
}


/// Index of minimum value in vector `v`.
/// When several equal minimum elements are found, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min_index
/// @param v  Pointer to vector.
/// @return  Index of minimum value in `v`.
inline size_t min_index(c::vector<unsigned short const> *v) {
  return gsl_vector_ushort_min_index(v);
}


/// Index of minimum value in vector `v`.
/// When several equal minimum elements are found, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min_index
/// @param v  Pointer to vector.
/// @return  Index of minimum value in `v`.
inline size_t min_index(c::vector<char const> *v) {
  return gsl_vector_char_min_index(v);
}


/// Index of minimum value in vector `v`.
/// When several equal minimum elements are found, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min_index
/// @param v  Pointer to vector.
/// @return  Index of minimum value in `v`.
inline size_t min_index(c::vector<unsigned char const> *v) {
  return gsl_vector_uchar_min_index(v);
}

} // namespace gsl::c

// EOF
