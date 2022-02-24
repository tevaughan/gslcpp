/// @file       include/gslcpp/c/iface.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
///
/// @brief      Definition for
///             gsl::c::vector,
///             gsl::c::vector_view,
///             gsl::c::basic_iface,
///             gsl::c::setter_iface, and
///             gsl::c::iface.

#pragma once

#include "xf.hpp" // xf
#include <concepts> // same_as

/// Namespace for interface to GSL's native, C-language functions and types.
namespace gsl::c {


using std::remove_const_t;
using std::same_as;


/// Specific type of `gsl_vector` corresponding to element-type `E`.
///
/// For example, when `E==double`, the type is `gsl_vector`, and when
/// `E==float`, the type is `gsl_vector_float`.
///
/// @param E  Type of each element.
template<typename E> using vector= typename xf<E>::vector;

/// Specific type of `gsl_vector_view` corresponding to element-type `E`.
///
/// For example, when `E==double`, the type is `gsl_vector_view`, and when
/// `E==float`, the type is `gsl_vector_float_view`.
///
/// @param E  Type of each element.
template<typename E> using vector_view= typename xf<E>::vector_view;


/// Requirements on the basic interface to GSL's native C-types and
/// C-functions.
///
/// `E` may here be a `const` or a non-`const` type and is the primitive type
/// (such as `double`) of each element in a vector or matrix.
///
/// For explanation of the relationships between `basic_iface` and \ref
/// gsl::c::setter_iface "setter_iface", however, let us suppose, for the
/// moment, that `E` designates a non-`const` type.  Then `xf<E>` implements
/// static functions, each of which calls the appropriate function in GSL's
/// native C-interface.  `xf<E const>` implements all of `basic_iface`, and
/// `xf<E>` implements all of \ref gsl::c::setter_iface "setter_iface".
///
/// Although `xf<E>` inherits from `xf<E const>`, three of the functions
/// identified in `basic_iface` and implemented in `xf<E const>` must be
/// re-implemented in `xf<E>` so that the non-`const` version exists for each
/// function.  They are
/// - `xf<E>::vector_view_array()`
/// - `xf<E>::subvector()`, and
/// - `xf<E>::ptr()`.
///
/// \sa \ref gsl::c::setter_iface "setter_iface"
/// \sa \ref gsl::c::xf<double>::vector_view_array()
///          "xf<double>::vector_view_array"
/// \sa \ref gsl::c::xf<double>::subvector() "xf<double>::subvector"
/// \sa \ref gsl::c::xf<double>::ptr() "xf<double>::ptr"
///
/// @tparam E  Type of each element; `E` can be `const` or non-`const`.
template<typename E>
concept basic_iface= requires(
      E *e,
      FILE *f,
      char const *c,
      remove_const_t<E> *nce,
      std::size_t *sp,
      std::size_t s,
      vector<E> *v) {
  typename vector<E>;
  typename vector_view<E>;
  // Need const and non-const versions of vector_view_array.
  { xf<E>::vector_view_array(e, s, s) } -> same_as<vector_view<E>>;
  // Need const and non-const versions of subvector.
  { xf<E>::subvector(v, s, s, s) } -> same_as<vector_view<E>>;
  { xf<E>::get(v, s) } -> same_as<remove_const_t<E>>;
  // Need const and non-const versions of ptr.
  { xf<E>::ptr(v, s) } -> same_as<E *>;
  { xf<E>::fwrite(f, v) } -> same_as<int>;
  { xf<E>::fprintf(f, v, c) } -> same_as<int>;
  { xf<E>::sum(v) } -> same_as<remove_const_t<E>>;
  { xf<E>::max(v) } -> same_as<remove_const_t<E>>;
  { xf<E>::min(v) } -> same_as<remove_const_t<E>>;
  { xf<E>::minmax(v, nce, nce) } -> same_as<void>;
  { xf<E>::max_index(v) } -> same_as<std::size_t>;
  { xf<E>::min_index(v) } -> same_as<std::size_t>;
  { xf<E>::minmax_index(v, sp, sp) } -> same_as<void>;
  { xf<E>::isnull(v) } -> same_as<bool>;
  { xf<E>::ispos(v) } -> same_as<bool>;
  { xf<E>::isneg(v) } -> same_as<bool>;
  { xf<E>::isnonneg(v) } -> same_as<bool>;
  { xf<E>::equal(v, v) } -> same_as<bool>;
};


/// Requirements on the full interface to GSL's native C-types and C-functions.
///
/// `E` must here be a non-`const` type. Each of the types and functions
/// identified in `setter_iface` need be implemented only in xf<E>, not also in
/// xf<E const>.
///
/// \sa \ref gsl::c::basic_iface "basic_iface"
///
/// @tparam E  Type of each element.
template<typename E>
concept setter_iface= basic_iface<E> && //
requires(
      E const &e, std::size_t s, vector<E> *v, vector<E> const *cv, FILE *f) {
  { xf<E>::set(v, s, e) } -> same_as<void>;
  { xf<E>::set_all(v, e) } -> same_as<void>;
  { xf<E>::set_zero(v) } -> same_as<void>;
  { xf<E>::set_basis(v, s) } -> same_as<int>;
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
  { xf<E>::axpby(e, cv, e, v) } -> same_as<int>;
  { xf<E>::memcpy(v, cv) } -> same_as<int>;
  { xf<E>::swap(v, v) } -> same_as<int>;
};


/// Declaration of generic template for GSL's native C-style interfaces
/// associated with elements of type `E`.  Two specializations are defined, one
/// for elements of non-`const` type and the other for elements of
/// `const`-type.
/// @tparam E  Type of each element.
template<typename E> struct iface;


/// Specialization for vector- and matrix-elements of `const`-type.
/// @param E  Non-`const` version of `const`-type of each element.
template<typename E>
requires basic_iface<E const> struct iface<E const>: public xf<E const> {};


/// Specialization for vector- and matrix-elements of non-`const` type.
/// @param E  (Non-`const`) type of each element.
template<typename E> requires setter_iface<E> struct iface<E>: public xf<E> {};


} // namespace gsl::c

// EOF
