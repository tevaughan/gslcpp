/// @file       gsl/impl/vec-iface-impl.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gsl::vec_iface.

#pragma once

#include "../vector.hpp"

namespace gsl {


template<typename D>
vectorv vec_iface<D>::subvector(size_t n, size_t i, size_t s) {
  return gsl_vector_subvector_with_stride(p(), i, s, n);
}


template<typename D>
vectorcv vec_iface<D>::subvector(size_t n, size_t i, size_t s) const {
  return gsl_vector_const_subvector_with_stride(p(), i, s, n);
}


} // namespace gsl

// EOF
