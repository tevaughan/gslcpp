/// \file       include/gslcpp/vector-view.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::vector_view.

#pragma once
#include "vec/v-iface.hpp" // v_iface
#include "wrap/vector-view-array.hpp" // w_vector_view_array

/// Namespace for C++-interface to GSL.
namespace gsl {


/// Constructor-type for vector-by-reference whose storage is *not* owned by
/// instance of view.
///
/// Despite its name, %vector_view allows both viewing and modifying data that
/// it refers to.  These data are presented as if they were in a virtual vector
/// represented by the intance.
///
/// %vector_view has its interface to storage given by gsl::v_view, and most of
/// the ordinary vector-interface is given by gsl::v_iface.
///
/// %vector_view inherits these and provides template-constructors for an
/// instance of type gsl::v_iface<T, S, v_view>.
///
///   - One constructor is from a normal, decayed pointer and a length (and
///     optionally a stride).
///
///   - The other is from a non-decayed C-style array (which still retains
///     information about its length).
///
/// Template-value-parameter `S` indicates the number of elements in the vector
/// at compile-time.  If `S` be zero, then the number of elements in the vector
/// is determined at run-time.
///
/// When using %vector_view, one typically does not need to specify
/// template-parameters:
///
/// ~~~{.cpp}
/// #include <gslcpp/vector-view.hpp>
///
/// int main() {
///   double g[]= {1, 2, 3, 4, 5, 6};
///
///   // Deduce vector_view<double, 6> with stride=1:
///   gsl::vector_view v1= g;
///
///   // Deduce vector_view<double, 0> with three elements and stride=2:
///   gsl::vector_view v2(g, 3, 2);
///
///   v2[1]= 10; // Now g[2] is no longer 3 but 10.
///
///   // Deduce vector_view<double const, 0> with three elements and stride=2:
///   double const *h= g;
///   gsl::vector_view v3(h, 3, 2); // Only fetching allowed, not setting.
///
///   return 0;
/// }
/// ~~~
///
/// @tparam T  Type of each element in vector.
/// @tparam S  Compile-time number of elements (0 for number set at run-time).
template<typename T, size_t S= 0>
struct vector_view: public v_iface<T, S, v_view> {
  using P= v_iface<T, S, v_view>; ///< Type of ancestor.
  using P::P;

  /// Initialize view of standard (decayed) C-array.
  ///
  /// Arguments are ordered differently from those given to
  /// gsl_vector_viewiew_array_with_stride().  Putting stride at *end* allows
  /// it to have default value of 1.
  ///
  /// \param b  Pointer to first element of array and of view.
  /// \param n  Number of elements in view.
  /// \param s  Stride of elements relative to array.
  vector_view(T *b, size_t n, size_t s= 1): P(w_vector_view_array(b, s, n)) {}

  /// Initialize view of non-decayed C-array.
  /// \param b  Reference to non-decayed C-array.
  vector_view(T (&b)[S]): P(w_vector_view_array(b, 1, S)) {}
};


} // namespace gsl

// EOF
