/// @file       gsl/view-aux.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition for gsl::view_aux.

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
/// - Template-type parameter `T` must be either `double` or `double const`.
/// - No other choice is presently supported.
/// - At present `view_aux` is supports `gsl_vector` but could in principle be
///   expanded to support `gsl_matrix` too.
/// @tparam T  Type of each element in view.
template<typename T> struct view_aux;


/// Specialization corresponding to element-type `double`.
template<> struct view_aux<double> {
  /// Raw-GSL vector-view associated with element-type `double`.
  using raw_vector_type= gsl_vector_view;

  /// Vector-view associated with element-type `double`.
  using vector_type= vector<VIEW, raw_vector_type>;
};


/// Specialization corresponding to element-type `double const`.
template<> struct view_aux<double const> {
  /// Raw-GSL vector-view associated with element-type `double const`.
  using raw_vector_type= gsl_vector_const_view;

  /// Vector-view associated with element-type `double const`.
  using vector_type= vector<VIEW, raw_vector_type> const;
};


} // namespace gsl

// EOF
