/// \file       include/gslcpp/wrap/complex.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::complex<A>.

#pragma once
#include <complex> // std::complex
#include <gsl/gsl_complex.h> // gsl_complex, etc.

namespace gsl {


/// Complex-number, each of whose components has type A.
/// This is the generic declaration; see each specialization for details.
/// \sa gsl::complex<double>
/// \sa gsl::complex<float>
/// \sa gsl::complex<long double>
/// \tparam A  Type of each component.
template<typename A> struct complex;


/// Specialization of \ref gsl::complex for double.
template<> struct complex<double>: public std::complex<double> {
  using P= std::complex<double>; ///< Type of parent.
  using P::P; ///< Inherit constructors.

  /// Construct from gsl_complex.
  /// \param z  Reference to instance of gsl_complex.
  complex(gsl_complex const &z): P(GSL_REAL(z), GSL_IMAG(z)) {}

  /// Construct from instance of parent's type.
  /// \param z  Reference to instance of parent's type.
  complex(P const &z): P(z) {}

  /// Convert to gsl_complex.
  /// \return  Reference to this as gsl_complex.
  operator gsl_complex &() { return *(gsl_complex *)this; }

  /// Convert to gsl_complex.
  /// \return  Reference to this as gsl_complex.
  operator gsl_complex const &() const { return *(gsl_complex const *)this; }
};


/// Specialization of \ref gsl::complex for float.
template<> struct complex<float>: public std::complex<float> {
  using P= std::complex<float>; ///< Type of parent.
  using P::P; ///< Inherit constructors.

  /// Construct from gsl_complex.
  /// \param z  Reference to instance of gsl_complex.
  complex(gsl_complex_float const &z): P(GSL_REAL(z), GSL_IMAG(z)) {}

  /// Construct from instance of parent's type.
  /// \param z  Reference to instance of parent's type.
  complex(P const &z): P(z) {}

  /// Convert to gsl_complex.
  /// \return  Reference to this as gsl_complex.
  operator gsl_complex_float &() { return *(gsl_complex_float *)this; }

  /// Convert to gsl_complex.
  /// \return  Reference to this as gsl_complex.
  operator gsl_complex_float const &() const {
    return *(gsl_complex_float const *)this;
  }
};


/// Specialization of \ref gsl::complex for long double.
template<> struct complex<long double>: public std::complex<long double> {
  using P= std::complex<long double>; ///< Type of parent.
  using P::P; ///< Inherit constructors.

  /// Construct from gsl_complex.
  /// \param z  Reference to instance of gsl_complex.
  complex(gsl_complex_long_double const &z): P(GSL_REAL(z), GSL_IMAG(z)) {}

  /// Construct from instance of parent's type.
  /// \param z  Reference to instance of parent's type.
  complex(P const &z): P(z) {}

  /// Convert to gsl_complex.
  /// \return  Reference to this as gsl_complex.
  operator gsl_complex_long_double &() {
    return *(gsl_complex_long_double *)this;
  }

  /// Convert to gsl_complex.
  /// \return  Reference to this as gsl_complex.
  operator gsl_complex_long_double const &() const {
    return *(gsl_complex_long_double const *)this;
  }
};


} // namespace gsl

// EOF
