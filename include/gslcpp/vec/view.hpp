/// \file       include/gslcpp/vec/view.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::vec::view.

#pragma once
#include "../c/iface.hpp" // c_iface

namespace gsl::vec {


/// Interface to vector-storage not owned by interface.
///
/// `view` implements concept vec::stor and can serve as template-type
/// parameter for (and thus base of) vec::iface.
///
/// @tparam T  Type of each element in vector.
template<typename T> class view {
public:
  using E= T; ///< Type of each element.

private:
  c::vector_view<E> view_; ///< GSL's view of data outside instance.

public:
  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to vector.
  auto &v() { return view_.vector; }

  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to immutable vector.
  auto &v() const { return view_.vector; }

  /// Constructor called by TBS.
  /// @param v  View to copy.
  view(c::vector_view<E> const &v): view_(v) {}

  /// GSL's native, C-language interface to vector-view.
  /// @return  GSL's native, C-language interface to vector-view.
  auto &cview() const { return view_; }
};


} // namespace gsl::vec

// EOF
