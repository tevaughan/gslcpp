/// @file       include/gslcpp/c/xf.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Declaration for gsl::c::xf.

#pragma once

// Use inline-definition of each accessor-function.
// - Define this before including `gsl_vector.h`.
#ifndef HAVE_INLINE
#  define HAVE_INLINE
#endif

#include <gsl/gsl_vector.h> // gsl_vector, gsl_vector_float, etc.

/// Namespace for implementation, by type of element in vector or matrix, of
/// interface to GSL's native, C-language functions and types.
namespace gsl::c {


/// Generic template for struct that provides, on basis of element-type `E`,
/// appropriate GSL C-types and functions.
/// @tparam E  Type of each element in vector.
template<typename E> struct xf;


} // namespace gsl::c

// EOF
