/// @file       include/gslcpp/vec-view.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition for gsl::vec_view.

#pragma once

#include "c-iface.hpp"

namespace gsl {


/// Specialization for vector that refers to mutable, external data.
template<typename T> class vec_view {
  using view= typename c_iface<T>::vec_view;
  view view_; ///< GSL's view of data outside instance.

public:
  /// Type of each element.
  using elem= T;

  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to vector.
  auto &v() { return view_.vector; }

  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to immutable vector.
  auto const &v() const { return view_.vector; }

  /// Constructor called by TBS.
  /// @param v  View to copy.
  vec_view(view const &v): view_(v) {}

  view const &cview() const { return view_; }
};


} // namespace gsl

// EOF
