/// \file       include/gslcpp/c/xf-float.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::c::xf<float>, gsl::c::xf<float const>.

#pragma once
#include "vector-view.hpp"
#include "vector.hpp"
#include "xf.hpp"

namespace gsl::c {


/// \anchor xf_float_const
/// Specialization for `float const`.
/// \sa \ref xf_generic
template<> struct xf<float const> {
  /// Write ASCII-formatted representation of vector to file.
  /// @param flp  Pointer to structure for buffered interface.
  /// @param vec  Pointer to gsl_vector.
  /// @param fmt  printf()-style format-string.
  /// @return  Zero only on success.
  static int fprintf(FILE *flp, vector<float const> *vec, char const *fmt) {
    return gsl_vector_float_fprintf(flp, vec, fmt);
  }

  /// Sum of elements in vector.
  /// @param v  Pointer to vector.
  /// @return  Sum.
  static float sum(vector<float const> *v) {
#if GSL_AT_LEAST(2, 7)
    return gsl_vector_float_sum(v);
#else
    return sum_for_gsl_lt_2p7(*v);
#endif
  }

  /// Maximum value of any element in vector.
  /// @param v  Pointer to vector.
  /// @return  Maximum value.
  static double max(vector<float const> *v) { return gsl_vector_float_max(v); }

  /// Minimum value of any element in vector.
  /// @param v  Pointer to vector.
  /// @return  Minimum value.
  static double min(vector<float const> *v) { return gsl_vector_float_min(v); }

  /// Greatest value and least value of any element in vector.
  /// @param v  Pointer to vector.
  /// @param min  Pointer to buffer into which least value is loaded.
  /// @param max  Pointer to buffer into which greatest value is loaded.
  static void minmax(vector<float const> *v, float *min, float *max) {
    gsl_vector_float_minmax(v, min, max);
  }

  /// Offset of element with maximum value.
  /// @param v  Pointer to vector.
  /// @return  Offset of element with maximum value.
  static size_t max_index(vector<float const> *v) {
    return gsl_vector_float_max_index(v);
  }

  /// Offset of element with minimum value.
  /// @param v  Pointer to vector.
  /// @return  Offset of element with minimum value.
  static size_t min_index(vector<float const> *v) {
    return gsl_vector_float_min_index(v);
  }

  /// Offset of element with minimum value and offset of element with maximum
  /// value.
  /// @param v  Pointer to vector.
  /// @param min  Pointer to buffer into which offset of minimum value is to be
  ///             stored.
  /// @param max  Pointer to buffer into which offset of maximum value is to be
  ///             stored.
  static void minmax_index(vector<float const> *v, size_t *min, size_t *max) {
    gsl_vector_float_minmax_index(v, min, max);
  }

  /// True only if every element have zero value.
  /// @param v  Pointer to vector.
  /// @return  True only if every element have zero value.
  static bool isnull(vector<float const> *v) {
    return gsl_vector_float_isnull(v);
  }

  /// True only if every element be positive.
  /// @param v  Pointer to vector.
  /// @return  True only if every element be positive.
  static bool ispos(vector<float const> *v) {
    return gsl_vector_float_ispos(v);
  }

  /// True only if every element be negative.
  /// @param v  Pointer to vector.
  /// @return  True only if every element be negative.
  static bool isneg(vector<float const> *v) {
    return gsl_vector_float_isneg(v);
  }

  /// True only if every element be non-negative.
  /// @param v  Pointer to vector.
  /// @return  True only if every element be non-negative.
  static bool isnonneg(vector<float const> *v) {
    return gsl_vector_float_isnonneg(v);
  }

  /// Test equality of two vectors.
  /// @param a  Pointer to one vector.
  /// @param b  Pointer to other vector.
  /// @return  True only if vectors be equal.
  static bool equal(vector<float const> *a, vector<float const> *b) {
    return gsl_vector_float_equal(a, b);
  }
};


/// \anchor xf_float
/// Specialization for `float`.
/// \sa \ref xf_generic
template<> struct xf<float>: public xf<float const> {
  /// Set element at offset `i` to unity and every other element to zero.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset of element to set to unity.
  /// @return  TBD: GSL's documentation does not specify.
  static int set_basis(vector<float> *v, size_t i) {
    return gsl_vector_float_set_basis(v, i);
  }

  /// Write non-portable binary image of vector to file.
  /// @param f  Pointer to structure for buffered interface.
  /// @param v  Pointer to gsl_vector.
  /// @return  Zero only on success.
  static int fwrite(FILE *f, vector<float> const *v) {
    return gsl_vector_float_fwrite(f, v);
  }

  /// Read non-portable binary-image of vector from file.
  /// @param f  Pointer to structure for buffered interface.
  /// @param v  Pointer to gsl_vector.
  /// @return  Zero only on success.
  static int fread(FILE *f, vector<float> *v) {
    return gsl_vector_float_fread(f, v);
  }

  /// Read ASCII-formatted representation of vector from file.
  /// @param f  Pointer to structure for buffered interface.
  /// @param v  Pointer to vector.
  /// @return  Zero only on success.
  static int fscanf(FILE *f, vector<float> *v) {
    return gsl_vector_float_fscanf(f, v);
  }

  /// Swap elements within vector.
  /// @param v  Pointer to vector.
  /// @param i  Offset of one element.
  /// @param j  Offset of other element.
  /// @return  TBD: GSL's documentation does not specify.
  static int swap_elements(vector<float> *v, size_t i, size_t j) {
    return gsl_vector_float_swap_elements(v, i, j);
  }

  /// Reverse order of elements.
  /// @param v  Pointer to vector.
  /// @return  TBD: GSL's documentation does not specify.
  static int reverse(vector<float> *v) { return gsl_vector_float_reverse(v); }

  /// Add contents of `cv` into `v` in place.
  /// @param v  Pointer to vector into which `cv` should be accumulated.
  /// @param cv  Pointer to vector whose contents should be added into `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int add(vector<float> *v, vector<float> const *cv) {
    return gsl_vector_float_add(v, cv);
  }

  /// Subtract contents of `cv` from `v` in place.
  /// @param v  Pointer to vector that should be reduced by `cv`.
  /// @param cv  Pointer to vector to be subtracted from `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int sub(vector<float> *v, vector<float> const *cv) {
    return gsl_vector_float_sub(v, cv);
  }

  /// Multiply contents of `cv` into `v` in place.
  /// @param v  Pointer to vector into which `cv` should be multiplied.
  /// @param cv  Pointer to vector to be multiplied into `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int mul(vector<float> *v, vector<float> const *cv) {
    return gsl_vector_float_mul(v, cv);
  }

  /// Dive `cv` into `v` in place.
  /// @param v  Pointer to vector that should be divided by `cv`.
  /// @param cv  Pointer to vector whose contents should be divided into `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int div(vector<float> *v, vector<float> const *cv) {
    return gsl_vector_float_div(v, cv);
  }

  /// Multiply scalar into vector in place.
  /// @param v  Pointer to vector to be scaled.
  /// @param x  Scalar to multiply into `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int scale(vector<float> *v, float x) {
    return gsl_vector_float_scale(v, x);
  }

  /// Add constant into each element of `v` in place.
  /// @param v  Pointer to vector whose elements are to be added to.
  /// @param x  Constant to add into `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int add_constant(vector<float> *v, float x) {
    return gsl_vector_float_add_constant(v, x);
  }

  /// Linearly combine in place as `y = a*x + b*y`. This is implemented via
  /// Eigen if the installed GSL have version less than 2.7.
  /// @param a  Coefficient of first vector.
  /// @param x  Pointer to first vector.
  /// @param b  Coefficient of second vector.
  /// @param y  Pointer to second vector and to result.
  /// @return  TBD for GSL, zero if Eigen be used.
  static int
  axpby(float a, vector<float> const *x, float b, vector<float> *y) {
#if GSL_AT_LEAST(2, 7)
    return gsl_vector_float_axpby(a, x, b, y);
#else
    return axpby_for_gsl_lt_2p7(a, *x, b, *y);
#endif
  }

  /// Copy data from source to destination.
  /// @param d  Pointer to destination-vector.
  /// @param s  Pointer to source-vector.
  /// @return TBD: GSL's documentation does not specify.
  static int memcpy(vector<float> *d, vector<float> const *s) {
    return gsl_vector_float_memcpy(d, s);
  }

  /// Swap contents of one and other vector, each with same length.
  /// @param a  Pointer to one vector.
  /// @param b  Pointer to other vector.
  /// @return  TBD: GSL's documentation does not specify.
  static int swap(vector<float> *a, vector<float> *b) {
    return gsl_vector_float_swap(a, b);
  }
};


} // namespace gsl::c

// EOF
