/// \file       include/gslcpp/wrap/vector-calloc.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_vector_calloc<E>(size_t).

#pragma once
#include "container.hpp" // w_vector

namespace gsl {


/// Generic template-declaration for function that allocates vector whose
/// element-type is E and initializes each element to zero.
///
/// @tparam E  Type of each element in vector.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for zero-initialized vector.
template<typename E> w_vector<E> *w_vector_calloc(size_t n);


/// Specialization for double.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<> inline w_vector<double> *w_vector_calloc<double>(size_t n) {
  return gsl_vector_calloc(n);
}


/// Specialization for float.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<> inline w_vector<float> *w_vector_calloc<float>(size_t n) {
  return gsl_vector_float_calloc(n);
}


/// Specialization for long double.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<>
inline w_vector<long double> *w_vector_calloc<long double>(size_t n) {
  return gsl_vector_long_double_calloc(n);
}


/// Specialization for int.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<> inline w_vector<int> *w_vector_calloc<int>(size_t n) {
  return gsl_vector_int_calloc(n);
}


/// Specialization for unsigned.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<> inline w_vector<unsigned> *w_vector_calloc<unsigned>(size_t n) {
  return gsl_vector_uint_calloc(n);
}


/// Specialization for long.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<> inline w_vector<long> *w_vector_calloc<long>(size_t n) {
  return gsl_vector_long_calloc(n);
}


/// Specialization for unsigned long.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<>
inline w_vector<unsigned long> *w_vector_calloc<unsigned long>(size_t n) {
  return gsl_vector_ulong_calloc(n);
}


/// Specialization for short.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<> inline w_vector<short> *w_vector_calloc<short>(size_t n) {
  return gsl_vector_short_calloc(n);
}


/// Specialization for unsigned short.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<>
inline w_vector<unsigned short> *w_vector_calloc<unsigned short>(size_t n) {
  return gsl_vector_ushort_calloc(n);
}


/// Specialization for char.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<> inline w_vector<char> *w_vector_calloc<char>(size_t n) {
  return gsl_vector_char_calloc(n);
}


/// Specialization for unsigned char.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<>
inline w_vector<unsigned char> *w_vector_calloc<unsigned char>(size_t n) {
  return gsl_vector_uchar_calloc(n);
}


/// Specialization for complex<double>.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<>
inline w_vector<complex<double>> *w_vector_calloc<complex<double>>(size_t n) {
  return gsl_vector_complex_calloc(n);
}


/// Specialization for complex<float>.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<>
inline w_vector<complex<float>> *w_vector_calloc<complex<float>>(size_t n) {
  return gsl_vector_complex_float_calloc(n);
}


/// Specialization for complex<long double>.
/// @param n  Number of elements to allocate.
/// @return  Pointer to GSL's native C-struct for vector.
template<>
inline w_vector<complex<long double>> *
w_vector_calloc<complex<long double>>(size_t n) {
  return gsl_vector_complex_long_double_calloc(n);
}


} // namespace gsl

// EOF
