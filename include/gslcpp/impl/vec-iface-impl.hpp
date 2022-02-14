/// @file       include/gslcpp/impl/vec-iface-impl.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gsl::vec_iface.

#pragma once

#include "../vector.hpp"

namespace gsl {


template<vec D>
vector_v<typename vec_iface<D>::element_t>
vec_iface<D>::subvector(size_t n, size_t i, size_t s) {
  return c_iface<element_t>::subvector(&v(), i, s, n);
}


template<vec D>
vector_v<typename vec_iface<D>::element_t const>
vec_iface<D>::subvector(size_t n, size_t i, size_t s) const {
  return c_iface<element_t const>::subvector(&v(), i, s, n);
}


template<vec D>
vector_v<typename vec_iface<D>::element_t> vec_iface<D>::view() {
  return c_iface<element_t>::subvector(&v(), 0, 1, size());
}


template<vec D>
vector_v<typename vec_iface<D>::element_t const> vec_iface<D>::view() const {
  return c_iface<element_t const>::subvector(&v(), 0, 1, size());
}


} // namespace gsl

// EOF
