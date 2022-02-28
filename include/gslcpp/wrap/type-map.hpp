/// \dir        include/gslcpp/wrap
/// \brief      C++-wrapper for each native C-type and function in GSL.

/// \file       include/gslcpp/wrap/type-map.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
///
/// \brief      Definition of
///             gsl::array_element_map,
///             gsl::type_map,
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


/// For any type E of element in vector or matrix, define type
/// array_element_map<E>::A of element in C-style *array* passed to
/// gsl_vector_view_array(), gsl_matrix_float_view_array(), or like.
///
/// \anchor gsl_array_element_map
///
/// For vector or matrix whose element-type is complex, element-type of vector
/// or matrix is different from element-type of C-style array passed, for
/// example, to gsl_vector_complex_view_array_with_stride().
///
/// Generic template defines array_element_map<E>::A to be same as E.
///
/// Each specialization, however, defines array_elemen_map<E>::A to be
/// different from E, as required by view-construction function for complex
/// array or complex matrix.
///
/// \ref type_map
///
/// \sa \ref gsl_array_element_map_complex "array_element_map<complex>"
/// \sa \ref gsl_array_element_map_complex_const "array_element_map<complex const>"
/// \sa \ref gsl_array_element_map_complex_float "array_element_map<complex_float>"
/// \sa \ref gsl_array_element_map_complex_float_const "array_element_map<complex_float const>"
/// \sa \ref gsl_array_element_map_complex_long_double "array_element_map<complex_long_double>"
/// \sa \ref gsl_array_element_map_complex_long_double_const "array_element_map<complex_long_double const>"
/// \sa \ref type_map
///
/// \tparam E  Type of each element in vector or array.
template<typename E> struct array_element_map {
  /// Type of element in C-style array passed to
  /// gsl_vector_view_array_with_stride() or the like.
  using A= E;
};


/// Specialization for gsl_complex.
/// \anchor gsl_array_element_map_complex
/// \sa \ref gsl_array_element_map "array_element_map"
template<> struct array_element_map<gsl_complex> {
  /// Type of element in C-style array passed to
  /// gsl_vector_complex_view_array_with_stride().
  using A= double;
};


/// Specialization for gsl_compex const.
/// \anchor gsl_array_element_map_complex_const
/// \sa \ref gsl_array_element_map "array_element_map"
template<> struct array_element_map<gsl_complex const> {
  /// Type of element in C-style array passed to
  /// gsl_vector_complex_const_view_array_with_stride().
  using A= double const;
};


/// Specialization for gsl_compex_float.
/// \anchor gsl_array_element_map_complex_float
/// \sa \ref gsl_array_element_map "array_element_map"
template<> struct array_element_map<gsl_complex_float> {
  /// Type of element in C-style array passed to
  /// gsl_vector_complex_float_view_array_with_stride().
  using A= float;
};


/// Specialization for gsl_compex_float const.
/// \anchor gsl_array_element_map_complex_float_const
/// \sa \ref gsl_array_element_map "array_element_map"
template<> struct array_element_map<gsl_complex_float const> {
  /// Type of element in C-style array passed to
  /// gsl_vector_complex_float_const_view_array_with_stride().
  using A= float const;
};


/// Specialization for gsl_compex_long_double.
/// \anchor gsl_array_element_map_complex_long_double
/// \sa \ref gsl_array_element_map "array_element_map"
template<> struct array_element_map<gsl_complex_long_double> {
  /// Type of element in C-style array passed to
  /// gsl_vector_complex_long_double_view_array_with_stride().
  using A= long double;
};


/// Specialization for gsl_compex_long_double const.
/// \anchor gsl_array_element_map_complex_long_double_const
/// \sa \ref gsl_array_element_map "array_element_map"
template<> struct array_element_map<gsl_complex_long_double const> {
  /// Type of element in C-style array passed to
  /// gsl_vector_complex_long_double_const_view_array_with_stride().
  using A= long double const;
};


/// Template whose every specialization for element-type `E` defines dependent
/// types, each corresponding to native type in GSL.
///
/// - %type_map<E>::A is type of element in array passed to
///   gsl_vector_view_array and like.
///
/// - %type_map<E>::vector is GSL's native vector, whose elements are of type
///   E.
///
/// - %type_map<E>::vector_view is GSL's native view of a vector whose elements
///   are of type E.
///
/// - %type_map<E>::matrix is GSL's native matrix, whose elements are of type
///   E.
///
/// - %type_map<E>::matrix_view is GSL's native view of a matrix, whose
///   elements are of type E.
///
/// \sa \ref gsl_type_map_double "type_map<double>"
/// \sa \ref gsl_type_map_double_const "type_map<double const>"
/// \sa \ref gsl_type_map_float "type_map<float>"
/// \sa \ref gsl_type_map_float_const "type_map<float const>"
/// \sa \ref gsl_type_map_long_double "type_map<long_double>"
/// \sa \ref gsl_type_map_long_double_const "type_map<long_double const>"
/// \sa \ref gsl_type_map_int "type_map<int>"
/// \sa \ref gsl_type_map_int_const "type_map<int const>"
/// \sa \ref gsl_type_map_unsigned "type_map<unsigned>"
/// \sa \ref gsl_type_map_unsigned_const "type_map<unsigned const>"
/// \sa \ref gsl_type_map_long "type_map<long>"
/// \sa \ref gsl_type_map_long_const "type_map<long const>"
/// \sa \ref gsl_type_map_unsigned_long "type_map<unsigned_long>"
/// \sa \ref gsl_type_map_unsigned_long_const "type_map<unsigned_long const>"
/// \sa \ref gsl_type_map_short "type_map<short>"
/// \sa \ref gsl_type_map_short_const "type_map<short const>"
/// \sa \ref gsl_type_map_unsigned_short "type_map<unsigned_short>"
/// \sa \ref gsl_type_map_unsigned_short_const "type_map<unsigned_short const>"
/// \sa \ref gsl_type_map_char "type_map<char>"
/// \sa \ref gsl_type_map_char_const "type_map<char const>"
/// \sa \ref gsl_type_map_unsigned_char "type_map<unsigned_char>"
/// \sa \ref gsl_type_map_unsigned_char_const "type_map<unsigned_char const>"
/// \sa \ref gsl_type_map_gsl_complex "type_map<gsl_complex>"
/// \sa \ref gsl_type_map_gsl_complex_const "type_map<gsl_complex const>"
/// \sa \ref gsl_type_map_gsl_complex_float "type_map<gsl_complex_float>"
/// \sa \ref gsl_type_map_gsl_complex_float_const "type_map<gsl_complex_float const>"
/// \sa \ref gsl_type_map_gsl_complex_long_double "type_map<gsl_complex_long_double>"
/// \sa \ref gsl_type_map_gsl_complex_long_double_const "type_map<gsl_complex_long_double const>"
///
/// @tparam E  Type of element for vector or matrix.
template<typename E> struct type_map;


/// Specialization for double.
/// \anchor gsl_type_map_double
/// \sa \ref type_map
template<> struct type_map<double>: public array_element_map<double> {
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
/// \anchor gsl_type_map_double_const
/// \sa \ref type_map
template<>
struct type_map<double const>: public array_element_map<double const> {
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
/// \anchor gsl_type_map_float
/// \sa \ref type_map
template<> struct type_map<float>: public array_element_map<float> {
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
/// \anchor gsl_type_map_float_const
/// \sa \ref type_map
template<>
struct type_map<float const>: public array_element_map<float const> {
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
/// \anchor gsl_type_map_long_double
/// \sa \ref type_map
template<>
struct type_map<long double>: public array_element_map<long double> {
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
/// \anchor gsl_type_map_long_double_const
/// \sa \ref type_map
template<>
struct type_map<long double const>:
    public array_element_map<long double const> {
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
/// \anchor gsl_type_map_int
/// \sa \ref type_map
template<> struct type_map<int>: public array_element_map<int> {
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
/// \anchor gsl_type_map_int_const
/// \sa \ref type_map
template<> struct type_map<int const>: public array_element_map<int const> {
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
/// \anchor gsl_type_map_unsigned
/// \sa \ref type_map
template<> struct type_map<unsigned>: public array_element_map<unsigned> {
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
/// \anchor gsl_type_map_unsigned_const
/// \sa \ref type_map
template<>
struct type_map<unsigned const>: public array_element_map<unsigned const> {
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
/// \anchor gsl_type_map_long
/// \sa \ref type_map
template<> struct type_map<long>: public array_element_map<long> {
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
/// \anchor gsl_type_map_long_const
/// \sa \ref type_map
template<> struct type_map<long const>: public array_element_map<long const> {
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
/// \anchor gsl_type_map_unsigned_long
/// \sa \ref type_map
template<>
struct type_map<unsigned long>: public array_element_map<unsigned long> {
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
/// \anchor gsl_type_map_unsigned_long_const
/// \sa \ref type_map
template<>
struct type_map<unsigned long const>:
    public array_element_map<unsigned long const> {
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
/// \anchor gsl_type_map_short
/// \sa \ref type_map
template<> struct type_map<short>: public array_element_map<short> {
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
/// \anchor gsl_type_map_short_const
/// \sa \ref type_map
template<>
struct type_map<short const>: public array_element_map<short const> {
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
/// \anchor gsl_type_map_unsigned_short
/// \sa \ref type_map
template<>
struct type_map<unsigned short>: public array_element_map<unsigned short> {
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
/// \anchor gsl_type_map_unsigned_short_const
/// \sa \ref type_map
template<>
struct type_map<unsigned short const>:
    public array_element_map<unsigned short const> {
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
/// \anchor gsl_type_map_char
/// \sa \ref type_map
template<> struct type_map<char>: public array_element_map<char> {
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
/// \anchor gsl_type_map_char_const
/// \sa \ref type_map
template<> struct type_map<char const>: public array_element_map<char const> {
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
/// \anchor gsl_type_map_unsigned_char
/// \sa \ref type_map
template<>
struct type_map<unsigned char>: public array_element_map<unsigned char> {
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
/// \anchor gsl_type_map_unsigned_char_const
/// \sa \ref type_map
template<>
struct type_map<unsigned char const>:
    public array_element_map<unsigned char const> {
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
/// \anchor gsl_type_map_gsl_complex
/// \sa \ref type_map
template<>
struct type_map<gsl_complex>: public array_element_map<gsl_complex> {
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
/// \anchor gsl_type_map_gsl_complex_const
/// \sa \ref type_map
template<>
struct type_map<gsl_complex const>:
    public array_element_map<gsl_complex const> {
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
/// \anchor gsl_type_map_gsl_complex_float
/// \sa \ref type_map
template<>
struct type_map<gsl_complex_float>:
    public array_element_map<gsl_complex_float> {
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
/// \anchor gsl_type_map_gsl_complex_float_const
/// \sa \ref type_map
template<>
struct type_map<gsl_complex_float const>:
    public array_element_map<gsl_complex_float const> {
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
/// \anchor gsl_type_map_gsl_complex_long_double
/// \sa \ref type_map
template<>
struct type_map<gsl_complex_long_double>:
    public array_element_map<gsl_complex_long_double> {
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
/// \anchor gsl_type_map_gsl_complex_long_double_const
/// \sa \ref type_map
template<>
struct type_map<gsl_complex_long_double const>:
    public array_element_map<gsl_complex_long_double const> {
  /// GSL's native type for vector.
  using vector= gsl_vector_complex_long_double const;

  /// GSL's native type for vector.
  using vector_view= gsl_vector_complex_long_double_const_view;

  /// GSL's native type for matrix.
  using matrix= gsl_matrix_complex_long_double const;

  /// GSL's native type for matrix-view.
  using matrix_view= gsl_matrix_complex_long_double_const_view;
};


/// Type of element in C-style array used to initialize view.
/// %w_array_elem is different from E if E be a complex type.
/// @tparam E  Type of element for vector.
template<typename E> using w_array_elem= typename type_map<E>::A;


/// GSL's native vector-type corresponding to element-type `E`.
/// \anchor w_vector
/// @tparam E  Type of element for vector.
template<typename E> using w_vector= typename type_map<E>::vector;


/// GSL's native view of vector corresponding to element-type `E`.
/// \anchor w_vector_view
/// @tparam E  Type of element for vector.
template<typename E> using w_vector_view= typename type_map<E>::vector_view;


/// GSL's native matrix-type corresponding to element-type `E`.
/// \anchor w_matrix
/// @tparam E  Type of element for matrix.
template<typename E> using w_matrix= typename type_map<E>::matrix;


/// GSL's native view of matrix corresponding to element-type `E`.
/// \anchor w_matrix_view
/// @tparam E  Type of element for matrix.
template<typename E> using w_matrix_view= typename type_map<E>::matrix_view;


} // namespace gsl

// EOF
