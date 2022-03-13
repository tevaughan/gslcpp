/// \file       include/gslcpp/wrap/is-complex.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::is_complex, gsl::is_complex_v.

#pragma once
#include "complex.hpp"

namespace gsl {


/// Define is_complex::VALUE as false for generic is_complex.
/// Specialization for each complex `T` defines value as true.
/// \tparam T  Candidate type for determination of complexity.
template<typename T> struct is_complex {
  enum : bool { VALUE= false /**< Indicate that `T` is not complex. */ };
};


/// Specialization that defines is_complex::VALUE as true.
/// Generic is_complex defines value as false.
/// \tparam U  Type of each element of complex value.
template<typename U> struct is_complex<gsl::complex<U>> {
  enum : bool { VALUE= true /**< Indicate that `T` is complex. */ };
};


/// Specialization that defines is_complex::VALUE as true.
/// Generic is_complex defines value as false.
/// \tparam U  Type of each element of complex (constant) value.
template<typename U> struct is_complex<gsl::complex<U> const> {
  enum : bool { VALUE= true /**< Indicate that `T` is complex. */ };
};


/// True if `T` be type of complex element in vector or matrix.
/// \tparam T  Candidate type of element in vector or matrix.
template<typename T> constexpr bool is_complex_v= is_complex<T>::VALUE;


} // namespace gsl

// EOF
