/// \file       include/gslcpp/vector_d.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::vector_d.

#pragma once

#include "vec/dyna.hpp" // vec::dyna
#include "vec/iface.hpp" // vec::iface, vec::stor, c::iface

namespace gsl {


/// Vector with storage allocated dynamically, at run-time, and owned by
/// instance of vector.
/// @tparam T  Type of each element in vector.
template<typename T> struct vector_d: public vec::iface<vec::dyna<T>> {
  using P= vec::iface<vec::dyna<T>>; ///< Type of ancestor.
  using P::P;
};


} // namespace gsl

// EOF
