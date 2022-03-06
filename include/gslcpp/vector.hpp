/// \dir        include/gslcpp
/// \brief      Top-level directory for gslcpp's header-only library.

/// \file       include/gslcpp/vector.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::vector.

#pragma once

#include "vec/v-iface.hpp" // v_iface
#include "vec/v-stor.hpp" // v_stor

namespace gsl {


/// @tparam T  Type of each element in vector.
template<typename T, size_t S= 0> struct vector: public v_iface<T, S, v_stor> {
  using P= v_iface<T, S, v_stor>; ///< Type of ancestor.
  using P::P;

  vector(vector const &src): P(src.v().size) { memcpy(*this, src); }
  vector(vector &&)= default;
  vector &operator=(vector const &)= default;
  vector &operator=(vector &&)= default;

  template<template<typename, size_t> class V>
  vector(v_iface<T const, S, V> const &src): P(src.v().size) {
    memcpy(*this, src);
  }

  template<template<typename, size_t> class V>
  vector(v_iface<T, S, V> const &src): P(src.v().size) {
    memcpy(*this, src);
  }

  vector(T const *d, size_t len, size_t s= 1): P(len) {
    auto const cview= w_vector_view_array(d, s, len);
    memcpy(*this, v_iface<T const, 0, v_view>(cview));
  }

  vector(T const (&d)[S]): P(S) {
    auto const cview= w_vector_view_array(d, 1, S);
    memcpy(*this, v_iface<T const, S, v_view>(cview));
  }
};


} // namespace gsl

// EOF
