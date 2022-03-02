/// \file       include/gslcpp/wrap/fwrite.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_fwrite().

#pragma once
#include "container.hpp" // w_vector

namespace gsl {


/// Write elements of vector `v` to stream `f` in binary format.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fwrite
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @return  0 on success and `GSL_EFAILED` on problem writing to stream.
inline int w_fwrite(FILE *f, w_vector<double const> *v) {
  return gsl_vector_fwrite(f, v);
}


/// Write elements of vector `v` to stream `f` in binary format.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fwrite
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @return  0 on success and `GSL_EFAILED` on problem writing to stream.
inline int w_fwrite(FILE *f, w_vector<float const> *v) {
  return gsl_vector_float_fwrite(f, v);
}


/// Write elements of vector `v` to stream `f` in binary format.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fwrite
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @return  0 on success and `GSL_EFAILED` on problem writing to stream.
inline int w_fwrite(FILE *f, w_vector<long double const> *v) {
  return gsl_vector_long_double_fwrite(f, v);
}


/// Write elements of vector `v` to stream `f` in binary format.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fwrite
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @return  0 on success and `GSL_EFAILED` on problem writing to stream.
inline int w_fwrite(FILE *f, w_vector<int const> *v) {
  return gsl_vector_int_fwrite(f, v);
}


/// Write elements of vector `v` to stream `f` in binary format.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fwrite
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @return  0 on success and `GSL_EFAILED` on problem writing to stream.
inline int w_fwrite(FILE *f, w_vector<unsigned const> *v) {
  return gsl_vector_uint_fwrite(f, v);
}


/// Write elements of vector `v` to stream `f` in binary format.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fwrite
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @return  0 on success and `GSL_EFAILED` on problem writing to stream.
inline int w_fwrite(FILE *f, w_vector<long const> *v) {
  return gsl_vector_long_fwrite(f, v);
}


/// Write elements of vector `v` to stream `f` in binary format.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fwrite
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @return  0 on success and `GSL_EFAILED` on problem writing to stream.
inline int w_fwrite(FILE *f, w_vector<unsigned long const> *v) {
  return gsl_vector_ulong_fwrite(f, v);
}


/// Write elements of vector `v` to stream `f` in binary format.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fwrite
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @return  0 on success and `GSL_EFAILED` on problem writing to stream.
inline int w_fwrite(FILE *f, w_vector<short const> *v) {
  return gsl_vector_short_fwrite(f, v);
}


/// Write elements of vector `v` to stream `f` in binary format.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fwrite
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @return  0 on success and `GSL_EFAILED` on problem writing to stream.
inline int w_fwrite(FILE *f, w_vector<unsigned short const> *v) {
  return gsl_vector_ushort_fwrite(f, v);
}


/// Write elements of vector `v` to stream `f` in binary format.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fwrite
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @return  0 on success and `GSL_EFAILED` on problem writing to stream.
inline int w_fwrite(FILE *f, w_vector<char const> *v) {
  return gsl_vector_char_fwrite(f, v);
}


/// Write elements of vector `v` to stream `f` in binary format.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fwrite
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @return  0 on success and `GSL_EFAILED` on problem writing to stream.
inline int w_fwrite(FILE *f, w_vector<unsigned char const> *v) {
  return gsl_vector_uchar_fwrite(f, v);
}


/// Write elements of vector `v` to stream `f` in binary format.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fwrite
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @return  0 on success and `GSL_EFAILED` on problem writing to stream.
inline int w_fwrite(FILE *f, w_vector<complex<double> const> *v) {
  return gsl_vector_complex_fwrite(f, v);
}


/// Write elements of vector `v` to stream `f` in binary format.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fwrite
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @return  0 on success and `GSL_EFAILED` on problem writing to stream.
inline int w_fwrite(FILE *f, w_vector<complex<float> const> *v) {
  return gsl_vector_complex_float_fwrite(f, v);
}


/// Write elements of vector `v` to stream `f` in binary format.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fwrite
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @return  0 on success and `GSL_EFAILED` on problem writing to stream.
inline int w_fwrite(FILE *f, w_vector<complex<long double> const> *v) {
  return gsl_vector_complex_long_double_fwrite(f, v);
}


} // namespace gsl

// EOF
