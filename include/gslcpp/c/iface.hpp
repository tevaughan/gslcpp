/// @file       include/gslcpp/c/iface.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition for gsl::c::iface_, gsl::c::iface.

#pragma once

#include "impl/iface-double.hpp" // impl::iface<double>
#include <concepts> // same_as

/// Namespace for interface to GSL's native, C-language functions and types.
namespace gsl::c {


using std::remove_const_t;
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
  { I::vector_get(v, s) } -> same_as<remove_const_t<typename I::elem_t>>;
  { I::vector_ptr(v, s) } -> same_as<typename I::elem_t *>;
};


/// GSL's native C-style interfaces associated with element-type `E`.
/// @param E  Type of each element in vector or matrix.
template<typename E>
requires interface<impl::iface<E>> struct iface: public impl::iface<E> {};


} // namespace gsl::c

// EOF
