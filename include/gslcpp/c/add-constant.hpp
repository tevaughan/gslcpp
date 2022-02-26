/// @file       include/gslcpp/c/add-constant.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gsl::c::add_constant.

#pragma once
#include "type-map.hpp"

namespace gsl::c {


/// Add same constant to every element in place.  `add_constant` is overloaded
/// to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add_constant
/// @param u  Pointer to vector whose elements are to be modified.
/// @param v  Constant to add into each element.
/// @return  TBD: Not specified in GSL's documentation.
inline int add_constant(c::vector<double> *u, double const &v) {
  return gsl_vector_add_constant(u, v);
}


/// Add same constant to every element in place.  `add_constant` is overloaded
/// to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add_constant
/// @param u  Pointer to vector whose elements are to be modified.
/// @param v  Constant to add into each element.
/// @return  TBD: Not specified in GSL's documentation.
inline int add_constant(c::vector<float> *u, float const &v) {
  return gsl_vector_float_add_constant(u, v);
}


/// Add same constant to every element in place.  `add_constant` is overloaded
/// to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add_constant
/// @param u  Pointer to vector whose elements are to be modified.
/// @param v  Constant to add into each element.
/// @return  TBD: Not specified in GSL's documentation.
inline int add_constant(c::vector<long double> *u, long double const &v) {
  return gsl_vector_long_double_add_constant(u, v);
}


/// Add same constant to every element in place.  `add_constant` is overloaded
/// to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add_constant
/// @param u  Pointer to vector whose elements are to be modified.
/// @param v  Constant to add into each element.
/// @return  TBD: Not specified in GSL's documentation.
inline int add_constant(c::vector<int> *u, int const &v) {
  return gsl_vector_int_add_constant(u, v);
}


/// Add same constant to every element in place.  `add_constant` is overloaded
/// to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add_constant
/// @param u  Pointer to vector whose elements are to be modified.
/// @param v  Constant to add into each element.
/// @return  TBD: Not specified in GSL's documentation.
inline int add_constant(c::vector<unsigned> *u, unsigned const &v) {
  return gsl_vector_uint_add_constant(u, v);
}


/// Add same constant to every element in place.  `add_constant` is overloaded
/// to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add_constant
/// @param u  Pointer to vector whose elements are to be modified.
/// @param v  Constant to add into each element.
/// @return  TBD: Not specified in GSL's documentation.
inline int add_constant(c::vector<long> *u, long const &v) {
  return gsl_vector_long_add_constant(u, v);
}


/// Add same constant to every element in place.  `add_constant` is overloaded
/// to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add_constant
/// @param u  Pointer to vector whose elements are to be modified.
/// @param v  Constant to add into each element.
/// @return  TBD: Not specified in GSL's documentation.
inline int add_constant(c::vector<unsigned long> *u, unsigned long const &v) {
  return gsl_vector_ulong_add_constant(u, v);
}


/// Add same constant to every element in place.  `add_constant` is overloaded
/// to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add_constant
/// @param u  Pointer to vector whose elements are to be modified.
/// @param v  Constant to add into each element.
/// @return  TBD: Not specified in GSL's documentation.
inline int add_constant(c::vector<short> *u, short const &v) {
  return gsl_vector_short_add_constant(u, v);
}


/// Add same constant to every element in place.  `add_constant` is overloaded
/// to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add_constant
/// @param u  Pointer to vector whose elements are to be modified.
/// @param v  Constant to add into each element.
/// @return  TBD: Not specified in GSL's documentation.
inline int
add_constant(c::vector<unsigned short> *u, unsigned short const &v) {
  return gsl_vector_ushort_add_constant(u, v);
}


/// Add same constant to every element in place.  `add_constant` is overloaded
/// to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add_constant
/// @param u  Pointer to vector whose elements are to be modified.
/// @param v  Constant to add into each element.
/// @return  TBD: Not specified in GSL's documentation.
inline int add_constant(c::vector<char> *u, char const &v) {
  return gsl_vector_char_add_constant(u, v);
}


/// Add same constant to every element in place.  `add_constant` is overloaded
/// to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add_constant
/// @param u  Pointer to vector whose elements are to be modified.
/// @param v  Constant to add into each element.
/// @return  TBD: Not specified in GSL's documentation.
inline int add_constant(c::vector<unsigned char> *u, unsigned char const &v) {
  return gsl_vector_uchar_add_constant(u, v);
}


/// Add same constant to every element in place.  `add_constant` is overloaded
/// to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add_constant
/// @param u  Pointer to vector whose elements are to be modified.
/// @param v  Constant to add into each element.
/// @return  TBD: Not specified in GSL's documentation.
inline int add_constant(c::vector<gsl_complex> *u, gsl_complex const &v) {
  return gsl_vector_complex_add_constant(u, v);
}


/// Add same constant to every element in place.  `add_constant` is overloaded
/// to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add_constant
/// @param u  Pointer to vector whose elements are to be modified.
/// @param v  Constant to add into each element.
/// @return  TBD: Not specified in GSL's documentation.
inline int
add_constant(c::vector<gsl_complex_float> *u, gsl_complex_float const &v) {
  return gsl_vector_complex_float_add_constant(u, v);
}


/// Add same constant to every element in place.  `add_constant` is overloaded
/// to provide the same name for every type of vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_add_constant
/// @param u  Pointer to vector whose elements are to be modified.
/// @param v  Constant to add into each element.
/// @return  TBD: Not specified in GSL's documentation.
inline int add_constant(
      c::vector<gsl_complex_long_double> *u,
      gsl_complex_long_double const &v) {
  return gsl_vector_complex_long_double_add_constant(u, v);
}


} // namespace gsl::c

// EOF