/// \file       include/gslcpp/wrap/get.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_get().

#pragma once
#include "type-map.hpp"

namespace gsl {


/// Return `i`th element of vector `v` with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_get
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Value of element or 0 on bounds-error.
inline double w_get(w_vector<double const> *v, size_t i) {
  return gsl_vector_get(v, i);
}


/// Return `i`th element of vector `v` with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_get
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Value of element or 0 on bounds-error.
inline float w_get(w_vector<float const> *v, size_t i) {
  return gsl_vector_float_get(v, i);
}


/// Return `i`th element of vector `v` with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_get
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Value of element or 0 on bounds-error.
inline long double w_get(w_vector<long double const> *v, size_t i) {
  return gsl_vector_long_double_get(v, i);
}


/// Return `i`th element of vector `v` with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_get
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Value of element or 0 on bounds-error.
inline int w_get(w_vector<int const> *v, size_t i) {
  return gsl_vector_int_get(v, i);
}


/// Return `i`th element of vector `v` with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_get
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Value of element or 0 on bounds-error.
inline unsigned w_get(w_vector<unsigned const> *v, size_t i) {
  return gsl_vector_uint_get(v, i);
}


/// Return `i`th element of vector `v` with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_get
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Value of element or 0 on bounds-error.
inline long w_get(w_vector<long const> *v, size_t i) {
  return gsl_vector_long_get(v, i);
}


/// Return `i`th element of vector `v` with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_get
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Value of element or 0 on bounds-error.
inline unsigned long w_get(w_vector<unsigned long const> *v, size_t i) {
  return gsl_vector_ulong_get(v, i);
}


/// Return `i`th element of vector `v` with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_get
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Value of element or 0 on bounds-error.
inline short w_get(w_vector<short const> *v, size_t i) {
  return gsl_vector_short_get(v, i);
}


/// Return `i`th element of vector `v` with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_get
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Value of element or 0 on bounds-error.
inline unsigned short w_get(w_vector<unsigned short const> *v, size_t i) {
  return gsl_vector_ushort_get(v, i);
}


/// Return `i`th element of vector `v` with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_get
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Value of element or 0 on bounds-error.
inline char w_get(w_vector<char const> *v, size_t i) {
  return gsl_vector_char_get(v, i);
}


/// Return `i`th element of vector `v` with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_get
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Value of element or 0 on bounds-error.
inline unsigned char w_get(w_vector<unsigned char const> *v, size_t i) {
  return gsl_vector_uchar_get(v, i);
}


/// Return `i`th element of vector `v` with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_get
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Value of element or 0 on bounds-error.
inline gsl_complex w_get(w_vector<gsl_complex const> *v, size_t i) {
  return gsl_vector_complex_get(v, i);
}


/// Return `i`th element of vector `v` with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_get
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Value of element or 0 on bounds-error.
inline gsl_complex_float
w_get(w_vector<gsl_complex_float const> *v, size_t i) {
  return gsl_vector_complex_float_get(v, i);
}


/// Return `i`th element of vector `v` with bounds-checking.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_get
/// @param v  Pointer to vector.
/// @param i  Offset of element in vector.
/// @return  Value of element or 0 on bounds-error.
inline gsl_complex_long_double
w_get(w_vector<gsl_complex_long_double const> *v, size_t i) {
  return gsl_vector_complex_long_double_get(v, i);
}


} // namespace gsl

// EOF
