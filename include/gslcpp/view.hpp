/// @file       include/gslcpp/view.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition for gsl::view.

#pragma once

// Use inline-definition of each accessor-function.
// - Define this before including `gsl_vector.h`.
#ifndef HAVE_INLINE
#define HAVE_INLINE
#endif

#include "size-code.hpp" // VIEW
#include <gsl/gsl_vector.h> // gsl_vector_view, gsl_vector_const_view

namespace gsl {


template<int S, typename V> class vector; // Forward declaration.


/// Generic structure used to translate type of element into type of view.
/// `view` uses constness of element-type `T` in order to provide
/// appropriate type for view.
/// - Template-type parameter `T` must be either `double` or `double const`.
/// - At present `view` is supports only `gsl_vector`.
/// - `view` could be expanded to support `gsl_matrix` too.
/// @tparam T  Type of each element in view.
template<typename T> struct view;


/// Specialization corresponding to element-type `double`.
template<> struct view<double> {
  /// Raw-GSL vector-view associated with element-type `double`.
  using raw_vector= gsl_vector_view;

  /// Vector-view associated with element-type `double`.
  using vector= gsl::vector<VIEW, raw_vector>;
};


/// Specialization corresponding to element-type `double const`.
template<> struct view<double const> {
  /// Raw-GSL vector-view associated with element-type `double const`.
  using raw_vector= gsl_vector_const_view;

  /// Vector-view associated with element-type `double const`.
  using vector= gsl::vector<VIEW, raw_vector> const;
};


} // namespace gsl

// EOF
