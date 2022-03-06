/// \file       include/gslcpp/vec/v-view.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::view.

#pragma once
#include "../wrap/container.hpp" // w_vector_view

namespace gsl {


/// Interface to vector-storage not owned by interface.
///
/// %v_view can serve as template-type parameter for (and thus base of)
/// vec::iface.
///
/// @tparam T  Type of each element in vector.
template<typename T, size_t N= 0> class v_view {
  w_vector_view<T> cview_; ///< GSL's view of data outside instance.

public:
  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to vector.
  auto &v() { return cview_.vector; }

  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to immutable vector.
  auto &v() const { return cview_.vector; }

  /// Constructor called by TBS.
  /// @param v  View to copy.
  v_view(w_vector_view<T> const &v): cview_(v) {}

  /// GSL's native, C-language interface to vector-view.
  /// @return  GSL's native, C-language interface to vector-view.
  auto &cview() const { return cview_; }
};


} // namespace gsl

// EOF
