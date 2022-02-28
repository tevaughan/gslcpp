/// \file       include/gslcpp/static-vector-complex.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::static_vector_complex.

#pragma once

#include "vec/v-iface.hpp" // v_iface, v_stor
#include "vec/v-stat.hpp" // v_stat
#include "wrap/complex.hpp" // complex
#include "wrap/vector-view-array.hpp" // vector_view_array
#include <type_traits> // enable_if_t

/// Namespace for C++-interface to GSL.
namespace gsl {


using std::enable_if_t;


/// With complex elements, vector whose storage has two key properties: (1)
/// that its size is known statically, at compile-time, and (2) that it is
/// owned by vector.
///
/// %static_vector_complex has storage by way of \ref gsl::v_stat, and most of
/// the interface is given by \ref gsl::v_iface.
///
/// %static_vector_complex inherits these and provides template-constructors.
///
/// @tparam S  Number of elements in vector.
/// @tparam A  Type of each element in initializing array (not in vector!).
template<unsigned S, typename A= double>
struct static_vector_complex: public v_iface<v_stat<S, complex_type<A>>> {
  using E= complex_type<A>; ///< Type of element in vector.
  using P= v_iface<v_stat<S, E>>; ///< Type of ancestor.
  using P::P;

  /// Construct by copying from dynamic vector of same size.
  /// - Mismatch in size produces run-time abort.
  /// @tparam OT  Type of elements in other vector.
  /// @param ov  Reference to source-vector.
  template<typename OT>
  static_vector_complex(v_iface<v_stat<0, OT>> const &ov) {
    memcpy(*this, ov);
  }

  /// Construct by copying from view of same size.
  /// - Mismatch in size produces run-time abort.
  /// @tparam OT  Type of elements in other vector.
  /// @param ov  Reference to source-vector.
  template<typename OT> static_vector_complex(v_iface<v_view<OT>> const &ov) {
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
  static_vector_complex(A const (&d)[2 * S]) {
    auto const cview= w_vector_view_array<E const>(d, 1, S);
    memcpy(*this, v_iface<v_view<E const>>(cview));
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
  /// @param i  Offset (in array not vector!) of initial element to be copied.
  /// @param s  Stride of elements (taken as pairs!) to be copied.
  template<unsigned N, typename= enable_if_t<N != 2 * S>>
  static_vector_complex(A const (&d)[N], size_t i= 0, size_t s= 1) {
    if(i + 2 * s * (2 * S - 1) > N - 1) {
      throw std::runtime_error("source-array not big enough");
    }
    auto const cview= w_vector_view_array<E const>(d + i, s, S);
    memcpy(*this, v_iface<v_view<E const>>(cview));
  }

  /// Initialize GSL's view, and initialize elements by copying from array.
  /// Stride is required as first argument in order to disambiguate this
  /// constructor from the one that takes a non-decayed array.
  /// @param s  Stride.
  /// @param d  Decayed C-style array.
  static_vector_complex(size_t s, A const *d): static_vector_complex() {
    auto const cview= w_vector_view_array<E const>(d, s, S);
    memcpy(*this, v_iface<v_view<E const>>(cview));
  }

  /// Initialize GSL's view, and initialize vector by deep copy.
  /// @param v  Data to copy for initialization.
  static_vector_complex(static_vector_complex const &v) { memcpy(*this, v); }

  /// Assign vector by deep copy.
  /// @param v  Data to copy for initialization.
  /// @return  Reference to modified vector.
  static_vector_complex &operator=(static_vector_complex const &v) {
    memcpy(*this, v);
    return *this;
  }

  /// Assign vector by copying from array.
  /// @param d  Data to copy.
  /// @return  Reference to modified vector.
  static_vector_complex &operator=(A const (&d)[2 * S]) {
    auto const cview= w_vector_view_array<E const>(d, 1, S);
    memcpy(*this, v_iface<v_view<E const>>(cview));
    return *this;
  }
};


} // namespace gsl

// EOF
