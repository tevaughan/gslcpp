/// @file       include/gslcpp/vec.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Declaration for gsl::vec and for functions for vectors.

#pragma once

#include "view.hpp" // vector_view

namespace gsl {


using std::enable_if_t;


/// Base-class for vector and name-space for static functions.
/// - An instance of vec does not have any fields.
/// - Also, vec has no function to access field of descendant.
/// - Yet some static functions can be collected here.
/// - Static function belongs in `vec` if function's arguments do not
///   distinguish it from similar function for matrix in global context of
///   namespace gsl.
/// - This allows GSL's matrix-capability cleanly to be added to library if
///   desired.
/// - Static function whose name is generic but whose arguments involve
///   vector-types can reside at root of namespace gsl and need not reside in
///   vec.
struct vec {
  /// View of standard (decayed) C-array.
  /// - Arguments are reordered relative to those of
  ///   gsl_vector_view_array_with_stride().
  /// - Putting number of elements at *beginning* distinguishes view of decayed
  ///   C-array from view of non-decayed C-array.
  /// - Putting stride at *end* allows it to have default value of 1.
  /// - SFINAE is not used to restrict type of `T` to `double` or `double
  ///   const`, but static assertion is included in implementation.
  /// @tparam T  Type (`double` or `double const`) of each element.
  /// @param n  Number of elements in view.
  /// @param b  Pointer to first element of array and of view.
  /// @param s  Stride of view relative to array.
  /// @return  View of array.
  template<typename T> static vector_view<T> view(size_t n, T *b, size_t s= 1);

  /// View of non-decayed C-array.
  /// - Arguments are reordered from those given to
  ///   gsl_vector_subvector_with_stride().
  /// - Putting initial offset and stride at end allows every argument to have
  ///   good default (N for number of elements in view, 0 for initial offset,
  ///   and 1 for stride).
  /// - SFINAE is not used to restrict type of `T` to `double` or `double
  ///   const`, but static assertion is included in implementation.
  /// @tparam T  Type (`double` or `double const`) of each element.
  /// @tparam N  Number of elements in array.
  /// @param b  Reference to non-decayed C-array.
  /// @param n  Number of elements in view.
  /// @param i  Offset in array of first element in view.
  /// @param s  Stride of view relative to array.
  /// @return  View of array.
  template<typename T, int N>
  static vector_view<T> view(T (&b)[N], size_t n= N, size_t i= 0, size_t s= 1);
};


} // namespace gsl

// EOF
