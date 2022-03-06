/// \file       include/gslcpp/vector-view.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::vector_view.

#pragma once
#include "vec/v-iface.hpp" // v_iface, v_stor
#include "wrap/vector-view-array.hpp" // w_vector_view_array

/// Namespace for C++-interface to GSL.
namespace gsl {

/// Vector with storage not owned by instance of vector.
///
/// %vector_view has its interface to storage given by \ref gsl::v_view, and
/// most of the external interface is given by \ref gsl::v_iface.
///
/// %vector_view inherits these and provides template-constructors.
///
/// @tparam T  Type of each element in vector.
template<typename T, size_t N= 0>
struct vector_view: public v_iface<T, N, v_view> {
  using P= v_iface<T, N, v_view>; ///< Type of ancestor.
  using P::P;

  /// Initialize view of standard (decayed) C-array.  Arguments are reordered
  /// relative to those given to gsl_vector_viewiew_array_with_stride().
  /// Putting number of element at *beginning* disambiguates from constructor
  /// from non-decayed array.  Putting stride at *end* allows it to have
  /// default value of 1.
  /// @param b  Pointer to first element of array and of view.
  /// @param n  Number of elements in view.
  vector_view(T *b, size_t n): P(w_vector_view_array(b, 1, n)) {}

  /// Initialize view of non-decayed C-array.  Arguments are reordered from
  /// those given to gsl_vector_subvector_with_stride().  Putting initial
  /// offset and stride at end allows every argument to have good default (N
  /// for number of elements in view, 0 for initial offset, and 1 for stride).
  /// @tparam N  Number of elements in array.
  /// @param b  Reference to non-decayed C-array.
  vector_view(T (&b)[N]): P(w_vector_view_array(b, 1, N)) {}

  /// Initialize view of other view.
  /// @param v  Other view.
  vector_view(v_iface<T, N, v_view> v): P(v.cview()) {}
};


} // namespace gsl

// EOF
