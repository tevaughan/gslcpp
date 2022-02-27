/// \file       include/gslcpp/c/set-basis.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::c::set_basis().

#pragma once
#include "type-map.hpp"

namespace gsl::c {


/// Make basis-vector by setting every element in `v` to zero except for `i`th
/// element, which is set to unity.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_basis
///
/// @param v  Pointer to vector.
/// @param i  Offset of component that should be set to unity.
/// @return  TBD: GSL's documentation does not specify.
inline int set_basis(c::vector<double> *v, size_t i) {
  return gsl_vector_set_basis(v, i);
}


/// Make basis-vector by setting every element in `v` to zero except for `i`th
/// element, which is set to unity.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_basis
///
/// @param v  Pointer to vector.
/// @param i  Offset of component that should be set to unity.
/// @return  TBD: GSL's documentation does not specify.
inline int set_basis(c::vector<float> *v, size_t i) {
  return gsl_vector_float_set_basis(v, i);
}


/// Make basis-vector by setting every element in `v` to zero except for `i`th
/// element, which is set to unity.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_basis
///
/// @param v  Pointer to vector.
/// @param i  Offset of component that should be set to unity.
/// @return  TBD: GSL's documentation does not specify.
inline int set_basis(c::vector<long double> *v, size_t i) {
  return gsl_vector_long_double_set_basis(v, i);
}


/// Make basis-vector by setting every element in `v` to zero except for `i`th
/// element, which is set to unity.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_basis
///
/// @param v  Pointer to vector.
/// @param i  Offset of component that should be set to unity.
/// @return  TBD: GSL's documentation does not specify.
inline int set_basis(c::vector<int> *v, size_t i) {
  return gsl_vector_int_set_basis(v, i);
}


/// Make basis-vector by setting every element in `v` to zero except for `i`th
/// element, which is set to unity.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_basis
///
/// @param v  Pointer to vector.
/// @param i  Offset of component that should be set to unity.
/// @return  TBD: GSL's documentation does not specify.
inline int set_basis(c::vector<unsigned> *v, size_t i) {
  return gsl_vector_uint_set_basis(v, i);
}


/// Make basis-vector by setting every element in `v` to zero except for `i`th
/// element, which is set to unity.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_basis
///
/// @param v  Pointer to vector.
/// @param i  Offset of component that should be set to unity.
/// @return  TBD: GSL's documentation does not specify.
inline int set_basis(c::vector<long> *v, size_t i) {
  return gsl_vector_long_set_basis(v, i);
}


/// Make basis-vector by setting every element in `v` to zero except for `i`th
/// element, which is set to unity.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_basis
///
/// @param v  Pointer to vector.
/// @param i  Offset of component that should be set to unity.
/// @return  TBD: GSL's documentation does not specify.
inline int set_basis(c::vector<unsigned long> *v, size_t i) {
  return gsl_vector_ulong_set_basis(v, i);
}


/// Make basis-vector by setting every element in `v` to zero except for `i`th
/// element, which is set to unity.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_basis
///
/// @param v  Pointer to vector.
/// @param i  Offset of component that should be set to unity.
/// @return  TBD: GSL's documentation does not specify.
inline int set_basis(c::vector<short> *v, size_t i) {
  return gsl_vector_short_set_basis(v, i);
}


/// Make basis-vector by setting every element in `v` to zero except for `i`th
/// element, which is set to unity.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_basis
///
/// @param v  Pointer to vector.
/// @param i  Offset of component that should be set to unity.
/// @return  TBD: GSL's documentation does not specify.
inline int set_basis(c::vector<unsigned short> *v, size_t i) {
  return gsl_vector_ushort_set_basis(v, i);
}


/// Make basis-vector by setting every element in `v` to zero except for `i`th
/// element, which is set to unity.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_basis
///
/// @param v  Pointer to vector.
/// @param i  Offset of component that should be set to unity.
/// @return  TBD: GSL's documentation does not specify.
inline int set_basis(c::vector<char> *v, size_t i) {
  return gsl_vector_char_set_basis(v, i);
}


/// Make basis-vector by setting every element in `v` to zero except for `i`th
/// element, which is set to unity.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_basis
///
/// @param v  Pointer to vector.
/// @param i  Offset of component that should be set to unity.
/// @return  TBD: GSL's documentation does not specify.
inline int set_basis(c::vector<unsigned char> *v, size_t i) {
  return gsl_vector_uchar_set_basis(v, i);
}


/// Make basis-vector by setting every element in `v` to zero except for `i`th
/// element, which is set to unity.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_basis
///
/// @param v  Pointer to vector.
/// @param i  Offset of component that should be set to unity.
/// @return  TBD: GSL's documentation does not specify.
inline int set_basis(c::vector<gsl_complex> *v, size_t i) {
  return gsl_vector_complex_set_basis(v, i);
}


/// Make basis-vector by setting every element in `v` to zero except for `i`th
/// element, which is set to unity.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_basis
///
/// @param v  Pointer to vector.
/// @param i  Offset of component that should be set to unity.
/// @return  TBD: GSL's documentation does not specify.
inline int set_basis(c::vector<gsl_complex_float> *v, size_t i) {
  return gsl_vector_complex_float_set_basis(v, i);
}


/// Make basis-vector by setting every element in `v` to zero except for `i`th
/// element, which is set to unity.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_basis
///
/// @param v  Pointer to vector.
/// @param i  Offset of component that should be set to unity.
/// @return  TBD: GSL's documentation does not specify.
inline int set_basis(c::vector<gsl_complex_long_double> *v, size_t i) {
  return gsl_vector_complex_long_double_set_basis(v, i);
}


} // namespace gsl::c

// EOF
