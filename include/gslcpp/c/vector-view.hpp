/// @file       include/gslcpp/c/vector-view.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::c::vw_ and gslcpp::c::vector_view.

#pragma once
#include "vector.hpp"

namespace gsl::c {


/// Template whose specialization defines dependent type, `vw_<E>::type`.
/// @tparam E  Type of element for vector.
template<typename E> struct vw_;


template<> struct vw_<double> { using type= gsl_vector_view; };

template<> struct vw_<double const> { using type= gsl_vector_const_view; };

template<> struct vw_<float> { using type= gsl_vector_float_view; };

template<> struct vw_<float const> {
  using type= gsl_vector_float_const_view;
};

template<> struct vw_<long double> {
  using type= gsl_vector_long_double_view;
};

template<> struct vw_<long double const> {
  using type= gsl_vector_long_double_const_view;
};

template<> struct vw_<int> { using type= gsl_vector_int_view; };

template<> struct vw_<int const> { using type= gsl_vector_int_const_view; };

template<> struct vw_<unsigned> { using type= gsl_vector_uint_view; };

template<> struct vw_<unsigned const> {
  using type= gsl_vector_uint_const_view;
};

template<> struct vw_<long> { using type= gsl_vector_long_view; };

template<> struct vw_<long const> { using type= gsl_vector_long_const_view; };

template<> struct vw_<unsigned long> { using type= gsl_vector_ulong_view; };

template<> struct vw_<unsigned long const> {
  using type= gsl_vector_ulong_const_view;
};

template<> struct vw_<short> { using type= gsl_vector_short_view; };

template<> struct vw_<short const> {
  using type= gsl_vector_short_const_view;
};

template<> struct vw_<unsigned short> { using type= gsl_vector_ushort_view; };

template<> struct vw_<unsigned short const> {
  using type= gsl_vector_ushort_const_view;
};

template<> struct vw_<char> { using type= gsl_vector_char_view; };

template<> struct vw_<char const> { using type= gsl_vector_char_const_view; };

template<> struct vw_<unsigned char> { using type= gsl_vector_uchar_view; };

template<> struct vw_<unsigned char const> {
  using type= gsl_vector_uchar_const_view;
};

template<> struct vw_<gsl_complex> { using type= gsl_vector_complex_view; };

template<> struct vw_<gsl_complex const> {
  using type= gsl_vector_complex_const_view;
};

template<> struct vw_<gsl_complex_float> {
  using type= gsl_vector_complex_float_view;
};

template<> struct vw_<gsl_complex_float const> {
  using type= gsl_vector_complex_float_const_view;
};

template<> struct vw_<gsl_complex_long_double> {
  using type= gsl_vector_complex_long_double_view;
};

template<> struct vw_<gsl_complex_long_double const> {
  using type= gsl_vector_complex_long_double_const_view;
};


/// GSL's native vector-type corresponding to element-type `E`.
/// @tparam E  Type of element for vector.
template<typename E> using vector_view= typename vw_<E>::type;


} // namespace gsl::c

// EOF
