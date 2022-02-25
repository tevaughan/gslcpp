/// \file       include/gslcpp/vector_v.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::vector_v.

#pragma once

#include "vec/iface.hpp" // vec::iface, vec::stor, c::iface

/// Namespace for C++-interface to GSL.
namespace gsl {


/// Vector with storage not owned by instance of vector.
template<typename T> struct vector_v: public vec::iface<vec::view<T>> {
  using P= vec::iface<vec::view<T>>; ///< Type of ancestor.
  using P::P;

  /// Initialize view of standard (decayed) C-array.  Arguments are reordered
  /// relative to those given to gsl_vector_view_array_with_stride().  Putting
  /// number of element at *beginning* disambiguates from constructor from
  /// non-decayed array.  Putting stride at *end* allows it to have default
  /// value of 1.
  /// @param b  Pointer to first element of array and of view.
  /// @param n  Number of elements in view.
  /// @param s  Stride of view relative to array.
  vector_v(size_t n, T *b, size_t s= 1):
      P([&] {
        if constexpr(is_const_v<T>) {
          return c::iface<T>::vector_const_view_array(b, s, n);
        } else {
          return c::iface<T>::vector_view_array(b, s, n);
        }
      }()) {}

  /// Initialize view of non-decayed C-array.  Arguments are reordered from
  /// those given to gsl_vector_subvector_with_stride().  Putting initial
  /// offset and stride at end allows every argument to have good default (N
  /// for number of elements in view, 0 for initial offset, and 1 for stride).
  /// @tparam N  Number of elements in array.
  /// @param b  Reference to non-decayed C-array.
  /// @param n  Number of elements in view.
  /// @param i  Offset in array of first element in view.
  /// @param s  Stride of view relative to array.
  template<int N>
  vector_v(T (&b)[N], size_t n= N, size_t i= 0, size_t s= 1):
      P([&] {
        if constexpr(is_const_v<T>) {
          return c::iface<T>::vector_const_view_array(b + i, s, n);
        } else {
          return c::iface<T>::vector_view_array(b + i, s, n);
        }
      }()) {}

  /// Initialize view of other view.
  /// @param v  Other view.
  vector_v(vec::iface<vec::view<T>> v): P(v.cview()) {}
};


} // namespace gsl

// EOF
