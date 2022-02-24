/// @file       include/gslcpp/c/xf-float.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition for gsl::c::xf<float>, gsl::c::xf<float const>.

#pragma once
#include "xf.hpp"

namespace gsl::c {


/// Specialization for `float`.
template<> struct xf<float> {
  /// GSL's C-library type for non-const elements.
  using vector= gsl_vector_float;

  /// GSL's C-library type for view of non-const elements.
  using vector_view= gsl_vector_float_view;

  /// GSL's native view of array.
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements relative to pointer.
  /// @param n  Number of elements in view.
  /// @return  GSL's native, C-style view.
  static vector_view vector_view_array(float *b, size_t s, size_t n) {
    return gsl_vector_float_view_array_with_stride(b, s, n);
  }

  /// GSL's native view of subvector.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset in gsl_vector of first element in view.
  /// @param s  Stride of elements in view relative to offsets in `v`.
  /// @param n  Number of elements in view.
  /// @return  GSL's native, C-style view.
  static vector_view subvector(vector *v, size_t i, size_t s, size_t n) {
    return gsl_vector_float_subvector_with_stride(v, i, s, n);
  }

  /// Fetch copy of element at offset `i` with bounds-checking.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset of element.
  /// @return  Copy of element.
  static float get(vector const *v, size_t i) {
    return gsl_vector_float_get(v, i);
  }

  /// Fetch pointer to element at offset `i` with bounds-checking.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset of element.
  /// @return  Pointer to element.
  static float *ptr(vector *v, size_t i) { return gsl_vector_float_ptr(v, i); }

  /// Set value of element at offset `i` with bounds-checking.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset of element.
  /// @param x  New value for element.
  static void set(vector *v, size_t i, float x) {
    gsl_vector_float_set(v, i, x);
  }

  /// Set same value into every element of vector.
  /// @param v  Pointer to gsl_vector.
  /// @param x  Same new value for every element.
  static void set_all(vector *v, float x) { gsl_vector_float_set_all(v, x); }

  /// Set zero into every element of vector.
  /// @param v  Pointer to gsl_vector.
  static void set_zero(vector *v) { gsl_vector_float_set_zero(v); }

  /// Set element at offset `i` to unity and every other element to zero.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset of element to set to unity.
  /// @return  TBD: GSL's documentation does not specify.
  static int set_basis(vector *v, size_t i) {
    return gsl_vector_float_set_basis(v, i);
  }

  /// Write non-portable binary image of vector to file.
  /// @param f  Pointer to structure for buffered interface.
  /// @param v  Pointer to gsl_vector.
  /// @return  Zero only on success.
  static int fwrite(FILE *f, vector const *v) {
    return gsl_vector_float_fwrite(f, v);
  }

  /// Read non-portable binary-image of vector from file.
  /// @param f  Pointer to structure for buffered interface.
  /// @param v  Pointer to gsl_vector.
  /// @return  Zero only on success.
  static int fread(FILE *f, vector *v) { return gsl_vector_float_fread(f, v); }

  /// Write ASCII-formatted representation of vector to file.
  /// @param flp  Pointer to structure for buffered interface.
  /// @param vec  Pointer to gsl_vector.
  /// @param fmt  printf()-style format-string.
  /// @return  Zero only on success.
  static int fprintf(FILE *flp, vector const *vec, char const *fmt) {
    return gsl_vector_float_fprintf(flp, vec, fmt);
  }

  /// Read ASCII-formatted representation of vector from file.
  /// @param f  Pointer to structure for buffered interface.
  /// @param v  Pointer to vector.
  /// @return  Zero only on success.
  static int fscanf(FILE *f, vector *v) {
    return gsl_vector_float_fscanf(f, v);
  }

  /// Swap elements within vector.
  /// @param v  Pointer to vector.
  /// @param i  Offset of one element.
  /// @param j  Offset of other element.
  /// @return  TBD: GSL's documentation does not specify.
  static int swap_elements(vector *v, size_t i, size_t j) {
    return gsl_vector_float_swap_elements(v, i, j);
  }

  /// Reverse order of elements.
  /// @param v  Pointer to vector.
  /// @return  TBD: GSL's documentation does not specify.
  static int reverse(vector *v) { return gsl_vector_float_reverse(v); }

  /// Add contents of `cv` into `v` in place.
  /// @param v  Pointer to vector into which `cv` should be accumulated.
  /// @param cv  Pointer to vector whose contents should be added into `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int add(vector *v, vector const *cv) {
    return gsl_vector_float_add(v, cv);
  }

  /// Subtract contents of `cv` from `v` in place.
  /// @param v  Pointer to vector that should be reduced by `cv`.
  /// @param cv  Pointer to vector to be subtracted from `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int sub(vector *v, vector const *cv) {
    return gsl_vector_float_sub(v, cv);
  }

  /// Multiply contents of `cv` into `v` in place.
  /// @param v  Pointer to vector into which `cv` should be multiplied.
  /// @param cv  Pointer to vector to be multiplied into `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int mul(vector *v, vector const *cv) {
    return gsl_vector_float_mul(v, cv);
  }

  /// Dive `cv` into `v` in place.
  /// @param v  Pointer to vector that should be divided by `cv`.
  /// @param cv  Pointer to vector whose contents should be divided into `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int div(vector *v, vector const *cv) {
    return gsl_vector_float_div(v, cv);
  }

  /// Multiply scalar into vector in place.
  /// @param v  Pointer to vector to be scaled.
  /// @param x  Scalar to multiply into `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int scale(vector *v, float x) { return gsl_vector_float_scale(v, x); }

  /// Add constant into each element of `v` in place.
  /// @param v  Pointer to vector whose elements are to be added to.
  /// @param x  Constant to add into `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int add_constant(vector *v, float x) {
    return gsl_vector_float_add_constant(v, x);
  }

  /// Sum of elements in vector.
  /// @param v  Pointer to vector.
  /// @return  Sum.
  static float sum(vector const *v) {
#if GSL_AT_LEAST(2, 7)
    return gsl_vector_float_sum(v);
#else
    return sum_for_gsl_lt_2p7(*v);
#endif
  }

  /// Maximum value of any element in vector.
  /// @param v  Pointer to vector.
  /// @return  Maximum value.
  static double max(vector const *v) { return gsl_vector_float_max(v); }

  /// Minimum value of any element in vector.
  /// @param v  Pointer to vector.
  /// @return  Minimum value.
  static double min(vector const *v) { return gsl_vector_float_min(v); }

  /// Greatest value and least value of any element in vector.
  /// @param v  Pointer to vector.
  /// @param min  Pointer to buffer into which least value is loaded.
  /// @param max  Pointer to buffer into which greatest value is loaded.
  static void minmax(vector const *v, float *min, float *max) {
    gsl_vector_float_minmax(v, min, max);
  }
};


/// Specialization for `float const`.
template<> struct xf<float const> {
  /// GSL's C-library type for non-const elements.
  using vector= gsl_vector_float const;

  /// GSL's C-library type for view of non-const elements.
  using vector_view= gsl_vector_float_const_view;

  /// GSL's native view of array.
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements relative to pointer.
  /// @param n  Number of elements in view.
  /// @return  GSL's native, C-style view.
  static vector_view vector_view_array(float const *b, size_t s, size_t n) {
    return gsl_vector_float_const_view_array_with_stride(b, s, n);
  }

  /// GSL's native view of subvector.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset in gsl_vector of first element in view.
  /// @param s  Stride of elements in view relative to offsets in `v`.
  /// @param n  Number of elements in view.
  /// @return  GSL's native, C-style view.
  static vector_view subvector(vector *v, size_t i, size_t s, size_t n) {
    return gsl_vector_float_const_subvector_with_stride(v, i, s, n);
  }

  /// Fetch copy of element at offset `i` with bounds-checking.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset of element.
  /// @return  Copy of element.
  static float get(vector *v, size_t i) { return gsl_vector_float_get(v, i); }

  /// Fetch pointer to element at offset `i` with bounds-checking.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset of element.
  /// @return  Pointer to element.
  static float const *ptr(vector *v, size_t i) {
    return gsl_vector_float_const_ptr(v, i);
  }

  /// Write non-portable binary image of vector to file.
  /// @param f  Pointer to structure for buffered interface.
  /// @param v  Pointer to gsl_vector.
  /// @return  Zero only on success.
  static int fwrite(FILE *f, vector *v) {
    return gsl_vector_float_fwrite(f, v);
  }

  /// Write ASCII-formatted representation of vector to file.
  /// @param flp  Pointer to structure for buffered interface.
  /// @param vec  Pointer to gsl_vector.
  /// @param fmt  printf()-style format-string.
  /// @return  Zero only on success.
  static int fprintf(FILE *flp, vector *vec, char const *fmt) {
    return gsl_vector_float_fprintf(flp, vec, fmt);
  }

  /// Sum of elements in vector.
  /// @param v  Pointer to vector.
  /// @return  Sum.
  static float sum(vector *v) {
#if GSL_AT_LEAST(2, 7)
    return gsl_vector_float_sum(v);
#else
    return sum_for_gsl_lt_2p7(*v);
#endif
  }

  /// Maximum value of any element in vector.
  /// @param v  Pointer to vector.
  /// @return  Maximum value.
  static double max(vector *v) { return gsl_vector_float_max(v); }

  /// Minimum value of any element in vector.
  /// @param v  Pointer to vector.
  /// @return  Minimum value.
  static double min(vector *v) { return gsl_vector_float_min(v); }

  /// Greatest value and least value of any element in vector.
  /// @param v  Pointer to vector.
  /// @param min  Pointer to buffer into which least value is loaded.
  /// @param max  Pointer to buffer into which greatest value is loaded.
  static void minmax(vector *v, float *min, float *max) {
    gsl_vector_float_minmax(v, min, max);
  }
};


} // namespace gsl::c

// EOF
