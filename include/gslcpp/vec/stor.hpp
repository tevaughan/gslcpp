/// \file       include/gslcpp/vec/stor.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::vec::stor.

#pragma once
#include "../c/iface.hpp" // c_iface

namespace gsl::vec {


using std::same_as;


/// Interface storage for vector.
///
/// `stor` defines what is necessary for template-type parameter for (and thus
/// base of) vec::iface.
///
/// @tparam T  Candidate type granting access to storage for vector.
template<typename T> concept stor= requires(T &x, T const &y) {
  typename T::E;
  { x.v() } -> same_as<c::vector<typename T::E> &>;
  { y.v() } -> same_as<c::vector<typename T::E> const &>;
};


} // namespace gsl::vec

// EOF
