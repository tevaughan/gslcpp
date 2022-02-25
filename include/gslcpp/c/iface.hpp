/// \dir        include/gslcpp/c
/// \brief      Interface to GSL's native, C-language functions and types.

/// \file       include/gslcpp/c/iface.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
///
/// \brief      Definition for
///             gsl::c::vector,
///             gsl::c::vector_view,
///             gsl::c::basic_iface,
///             gsl::c::setter_iface, and
///             gsl::c::iface.

#pragma once

#include "xf.hpp" // xf
#include <concepts> // same_as

/// Interface to GSL's native, C-language functions and types.
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
/// However, for explanation of the relationships between `basic_iface` and
/// \ref gsl::c::setter_iface "setter_iface",
/// let us suppose, for the moment, that `E` designates a non-`const` type.
///
///   - Then \ref xf_double_const "xf<E const>" implements static functions,
///     each of which calls the appropriate function in GSL's native
///     C-interface, in order to cover all of `basic_iface`, and
///
///   - \ref xf_double "xf<E>" inherits from \ref xf_double_const "xf<E const>"
///     in order to pick up the functions needed to cover `basic_iface`.
///
///   - \ref xf_double "xf<E>" implements additional static functions in order
///     to cover \ref gsl::c::setter_iface "setter_iface".
///
/// \see \ref xf_generic
/// \see \ref xf_double_const
/// \see \ref xf_double
/// \see \ref xf_float_const
/// \see \ref xf_float
///
/// @tparam E  Type of each element; `E` can be `const` or non-`const`.
template<typename E>
concept basic_iface= requires(
      E *ep, ///< Pointer to element.
      FILE *f, ///< Pointer to buffered file-interface.
      char const *c, ///< Pointer to printf-style format-string.
      remove_const_t<E> *nce, ///< Pointer to guaranteed non-const element.
      std::size_t *sp, ///< Pointer to offset.
      std::size_t s, ///< Offset.
      vector<E> *v ///< Pointer to gsl_vector.
) {
  typename vector<E>;
  typename vector_view<E>;
  {
    xf<E>::vector_const_view_array(ep, s, s)
    } -> same_as<vector_view<E const>>;
  { xf<E>::const_subvector(v, s, s, s) } -> same_as<vector_view<E const>>;
  { xf<E>::get(v, s) } -> same_as<remove_const_t<E>>;
  { xf<E>::const_ptr(v, s) } -> same_as<E const *>;
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
      E * ep, ///< Pointer to element.
      E const &e, ///< Reference to immutable element.
      FILE *f, ///< Pointer to buffered file-interface.
      std::size_t s, ///< Offset.
      vector<E> *v, ///< Pointer to gsl_vector.
      vector<E> const *cv ///< Pointer to gsl_vector const.
) {
  { xf<E>::vector_view_array(ep, s, s) } -> same_as<vector_view<E>>;
  { xf<E>::subvector(v, s, s, s) } -> same_as<vector_view<E>>;
  { xf<E>::set(v, s, e) } -> same_as<void>;
  { xf<E>::set_all(v, e) } -> same_as<void>;
  { xf<E>::set_zero(v) } -> same_as<void>;
  { xf<E>::set_basis(v, s) } -> same_as<int>;
  { xf<E>::ptr(v, s) } -> same_as<E *>;
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


/// \anchor c_iface_generic
/// Generic template for interface to GSL-containers with element-type `E`.
/// \sa \ref c_iface_nonconst
/// \sa \ref c_iface_const
/// @tparam E  Primitive type of each element in vector or matrix.
template<typename E> struct iface;


/// Specialization for elements of `const`-type.
/// \anchor c_iface_const
/// `iface<E const>` implements gsl::c::basic_iface.
/// \sa \ref c_iface_generic
/// @param E  Non-`const` version of `const`-type of each element.
template<typename E>
requires basic_iface<E const> struct iface<E const>: public xf<E const> {};


/// Specialization for elements of non-`const` type.
/// \anchor c_iface_nonconst
/// `iface<E>` (for non-`const` `E`) implements  gsl::c::setter_iface.
/// \sa \ref c_iface_generic
/// @param E  (Non-`const`) type of each element.
template<typename E> requires setter_iface<E> struct iface<E>: public xf<E> {};


} // namespace gsl::c

// EOF
