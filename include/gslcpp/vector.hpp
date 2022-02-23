/// @file       include/gslcpp/vector.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition for gsl::vector_s, gsl::vector_d, and gsl::vector_v.

#pragma once

#include "vec/iface.hpp" // vec_iface, vec_stor, c_iface
#include <algorithm> // swap
#include <type_traits> // enable_if_t

/// Namespace for C++-interface to GSL.
namespace gsl {


using std::enable_if_t;


/// Vector whose storage is static, on stack, defined at compile-time, and
/// owned by instance of vector.
/// @tparam S  Number of elements in vector.
/// @tparam T  Type of each element in vector.
template<unsigned S, typename T= double>
struct vector_s: public vec::iface<vec_static<S, T>> {
  using P= vec::iface<vec_static<S, T>>; ///< Type of ancestor.
  using P::P;

  /// Construct by copying from dynamic vector of same size.
  /// - Mismatch in size produces run-time abort.
  /// @tparam OT  Type of other elements.
  /// @param ov  Reference to source-vector.
  template<typename OT> vector_s(vec::iface<vec_static<0, OT>> const &ov) {
    memcpy(*this, ov);
  }

  /// Construct by copying from view of same size.
  /// - Mismatch in size produces run-time abort.
  /// @tparam OT  Type of other elements.
  /// @param ov  Reference to source-vector.
  template<typename OT> vector_s(vec::iface<vec_view<OT>> const &ov) {
    memcpy(*this, ov);
  }

  /// Initialize GSL's view, and initialize elements by copying from array.
  /// Size-parameter `S` can be *deduced* from the argument!  So, for example,
  /// one can do this:
  /// ~~~{cpp}
  ///   double d[]= {2.0, 3.0, 4.0};
  ///   vector v(d); // No template-parameter required!
  /// ~~~
  /// @param d  Data to copy for initialization.
  vector_s(T const (&d)[S]) {
    auto const cview= c::iface<T const>::vector_view_array(d, 1, S);
    memcpy(*this, vec::iface<vec_view<T const>>(cview));
  }

  /// Initialize GSL's view, and initialize vector by copying from array.
  /// Mismatch in size produces run-time abort.  For example:
  /// ~~~{cpp}
  ///   double d[]= {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  ///   vector<3> v(d, 1, 2); // Start at offset 1 (not 0) and use stride 2.
  ///   // So v == [2.0, 4.0, 6.0].
  /// ~~~
  /// @tparam N  Number of elements in non-decayed C-style array.
  /// @param d  Non-decayed C-style array.
  /// @param i  Offset of initial element to be copied.
  /// @param s  Stride of elements to be copied.
  template<unsigned N, typename= enable_if_t<N != S>>
  vector_s(T const (&d)[N], size_t i= 0, size_t s= 1) {
    if(i + s * (S - 1) > N - 1) {
      throw std::runtime_error("source-array not big enough");
    }
    auto const cview= c::iface<T const>::vector_view_array(d + i, s, S);
    memcpy(*this, vec::iface<vec_view<T const>>(cview));
  }

  /// Initialize GSL's view, and initialize elements by copying from array.
  /// Stride is required as first argument in order to disambiguate this
  /// constructor from the one that takes a non-decayed array.
  /// @param s  Stride.
  /// @param d  Decayed C-style array.
  vector_s(size_t s, T const *d): vector_s() { memcpy(*this, view(S, d, s)); }

  /// Initialize GSL's view, and initialize vector by deep copy.
  /// @param v  Data to copy for initialization.
  vector_s(vector_s const &v) { memcpy(*this, v); }

  /// Assign vector by deep copy.
  /// @param v  Data to copy for initialization.
  /// @return  Reference to modified vector.
  vector_s &operator=(vector_s const &v) {
    memcpy(*this, v);
    return *this;
  }

  /// Assign vector by copying from array.
  /// @param d  Data to copy.
  /// @return  Reference to modified vector.
  vector_s &operator=(T const (&d)[S]) {
    memcpy(*this, view(d));
    return *this;
  }
};


/// Vector with storage allocated dynamically, at run-time, and owned by
/// instance of vector.
/// @tparam T  Type of each element in vector.
template<typename T> struct vector_d: public vec::iface<vec_dynamic<T>> {
  using P= vec::iface<vec_dynamic<T>>; ///< Type of ancestor.
  using P::P;
};


/// Vector with storage not owned by instance of vector.
template<typename T> struct vector_v: public vec::iface<vec_view<T>> {
  using P= vec::iface<vec_view<T>>; ///< Type of ancestor.
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
      P(c::iface<T>::vector_view_array(b, s, n)) {}

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
      P(c::iface<T>::vector_view_array(b + i, s, n)) {}

  /// Initialize view of other view.
  /// @param v  Other view.
  vector_v(vec::iface<vec_view<T>> v): P(v.cview()) {}
};


} // namespace gsl

// EOF
