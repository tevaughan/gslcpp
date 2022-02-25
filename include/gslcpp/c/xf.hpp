/// \file       include/gslcpp/c/xf.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Declaration for gsl::c::xf.

#pragma once
// Use inline-definition of each accessor-function.
// - Define this before including `gsl_vector.h`.
#ifndef HAVE_INLINE
#  define HAVE_INLINE
#endif
#include <gsl/gsl_vector.h> // gsl_vector, gsl_vector_float, etc.

namespace gsl::c {


/// \anchor xf_generic
/// Generic template for struct that provides, on basis of element-type `E`,
/// appropriate GSL C-types and functions.
///
/// \sa \ref gsl::c::basic_iface "basic_iface"
/// \sa \ref xf_double_const
/// \sa \ref xf_double
/// \sa \ref xf_float_const
/// \sa \ref xf_float
///
/// @tparam E  Primitive type (either `const` or non-`const) of each element in
///            vector or array.
template<typename E> struct xf;


} // namespace gsl::c

// EOF
