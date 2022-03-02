/// \file       include/gslcpp/wrap/fprintf.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition of gsl::w_fprintf().

#pragma once
#include "container.hpp" // w_vector

namespace gsl {


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int w_fprintf(FILE *f, w_vector<double const> *v, char const *fmt) {
  return gsl_vector_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int w_fprintf(FILE *f, w_vector<float const> *v, char const *fmt) {
  return gsl_vector_float_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int
w_fprintf(FILE *f, w_vector<long double const> *v, char const *fmt) {
  return gsl_vector_long_double_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int w_fprintf(FILE *f, w_vector<int const> *v, char const *fmt) {
  return gsl_vector_int_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int w_fprintf(FILE *f, w_vector<unsigned const> *v, char const *fmt) {
  return gsl_vector_uint_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int w_fprintf(FILE *f, w_vector<long const> *v, char const *fmt) {
  return gsl_vector_long_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int
w_fprintf(FILE *f, w_vector<unsigned long const> *v, char const *fmt) {
  return gsl_vector_ulong_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int w_fprintf(FILE *f, w_vector<short const> *v, char const *fmt) {
  return gsl_vector_short_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int
w_fprintf(FILE *f, w_vector<unsigned short const> *v, char const *fmt) {
  return gsl_vector_ushort_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int w_fprintf(FILE *f, w_vector<char const> *v, char const *fmt) {
  return gsl_vector_char_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int
w_fprintf(FILE *f, w_vector<unsigned char const> *v, char const *fmt) {
  return gsl_vector_uchar_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int
w_fprintf(FILE *f, w_vector<complex<double> const> *v, char const *fmt) {
  return gsl_vector_complex_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int
w_fprintf(FILE *f, w_vector<complex<float> const> *v, char const *fmt) {
  return gsl_vector_complex_float_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int
w_fprintf(FILE *f, w_vector<complex<long double> const> *v, char const *fmt) {
  return gsl_vector_complex_long_double_fprintf(f, v, fmt);
}


} // namespace gsl

// EOF
