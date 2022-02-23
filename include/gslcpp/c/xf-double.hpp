/// @file       include/gslcpp/c/xf-double.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition for gsl::c::xf<double>, gsl::c::xf<double const>.

#pragma once
#include "xf.hpp"

namespace gsl::c {


/// Specialization for `double`.
template<> struct xf<double> {
  /// GSL's C-library type for non-const elements.
  using vector= gsl_vector;

  /// GSL's C-library type for view of non-const elements.
  using vector_view= gsl_vector_view;

  /// GSL's native view of array.
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements relative to pointer.
  /// @param n  Number of elements in view.
  /// @return  GSL's native, C-style view.
  static vector_view vector_view_array(double *b, size_t s, size_t n) {
    return gsl_vector_view_array_with_stride(b, s, n);
  }

  /// GSL's native view of subvector.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset in gsl_vector of first element in view.
  /// @param s  Stride of elements in view relative to offsets in `v`.
  /// @param n  Number of elements in view.
  /// @return  GSL's native, C-style view.
  static vector_view subvector(vector *v, size_t i, size_t s, size_t n) {
    return gsl_vector_subvector_with_stride(v, i, s, n);
  }

  /// Fetch copy of element at offset `i` with bounds-checking.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset of element.
  /// @return  Copy of element.
  static double vector_get(vector const *v, size_t i) {
    return gsl_vector_get(v, i);
  }

  /// Fetch pointer to element at offset `i` with bounds-checking.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset of element.
  /// @return  Pointer to element.
  static double *vector_ptr(vector *v, size_t i) {
    return gsl_vector_ptr(v, i);
  }

  /// Set value of element at offset `i` with bounds-checking.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset of element.
  /// @param x  New value for element.
  static void vector_set(vector *v, size_t i, double const &x) {
    gsl_vector_set(v, i, x);
  }
};


/// Specialization for `double const`.
template<> struct xf<double const> {
  /// GSL's C-library type for non-const elements.
  using vector= gsl_vector const;

  /// GSL's C-library type for view of non-const elements.
  using vector_view= gsl_vector_const_view;

  /// GSL's native view of array.
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements relative to pointer.
  /// @param n  Number of elements in view.
  /// @return  GSL's native, C-style view.
  static vector_view vector_view_array(double const *b, size_t s, size_t n) {
    return gsl_vector_const_view_array_with_stride(b, s, n);
  }

  /// GSL's native view of subvector.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset in gsl_vector of first element in view.
  /// @param s  Stride of elements in view relative to offsets in `v`.
  /// @param n  Number of elements in view.
  /// @return  GSL's native, C-style view.
  static vector_view subvector(vector *v, size_t i, size_t s, size_t n) {
    return gsl_vector_const_subvector_with_stride(v, i, s, n);
  }

  /// Fetch copy of element at offset `i` with bounds-checking.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset of element.
  /// @return  Copy of element.
  static double vector_get(vector *v, size_t i) {
    return gsl_vector_get(v, i);
  }

  /// Fetch pointer to element at offset `i` with bounds-checking.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset of element.
  /// @return  Pointer to element.
  static double const *vector_ptr(vector *v, size_t i) {
    return gsl_vector_const_ptr(v, i);
  }
};


} // namespace gsl::c

// EOF
