/// @file       include/gslcpp/impl/vec-iface-impl.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gsl::vec_iface.

#pragma once

#include "../vector.hpp"

namespace gsl {


template<vec D>
vector_v<typename vec_iface<D>::element_t>
vec_iface<D>::subvector(size_t n, size_t i, size_t s) {
  return gsl_vector_subvector_with_stride(&v(), i, s, n);
}


template<vec D>
vector_cv<typename vec_iface<D>::element_t>
vec_iface<D>::subvector(size_t n, size_t i, size_t s) const {
  return gsl_vector_const_subvector_with_stride(&v(), i, s, n);
}


template<vec D>
vector_v<typename vec_iface<D>::element_t> vec_iface<D>::view() {
  return gsl_vector_subvector_with_stride(&v(), 0, 1, size());
}


template<vec D>
vector_cv<typename vec_iface<D>::element_t> vec_iface<D>::view() const {
  return gsl_vector_const_subvector_with_stride(&v(), 0, 1, size());
}


} // namespace gsl

// EOF
