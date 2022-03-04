/// \dir        include/gslcpp
/// \brief      Top-level directory for gslcpp's header-only library.

/// \file       include/gslcpp/vector.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::vector.

#pragma once

#include "vec/v-iface.hpp" // v_iface
#include "vec/v-stor.hpp" // v_stor

namespace gsl {


/// Vector whose storage has two key properties: (1) that storage-size is
/// determined dynamically, at run-time, and (2) that storage is owned by
/// vector.
///
/// @tparam T  Type of each element in vector.
template<typename T, unsigned S= 0>
struct vector: public v_iface<v_stor<T, S>> {
  using P= v_iface<v_stor<T, S>>; ///< Type of ancestor.
  using P::P;

  /// Type used to specify kind of dynamic allocation.
  using alloc_type= typename v_stor<T>::alloc_type;

  /// Allocate vector and its descriptor, and perform deep copy on
  /// construction.
  /// @tparam U  Type of source.
  /// @param src  Vector to copy.
  template<typename U>
  vector(v_iface<U> const &src): P(src.v().size, alloc_type::ALLOC) {
    memcpy(*this, src);
  }

  /// Deallocate existing vector and its descriptor; allocate new vector and
  /// its descriptor; and perform deep copy on assignment.
  /// @tparam U  Type of source.
  /// @param src  Vector to copy.
  /// @return  Reference to instance after modification.
  template<typename U> vector &operator=(v_iface<U> const &src) {
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
