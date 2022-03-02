/// \file       include/gslcpp/wrap/set-basis.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_set_basis().

#pragma once
#include "container.hpp" // w_vector

namespace gsl {


/// Make basis-vector by setting every element in `v` to zero except for `i`th
/// element, which is set to unity.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_set_basis
///
/// @param v  Pointer to vector.
/// @param i  Offset of component that should be set to unity.
/// @return  TBD: GSL's documentation does not specify.
inline int w_set_basis(w_vector<double> *v, size_t i) {
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
inline int w_set_basis(w_vector<float> *v, size_t i) {
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
inline int w_set_basis(w_vector<long double> *v, size_t i) {
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
inline int w_set_basis(w_vector<int> *v, size_t i) {
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
inline int w_set_basis(w_vector<unsigned> *v, size_t i) {
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
inline int w_set_basis(w_vector<long> *v, size_t i) {
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
inline int w_set_basis(w_vector<unsigned long> *v, size_t i) {
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
inline int w_set_basis(w_vector<short> *v, size_t i) {
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
inline int w_set_basis(w_vector<unsigned short> *v, size_t i) {
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
inline int w_set_basis(w_vector<char> *v, size_t i) {
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
inline int w_set_basis(w_vector<unsigned char> *v, size_t i) {
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
inline int w_set_basis(w_vector<complex<double>> *v, size_t i) {
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
inline int w_set_basis(w_vector<complex<float>> *v, size_t i) {
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
inline int w_set_basis(w_vector<complex<long double>> *v, size_t i) {
  return gsl_vector_complex_long_double_set_basis(v, i);
}


} // namespace gsl

// EOF
