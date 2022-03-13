/// \file       include/gslcpp/wrap/max.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_max().

#pragma once
#include "container.hpp" // w_vector // vector

namespace gsl {


/// Maximum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max
/// @param v  Pointer to vector.
/// @return  Maximum value in `v`.
inline auto w_max(w_vector<double const> *v) { return gsl_vector_max(v); }


/// Maximum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max
/// @param v  Pointer to vector.
/// @return  Maximum value in `v`.
inline auto w_max(w_vector<float const> *v) { return gsl_vector_float_max(v); }


/// Maximum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max
/// @param v  Pointer to vector.
/// @return  Maximum value in `v`.
inline auto w_max(w_vector<long double const> *v) {
  return gsl_vector_long_double_max(v);
}


/// Maximum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max
/// @param v  Pointer to vector.
/// @return  Maximum value in `v`.
inline auto w_max(w_vector<int const> *v) { return gsl_vector_int_max(v); }


/// Maximum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max
/// @param v  Pointer to vector.
/// @return  Maximum value in `v`.
inline auto w_max(w_vector<unsigned const> *v) {
  return gsl_vector_uint_max(v);
}


/// Maximum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max
/// @param v  Pointer to vector.
/// @return  Maximum value in `v`.
inline auto w_max(w_vector<long const> *v) { return gsl_vector_long_max(v); }


/// Maximum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max
/// @param v  Pointer to vector.
/// @return  Maximum value in `v`.
inline auto w_max(w_vector<unsigned long const> *v) {
  return gsl_vector_ulong_max(v);
}


/// Maximum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max
/// @param v  Pointer to vector.
/// @return  Maximum value in `v`.
inline auto w_max(w_vector<short const> *v) { return gsl_vector_short_max(v); }


/// Maximum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max
/// @param v  Pointer to vector.
/// @return  Maximum value in `v`.
inline auto w_max(w_vector<unsigned short const> *v) {
  return gsl_vector_ushort_max(v);
}


/// Maximum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max
/// @param v  Pointer to vector.
/// @return  Maximum value in `v`.
inline auto w_max(w_vector<char const> *v) { return gsl_vector_char_max(v); }


/// Maximum value in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_max
/// @param v  Pointer to vector.
/// @return  Maximum value in `v`.
inline auto w_max(w_vector<unsigned char const> *v) {
  return gsl_vector_uchar_max(v);
}


} // namespace gsl

// EOF
