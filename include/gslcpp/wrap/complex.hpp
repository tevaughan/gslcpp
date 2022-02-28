/// \file       include/gslcpp/wrap/complex.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::complex<A>, gsl::complex_type<A>.

#pragma once
#include <gsl/gsl_complex.h> // gsl_complex, etc.

namespace gsl {


/// For type A of element in C-style array used to initialize view, define
/// complex type of element in vector or matrix.
///
/// \tparam A  Type of each element in C-style array used to initialize view.
template<typename A> struct complex;


/// Specialization for double.
template<> struct complex<double> {
  /// Type of complex element in vector or matrix.
  using E= gsl_complex;
};


/// Specialization for double const.
template<> struct complex<double const> {
  /// Type of complex element in vector or matrix.
  using E= gsl_complex const;
};


/// Specialization for float.
template<> struct complex<float> {
  /// Type of complex element in vector or matrix.
  using E= gsl_complex_float;
};


/// Specialization for float const.
template<> struct complex<float const> {
  /// Type of complex element in vector or matrix.
  using E= gsl_complex_float const;
};


/// Specialization for long double.
template<> struct complex<long double> {
  /// Type of complex element in vector or matrix.
  using E= gsl_complex_long_double;
};


/// Specialization for long double const.
template<> struct complex<long double const> {
  /// Type of complex element in vector or matrix.
  using E= gsl_complex_long_double const;
};


/// Type of complex element in vector or matrix.
/// \tparam A  Type of element in C-style array used to initialize view.
template<typename A> using complex_type= typename complex<A>::E;


} // namespace gsl

// EOF
