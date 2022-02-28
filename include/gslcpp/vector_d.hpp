/// \file       include/gslcpp/vector_d.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::vector_d.

#pragma once

#include "vec/v-dyna.hpp" // v_dyna
#include "vec/v-iface.hpp" // v_iface, v_stor, c::iface

namespace gsl {


/// Vector whose storage has two key properties: (1) that its size is
/// determined dynamically, at run-time, and (2) that it is owned by vector.
///
/// Storage is provided by \ref gsl::v_dyna, and most of interface is
/// provided by \ref gsl::v_iface.
///
/// %vector_d inherits these and provides template-constructors.
///
/// \sa \ref gsl::v_dyna
/// \sa \ref gsl::v_iface
///
/// @tparam T  Type of each element in vector.
template<typename T> struct vector_d: public v_iface<v_dyna<T>> {
  using P= v_iface<v_dyna<T>>; ///< Type of ancestor.
  using P::P;
};


} // namespace gsl

// EOF
