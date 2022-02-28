/// \dir        include/gslcpp/wrap
/// \brief      C++-wrapper for each native C-type and function in GSL.

/// \file       include/gslcpp/wrap/container.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
///
/// \brief      Definition of
///             gsl::container,
///             \ref w_vector,
///             \ref w_vector_view,
///             \ref w_matrix,
///             \ref w_matrix_view.

#pragma once

#ifndef HAVE_INLINE
/// Indicate that the inline-definition of each function in GSL should used.
/// `HAVE_INLINE` should be defined *before* the inclusion of `gsl_vector.h`.
#  define HAVE_INLINE
#endif

#include <gsl/gsl_matrix.h> // gsl_matrix, gsl_matrix_float, etc.
#include <gsl/gsl_vector.h> // gsl_vector, gsl_vector_float, etc.

namespace gsl {


/// For type E of element, define type of each vector, matrix, and view.
/// @tparam E  Type of each element in vector or matrix.
template<typename E> struct container;


/// Specialization for double.
/// \sa \ref container
template<> struct container<double> {
  /// GSL's native type for vector.
  using vector= gsl_vector;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_view;
};


/// Specialization for double const.
/// \sa \ref container
template<> struct container<double const> {
  /// GSL's native type for vector.
  using vector= gsl_vector const;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix const;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_const_view;
};


/// Specialization for float.
/// \sa \ref container
template<> struct container<float> {
  /// GSL's native type for vector.
  using vector= gsl_vector_float;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_float_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_float;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_float_view;
};


/// Specialization for float const.
/// \sa \ref container
template<> struct container<float const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_float const;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_float_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_float const;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_float_const_view;
};


/// Specialization for long double.
/// \sa \ref container
template<> struct container<long double> {
  /// GSL's native type for vector.
  using vector= gsl_vector_long_double;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_long_double_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_long_double;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_long_double_view;
};


/// Specialization for long double const.
/// \sa \ref container
template<> struct container<long double const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_long_double const;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_long_double_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_long_double const;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_long_double_const_view;
};


/// Specialization for int.
/// \sa \ref container
template<> struct container<int> {
  /// GSL's native type for vector.
  using vector= gsl_vector_int;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_int_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_int;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_int_view;
};


/// Specialization for int const.
/// \sa \ref container
template<> struct container<int const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_int const;

  /// GSL's native type for vector-view
  using vector_view= gsl_vector_int_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_int const;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_int_const_view;
};


/// Specialization for unsigned.
/// \sa \ref container
template<> struct container<unsigned> {
  /// GSL's native type for vector.
  using vector= gsl_vector_uint;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_uint_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_uint;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_uint_view;
};


/// Specialization for unsigned const.
/// \sa \ref container
template<> struct container<unsigned const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_uint const;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_uint_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_uint const;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_uint_const_view;
};


/// Specialization for long.
/// \sa \ref container
template<> struct container<long> {
  /// GSL's native type for vector.
  using vector= gsl_vector_long;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_long_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_long;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_long_view;
};


/// Specialization for long const.
/// \sa \ref container
template<> struct container<long const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_long const;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_long_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_long const;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_long_const_view;
};


/// Specialization for unsigned long.
/// \sa \ref container
template<> struct container<unsigned long> {
  /// GSL's native type for vector.
  using vector= gsl_vector_ulong;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_ulong_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_ulong;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_ulong_view;
};


/// Specialization for unsigned long const.
/// \sa \ref container
template<> struct container<unsigned long const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_ulong const;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_ulong_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_ulong const;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_ulong_const_view;
};


/// Specialization for short.
/// \sa \ref container
template<> struct container<short> {
  /// GSL's native type for vector.
  using vector= gsl_vector_short;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_short_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_short;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_short_view;
};


/// Specialization for short const.
/// \sa \ref container
template<> struct container<short const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_short const;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_short_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_short const;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_short_const_view;
};


/// Specialization for unsigned short.
/// \sa \ref container
template<> struct container<unsigned short> {
  /// GSL's native type for vector.
  using vector= gsl_vector_ushort;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_ushort_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_ushort;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_ushort_view;
};


/// Specialization for unsigned short const.
/// \sa \ref container
template<> struct container<unsigned short const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_ushort const;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_ushort_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_ushort const;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_ushort_const_view;
};


/// Specialization for char.
/// \sa \ref container
template<> struct container<char> {
  /// GSL's native type for vector.
  using vector= gsl_vector_char;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_char_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_char;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_char_view;
};


/// Specialization for char const.
/// \sa \ref container
template<> struct container<char const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_char const;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_char_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_char const;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_char_const_view;
};


/// Specialization for unsigned char.
/// \sa \ref container
template<> struct container<unsigned char> {
  /// GSL's native type for vector.
  using vector= gsl_vector_uchar;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_uchar_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_uchar;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_uchar_view;
};


/// Specialization for unsigned char const.
/// \sa \ref container
template<> struct container<unsigned char const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_uchar const;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_uchar_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_uchar const;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_uchar_const_view;
};


/// Specialization for gsl_complex.
/// \sa \ref container
template<> struct container<gsl_complex> {
  /// GSL's native type for vector.
  using vector= gsl_vector_complex;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_complex_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_complex;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_complex_view;
};


/// Specialization for gsl_complex const.
/// \sa \ref container
template<> struct container<gsl_complex const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_complex const;

  /// GSL's native type for vector-view.
  using vector_view= gsl_vector_complex_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_complex const;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_complex_const_view;
};


/// Specialization for gsl_complex_float.
/// \sa \ref container
template<> struct container<gsl_complex_float> {
  /// GSL's native type for vector.
  using vector= gsl_vector_complex_float;

  /// GSL's native type for vector.
  using vector_view= gsl_vector_complex_float_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_complex_float;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_complex_float_view;
};


/// Specialization for gsl_complex_float const.
/// \sa \ref container
template<> struct container<gsl_complex_float const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_complex_float const;

  /// GSL's native type for vector.
  using vector_view= gsl_vector_complex_float_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_complex_float const;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_complex_float_const_view;
};


/// Specialization for gsl_complex_long_double.
/// \sa \ref container
template<> struct container<gsl_complex_long_double> {
  /// GSL's native type for vector.
  using vector= gsl_vector_complex_long_double;

  /// GSL's native type for vector.
  using vector_view= gsl_vector_complex_long_double_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_complex_long_double;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_complex_long_double_view;
};


/// Specialization for gsl_complex_long_double const.
/// \sa \ref container
template<> struct container<gsl_complex_long_double const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_complex_long_double const;

  /// GSL's native type for vector.
  using vector_view= gsl_vector_complex_long_double_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_complex_long_double const;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_complex_long_double_const_view;
};


/// GSL's native vector-type corresponding to element-type `E`.
/// \anchor w_vector
/// @tparam E  Type of element for vector.
template<typename E> using w_vector= typename container<E>::vector;


/// GSL's native view of vector corresponding to element-type `E`.
/// \anchor w_vector_view
/// @tparam E  Type of element for vector.
template<typename E> using w_vector_view= typename container<E>::vector_view;


/// GSL's native matrix-type corresponding to element-type `E`.
/// \anchor w_matrix
/// @tparam E  Type of element for matrix.
template<typename E> using w_matrix= typename container<E>::matrix;


/// GSL's native view of matrix corresponding to element-type `E`.
/// \anchor w_matrix_view
/// @tparam E  Type of element for matrix.
template<typename E> using w_matrix_view= typename container<E>::matrix_view;


} // namespace gsl

// EOF
