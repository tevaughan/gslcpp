/// \file       include/gslcpp/vector_d.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::vector_d.

#pragma once

#include "vec/dyna.hpp" // vec::dyna
#include "vec/iface.hpp" // vec::iface, vec::stor, c::iface

namespace gsl {


/// Vector whose storage has two key properties: (1) that its size is
/// determined dynamically, at run-time, and (2) that it is owned by vector.
///
/// Storage is provided by \ref gsl::vec::dyna, and most of interface is
/// provided by \ref gsl::vec::iface.
///
/// `vector_d` inherits these and provides template-constructors.
///
/// \sa \ref gsl::vec::dyna
/// \sa \ref gsl::vec::iface
///
/// @tparam T  Type of each element in vector.
template<typename T> struct vector_d: public vec::iface<vec::dyna<T>> {
  using P= vec::iface<vec::dyna<T>>; ///< Type of ancestor.
  using P::P;
};


} // namespace gsl

// EOF
