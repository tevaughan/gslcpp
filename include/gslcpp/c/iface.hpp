/// @file       include/gslcpp/c/iface.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition for gsl::c::iface_, gsl::c::iface.

#pragma once

#include "impl/iface-double.hpp" // impl::iface<double>
#include <concepts> // same_as

/// Namespace for interface to GSL's native, C-language functions and types.
namespace gsl::c {


using std::same_as;


/// Interface required for template referring to GSL's native C-types and
/// C-functions for a given element-type.
/// @tparam I  Candidate type for interface.
template<typename I>
concept interface=
  requires(typename I::elem_t *e, std::size_t s, typename I::vector *v) {
  typename I::elem_t;
  typename I::vector;
  typename I::vector_view;
  { I::vector_view_array(e, s, s) } -> same_as<typename I::vector_view>;
  { I::subvector(v, s, s, s) } -> same_as<typename I::vector_view>;
};


/// GSL's native C-style interfaces associated with element-type `E`.
/// @param E  Type of each element in vector or matrix.
template<typename E>
requires interface<impl::iface<E>> struct iface: public impl::iface<E> {
  using P= impl::iface<E>; ///< Type of ancestor.

  using P::subvector;
  using P::vector_view_array;
  using typename P::elem_t;
  using typename P::vector;
  using typename P::vector_view;
};


} // namespace gsl::c

// EOF
