/// @file       include/gslcpp/wrap/axpby.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gsl::w_axpby().

#pragma once
#include "compat.hpp"
#include "container.hpp" // w_vector

namespace gsl {

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
inline int w_axpby(
      double const &a,
      w_vector<double const> *x,
      double const &b,
      w_vector<double> *y) {
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
inline int w_axpby(
      float const &a,
      w_vector<float const> *x,
      float const &b,
      w_vector<float> *y) {
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
inline int w_axpby(
      long double const &a,
      w_vector<long double const> *x,
      long double const &b,
      w_vector<long double> *y) {
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
w_axpby(int const &a, w_vector<int const> *x, int const &b, w_vector<int> *y) {
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
inline int w_axpby(
      unsigned const &a,
      w_vector<unsigned const> *x,
      unsigned const &b,
      w_vector<unsigned> *y) {
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
inline int w_axpby(
      long const &a,
      w_vector<long const> *x,
      long const &b,
      w_vector<long> *y) {
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
inline int w_axpby(
      unsigned long const &a,
      w_vector<unsigned long const> *x,
      unsigned long const &b,
      w_vector<unsigned long> *y) {
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
inline int w_axpby(
      short const &a,
      w_vector<short const> *x,
      short const &b,
      w_vector<short> *y) {
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
inline int w_axpby(
      unsigned short const &a,
      w_vector<unsigned short const> *x,
      unsigned short const &b,
      w_vector<unsigned short> *y) {
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
inline int w_axpby(
      char const &a,
      w_vector<char const> *x,
      char const &b,
      w_vector<char> *y) {
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
inline int w_axpby(
      unsigned char const &a,
      w_vector<unsigned char const> *x,
      unsigned char const &b,
      w_vector<unsigned char> *y) {
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
inline int w_axpby(
      gsl_complex const &a,
      w_vector<gsl_complex const> *x,
      gsl_complex const &b,
      w_vector<gsl_complex> *y) {
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
inline int w_axpby(
      gsl_complex_float const &a,
      w_vector<gsl_complex_float const> *x,
      gsl_complex_float const &b,
      w_vector<gsl_complex_float> *y) {
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
inline int w_axpby(
      gsl_complex_long_double const &a,
      w_vector<gsl_complex_long_double const> *x,
      gsl_complex_long_double const &b,
      w_vector<gsl_complex_long_double> *y) {
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
int w_axpby(data_t<V> const &a, V const *x, data_t<V> const &b, V *y) {
  return axpby_for_gsl_lt_2p7(a, *x, b, *y);
}


#endif // if GSL_AT_LEAST(2, 7)

} // namespace gsl

// EOF
