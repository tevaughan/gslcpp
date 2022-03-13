/// \file       include/gslcpp/wrap/sum.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_sum().

#pragma once
#include "container.hpp" // w_vector // vector

namespace gsl {


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<double const> *v) { return gsl_vector_sum(v); }


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<float const> *v) { return gsl_vector_float_sum(v); }


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<long double const> *v) {
  return gsl_vector_long_double_sum(v);
}


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<int const> *v) { return gsl_vector_int_sum(v); }


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<unsigned const> *v) {
  return gsl_vector_uint_sum(v);
}


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<long const> *v) { return gsl_vector_long_sum(v); }


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<unsigned long const> *v) {
  return gsl_vector_ulong_sum(v);
}


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<short const> *v) { return gsl_vector_short_sum(v); }


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<unsigned short const> *v) {
  return gsl_vector_ushort_sum(v);
}


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<char const> *v) { return gsl_vector_char_sum(v); }


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline auto w_sum(w_vector<unsigned char const> *v) {
  return gsl_vector_uchar_sum(v);
}


} // namespace gsl

// EOF
