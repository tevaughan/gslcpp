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


/// Specific type of `gsl_vector` corresponding to element-type `E`. For
/// example, when `E==double`, the type is `gsl_vector`, and when `E==float`,
/// the type is `gsl_vector_float`.
/// @param E  Type of each element.
template<typename E> using vector= typename xf<E>::vector;

/// Specific type of `gsl_vector_view` corresponding to element-type `E`.  For
/// example, when `E==double`, the type is `gsl_vector_view`, and when
/// `E==float`, the type is `gsl_vector_float_view`.
/// @param E  Type of each element.
template<typename E> using vector_view= typename xf<E>::vector_view;


/// Requirements on the basic interface to GSL's native C-types and
/// C-functions.  The type of each element of the vector or the matrix might be
/// either `const` or non-`const`.
/// @tparam E  type of each element.
template<typename E>
concept basic_iface= requires(
      E *e,
      std::size_t s,
      vector<E> *v,
      FILE *f,
      char const *c,
      remove_const_t<E> *nce,
      std::size_t *sp) {
  typename vector<E>;
  typename vector_view<E>;
  { xf<E>::vector_view_array(e, s, s) } -> same_as<vector_view<E>>;
  { xf<E>::subvector(v, s, s, s) } -> same_as<vector_view<E>>;
  { xf<E>::get(v, s) } -> same_as<remove_const_t<E>>;
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
};


/// Requirements on the full interface to GSL's native C-types and C-functions.
/// The type of each element of the vector or the matrix must be non-`const`.
/// @tparam E  Type of each element.
template<typename E>
concept setter_iface= //
      basic_iface<E> //
            && //
            requires(
                  E const &e,
                  std::size_t s,
                  vector<E> *v,
                  vector<E> const *cv,
                  FILE *f) {
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
