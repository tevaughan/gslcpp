/// @file       include/gslcpp/vec-base.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Declaration for gsl::vec_base and for functions for vectors.

#pragma once

#include "view.hpp" // view
#include <iosfwd> // ostream

namespace gsl {


template<typename D> struct vec_iface; // Forward-declaration.


/// Base-class name-space for static functions.
/// - An instance of vec_base does not have any fields.
/// - Also, vec_base has no function to access field of descendant.
/// - Yet some static functions can be collected here.
/// - Static function belongs in `vec_base` if function's arguments do not
///   distinguish it from similar function for matrix.
/// - This allows GSL's matrix-capability cleanly to be added to library if
///   desired.
/// - Static function whose name is generic but whose arguments involve
///   vector-types can reside at root of namespace gsl and need not reside in
///   vec_base.
struct vec_base {
  /// View of standard (decayed) C-array.
  /// - Arguments are reordered relative to those of
  ///   gsl_vector_view_array_with_stride().
  /// - Putting number of elements at *beginning* distinguishes view of decayed
  ///   C-array from view of non-decayed C-array.
  /// - Putting stride at *end* allows it to have default value of 1.
  /// @tparam T  Type of each element.
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
  /// @tparam T  Type of each element.
  /// @tparam N  Number of elements in array.
  /// @param b  Reference to non-decayed C-array.
  /// @param n  Number of elements in view.
  /// @param i  Offset in array of first element in view.
  /// @param s  Stride of view relative to array.
  /// @return  View of array.
  template<typename T, int N>
  static vector_view<T> view(T (&b)[N], size_t n= N, size_t i= 0, size_t s= 1);
};


#if defined(GSL_VER) && GSL_VER > 26
/// Linearly combine vector `x` into vector `y` in place.
/// @tparam X  Type of first source-vector.
/// @tparam Y  Type of second source-vector and destination-vector.
/// @param a  Coeffient of `x`.
/// @param x  First source-vector.
/// @param b  Coefficient of `y`.
/// @param y  Second source-vector and destination-vector.
/// @return  TBD.
template<typename X, typename Y>
int axpby(double a, vec_iface<X> const &x, double b, vec_iface<Y> &y);
#endif


/// Test equality of two vectors.
/// @tparam U  Type of one descendant of vec_iface.
/// @tparam V  Type of other descendant of vec_iface.
/// @param u  Reference to one vector.
/// @param v  Reference to other vector.
/// @return  True only if vectors be equal.
template<typename U, typename V>
bool equal(vec_iface<U> const &u, vec_iface<V> const &v);


/// Copy data from source, whose length must be same as that of destination.
/// @tparam D  Type of descendant destination.
/// @tparam S  Type of descendant source.
/// @param dst  Destination.
/// @param src  Source.
/// @return  TBD.
template<typename D, typename S>
int memcpy(vec_iface<D> &dst, vec_iface<S> const &src);


/// Swap contents of one and other vector, each with same length.
/// @tparam V  Type of one vector.
/// @tparam W  Type of other vector.
/// @param v  One vector.
/// @param w  Other vector.
/// @return  TBD.
template<typename V, typename W> int swap(vec_iface<V> &v, vec_iface<W> &w);


/// Test equality of two vectors.
/// @tparam U  Type of one descendant of vec_iface.
/// @tparam V  Type of other descendant of vec_iface.
/// @param u  Reference to one vector.
/// @param v  Reference to other vector.
/// @return  True only if vectors be equal.
template<typename U, typename V>
bool operator==(vec_iface<U> const &u, vec_iface<V> const &v) {
  return equal(u, v);
}


/// Test inequality of two vectors.
/// @tparam U  Type of one descendant of vec_iface.
/// @tparam V  Type of other descendant of vec_iface.
/// @param u  Reference to one vector.
/// @param v  Reference to other vector.
/// @return  True only if vectors be unequal.
template<typename U, typename V>
bool operator!=(vec_iface<U> const &u, vec_iface<V> const &v) {
  return !equal(u, v);
}


/// Print vector to output-stream.
/// @tparam U  Type of descendant of vec_iface.
/// @param os  Reference to output-stream.
/// @param u  Reference to vector.
/// @return  Reference to modified output-stream.
template<typename U>
std::ostream &operator<<(std::ostream &os, vec_iface<U> const &u);


} // namespace gsl

// EOF
