/// \file       include/gslcpp/vec/v-stat.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::v_stat.

#pragma once
#include "../wrap/vector-view-array.hpp" // vector_view_array

namespace gsl {


/// Interface to vector-storage with two key properties: (1) that its size is
/// known statically, at compile-time, and (2) that it is owned by instance of
/// interface.
///
/// %v_stat implements concept \ref gsl::v_stor and can serve as template-type
/// parameter for (and thus base of) \ref gsl::v_iface.
///
/// @tparam S  Positive size.
/// @tparam T  Type of each element in vector.
template<unsigned S, typename T= double> class v_stat {
  static_assert(S > 0);

public:
  using E= T; ///< Type of each element in vector.

private:
  E d_[S]; ///< Storage for data.
  w_vector_view<E> view_; ///< GSL's view of data.

public:
  /// Initialize GSL's view of static storage, but do not initialize elements.
  v_stat(): view_(w_vector_view_array(d_, 1, S)) {}

  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to vector.
  auto &v() { return view_.vector; }

  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to immutable vector.
  auto &v() const { return view_.vector; }
};


} // namespace gsl

// EOF
