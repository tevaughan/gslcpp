/// \file       include/gslcpp/wrap/element.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::element, gsl::element_t.

#pragma once
#include "complex.hpp"

namespace gsl {


/// Via specialization, define fundamental, atomic element for type E of each
/// (possibly complex) element in vector or matrix.
///
/// If `E` be not complex, then define fundamental type as `E`, so that each of
/// v_iface::real(), v_iface::imag(), m_iface::real(), and m_iface::imag() has
/// a well defined return-type.
///
/// - Any attempt in client-code to ask for the imaginary part of a real vector
///   or a real matrix will result in a compile-time error.
///
/// - However, a call to v_iface::real() or m_iface::real() should compile and
///   work properly for any type of vector.
///
/// \tparam E  Possibly complex type of each element in vector or matrix.
template<typename E> struct element {
  /// Allow each of v_iface::real(), v_iface::imag(), m_iface::real(), or
  /// m_iface::imag() to compile without error, so long as client-code does not
  /// request the imaginary part of a real vector or a real matrix.
  using type= E;
};


/// Specialization of \ref element for gsl::complex<double>.
template<> struct element<gsl::complex<double>> {
  /// Type of element in view returned by v_iface::real(), etc.
  using type= double;
};


/// Specialization of \ref element for gsl::complex<float>.
template<> struct element<gsl::complex<float>> {
  /// Type of element in view returned by v_iface::real(), etc.
  using type= float;
};


/// Specialization of \ref element for gsl::complex<long double>.
template<> struct element<gsl::complex<long double>> {
  /// Type of element in view returned by v_iface::real(), etc.
  using type= long double;
};


/// Specialization of \ref element for `gsl::complex<double> const`
template<> struct element<gsl::complex<double> const> {
  /// Type of element in view returned by v_iface::real(), etc.
  using type= double const;
};


/// Specialization of \ref element for `gsl::complex<float> const`.
template<> struct element<gsl::complex<float> const> {
  /// Type of element in view returned by v_iface::real(), etc.
  using type= float const;
};


/// Specialization of \ref element for `gsl::complex<long double> const`.
template<> struct element<gsl::complex<long double> const> {
  /// Type of element in view returned by v_iface::real(), etc.
  using type= long double const;
};


/// Via specialization, define fundamental, atomic element for type E of each
/// (possibly complex) element in vector or matrix.
///
/// If `E` be not complex, then define fundamental type as `E`, so that each of
/// v_iface::real(), v_iface::imag(), m_iface::real(), and m_iface::imag() has
/// a well defined return-type.
///
/// - Any attempt in client-code to ask for the imaginary part of a real vector
///   or a real matrix will result in a compile-time error.
///
/// - However, a call to v_iface::real() or m_iface::real() should compile and
///   work properly for any type of vector.
///
/// \sa gsl::element<E>
///
/// \tparam E  Possibly complex type of each element in vector or matrix.
template<typename E> using element_t= typename element<E>::type;


} // namespace gsl

// EOF
