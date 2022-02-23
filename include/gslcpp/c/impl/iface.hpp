/// @file       include/gslcpp/c/impl/iface.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Declaration for gsl::c::impl::iface.

#pragma once

// Use inline-definition of each accessor-function.
// - Define this before including `gsl_vector.h`.
#ifndef HAVE_INLINE
#  define HAVE_INLINE
#endif

#include <gsl/gsl_vector.h> // gsl_vector_view, gsl_vector_const_view

/// Namespace for implementation, by type of element in vector or matrix, of
/// interface to GSL's native, C-language functions and types.
namespace gsl::c::impl {


/// Generic template for struct that provides, on basis of element-type `E`,
/// appropriate GSL C-types and functions.
/// @tparam E  Type of each element in vector.
template<typename E> struct iface;


}

// EOF
