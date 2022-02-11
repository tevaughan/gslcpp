/// @file       include/gslcpp/impl/vec-impl.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition for gsl::vec and for functions for vectors.

#pragma once

#include "../vec.hpp"
#include <iostream> // ostream
#include <type_traits> // is_const_v

namespace gsl {


using std::is_const_v;


/// True only if `T` be either `double` or `double const`.
/// @tparam T  Type to be tested.
template<typename T>
constexpr bool is_double= is_same_v<T, double> || is_same_v<T, double const>;


template<typename T> vector_view<T> vec::view(size_t n, T *b, size_t s) {
  static_assert(is_double<T>);
  if constexpr(is_const_v<T>) {
    return gsl_vector_const_view_array_with_stride(b, s, n);
  } else {
    return gsl_vector_view_array_with_stride(b, s, n);
  }
}


template<typename T, int N>
vector_view<T> vec::view(T (&b)[N], size_t n, size_t i, size_t s) {
  static_assert(is_double<T>);
  if constexpr(is_const_v<T>) {
    return gsl_vector_const_view_array_with_stride(b + i, s, n);
  } else {
    return gsl_vector_view_array_with_stride(b + i, s, n);
  }
}


} // namespace gsl

// EOF
