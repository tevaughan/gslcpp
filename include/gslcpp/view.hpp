/// @file       include/gslcpp/view.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition for gsl::view_helper, gsl::vector_view.

#pragma once

// Use inline-definition of each accessor-function.
// - Define this before including `gsl_vector.h`.
#ifndef HAVE_INLINE
#  define HAVE_INLINE
#endif

#include "size-code.hpp" // VIEW
#include <gsl/gsl_vector.h> // gsl_vector_view, gsl_vector_const_view
#include <type_traits> // is_same_v

namespace gsl {


template<int S, typename V> class vector; // Forward declaration.


using std::is_same_v;


/// Generic structure for translating type of element into type of view.
/// - All work is done in specializations; generic instance is disallowed.
/// - Constness of element-type decides constness of view.
/// - `T` must be either `double` or `double const`.
/// - At present `view_helper` supports only `gsl_vector`.
/// - But `view_helper` could be expanded to support `gsl_matrix` too.
/// @tparam T  Type of each element in view.
template<typename T> struct view_helper {
  // Disallow instance of generic type.
  // - Specializations are used for each of `T=double` and `T=double const`.
  // - So any other value for `T` will fail on this assertion.
  static_assert(is_same_v<T, double> || is_same_v<T, double const>);
};


/// Specialization corresponding to element-type `double`.
template<> struct view_helper<double> {
  /// Vector-view associated with element-type `double`.
  using vector= gsl::vector<VIEW, gsl_vector_view>;
};


/// Specialization corresponding to element-type `double const`.
template<> struct view_helper<double const> {
  /// Vector-view associated with element-type `double const`.
  using vector= gsl::vector<VIEW, gsl_vector_const_view> const;
};


/// Vector-view associated with element-type `T`.
/// @tparam T  Type of each element in view.
template<typename T> using vector_view= typename view_helper<T>::vector;


/// Vector-view exposing immutable elements.
using vectorv= vector_view<double>;


/// Vector-view exposing immutable elements.
using vectorcv= vector_view<double const>;


} // namespace gsl

// EOF
