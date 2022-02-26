#pragma once
#include "vector.hpp" // vector
#include "xf.hpp" // xf
#include <concepts> // same_as

/// Interface to GSL's native, C-language functions and types.
namespace gsl::c {


using std::same_as;


template<typename E> concept basic_iface= true;


template<typename E>
concept setter_iface= basic_iface<E> &&
requires(E const &e, std::size_t s, vector<E> *v, vector<E> const *cv) {
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
