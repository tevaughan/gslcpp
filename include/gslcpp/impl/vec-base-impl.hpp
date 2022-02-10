/// @file       include/gslcpp/impl/vec-base-impl.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition for gsl::vec_base and for functions for vectors.

#pragma once

#include "../vec-base.hpp"
#include <iostream> // ostream
#include <type_traits> // is_const_v

namespace gsl {


using std::is_const_v;


template<typename T> vector_view<T> vec_base::view(size_t n, T *b, size_t s) {
  if constexpr(is_const_v<T>) {
    return gsl_vector_const_view_array_with_stride(b, s, n);
  } else {
    return gsl_vector_view_array_with_stride(b, s, n);
  }
}


template<typename T, int N>
vector_view<T> vec_base::view(T (&b)[N], size_t n, size_t i, size_t s) {
  if constexpr(is_const_v<T>) {
    return gsl_vector_const_view_array_with_stride(b + i, s, n);
  } else {
    return gsl_vector_view_array_with_stride(b + i, s, n);
  }
}


#if defined(GSL_VER) && GSL_VER > 26
template<typename T, typename U>
int axpby(double alpha, vec_iface<T> const &x, double beta, vec_iface<U> &y) {
  return gsl_vector_axpby(alpha, &x.vec(), beta, &y.vec());
}
#endif


template<typename T, typename U>
bool equal(vec_iface<T> const &u, vec_iface<U> const &v) {
  return gsl_vector_equal(&u.vec(), &v.vec());
}


template<typename D, typename S>
int memcpy(vec_iface<D> &dst, vec_iface<S> const &src) {
  return gsl_vector_memcpy(&dst.vec(), &src.vec());
}


template<typename V, typename W> int swap(vec_iface<V> &v, vec_iface<W> &w) {
  return gsl_vector_swap(&v.vec(), &w.vec());
}


template<typename U>
std::ostream &operator<<(std::ostream &os, vec_iface<U> const &u) {
  os << "[";
  int const last= int(u.size()) - 1;
  for(int i= 0; i < last; ++i) os << u[i] << ",";
  if(last >= 0) os << u[last];
  os << "]";
  return os;
}


} // namespace gsl

// EOF
