/// \file       include/gslcpp/wrap/fread.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_fread().

#pragma once
#include "container.hpp" // w_vector

namespace gsl {


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%w_fread()`, `v` must already have right size because
/// `%w_fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fread(FILE *f, w_vector<double> *v) {
  return gsl_vector_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%w_fread()`, `v` must already have right size because
/// `%w_fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fread(FILE *f, w_vector<float> *v) {
  return gsl_vector_float_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%w_fread()`, `v` must already have right size because
/// `%w_fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fread(FILE *f, w_vector<long double> *v) {
  return gsl_vector_long_double_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%w_fread()`, `v` must already have right size because
/// `%w_fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fread(FILE *f, w_vector<int> *v) {
  return gsl_vector_int_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%w_fread()`, `v` must already have right size because
/// `%w_fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fread(FILE *f, w_vector<unsigned> *v) {
  return gsl_vector_uint_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%w_fread()`, `v` must already have right size because
/// `%w_fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fread(FILE *f, w_vector<long> *v) {
  return gsl_vector_long_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%w_fread()`, `v` must already have right size because
/// `%w_fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fread(FILE *f, w_vector<unsigned long> *v) {
  return gsl_vector_ulong_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%w_fread()`, `v` must already have right size because
/// `%w_fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fread(FILE *f, w_vector<short> *v) {
  return gsl_vector_short_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%w_fread()`, `v` must already have right size because
/// `%w_fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fread(FILE *f, w_vector<unsigned short> *v) {
  return gsl_vector_ushort_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%w_fread()`, `v` must already have right size because
/// `%w_fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fread(FILE *f, w_vector<char> *v) {
  return gsl_vector_char_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%w_fread()`, `v` must already have right size because
/// `%w_fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fread(FILE *f, w_vector<unsigned char> *v) {
  return gsl_vector_uchar_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%w_fread()`, `v` must already have right size because
/// `%w_fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fread(FILE *f, w_vector<complex<double>> *v) {
  return gsl_vector_complex_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%w_fread()`, `v` must already have right size because
/// `%w_fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fread(FILE *f, w_vector<complex<float>> *v) {
  return gsl_vector_complex_float_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%w_fread()`, `v` must already have right size because
/// `%w_fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int w_fread(FILE *f, w_vector<complex<long double>> *v) {
  return gsl_vector_complex_long_double_fread(f, v);
}


} // namespace gsl

// EOF
