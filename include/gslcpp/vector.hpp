/// \file       include/gslcpp/vector.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::vector.

#pragma once

#include "vec/v-dyna.hpp" // v_dyna
#include "vec/v-iface.hpp" // v_iface

namespace gsl {


/// Vector whose storage has two key properties: (1) that storage-size is
/// determined dynamically, at run-time, and (2) that storage is owned by
/// vector.
///
/// Storage is provided by \ref gsl::v_dyna, and most of interface is
/// provided by \ref gsl::v_iface.
///
/// %vector inherits these and provides template-constructors.
///
/// \sa \ref gsl::v_dyna
/// \sa \ref gsl::v_iface
///
/// @tparam T  Type of each element in vector.
template<typename T> struct vector: public v_iface<v_dyna<T>> {
  using P= v_iface<v_dyna<T>>; ///< Type of ancestor.
  using P::P;
  using typename v_dyna<T>::alloc_type;

  /// Allocate vector and its descriptor, and perform deep copy on
  /// construction.
  /// @tparam S  Type of source.
  /// @param src  Vector to copy.
  template<typename S>
  vector(v_iface<S> const &src): P(src.v().size, alloc_type::ALLOC) {
    memcpy(*this, src);
  }

  /// Deallocate existing vector and its descriptor; allocate new vector and
  /// its descriptor; and perform deep copy on assignment.
  /// @tparam S  Type of source.
  /// @param src  Vector to copy.
  /// @return  Reference to instance after modification.
  template<typename S> vector &operator=(v_iface<S> const &src) {
    using P::alloc_type_;
    using P::v_;
    alloc_type_= alloc_type::ALLOC;
    v_= allocate(src.v().size);
    memcpy(*this, src);
    return *this;
  }
};


} // namespace gsl

// EOF
