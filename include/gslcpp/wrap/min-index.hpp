/// \file       include/gslcpp/wrap/min-index.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_min_index().

#pragma once
#include "container.hpp" // w_vector // vector

namespace gsl {


/// Index of minimum value in vector `v`.
/// When several equal minimum elements are found, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min_index
/// @param v  Pointer to vector.
/// @return  Index of minimum value in `v`.
inline size_t w_min_index(w_vector<double const> *v) {
  return gsl_vector_min_index(v);
}


/// Index of minimum value in vector `v`.
/// When several equal minimum elements are found, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min_index
/// @param v  Pointer to vector.
/// @return  Index of minimum value in `v`.
inline size_t w_min_index(w_vector<float const> *v) {
  return gsl_vector_float_min_index(v);
}


/// Index of minimum value in vector `v`.
/// When several equal minimum elements are found, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min_index
/// @param v  Pointer to vector.
/// @return  Index of minimum value in `v`.
inline size_t w_min_index(w_vector<long double const> *v) {
  return gsl_vector_long_double_min_index(v);
}


/// Index of minimum value in vector `v`.
/// When several equal minimum elements are found, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min_index
/// @param v  Pointer to vector.
/// @return  Index of minimum value in `v`.
inline size_t w_min_index(w_vector<int const> *v) {
  return gsl_vector_int_min_index(v);
}


/// Index of minimum value in vector `v`.
/// When several equal minimum elements are found, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min_index
/// @param v  Pointer to vector.
/// @return  Index of minimum value in `v`.
inline size_t w_min_index(w_vector<unsigned const> *v) {
  return gsl_vector_uint_min_index(v);
}


/// Index of minimum value in vector `v`.
/// When several equal minimum elements are found, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min_index
/// @param v  Pointer to vector.
/// @return  Index of minimum value in `v`.
inline size_t w_min_index(w_vector<long const> *v) {
  return gsl_vector_long_min_index(v);
}


/// Index of minimum value in vector `v`.
/// When several equal minimum elements are found, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min_index
/// @param v  Pointer to vector.
/// @return  Index of minimum value in `v`.
inline size_t w_min_index(w_vector<unsigned long const> *v) {
  return gsl_vector_ulong_min_index(v);
}


/// Index of minimum value in vector `v`.
/// When several equal minimum elements are found, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min_index
/// @param v  Pointer to vector.
/// @return  Index of minimum value in `v`.
inline size_t w_min_index(w_vector<short const> *v) {
  return gsl_vector_short_min_index(v);
}


/// Index of minimum value in vector `v`.
/// When several equal minimum elements are found, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min_index
/// @param v  Pointer to vector.
/// @return  Index of minimum value in `v`.
inline size_t w_min_index(w_vector<unsigned short const> *v) {
  return gsl_vector_ushort_min_index(v);
}


/// Index of minimum value in vector `v`.
/// When several equal minimum elements are found, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min_index
/// @param v  Pointer to vector.
/// @return  Index of minimum value in `v`.
inline size_t w_min_index(w_vector<char const> *v) {
  return gsl_vector_char_min_index(v);
}


/// Index of minimum value in vector `v`.
/// When several equal minimum elements are found, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_min_index
/// @param v  Pointer to vector.
/// @return  Index of minimum value in `v`.
inline size_t w_min_index(w_vector<unsigned char const> *v) {
  return gsl_vector_uchar_min_index(v);
}

} // namespace gsl

// EOF
