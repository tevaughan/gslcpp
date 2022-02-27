/// \file       include/gslcpp/vec/stor.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::vec::stor.

#pragma once
#include "../wrap/type-map.hpp" // vector
#include <concepts> // same_as

namespace gsl::vec {


using std::same_as;


/// Interface storage for vector.
///
/// `stor` defines what is necessary for template-type parameter for (and thus
/// base of) gsl::vec::iface.
///
/// @tparam T  Candidate type granting access to storage for vector.
template<typename T> concept stor= requires(T &x, T const &y) {
  typename T::E;
  { x.v() } -> same_as<w_vector<typename T::E> &>;
  { y.v() } -> same_as<w_vector<typename T::E> const &>;
};


} // namespace gsl::vec

// EOF
