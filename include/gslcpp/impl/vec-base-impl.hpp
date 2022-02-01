/// @file       gsl/impl/vec-base-impl.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition for gsl::vec_base and for functions for vectors.

#pragma once

#include "../vec-base.hpp"
#include <type_traits> // is_const_v

namespace gsl {


using std::is_const_v;


template<typename T>
vec_base::view<T> vec_base::view_array(T *b, size_t n, size_t s) {
  if constexpr(is_const_v<T>) {
    return gsl_vector_const_view_array_with_stride(b, s, n);
  } else {
    return gsl_vector_view_array_with_stride(b, s, n);
  }
}


template<typename T, int N>
vec_base::view<T> vec_base::subarray(T (&b)[N], size_t n, size_t i, size_t s) {
  if constexpr(is_const_v<T>) {
    return gsl_vector_const_view_array_with_stride(b + i, s, n);
  } else {
    return gsl_vector_view_array_with_stride(b + i, s, n);
  }
}


template<typename T, typename U>
int axpby(double alpha, vec_iface<T> const &x, double beta, vec_iface<U> &y) {
  return gsl_vector_axpby(alpha, x.p(), beta, y.p());
}


template<typename T, typename U>
bool equal(vec_iface<T> const &u, vec_iface<U> const &v) {
  return gsl_vector_equal(u.p(), v.p());
}


template<typename D, typename S>
int memcpy(vec_iface<D> &dst, vec_iface<S> const &src) {
  return gsl_vector_memcpy(dst.p(), src.p());
}


template<typename V, typename W> int swap(vec_iface<V> &v, vec_iface<W> &w) {
  return gsl_vector_swap(v.p(), w.p());
}


template<typename U, typename V>
bool operator==(vec_iface<U> const &u, vec_iface<V> const &v) {
  return equal(u, v);
}


} // namespace gsl

// EOF
