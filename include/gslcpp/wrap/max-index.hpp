/// \file       include/gslcpp/wrap/max-index.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_max_index().

#pragma once
#include "container.hpp" // w_vector // vector

namespace gsl {


/// Index of maximum value in vector `v`.
/// When there are several equal maximum elements, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max_index
/// @param v  Pointer to vector.
/// @return  Index of maximum value in `v`.
inline auto w_max_index(w_vector<double const> *v) {
  return gsl_vector_max_index(v);
}


/// Index of maximum value in vector `v`.
/// When there are several equal maximum elements, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max_index
/// @param v  Pointer to vector.
/// @return  Index of maximum value in `v`.
inline auto w_max_index(w_vector<float const> *v) {
  return gsl_vector_float_max_index(v);
}


/// Index of maximum value in vector `v`.
/// When there are several equal maximum elements, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max_index
/// @param v  Pointer to vector.
/// @return  Index of maximum value in `v`.
inline auto w_max_index(w_vector<long double const> *v) {
  return gsl_vector_long_double_max_index(v);
}


/// Index of maximum value in vector `v`.
/// When there are several equal maximum elements, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max_index
/// @param v  Pointer to vector.
/// @return  Index of maximum value in `v`.
inline auto w_max_index(w_vector<int const> *v) {
  return gsl_vector_int_max_index(v);
}


/// Index of maximum value in vector `v`.
/// When there are several equal maximum elements, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max_index
/// @param v  Pointer to vector.
/// @return  Index of maximum value in `v`.
inline auto w_max_index(w_vector<unsigned const> *v) {
  return gsl_vector_uint_max_index(v);
}


/// Index of maximum value in vector `v`.
/// When there are several equal maximum elements, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max_index
/// @param v  Pointer to vector.
/// @return  Index of maximum value in `v`.
inline auto w_max_index(w_vector<long const> *v) {
  return gsl_vector_long_max_index(v);
}


/// Index of maximum value in vector `v`.
/// When there are several equal maximum elements, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max_index
/// @param v  Pointer to vector.
/// @return  Index of maximum value in `v`.
inline auto w_max_index(w_vector<unsigned long const> *v) {
  return gsl_vector_ulong_max_index(v);
}


/// Index of maximum value in vector `v`.
/// When there are several equal maximum elements, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max_index
/// @param v  Pointer to vector.
/// @return  Index of maximum value in `v`.
inline auto w_max_index(w_vector<short const> *v) {
  return gsl_vector_short_max_index(v);
}


/// Index of maximum value in vector `v`.
/// When there are several equal maximum elements, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max_index
/// @param v  Pointer to vector.
/// @return  Index of maximum value in `v`.
inline auto w_max_index(w_vector<unsigned short const> *v) {
  return gsl_vector_ushort_max_index(v);
}


/// Index of maximum value in vector `v`.
/// When there are several equal maximum elements, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max_index
/// @param v  Pointer to vector.
/// @return  Index of maximum value in `v`.
inline auto w_max_index(w_vector<char const> *v) {
  return gsl_vector_char_max_index(v);
}


/// Index of maximum value in vector `v`.
/// When there are several equal maximum elements, lowest index is returned.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max_index
/// @param v  Pointer to vector.
/// @return  Index of maximum value in `v`.
inline auto w_max_index(w_vector<unsigned char const> *v) {
  return gsl_vector_uchar_max_index(v);
}

} // namespace gsl

// EOF
