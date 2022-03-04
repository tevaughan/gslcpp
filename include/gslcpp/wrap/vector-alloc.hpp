/// \file       include/gslcpp/wrap/vector-alloc.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_vector_alloc<E>(size_t).

#pragma once
#include "container.hpp" // w_vector

namespace gsl {


/// Generic template-declaration for function that allocates vector whose
/// element-type is E.
///
/// @tparam E  Type of each element in vector.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<typename E> w_vector<E> *w_vector_alloc(size_t n);


/// Specialization for double.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<> inline w_vector<double> *w_vector_alloc<double>(size_t n) {
  return gsl_vector_alloc(n);
}


/// Specialization for float.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<> inline w_vector<float> *w_vector_alloc<float>(size_t n) {
  return gsl_vector_float_alloc(n);
}


/// Specialization for long double.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<>
inline w_vector<long double> *w_vector_alloc<long double>(size_t n) {
  return gsl_vector_long_double_alloc(n);
}


/// Specialization for int.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<> inline w_vector<int> *w_vector_alloc<int>(size_t n) {
  return gsl_vector_int_alloc(n);
}


/// Specialization for unsigned.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<> inline w_vector<unsigned> *w_vector_alloc<unsigned>(size_t n) {
  return gsl_vector_uint_alloc(n);
}


/// Specialization for long.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<> inline w_vector<long> *w_vector_alloc<long>(size_t n) {
  return gsl_vector_long_alloc(n);
}


/// Specialization for unsigned long.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<>
inline w_vector<unsigned long> *w_vector_alloc<unsigned long>(size_t n) {
  return gsl_vector_ulong_alloc(n);
}


/// Specialization for short.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<> inline w_vector<short> *w_vector_alloc<short>(size_t n) {
  return gsl_vector_short_alloc(n);
}


/// Specialization for unsigned short.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<>
inline w_vector<unsigned short> *w_vector_alloc<unsigned short>(size_t n) {
  return gsl_vector_ushort_alloc(n);
}


/// Specialization for char.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<> inline w_vector<char> *w_vector_alloc<char>(size_t n) {
  return gsl_vector_char_alloc(n);
}


/// Specialization for unsigned char.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<>
inline w_vector<unsigned char> *w_vector_alloc<unsigned char>(size_t n) {
  return gsl_vector_uchar_alloc(n);
}


/// Specialization for complex<double>.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<>
inline w_vector<complex<double>> *w_vector_alloc<complex<double>>(size_t n) {
  return gsl_vector_complex_alloc(n);
}


/// Specialization for complex<float>.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<>
inline w_vector<complex<float>> *w_vector_alloc<complex<float>>(size_t n) {
  return gsl_vector_complex_float_alloc(n);
}


/// Specialization for complex<long double>.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<>
inline w_vector<complex<long double>> *
w_vector_alloc<complex<long double>>(size_t n) {
  return gsl_vector_complex_long_double_alloc(n);
}


} // namespace gsl

// EOF
