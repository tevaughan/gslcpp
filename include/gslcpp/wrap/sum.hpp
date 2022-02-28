/// \file       include/gslcpp/wrap/sum.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_sum().

#pragma once
#include "compat.hpp" // GSL_AT_LEAST(), sum_for_gsl_lt_2p7()
#include "container.hpp" // w_vector // vector

namespace gsl {

#if GSL_AT_LEAST(2, 7)


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline double w_sum(w_vector<double const> *v) { return gsl_vector_sum(v); }


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline float w_sum(w_vector<float const> *v) {
  return gsl_vector_float_sum(v);
}


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline long double w_sum(w_vector<long double const> *v) {
  return gsl_vector_long_double_sum(v);
}


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline int w_sum(w_vector<int const> *v) { return gsl_vector_int_sum(v); }


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline unsigned w_sum(w_vector<unsigned const> *v) {
  return gsl_vector_uint_sum(v);
}


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline long w_sum(w_vector<long const> *v) { return gsl_vector_long_sum(v); }


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline unsigned long w_sum(w_vector<unsigned long const> *v) {
  return gsl_vector_ulong_sum(v);
}


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline short w_sum(w_vector<short const> *v) {
  return gsl_vector_short_sum(v);
}


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline unsigned short w_sum(w_vector<unsigned short const> *v) {
  return gsl_vector_ushort_sum(v);
}


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline char w_sum(w_vector<char const> *v) { return gsl_vector_char_sum(v); }


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline unsigned char w_sum(w_vector<unsigned char const> *v) {
  return gsl_vector_uchar_sum(v);
}


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline gsl_complex w_sum(w_vector<gsl_complex const> *v) {
  return gsl_vector_complex_sum(v);
}


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline gsl_complex_float w_sum(w_vector<gsl_complex_float const> *v) {
  return gsl_vector_complex_float_sum(v);
}


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
inline gsl_complex_long_double
w_sum(w_vector<gsl_complex_long_double const> *v) {
  return gsl_vector_complex_long_double_sum(v);
}


#else


/// Sum of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_sum
/// @param v  Pointer to vector.
/// @return  Sum of elements in `v`.
template<typename V> auto w_sum(V *v) { return sum_for_gsl_lt_2p7(*v); }


#endif


} // namespace gsl

// EOF
