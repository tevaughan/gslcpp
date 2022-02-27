/// \dir        include
/// \brief      Top-level directory of include-files of any library.

/// \dir        include/gslcpp
/// \brief      Top-level directory for gslcpp's header-only library.

/// \file       include/gslcpp/vector_s.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::vector_s.

#pragma once

#include "vec/iface.hpp" // vec::iface, vec::stor
#include "vec/stat.hpp" // vec::stat
#include "wrap/vector-view-array.hpp" // vector_view_array
#include <type_traits> // enable_if_t

/// Namespace for C++-interface to GSL.
namespace gsl {


using std::enable_if_t;


/// Vector whose storage has two key properties: (1) that its size is known
/// statically, at compile-time, and (2) that it is owned by vector.
///
/// `vector_s` has storage by way of \ref gsl::vec::stat, and most of the
/// interface is given by \ref gsl::vec::iface.
///
/// `vector_s` inherits these and provides template-constructors.
///
/// @tparam S  Number of elements in vector.
/// @tparam T  Type of each element in vector.
template<unsigned S, typename T= double>
struct vector_s: public vec::iface<vec::stat<S, T>> {
  using P= vec::iface<vec::stat<S, T>>; ///< Type of ancestor.
  using P::P;

  /// Construct by copying from dynamic vector of same size.
  /// - Mismatch in size produces run-time abort.
  /// @tparam OT  Type of other elements.
  /// @param ov  Reference to source-vector.
  template<typename OT> vector_s(vec::iface<vec::stat<0, OT>> const &ov) {
    memcpy(*this, ov);
  }

  /// Construct by copying from view of same size.
  /// - Mismatch in size produces run-time abort.
  /// @tparam OT  Type of other elements.
  /// @param ov  Reference to source-vector.
  template<typename OT> vector_s(vec::iface<vec::view<OT>> const &ov) {
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
    auto const cview= w_vector_view_array<T const>(d, 1, S);
    memcpy(*this, vec::iface<vec::view<T const>>(cview));
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
    auto const cview= w_vector_view_array<T const>(d + i, s, S);
    memcpy(*this, vec::iface<vec::view<T const>>(cview));
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


} // namespace gsl

// EOF
