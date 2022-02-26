/// \dir        include/gslcpp/c
/// \brief      Interface to GSL's native, C-language functions and types.

/// \file       include/gslcpp/c/iface.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
///
/// \brief      Definition for
///             gsl::c::basic_iface,
///             gsl::c::setter_iface, and
///             gsl::c::iface.

#pragma once

#include "vector.hpp" // vector
#include "xf.hpp" // xf
#include <concepts> // same_as

/// Interface to GSL's native, C-language functions and types.
namespace gsl::c {


using std::remove_const_t;
using std::same_as;


template<typename E> concept basic_iface= true;


/// Requirements on the full interface to GSL's native C-types and C-functions.
///
/// `E` must here be a non-`const` type.  Each of the types and functions
/// identified in `setter_iface` need be implemented only in
/// \ref xf_double "xf<E>", not also in \ref xf_double_const "xf<E const>".
///
/// \sa \ref gsl::c::basic_iface
///
/// @tparam E  Type of each element.
template<typename E>
concept setter_iface= basic_iface<E> && //
requires(
      E const &e, ///< Reference to immutable element.
      FILE *f, ///< Pointer to buffered file-interface.
      std::size_t s, ///< Offset.
      vector<E> *v, ///< Pointer to gsl_vector.
      vector<E> const *cv ///< Pointer to gsl_vector const.
) {
  { xf<E>::fread(f, v) } -> same_as<int>;
  { xf<E>::fscanf(f, v) } -> same_as<int>;
  { xf<E>::swap_elements(v, s, s) } -> same_as<int>;
  { xf<E>::reverse(v) } -> same_as<int>;
  { xf<E>::add(v, cv) } -> same_as<int>;
  { xf<E>::sub(v, cv) } -> same_as<int>;
  { xf<E>::mul(v, cv) } -> same_as<int>;
  { xf<E>::div(v, cv) } -> same_as<int>;
  { xf<E>::scale(v, e) } -> same_as<int>;
  { xf<E>::add_constant(v, e) } -> same_as<int>;
  { xf<E>::memcpy(v, cv) } -> same_as<int>;
  { xf<E>::swap(v, v) } -> same_as<int>;
};


/// \anchor c_iface_generic
/// Generic template for interface to GSL-containers with element-type `E`.
/// \sa \ref c_iface_nonconst
/// \sa \ref c_iface_const
/// @tparam E  Primitive type of each element in vector or matrix.
template<typename E> struct iface;


/// \anchor c_iface_const
/// Specialization for elements of `const`-type.
/// `iface<E const>` implements gsl::c::basic_iface.
/// \sa \ref c_iface_generic
/// @param E  Non-`const` version of `const`-type of each element.
template<typename E>
requires basic_iface<E const> struct iface<E const>: public xf<E const> {};


/// \anchor c_iface_nonconst
/// Specialization for elements of non-`const` type.
/// `iface<E>` (for non-`const` `E`) implements  gsl::c::setter_iface.
/// \sa \ref c_iface_generic
/// @param E  (Non-`const`) type of each element.
template<typename E> requires setter_iface<E> struct iface<E>: public xf<E> {};


} // namespace gsl::c

// EOF
