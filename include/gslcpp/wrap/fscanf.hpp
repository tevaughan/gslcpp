/// \file       include/gslcpp/wrap/fscanf.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_fscanf().

#pragma once
#include "type-map.hpp"

namespace gsl {


/// Read formatted data from stream `f` into vector `v`.
///
/// Vector `v` must have correct size before call to `%w_fscanf()` because
/// `%w_fscanf()` uses size of `v` to determine how many numbers to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fscanf
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that will be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fscanf(FILE *f, w_vector<double> *v) {
  return gsl_vector_fscanf(f, v);
}


/// Read formatted data from stream `f` into vector `v`.
///
/// Vector `v` must have correct size before call to `%w_fscanf()` because
/// `%w_fscanf()` uses size of `v` to determine how many numbers to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fscanf
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that will be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fscanf(FILE *f, w_vector<float> *v) {
  return gsl_vector_float_fscanf(f, v);
}


/// Read formatted data from stream `f` into vector `v`.
///
/// Vector `v` must have correct size before call to `%w_fscanf()` because
/// `%w_fscanf()` uses size of `v` to determine how many numbers to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fscanf
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that will be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fscanf(FILE *f, w_vector<long double> *v) {
  return gsl_vector_long_double_fscanf(f, v);
}


/// Read formatted data from stream `f` into vector `v`.
///
/// Vector `v` must have correct size before call to `%w_fscanf()` because
/// `%w_fscanf()` uses size of `v` to determine how many numbers to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fscanf
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that will be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fscanf(FILE *f, w_vector<int> *v) {
  return gsl_vector_int_fscanf(f, v);
}


/// Read formatted data from stream `f` into vector `v`.
///
/// Vector `v` must have correct size before call to `%w_fscanf()` because
/// `%w_fscanf()` uses size of `v` to determine how many numbers to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fscanf
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that will be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fscanf(FILE *f, w_vector<unsigned> *v) {
  return gsl_vector_uint_fscanf(f, v);
}


/// Read formatted data from stream `f` into vector `v`.
///
/// Vector `v` must have correct size before call to `%w_fscanf()` because
/// `%w_fscanf()` uses size of `v` to determine how many numbers to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fscanf
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that will be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fscanf(FILE *f, w_vector<long> *v) {
  return gsl_vector_long_fscanf(f, v);
}


/// Read formatted data from stream `f` into vector `v`.
///
/// Vector `v` must have correct size before call to `%w_fscanf()` because
/// `%w_fscanf()` uses size of `v` to determine how many numbers to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fscanf
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that will be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fscanf(FILE *f, w_vector<unsigned long> *v) {
  return gsl_vector_ulong_fscanf(f, v);
}


/// Read formatted data from stream `f` into vector `v`.
///
/// Vector `v` must have correct size before call to `%w_fscanf()` because
/// `%w_fscanf()` uses size of `v` to determine how many numbers to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fscanf
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that will be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fscanf(FILE *f, w_vector<short> *v) {
  return gsl_vector_short_fscanf(f, v);
}


/// Read formatted data from stream `f` into vector `v`.
///
/// Vector `v` must have correct size before call to `%w_fscanf()` because
/// `%w_fscanf()` uses size of `v` to determine how many numbers to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fscanf
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that will be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fscanf(FILE *f, w_vector<unsigned short> *v) {
  return gsl_vector_ushort_fscanf(f, v);
}


/// Read formatted data from stream `f` into vector `v`.
///
/// Vector `v` must have correct size before call to `%w_fscanf()` because
/// `%w_fscanf()` uses size of `v` to determine how many numbers to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fscanf
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that will be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fscanf(FILE *f, w_vector<char> *v) {
  return gsl_vector_char_fscanf(f, v);
}


/// Read formatted data from stream `f` into vector `v`.
///
/// Vector `v` must have correct size before call to `%w_fscanf()` because
/// `%w_fscanf()` uses size of `v` to determine how many numbers to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fscanf
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that will be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fscanf(FILE *f, w_vector<unsigned char> *v) {
  return gsl_vector_uchar_fscanf(f, v);
}


/// Read formatted data from stream `f` into vector `v`.
///
/// Vector `v` must have correct size before call to `%w_fscanf()` because
/// `%w_fscanf()` uses size of `v` to determine how many numbers to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fscanf
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that will be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fscanf(FILE *f, w_vector<gsl_complex> *v) {
  return gsl_vector_complex_fscanf(f, v);
}


/// Read formatted data from stream `f` into vector `v`.
///
/// Vector `v` must have correct size before call to `%w_fscanf()` because
/// `%w_fscanf()` uses size of `v` to determine how many numbers to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fscanf
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that will be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fscanf(FILE *f, w_vector<gsl_complex_float> *v) {
  return gsl_vector_complex_float_fscanf(f, v);
}


/// Read formatted data from stream `f` into vector `v`.
///
/// Vector `v` must have correct size before call to `%w_fscanf()` because
/// `%w_fscanf()` uses size of `v` to determine how many numbers to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fscanf
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that will be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fscanf(FILE *f, w_vector<gsl_complex_long_double> *v) {
  return gsl_vector_complex_long_double_fscanf(f, v);
}


} // namespace gsl

// EOF
