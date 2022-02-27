/// \file       include/gslcpp/wrap/reverse.hpp
/// \copyright  2022 Thomas E. Vaughan
/// \brief      Definition of gsl::w_reverse().

#pragma once
#include "type-map.hpp"

namespace gsl {


/// Reverse order of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_reverse
/// @param v  Pointer to vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_reverse(w_vector<double> *v) { return gsl_vector_reverse(v); }


/// Reverse order of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_reverse
/// @param v  Pointer to vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_reverse(w_vector<float> *v) {
  return gsl_vector_float_reverse(v);
}


/// Reverse order of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_reverse
/// @param v  Pointer to vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_reverse(w_vector<long double> *v) {
  return gsl_vector_long_double_reverse(v);
}


/// Reverse order of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_reverse
/// @param v  Pointer to vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_reverse(w_vector<int> *v) { return gsl_vector_int_reverse(v); }


/// Reverse order of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_reverse
/// @param v  Pointer to vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_reverse(w_vector<unsigned> *v) {
  return gsl_vector_uint_reverse(v);
}


/// Reverse order of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_reverse
/// @param v  Pointer to vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_reverse(w_vector<long> *v) { return gsl_vector_long_reverse(v); }


/// Reverse order of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_reverse
/// @param v  Pointer to vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_reverse(w_vector<unsigned long> *v) {
  return gsl_vector_ulong_reverse(v);
}


/// Reverse order of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_reverse
/// @param v  Pointer to vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_reverse(w_vector<short> *v) {
  return gsl_vector_short_reverse(v);
}


/// Reverse order of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_reverse
/// @param v  Pointer to vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_reverse(w_vector<unsigned short> *v) {
  return gsl_vector_ushort_reverse(v);
}


/// Reverse order of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_reverse
/// @param v  Pointer to vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_reverse(w_vector<char> *v) { return gsl_vector_char_reverse(v); }


/// Reverse order of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_reverse
/// @param v  Pointer to vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_reverse(w_vector<unsigned char> *v) {
  return gsl_vector_uchar_reverse(v);
}


/// Reverse order of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_reverse
/// @param v  Pointer to vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_reverse(w_vector<gsl_complex> *v) {
  return gsl_vector_complex_reverse(v);
}


/// Reverse order of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_reverse
/// @param v  Pointer to vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_reverse(w_vector<gsl_complex_float> *v) {
  return gsl_vector_complex_float_reverse(v);
}


/// Reverse order of elements in vector `v`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_reverse
/// @param v  Pointer to vector.
/// @return  TBD: GSL's documentation does not specify.
inline int w_reverse(w_vector<gsl_complex_long_double> *v) {
  return gsl_vector_complex_long_double_reverse(v);
}


} // namespace gsl

// EOF
