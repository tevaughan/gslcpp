/// @file       include/gslcpp/vector.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition for gsl::vector.

// Use old-style include-guards instead of '#pragma once' here because we have
// to include at bottom implementation-headers, each of which includes this
// file; old-style guards here make neovim happy.
#ifndef GSL_VECTOR_HPP
#  define GSL_VECTOR_HPP

#  include "vec-iface.hpp" // vec_iface
#  include "vec-stor.hpp" // vec_stor
#  include <algorithm> // swap
#  include <type_traits> // is_same_v, enable_if_t

/// Namespace for C++-interface to small subset of GSL's functionality,
/// initially just minimization, which requires using gsl_vector.
namespace gsl {


using std::enable_if_t;
using std::is_const_v;
using std::is_same_v;


template<unsigned S, typename T= double>
struct vector_s: public vec_iface<vec_stor<S, T>> {
  using P= vec_iface<vec_stor<S, T>>;
  using P::P;

  /// Construct by copying from dynamic vector of same size.
  /// - Mismatch in size produces run-time abort.
  /// @tparam OT  Type of other elements.
  /// @param ov  Reference to source-vector.
  template<typename OT> vector_s(vec_iface<vec_stor<0, OT>> const &ov) {
    memcpy(*this, ov);
  }

  /// Construct by copying from view of same size.
  /// - Mismatch in size produces run-time abort.
  /// @tparam OT  Type of other elements.
  /// @param ov  Reference to source-vector.
  template<typename OT> vector_s(vec_iface<vec_view<OT>> const &ov) {
    memcpy(*this, ov);
  }

  /// Initialize GSL's view, and initialize elements by copying from array.
  /// - Size-parameter `S` can be *deduced* from the argument!
  /// - So, for example, one can do this:
  ///   ```c++
  ///   double d[]= {2.0, 3.0, 4.0};
  ///   vector v(d); // No template-parameter required!
  ///   ```
  /// @param d  Data to copy for initialization.
  vector_s(T const (&d)[S]) {
    auto const cview= c_iface<T const>::vec_view_array(d, 1, S);
    memcpy(*this, vec_iface<vec_view<T const>>(cview));
  }

  /// Initialize GSL's view, and initialize vector by copying from array.
  /// - Mismatch in size produces run-time abort.
  /// - For example:
  ///   ```c++
  ///   double d[]= {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  ///   vector<3> v(d, 1, 2); // Start at offset 1 (not 0) and use stride 2.
  ///   // So v == [2.0, 4.0, 6.0].
  ///   ```
  /// @tparam N  Number of elements in non-decayed C-style array.
  /// @param d  Non-decayed C-style array.
  /// @param i  Offset of initial element to be copied.
  /// @param s  Stride of elements to be copied.
  template<unsigned N, typename= enable_if_t<N != S>>
  vector_s(T const (&d)[N], size_t i= 0, size_t s= 1) {
    if(i + s * (S - 1) > N - 1) {
      throw std::runtime_error("source-array not big enough");
    }
    auto const cview= c_iface<T const>::vec_view_array(d + i, s, S);
    memcpy(*this, vec_iface<vec_view<T const>>(cview));
  }

  /// Initialize GSL's view, and initialize elements by copying from array.
  /// - Stride is required as first argument in order to disambiguate this
  ///   constructor from the one that takes a non-decayed array.
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
  /// @param v  Data to copy for initialization.
  /// @return  Reference to modified vector.
  vector_s &operator=(T const (&d)[S]) {
    memcpy(*this, view(d));
    return *this;
  }
};


template<typename T>
struct vector_d: public vec_iface<vec_stor<0, T>> {
  using P= vec_iface<vec_stor<0, T>>;
  using P::P;
};


template<typename T> struct vector_v: public vec_iface<vec_view<T>> {
  using P= vec_iface<vec_view<T>>;
  using P::P;

  /// Initialize view of standard (decayed) C-array.
  /// - Arguments are reordered relative to those given to
  ///   gsl_vector_view_array_with_stride().
  /// - Putting number of element at *beginning* disambiguates from constructor
  ///   from non-decayed array.
  /// - Putting stride at *end* allows it to have default value of 1.
  /// @param b  Pointer to first element of array and of view.
  /// @param n  Number of elements in view.
  /// @param s  Stride of view relative to array.
  vector_v(size_t n, T *b, size_t s= 1):
      P(c_iface<T>::make_vec_view(n, b, s)) {}

  /// Initialize view of non-decayed C-array.
  /// - Arguments are reordered from those given to
  ///   gsl_vector_subvector_with_stride().
  /// - Putting initial offset and stride at end allows every argument to have
  ///   good default (N for number of elements in view, 0 for initial offset,
  ///   and 1 for stride).
  /// @tparam N  Number of elements in array.
  /// @param b  Reference to non-decayed C-array.
  /// @param n  Number of elements in view.
  /// @param i  Offset in array of first element in view.
  /// @param s  Stride of view relative to array.
  template<int N>
  vector_v(T (&b)[N], size_t n= N, size_t i= 0, size_t s= 1):
      P(c_iface<T>::make_vec_view(b, n, i, s)) {}

  vector_v(vec_iface<vec_view<T>> v): P(v.cview()) {}
};


} // namespace gsl

#endif // ndef GSL_VECTOR_HPP

// EOF
