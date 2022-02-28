/// \file       include/gslcpp/wrap/free.hpp
/// \copyright  2022 Thomas E. Vaughan
/// \brief      Definition of gsl::w_free().

#pragma once
#include "type-map.hpp"

namespace gsl {


/// Deallocate memory for GSL's native vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_free
/// @param v  Pointer to vector.
inline void w_free(w_vector<double> *v) { gsl_vector_free(v); }


/// Deallocate memory for GSL's native vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_free
/// @param v  Pointer to vector.
inline void w_free(w_vector<float> *v) { gsl_vector_float_free(v); }


/// Deallocate memory for GSL's native vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_free
/// @param v  Pointer to vector.
inline void w_free(w_vector<long double> *v) {
  gsl_vector_long_double_free(v);
}


/// Deallocate memory for GSL's native vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_free
/// @param v  Pointer to vector.
inline void w_free(w_vector<int> *v) { gsl_vector_int_free(v); }


/// Deallocate memory for GSL's native vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_free
/// @param v  Pointer to vector.
inline void w_free(w_vector<unsigned> *v) { gsl_vector_uint_free(v); }


/// Deallocate memory for GSL's native vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_free
/// @param v  Pointer to vector.
inline void w_free(w_vector<long> *v) { gsl_vector_long_free(v); }


/// Deallocate memory for GSL's native vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_free
/// @param v  Pointer to vector.
inline void w_free(w_vector<unsigned long> *v) { gsl_vector_ulong_free(v); }


/// Deallocate memory for GSL's native vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_free
/// @param v  Pointer to vector.
inline void w_free(w_vector<short> *v) { gsl_vector_short_free(v); }


/// Deallocate memory for GSL's native vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_free
/// @param v  Pointer to vector.
inline void w_free(w_vector<unsigned short> *v) { gsl_vector_ushort_free(v); }


/// Deallocate memory for GSL's native vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_free
/// @param v  Pointer to vector.
inline void w_free(w_vector<char> *v) { gsl_vector_char_free(v); }


/// Deallocate memory for GSL's native vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_free
/// @param v  Pointer to vector.
inline void w_free(w_vector<unsigned char> *v) { gsl_vector_uchar_free(v); }


/// Deallocate memory for GSL's native vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_free
/// @param v  Pointer to vector.
inline void w_free(w_vector<gsl_complex> *v) { gsl_vector_complex_free(v); }


/// Deallocate memory for GSL's native vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_free
/// @param v  Pointer to vector.
inline void w_free(w_vector<gsl_complex_float> *v) {
  gsl_vector_complex_float_free(v);
}


/// Deallocate memory for GSL's native vector.
/// https://www.gnu.org/software/gsl/doc/html/vectors.html#c.gsl_vector_free
/// @param v  Pointer to vector.
inline void w_free(w_vector<gsl_complex_long_double> *v) {
  gsl_vector_complex_long_double_free(v);
}


} // namespace gsl

// EOF
