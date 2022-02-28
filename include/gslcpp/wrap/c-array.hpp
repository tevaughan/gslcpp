/// \file       include/gslcpp/wrap/c-array.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
///
/// \brief      Definition of
///             gsl::c_array,
///             gsl::w_array_elem, and
///             gsl::w_array_size().

#pragma once
#include <gsl/gsl_complex.h> // gsl_complex, etc.

namespace gsl {


/// For type E of element in matrix or vector, define type of element in
/// C-style array from which view of matrix or vector can be constructed and,
/// for number of elements in vector, define number of elements in C-style
/// array.
///
/// For non-complex element-type, the element in the matrix or in the vector is
/// the same as the element in the C-style array, but for complex element-type
/// this is not so.
///
/// There is a specialization of %c_array for each complex type.
///
/// \tparam GE  Type of element in matrix or vector.
template<typename E> struct c_array {
  using A= E; ///< Type of element in C-style array.

  /// Number of elements in C-style array.
  /// @param n  Number of elements in vector.
  /// @return  Number of elements in C-style array.
  constexpr static unsigned size(unsigned n) { return n; }
};


/// Specialization for gsl_complex.
template<> struct c_array<gsl_complex> {
  using A= double; ///< Type of element in C-style array.

  /// Number of elements in C-style array.
  /// @param n  Number of elements in vector.
  /// @return  Number of elements in C-style array.
  constexpr static unsigned size(unsigned n) { return 2 * n; }
};


/// Specialization for gsl_complex const.
template<> struct c_array<gsl_complex const> {
  using A= double const; ///< Type of element in C-style array.

  /// Number of elements in C-style array.
  /// @param n  Number of elements in vector.
  /// @return  Number of elements in C-style array.
  constexpr static unsigned size(unsigned n) { return 2 * n; }
};


/// Specialization for gsl_complex_float.
template<> struct c_array<gsl_complex_float> {
  using A= float; ///< Type of element in C-style array.

  /// Number of elements in C-style array.
  /// @param n  Number of elements in vector.
  /// @return  Number of elements in C-style array.
  constexpr static unsigned size(unsigned n) { return 2 * n; }
};


/// Specialization for gsl_complex_float const.
template<> struct c_array<gsl_complex_float const> {
  using A= float const; ///< Type of element in C-style array.

  /// Number of elements in C-style array.
  /// @param n  Number of elements in vector.
  /// @return  Number of elements in C-style array.
  constexpr static unsigned size(unsigned n) { return 2 * n; }
};


/// Specialization for gsl_complex_long_double.
template<> struct c_array<gsl_complex_long_double> {
  using A= long double; ///< Type of element in C-style array.

  /// Number of elements in C-style array.
  /// @param n  Number of elements in vector.
  /// @return  Number of elements in C-style array.
  constexpr static unsigned size(unsigned n) { return 2 * n; }
};


/// Specialization for gsl_complex_long_double const.
template<> struct c_array<gsl_complex_long_double const> {
  using A= long double const; ///< Type of element in C-style array.

  /// Number of elements in C-style array.
  /// @param n  Number of elements in vector.
  /// @return  Number of elements in C-style array.
  constexpr static unsigned size(unsigned n) { return 2 * n; }
};


/// Type of element in C-style array from which view is constructed.
/// \tparam E  Type of element in matrix or vector.
template<typename E> using w_array_elem= typename c_array<E>::A;


/// Number of elements in C-style array from which view is constructed.
/// \tparam E  Type of element in vector.
/// \param n  Number of elements in vector.
/// \return  Number of elements in C-style array.
template<typename E> constexpr unsigned w_array_size(unsigned n) {
  return c_array<E>::size(n);
}


} // namespace gsl

// EOF
