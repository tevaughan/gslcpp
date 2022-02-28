/// \file       include/gslcpp/vec/stat.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::vec::stat.

#pragma once
#include "../wrap/type-map.hpp" // vector_view
#include "../wrap/vector-view-array.hpp" // vector_view_array

namespace gsl::vec {


/// Interface to vector-storage with two key properties: (1) that its size is
/// known statically, at compile-time, and (2) that it is owned by instance of
/// interface.
///
/// `stat` implements concept vec::stor and can serve as template-type
/// parameter for (and thus base of) vec::iface.
///
/// @tparam S  Positive size.
/// @tparam T  Type of each element in vector.
template<unsigned S, typename T= double> class stat {
  static_assert(S > 0);
  using A= typename type_map<T>::A;

public:
  using E= T; ///< Type of each element in vector.
  static_assert(sizeof(E) / sizeof(A) == 1 || sizeof(E) / sizeof(A) == 2);

private:
  /// Storage for data.  If sizeof(E) be different from sizeof(A), then E is
  /// a complex type, and we need twice the number of elements.
  A d_[S * sizeof(E) / sizeof(A)];

  w_vector_view<E> view_; ///< GSL's view of data.

public:
  /// Initialize GSL's view of static storage, but do not initialize elements.
  stat(): view_(w_vector_view_array<E>(d_, 1, S)) {}

  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to vector.
  auto &v() { return view_.vector; }

  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to immutable vector.
  auto &v() const { return view_.vector; }
};


} // namespace gsl::vec

// EOF
