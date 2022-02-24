/// @file       include/gslcpp/c/xf.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Declaration for gsl::c::xf.

#pragma once

// Use inline-definition of each accessor-function.
// - Define this before including `gsl_vector.h`.
#ifndef HAVE_INLINE
#  define HAVE_INLINE
#endif

#include "../version.hpp" // at_least()
#include <Eigen/Core> // Map, Matrix
#include <gsl/gsl_vector.h> // gsl_vector, gsl_vector_float, etc.

/// Namespace for implementation, by type of element in vector or matrix, of
/// interface to GSL's native, C-language functions and types.
namespace gsl::c {


using Eigen::Dynamic;
using Eigen::Map;
using Eigen::Matrix;
using Eigen::Stride;


/// Generic template for struct that provides, on basis of element-type `E`,
/// appropriate GSL C-types and functions.
/// @tparam E  Type of each element in vector.
template<typename E> struct xf;


/// Type of each element in gsl_vector of type V.
/// @tparam V  Type of gsl_vector (for example, gsl_vector_float).
template<typename V>
using vdata_t= std::remove_reference_t<decltype(*V::data)>;


/// Sum of elements in vector, for use when GSL's version be less than 2.7.
/// This function uses Eigen to compute the sum.
/// @tparam V  Type of gsl_vector.
/// @param v  Reference to vector.
/// @return  Sum of elements.
template<typename V> vdata_t<V> sum_for_gsl_lt_2p7(V const &v) {
  using E= vdata_t<V>;
  using S= Stride<Dynamic, Dynamic>;
  using map= Map<Matrix<E, Dynamic, Dynamic>, 0, S>;
  return map(v.data, v.size, 1, S(0, v.stride)).sum();
}


} // namespace gsl::c

// EOF
