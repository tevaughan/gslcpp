/// @file       include/gslcpp/c-iface.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition for gsl::c_iface_, gsl::c_iface.

#pragma once

// Use inline-definition of each accessor-function.
// - Define this before including `gsl_vector.h`.
#ifndef HAVE_INLINE
#  define HAVE_INLINE
#endif

#include <functional> // fucntion
#include <gsl/gsl_vector.h> // gsl_vector_view, gsl_vector_const_view
#include <stdexcept> // runtime_error

namespace gsl {


using std::runtime_error;
using std::same_as;


/// Interface required for template referring to GSL's native C-types and
/// C-functions for a given element-type.
/// @tparam I  Candidate type for interface.
template<typename I>
concept c_interface=
  requires(typename I::elem_t *e, size_t s, typename I::vector *v) {
  typename I::elem_t;
  typename I::vector;
  typename I::vector_view;
  { I::vector_view_array(e, s, s) } -> same_as<typename I::vector_view>;
  { I::subvector(v, s, s, s) } -> same_as<typename I::vector_view>;
};


/// Generic template for struct that provides, on basis of element-type `E`,
/// appropriate GSL C-types and functions.
/// @tparam E  Type of each element in vector.
template<typename E> struct c_iface_;


/// Specialization for non-const double.
template<> struct c_iface_<double> {
  /// Type of each element in vector or matrix.
  using elem_t= double;

  /// GSL's C-library type for non-const elements.
  using vector= gsl_vector;

  /// GSL's C-library type for view of non-const elements.
  using vector_view= gsl_vector_view;

  /// Function that converts array to GSL's native view.
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements relative to pointer.
  /// @param n  Number of elements in view.
  /// @return  GSL's native, C-style view.
  static vector_view vector_view_array(elem_t *b, size_t s, size_t n) {
    return gsl_vector_view_array_with_stride(b, s, n);
  }

  /// Function that converts subvector to GSL's native view.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset in gsl_vector of first element in view.
  /// @param s  Stride of elements in view relative to offsets in `v`.
  /// @param n  Number of elements in view.
  /// @return  GSL's native, C-style view.
  static vector_view subvector(vector *v, size_t i, size_t s, size_t n) {
    return gsl_vector_subvector_with_stride(v, i, s, n);
  }
};


/// Specialization for const double.
template<> struct c_iface_<double const> {
  /// Type of each element in vector or matrix.
  using elem_t= double const;

  /// GSL's C-library type for non-const elements.
  using vector= gsl_vector const;

  /// GSL's C-library type for view of non-const elements.
  using vector_view= gsl_vector_const_view;

  /// Function that converts array to GSL's native view.
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements relative to pointer.
  /// @param n  Number of elements in view.
  /// @return  GSL's native, C-style view.
  static vector_view vector_view_array(elem_t *b, size_t s, size_t n) {
    return gsl_vector_const_view_array_with_stride(b, s, n);
  }

  /// Function that converts subvector to GSL's native view.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset in gsl_vector of first element in view.
  /// @param s  Stride of elements in view relative to offsets in `v`.
  /// @param n  Number of elements in view.
  /// @return  GSL's native, C-style view.
  static vector_view subvector(vector *v, size_t i, size_t s, size_t n) {
    return gsl_vector_const_subvector_with_stride(v, i, s, n);
  }
};


/// GSL's native C-style interfaces associated with element-type `E`.
/// @param E  Type of each element in vector or matrix.
template<typename E>
requires c_interface<c_iface_<E>> struct c_iface: public c_iface_<E> {
  using P= c_iface_<E>; ///< Type of ancestor.

  using P::subvector;
  using P::vector_view_array;
  using typename P::elem_t;
  using typename P::vector;
  using typename P::vector_view;
};


} // namespace gsl

// EOF
