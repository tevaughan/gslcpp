/// @file       include/gslcpp/c/fprintf.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gsl::c::fprintf().

#pragma once
#include "type-map.hpp"

namespace gsl::c {


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int fprintf(FILE *f, c::vector<double const> *v, char const *fmt) {
  return gsl_vector_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int fprintf(FILE *f, c::vector<float const> *v, char const *fmt) {
  return gsl_vector_float_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int fprintf(FILE *f, c::vector<long double const> *v, char const *fmt) {
  return gsl_vector_long_double_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int fprintf(FILE *f, c::vector<int const> *v, char const *fmt) {
  return gsl_vector_int_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int fprintf(FILE *f, c::vector<unsigned const> *v, char const *fmt) {
  return gsl_vector_uint_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int fprintf(FILE *f, c::vector<long const> *v, char const *fmt) {
  return gsl_vector_long_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int
fprintf(FILE *f, c::vector<unsigned long const> *v, char const *fmt) {
  return gsl_vector_ulong_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int fprintf(FILE *f, c::vector<short const> *v, char const *fmt) {
  return gsl_vector_short_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int
fprintf(FILE *f, c::vector<unsigned short const> *v, char const *fmt) {
  return gsl_vector_ushort_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int fprintf(FILE *f, c::vector<char const> *v, char const *fmt) {
  return gsl_vector_char_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int
fprintf(FILE *f, c::vector<unsigned char const> *v, char const *fmt) {
  return gsl_vector_uchar_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int fprintf(FILE *f, c::vector<gsl_complex const> *v, char const *fmt) {
  return gsl_vector_complex_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int
fprintf(FILE *f, c::vector<gsl_complex_float const> *v, char const *fmt) {
  return gsl_vector_complex_float_fprintf(f, v, fmt);
}


/// Write elements of `v` line by line to stream `f` via specifier `fmt`.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_fprintf
/// @param f  Pointer to file-stream.
/// @param v  Pointer to vector.
/// @param fmt  Pointer to printf-style specifier of format.
/// @return  0 on success or GSL_EFAILED on problem writing to file.
inline int fprintf(
      FILE *f, c::vector<gsl_complex_long_double const> *v, char const *fmt) {
  return gsl_vector_complex_long_double_fprintf(f, v, fmt);
}


} // namespace gsl::c

// EOF
