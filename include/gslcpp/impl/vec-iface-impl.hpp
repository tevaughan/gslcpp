/// @file       include/gslcpp/impl/vec-iface-impl.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gsl::vec_iface.

#pragma once

#include "../vector.hpp"

namespace gsl {


template<vec D>
vector_v<typename vec_iface<D>::element_t>
vec_iface<D>::subvector(size_t n, size_t i, size_t s) {
  return e_props<element_t>::vec_view_subvec(&v(), i, s, n);
}


template<vec D>
vector_v<typename vec_iface<D>::element_t const>
vec_iface<D>::subvector(size_t n, size_t i, size_t s) const {
  return e_props<element_t const>::vec_view_subvec(&v(), i, s, n);
}


template<vec D>
vector_v<typename vec_iface<D>::element_t> vec_iface<D>::view() {
  return e_props<element_t>::vec_view_subvec(&v(), 0, 1, size());
}


template<vec D>
vector_v<typename vec_iface<D>::element_t const> vec_iface<D>::view() const {
  return e_props<element_t const>::vec_view_subvec(&v(), 0, 1, size());
}


} // namespace gsl

// EOF
