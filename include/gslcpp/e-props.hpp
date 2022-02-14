/// @file       include/gslcpp/e-props.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition for gsl::c_iface, gsl::e_props.

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


/// Generic template for struct that provides, on basis of element-type `E`,
/// appropriate GSL C-types functions, each for constructing appropriate view.
/// @tparam E  Type of each element in vector.
template<typename E> struct c_iface;


/// Specialization for non-const double.
template<> struct c_iface<double> {
  /// GSL's C-library type for non-const elements.
  using vec= gsl_vector;

  /// GSL's C-library type for view of non-const elements.
  using vec_view= gsl_vector_view;

  /// Function that converts array to GSL's native view.
  static vec_view vec_view_array(double *b, size_t s, size_t n) {
    return gsl_vector_view_array_with_stride(b, s, n);
  }
};


/// Specialization for const double.
template<> struct c_iface<double const> {
  /// GSL's C-library type for non-const elements.
  using vec= gsl_vector const;

  /// GSL's C-library type for view of non-const elements.
  using vec_view= gsl_vector_const_view;

  /// Function that converts array to GSL's native view.
  static vec_view vec_view_array(double const *b, size_t s, size_t n) {
    return gsl_vector_const_view_array_with_stride(b, s, n);
  }
};


/// Properties associated with element-type `E`.
/// @param E  Type of each element in vector or matrix.
template<typename E> struct e_props: public c_iface<E> {
  using P= c_iface<E>;
  using P::vec_view_array;
  using typename P::vec_view;

  /// C-library view of decayed C-style array.
  /// @param n  Number of elements in view.
  /// @param b  Pointer to first element.
  /// @param s  Stride of successive elements in array.
  /// @return  C-library view of array.
  static vec_view make_vec_view(size_t n, E *b, size_t s) {
    return c_iface<E>::vec_view_array(b, s, n);
  }

  /// C-library view of elements in non-decayed C-style array.
  /// @tparam N  Number of elements in array.
  /// @param b  Non-decayed C-style array.
  /// @param n  Number of elements in view.
  /// @param i  Offset of first element in view.
  /// @param s  Stride of successive elements in array.
  template<int N>
  static vec_view
  make_vec_view(E (&b)[N], size_t n= N, size_t i= 0, size_t s= 1) {
    if(i + s * (n - 1) > N - 1) {
      throw runtime_error("source-array not big enough");
    }
    return c_iface<E>::vec_view_array(b + i, s, n);
  }
};


} // namespace gsl

// EOF
