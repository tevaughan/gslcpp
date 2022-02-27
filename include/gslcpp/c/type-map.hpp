/// \file       include/gslcpp/c/type-map.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
///
/// \brief      Definition of
///             gsl::c::type_map,
///             \ref vector,
///             \ref vector_view,
///             \ref matrix.

#pragma once

#ifndef HAVE_INLINE
/// Indicate that the inline-definition of each function in GSL should used.
/// `HAVE_INLINE` should be defined *before* the inclusion of `gsl_vector.h`.
#  define HAVE_INLINE
#endif

#include <gsl/gsl_matrix.h> // gsl_matrix, gsl_matrix_float, etc.
#include <gsl/gsl_vector.h> // gsl_vector, gsl_vector_float, etc.

namespace gsl::c {


/// Template whose every specialization for element-type `E` defines dependent
/// types, each corresponding to native type in GSL.
///
/// - `type_map<E>::vector` is GSL's native vector, whose elements are of type
///   `E`.
///
/// - `type_map<E>::vector_view` is GSL's native view of a vector whose
///   elements are of type `E`.
///
/// - `type_map<E>::matrix` is GSL's native matrix, whose elements are of type
///   `E`.
///
/// @tparam E  Type of element for vector or matrix.
template<typename E> struct type_map;


/** Specialization for double. */
template<> struct type_map<double> {
  /// GSL's native type for vector.
  using vector= gsl_vector;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix;
};


/** Specialization for double const. */
template<> struct type_map<double const> {
  /// GSL's native type for vector.
  using vector= gsl_vector const;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix const;
};


/** Specialization for float. */
template<> struct type_map<float> {
  /// GSL's native type for vector.
  using vector= gsl_vector_float;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_float_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_float;
};


/** Specialization for float const. */
template<> struct type_map<float const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_float const;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_float_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_float const;
};


/** Specialization for long double. */
template<> struct type_map<long double> {
  /// GSL's native type for vector.
  using vector= gsl_vector_long_double;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_long_double_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_long_double;
};


/** Specialization for long double const. */
template<> struct type_map<long double const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_long_double const;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_long_double_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_long_double const;
};


/** Specialization for int. */
template<> struct type_map<int> {
  /// GSL's native type for vector.
  using vector= gsl_vector_int;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_int_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_int;
};


/** Specialization for int const. */
template<> struct type_map<int const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_int const;

  /// GSL's native type for vector-view
  using vector_view= gsl_vector_int_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_int const;
};


/** Specialization for unsigned. */
template<> struct type_map<unsigned> {
  /// GSL's native type for vector.
  using vector= gsl_vector_uint;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_uint_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_uint;
};


/** Specialization for unsigned const. */
template<> struct type_map<unsigned const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_uint const;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_uint_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_uint const;
};


/** Specialization for long. */
template<> struct type_map<long> {
  /// GSL's native type for vector.
  using vector= gsl_vector_long;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_long_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_long;
};


/** Specialization for long const. */
template<> struct type_map<long const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_long const;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_long_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_long const;
};


/** Specialization for unsigned long. */
template<> struct type_map<unsigned long> {
  /// GSL's native type for vector.
  using vector= gsl_vector_ulong;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_ulong_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_ulong;
};


/** Specialization for unsigned long const. */
template<> struct type_map<unsigned long const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_ulong const;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_ulong_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_ulong const;
};


/** Specialization for short. */
template<> struct type_map<short> {
  /// GSL's native type for vector.
  using vector= gsl_vector_short;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_short_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_short;
};


/** Specialization for short const. */
template<> struct type_map<short const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_short const;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_short_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_short const;
};


/** Specialization for unsigned short. */
template<> struct type_map<unsigned short> {
  /// GSL's native type for vector.
  using vector= gsl_vector_ushort;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_ushort_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_ushort;
};


/** Specialization for unsigned short const. */
template<> struct type_map<unsigned short const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_ushort const;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_ushort_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_ushort const;
};


/** Specialization for char. */
template<> struct type_map<char> {
  /// GSL's native type for vector.
  using vector= gsl_vector_char;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_char_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_char;
};


/** Specialization for char const. */
template<> struct type_map<char const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_char const;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_char_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_char const;
};


/** Specialization for unsigned char. */
template<> struct type_map<unsigned char> {
  /// GSL's native type for vector.
  using vector= gsl_vector_uchar;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_uchar_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_uchar;
};


/** Specialization for unsigned char const. */
template<> struct type_map<unsigned char const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_uchar const;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_uchar_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_uchar const;
};


/** Specialization for gsl_complex. */
template<> struct type_map<gsl_complex> {
  /// GSL's native type for vector.
  using vector= gsl_vector_complex;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_complex_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_complex;
};


/** Specialization for gsl_complex const. */
template<> struct type_map<gsl_complex const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_complex const;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_complex_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_complex const;
};


/** Specialization for gsl_complex_float. */
template<> struct type_map<gsl_complex_float> {
  /// GSL's native type for vector.
  using vector= gsl_vector_complex_float;

  /// GSL's native type for vector.
  using vector_view= gsl_vector_complex_float_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_complex_float;
};


/** Specialization for gsl_complex_float const. */
template<> struct type_map<gsl_complex_float const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_complex_float const;

  /// GSL's native type for vector.
  using vector_view= gsl_vector_complex_float_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_complex_float const;
};


/** Specialization for gsl_complex_long_double. */
template<> struct type_map<gsl_complex_long_double> {
  /// GSL's native type for vector.
  using vector= gsl_vector_complex_long_double;

  /// GSL's native type for vector.
  using vector_view= gsl_vector_complex_long_double_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_complex_long_double;
};


/** Specialization for gsl_complex_long_double const. */
template<> struct type_map<gsl_complex_long_double const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_complex_long_double const;

  /// GSL's native type for vector.
  using vector_view= gsl_vector_complex_long_double_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_complex_long_double const;
};


/// \anchor vector
/// GSL's native vector-type corresponding to element-type `E`.
/// @tparam E  Type of element for vector.
template<typename E> using vector= typename type_map<E>::vector;


/// \anchor vector_view
/// GSL's native view of vector corresponding to element-type `E`.
/// @tparam E  Type of element for vector.
template<typename E> using vector_view= typename type_map<E>::vector_view;


/// \anchor matrix
/// GSL's native matrix-type corresponding to element-type `E`.
/// @tparam E  Type of element for matrix.
template<typename E> using matrix= typename type_map<E>::matrix;


} // namespace gsl::c

// EOF
