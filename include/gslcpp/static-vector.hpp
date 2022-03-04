/// \dir        include
/// \brief      Top-level directory of include-files of any library.

/// \dir        include/gslcpp
/// \brief      Top-level directory for gslcpp's header-only library.

/// \file       include/gslcpp/static-vector.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::static_vector.

#pragma once

#include "vec/v-iface.hpp" // v_iface, v_stor
#include "vec/v-stor.hpp" // v_stor
#include <type_traits> // enable_if_t

/// Namespace for C++-interface to GSL.
namespace gsl {


using std::enable_if_t;


/// Vector whose storage has two key properties: (1) that its size is known
/// statically, at compile-time, and (2) that it is owned by vector.
///
/// %static_vector has storage by way of \ref gsl::v_stor, and most of the
/// interface is given by \ref gsl::v_iface.
///
/// %static_vector inherits these and provides template-constructors.
///
/// @tparam T  Type of each element in vector.
/// @tparam S  Number of elements in vector.
template<typename T, unsigned S= 0>
struct static_vector: public v_iface<v_stor<T, S>> {
  using P= v_iface<v_stor<T, S>>; ///< Type of ancestor.
  using P::P;

  /// Construct by copying from view of same size.
  /// - Mismatch in size produces run-time abort.
  /// @tparam OT  Type of other elements.
  /// @param ov  Reference to source-vector.
  template<typename OT> static_vector(v_iface<v_view<OT>> const &ov) {
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
  static_vector(T const (&d)[S]) {
    auto const cview= w_vector_view_array(d, 1, S);
    memcpy(*this, v_iface<v_view<T const>>(cview));
  }

  /// Initialize GSL's view, and initialize elements by copying from array.
  /// Stride is required as first argument in order to disambiguate this
  /// constructor from the one that takes a non-decayed array.
  /// @param s  Stride.
  /// @param d  Decayed C-style array.
  static_vector(size_t s, T const *d) {
    auto const cview= w_vector_view_array(d, s, S);
    memcpy(*this, v_iface<v_view<T const>>(cview));
  }

  /// Initialize GSL's view, and initialize vector by deep copy.
  /// @param v  Data to copy for initialization.
  static_vector(static_vector const &v) { memcpy(*this, v); }

  /// Assign vector by deep copy.
  /// @param v  Data to copy for initialization.
  /// @return  Reference to modified vector.
  static_vector &operator=(static_vector const &v) {
    memcpy(*this, v);
    return *this;
  }

  /// Assign vector by copying from array.
  /// @param d  Data to copy.
  /// @return  Reference to modified vector.
  static_vector &operator=(T const (&d)[S]) {
    auto const cview= w_vector_view_array(d, 1, S);
    memcpy(*this, v_iface<v_view<T const>>(cview));
    return *this;
  }
};


} // namespace gsl

// EOF
