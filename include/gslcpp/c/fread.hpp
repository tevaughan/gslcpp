/// \file       include/gslcpp/c/fread.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::c::fread().

#pragma once
#include "type-map.hpp"

namespace gsl::c {


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%fread()`, `v` must already have right size because
/// `%fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int fread(FILE *f, c::vector<double> *v) {
  return gsl_vector_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%fread()`, `v` must already have right size because
/// `%fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int fread(FILE *f, c::vector<float> *v) {
  return gsl_vector_float_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%fread()`, `v` must already have right size because
/// `%fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int fread(FILE *f, c::vector<long double> *v) {
  return gsl_vector_long_double_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%fread()`, `v` must already have right size because
/// `%fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int fread(FILE *f, c::vector<int> *v) {
  return gsl_vector_int_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%fread()`, `v` must already have right size because
/// `%fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int fread(FILE *f, c::vector<unsigned> *v) {
  return gsl_vector_uint_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%fread()`, `v` must already have right size because
/// `%fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int fread(FILE *f, c::vector<long> *v) {
  return gsl_vector_long_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%fread()`, `v` must already have right size because
/// `%fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int fread(FILE *f, c::vector<unsigned long> *v) {
  return gsl_vector_ulong_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%fread()`, `v` must already have right size because
/// `%fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int fread(FILE *f, c::vector<short> *v) {
  return gsl_vector_short_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%fread()`, `v` must already have right size because
/// `%fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int fread(FILE *f, c::vector<unsigned short> *v) {
  return gsl_vector_ushort_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%fread()`, `v` must already have right size because
/// `%fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int fread(FILE *f, c::vector<char> *v) {
  return gsl_vector_char_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%fread()`, `v` must already have right size because
/// `%fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int fread(FILE *f, c::vector<unsigned char> *v) {
  return gsl_vector_uchar_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%fread()`, `v` must already have right size because
/// `%fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int fread(FILE *f, c::vector<gsl_complex> *v) {
  return gsl_vector_complex_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%fread()`, `v` must already have right size because
/// `%fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int fread(FILE *f, c::vector<gsl_complex_float> *v) {
  return gsl_vector_complex_float_fread(f, v);
}


/// Read into `v` from stream `f` in binary format.
///
/// Before call to `%fread()`, `v` must already have right size because
/// `%fread()` uses size of `v` to determine number bytes to read.
///
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fread
///
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector that should be initialized from stream.
/// @return  0 on success or GSL_EFAILED on problem reading from stream.
inline int fread(FILE *f, c::vector<gsl_complex_long_double> *v) {
  return gsl_vector_complex_long_double_fread(f, v);
}


} // namespace gsl::c

// EOF
