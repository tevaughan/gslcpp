/// @file       include/gslcpp/c/axpby.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gsl::c::axpby().

#pragma once
#include "compat.hpp"
#include "type-map.hpp"

namespace gsl::c {

#if GSL_AT_LEAST(2, 7)


/// Perform the logical equivalent of `y = a*x + b*y`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_axpby
///
/// @param a  Coefficient of vector `x`.
/// @param x  Pointer to vector that is multiplied by `a`.
/// @param b  Coefficient of vector `y`.
/// @param y  Pointer to vector that is multiplied by `b` and then updated as
///           `a*x + b*y`.
/// @return  TBD: GSL's documentation does not specify.
inline int
axpby(double const &a,
      c::vector<double const> *x,
      double const &b,
      c::vector<double> *y) {
  return gsl_vector_axpby(a, x, b, y);
}


/// Perform the logical equivalent of `y = a*x + b*y`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_axpby
///
/// @param a  Coefficient of vector `x`.
/// @param x  Pointer to vector that is multiplied by `a`.
/// @param b  Coefficient of vector `y`.
/// @param y  Pointer to vector that is multiplied by `b` and then updated as
///           `a*x + b*y`.
/// @return  TBD: GSL's documentation does not specify.
inline int
axpby(float const &a,
      c::vector<float const> *x,
      float const &b,
      c::vector<float> *y) {
  return gsl_vector_float_axpby(a, x, b, y);
}


/// Perform the logical equivalent of `y = a*x + b*y`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_axpby
///
/// @param a  Coefficient of vector `x`.
/// @param x  Pointer to vector that is multiplied by `a`.
/// @param b  Coefficient of vector `y`.
/// @param y  Pointer to vector that is multiplied by `b` and then updated as
///           `a*x + b*y`.
/// @return  TBD: GSL's documentation does not specify.
inline int
axpby(long double const &a,
      c::vector<long double const> *x,
      long double const &b,
      c::vector<long double> *y) {
  return gsl_vector_long_double_axpby(a, x, b, y);
}


/// Perform the logical equivalent of `y = a*x + b*y`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_axpby
///
/// @param a  Coefficient of vector `x`.
/// @param x  Pointer to vector that is multiplied by `a`.
/// @param b  Coefficient of vector `y`.
/// @param y  Pointer to vector that is multiplied by `b` and then updated as
///           `a*x + b*y`.
/// @return  TBD: GSL's documentation does not specify.
inline int
axpby(int const &a, c::vector<int const> *x, int const &b, c::vector<int> *y) {
  return gsl_vector_int_axpby(a, x, b, y);
}


/// Perform the logical equivalent of `y = a*x + b*y`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_axpby
///
/// @param a  Coefficient of vector `x`.
/// @param x  Pointer to vector that is multiplied by `a`.
/// @param b  Coefficient of vector `y`.
/// @param y  Pointer to vector that is multiplied by `b` and then updated as
///           `a*x + b*y`.
/// @return  TBD: GSL's documentation does not specify.
inline int
axpby(unsigned const &a,
      c::vector<unsigned const> *x,
      unsigned const &b,
      c::vector<unsigned> *y) {
  return gsl_vector_uint_axpby(a, x, b, y);
}


/// Perform the logical equivalent of `y = a*x + b*y`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_axpby
///
/// @param a  Coefficient of vector `x`.
/// @param x  Pointer to vector that is multiplied by `a`.
/// @param b  Coefficient of vector `y`.
/// @param y  Pointer to vector that is multiplied by `b` and then updated as
///           `a*x + b*y`.
/// @return  TBD: GSL's documentation does not specify.
inline int
axpby(long const &a,
      c::vector<long const> *x,
      long const &b,
      c::vector<long> *y) {
  return gsl_vector_long_axpby(a, x, b, y);
}


/// Perform the logical equivalent of `y = a*x + b*y`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_axpby
///
/// @param a  Coefficient of vector `x`.
/// @param x  Pointer to vector that is multiplied by `a`.
/// @param b  Coefficient of vector `y`.
/// @param y  Pointer to vector that is multiplied by `b` and then updated as
///           `a*x + b*y`.
/// @return  TBD: GSL's documentation does not specify.
inline int
axpby(unsigned long const &a,
      c::vector<unsigned long const> *x,
      unsigned long const &b,
      c::vector<unsigned long> *y) {
  return gsl_vector_ulong_axpby(a, x, b, y);
}


/// Perform the logical equivalent of `y = a*x + b*y`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_axpby
///
/// @param a  Coefficient of vector `x`.
/// @param x  Pointer to vector that is multiplied by `a`.
/// @param b  Coefficient of vector `y`.
/// @param y  Pointer to vector that is multiplied by `b` and then updated as
///           `a*x + b*y`.
/// @return  TBD: GSL's documentation does not specify.
inline int
axpby(short const &a,
      c::vector<short const> *x,
      short const &b,
      c::vector<short> *y) {
  return gsl_vector_short_axpby(a, x, b, y);
}


/// Perform the logical equivalent of `y = a*x + b*y`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_axpby
///
/// @param a  Coefficient of vector `x`.
/// @param x  Pointer to vector that is multiplied by `a`.
/// @param b  Coefficient of vector `y`.
/// @param y  Pointer to vector that is multiplied by `b` and then updated as
///           `a*x + b*y`.
/// @return  TBD: GSL's documentation does not specify.
inline int
axpby(unsigned short const &a,
      c::vector<unsigned short const> *x,
      unsigned short const &b,
      c::vector<unsigned short> *y) {
  return gsl_vector_ushort_axpby(a, x, b, y);
}


/// Perform the logical equivalent of `y = a*x + b*y`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_axpby
///
/// @param a  Coefficient of vector `x`.
/// @param x  Pointer to vector that is multiplied by `a`.
/// @param b  Coefficient of vector `y`.
/// @param y  Pointer to vector that is multiplied by `b` and then updated as
///           `a*x + b*y`.
/// @return  TBD: GSL's documentation does not specify.
inline int
axpby(char const &a,
      c::vector<char const> *x,
      char const &b,
      c::vector<char> *y) {
  return gsl_vector_char_axpby(a, x, b, y);
}


/// Perform the logical equivalent of `y = a*x + b*y`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_axpby
///
/// @param a  Coefficient of vector `x`.
/// @param x  Pointer to vector that is multiplied by `a`.
/// @param b  Coefficient of vector `y`.
/// @param y  Pointer to vector that is multiplied by `b` and then updated as
///           `a*x + b*y`.
/// @return  TBD: GSL's documentation does not specify.
inline int
axpby(unsigned char const &a,
      c::vector<unsigned char const> *x,
      unsigned char const &b,
      c::vector<unsigned char> *y) {
  return gsl_vector_uchar_axpby(a, x, b, y);
}


/// Perform the logical equivalent of `y = a*x + b*y`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_axpby
///
/// @param a  Coefficient of vector `x`.
/// @param x  Pointer to vector that is multiplied by `a`.
/// @param b  Coefficient of vector `y`.
/// @param y  Pointer to vector that is multiplied by `b` and then updated as
///           `a*x + b*y`.
/// @return  TBD: GSL's documentation does not specify.
inline int
axpby(gsl_complex const &a,
      c::vector<gsl_complex const> *x,
      gsl_complex const &b,
      c::vector<gsl_complex> *y) {
  return gsl_vector_complex_axpby(a, x, b, y);
}


/// Perform the logical equivalent of `y = a*x + b*y`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_axpby
///
/// @param a  Coefficient of vector `x`.
/// @param x  Pointer to vector that is multiplied by `a`.
/// @param b  Coefficient of vector `y`.
/// @param y  Pointer to vector that is multiplied by `b` and then updated as
///           `a*x + b*y`.
/// @return  TBD: GSL's documentation does not specify.
inline int
axpby(gsl_complex_float const &a,
      c::vector<gsl_complex_float const> *x,
      gsl_complex_float const &b,
      c::vector<gsl_complex_float> *y) {
  return gsl_vector_complex_float_axpby(a, x, b, y);
}


/// Perform the logical equivalent of `y = a*x + b*y`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_axpby
///
/// @param a  Coefficient of vector `x`.
/// @param x  Pointer to vector that is multiplied by `a`.
/// @param b  Coefficient of vector `y`.
/// @param y  Pointer to vector that is multiplied by `b` and then updated as
///           `a*x + b*y`.
/// @return  TBD: GSL's documentation does not specify.
inline int
axpby(gsl_complex_long_double const &a,
      c::vector<gsl_complex_long_double const> *x,
      gsl_complex_long_double const &b,
      c::vector<gsl_complex_long_double> *y) {
  return gsl_vector_complex_long_double_axpby(a, x, b, y);
}


#else


/// Perform the logical equivalent of `y = a*x + b*y`.
///
/// Provide the functionality of GSL's `gsl_vector_axpby` even when installed
/// version of GSL be less than 2.7, at which revision `gsl_vector_axpby` was
/// added to GSL.
///
/// `axpby` uses Eigen to perform the computation.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_axpby
///
/// @param a  Coefficient of vector `x`.
/// @param x  Pointer to vector that is multiplied by `a`.
/// @param b  Coefficient of vector `y`.
/// @param y  Pointer to vector that is multiplied by `b` and then updated as
///           `a*x + b*y`.
/// @return  GSL's documentation does not specify, but this implementation
///          returns zero.
template<typename V>
int axpby(data_t<V> const &a, V const *x, data_t<V> const &b, V *y) {
  return axpby_for_gsl_lt_2p7(a, *x, b, *y);
}


#endif // if GSL_AT_LEAST(2, 7)

} // namespace gsl::c

// EOF
