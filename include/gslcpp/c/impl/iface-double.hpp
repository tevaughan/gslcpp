/// @file       include/gslcpp/c/impl/iface-double.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
///
/// @brief      Definition for
///             gsl::c::impl::iface<double>,
///             gsl::c::impl::iface<double const>

#pragma once
#include "iface.hpp"

namespace gsl::c::impl {


/// Specialization for non-const double.
template<> struct iface<double> {
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
template<> struct iface<double const> {
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


} // namespace gsl::c::impl

// EOF
