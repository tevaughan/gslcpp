/// \dir        include/gslcpp
/// \brief      Top-level directory for gslcpp's header-only library.

/// \file       include/gslcpp/vector.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::vector.

#pragma once

#include "vec/v-iface.hpp" // v_iface
#include "vec/v-stor.hpp" // v_stor

using std::enable_if_t;
using std::is_same_v;

namespace gsl {


template<typename T> struct ref_base {
  T *ptr;
  size_t size;
  size_t stride;

protected:
  ref_base(T *p, size_t siz, size_t str): ptr(p), size(siz), stride(str) {}
};


template<typename T, unsigned S> struct ref: public ref_base<T> {
  ref(T *p, size_t str= 1): ref_base<T>(p, S, str) {}
};


template<typename T> struct ref<T, 0>: public ref_base<T> {
  ref(T *p, size_t siz, size_t str= 1): ref_base<T>(p, siz, str) {}
};


/// @tparam T  Type of each element in vector.
template<typename T, unsigned S= 0>
struct vector: public v_iface<T, S, v_stor> {
  using P= v_iface<T, S, v_stor>; ///< Type of ancestor.
  using P::P;

  void allocate_if_necessary(size_t s) {
    if constexpr(S == 0) {
      using P::allocate;
      using P::v_;
      v_= allocate(s);
    } else {
      if(s != S) throw "mismatch in size";
    }
  }

  vector(vector const &src) {
    allocate_if_necessary(src.v().size);
    memcpy(*this, src);
  }

  template<template<typename, unsigned> class V>
  vector(v_iface<T const, S, V> const &src) {
    allocate_if_necessary(src.v().size);
    memcpy(*this, src);
  }

  template<template<typename, unsigned> class V>
  vector(v_iface<T, S, V> const &src) {
    allocate_if_necessary(src.v().size);
    memcpy(*this, src);
  }

  template<template<typename, unsigned> class V>
  vector &operator=(v_iface<T const, S, V> const &src) {
    memcpy(*this, src);
    return *this;
  }

  vector &operator=(vector const &src) {
    memcpy(*this, src);
    return *this;
  }

  template<template<typename, unsigned> class V>
  vector &operator=(v_iface<T, S, V> const &src) {
    memcpy(*this, src);
    return *this;
  }

  vector(T const (&d)[S]) {
    auto const cview= w_vector_view_array(d, 1, S);
    memcpy(*this, v_iface<T const, S, v_view>(cview));
  }

  vector &operator=(T const (&d)[S]) {
    auto const cview= w_vector_view_array(d, 1, S);
    memcpy(*this, v_iface<T const, 0, v_view>(cview));
    return *this;
  }

  vector(ref<T const, S> const &r) {
    allocate_if_necessary(r.size);
    auto const cview= w_vector_view_array(r.ptr, r.stride, r.size);
    memcpy(*this, v_iface<T const, 0, v_view>(cview));
  }
};


} // namespace gsl

// EOF
