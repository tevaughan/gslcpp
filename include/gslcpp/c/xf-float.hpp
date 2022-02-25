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
