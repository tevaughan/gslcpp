/// \file       include/gslcpp/c/xf-double.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::c::xf<double>, gsl::c::xf<double const>.

#pragma once
#include "xf.hpp"

namespace gsl::c {


/// \anchor xf_double_const
/// Specialization for `double const`.
/// \sa \ref xf_generic
template<> struct xf<double const> {
  /// GSL's C-library type for non-const elements.
  using vector= gsl_vector const;

  /// GSL's C-library type for view of non-const elements.
  using vector_view= gsl_vector_const_view;

  /// GSL's native view of array.
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements relative to pointer.
  /// @param n  Number of elements in view.
  /// @return  GSL's native, C-style view.
  static vector_view
  vector_const_view_array(double const *b, size_t s, size_t n) {
    return gsl_vector_const_view_array_with_stride(b, s, n);
  }

  /// GSL's native view of subvector.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset in gsl_vector of first element in view.
  /// @param s  Stride of elements in view relative to offsets in `v`.
  /// @param n  Number of elements in view.
  /// @return  GSL's native, C-style view.
  static vector_view const_subvector(vector *v, size_t i, size_t s, size_t n) {
    return gsl_vector_const_subvector_with_stride(v, i, s, n);
  }

  /// Fetch copy of element at offset `i` with bounds-checking.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset of element.
  /// @return  Copy of element.
  static double get(vector *v, size_t i) { return gsl_vector_get(v, i); }

  /// Fetch pointer to element at offset `i` with bounds-checking.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset of element.
  /// @return  Pointer to element.
  static double const *const_ptr(vector *v, size_t i) {
    return gsl_vector_const_ptr(v, i);
  }

  /// Write non-portable binary image of vector to file.
  /// @param f  Pointer to structure for buffered interface.
  /// @param v  Pointer to gsl_vector.
  /// @return  Zero only on success.
  static int fwrite(FILE *f, vector *v) { return gsl_vector_fwrite(f, v); }

  /// Write ASCII-formatted representation of vector to file.
  /// @param flp  Pointer to structure for buffered interface.
  /// @param vec  Pointer to gsl_vector.
  /// @param fmt  printf()-style format-string.
  /// @return  Zero only on success.
  static int fprintf(FILE *flp, vector *vec, char const *fmt) {
    return gsl_vector_fprintf(flp, vec, fmt);
  }

  /// Sum of elements in vector.
  /// @param v  Pointer to vector.
  /// @return  Sum.
  static double sum(vector *v) {
#if GSL_AT_LEAST(2, 7)
    return gsl_vector_sum(v);
#else
    return sum_for_gsl_lt_2p7(*v);
#endif
  }

  /// Maximum value of any element in vector.
  /// @param v  Pointer to vector.
  /// @return  Maximum value.
  static double max(vector *v) { return gsl_vector_max(v); }

  /// Minimum value of any element in vector.
  /// @param v  Pointer to vector.
  /// @return  Minimum value.
  static double min(vector *v) { return gsl_vector_min(v); }

  /// Greatest value and least value of any element in vector.
  /// @param v  Pointer to vector.
  /// @param min  Pointer to buffer into which least value is loaded.
  /// @param max  Pointer to buffer into which greatest value is loaded.
  static void minmax(vector *v, double *min, double *max) {
    gsl_vector_minmax(v, min, max);
  }

  /// Offset of element with maximum value.
  /// @param v  Pointer to vector.
  /// @return  Offset of element with maximum value.
  static std::size_t max_index(vector *v) { return gsl_vector_max_index(v); }

  /// Offset of element with minimum value.
  /// @param v  Pointer to vector.
  /// @return  Offset of element with minimum value.
  static std::size_t min_index(vector *v) { return gsl_vector_min_index(v); }

  /// Offset of element with minimum value and offset of element with maximum
  /// value.
  /// @param v  Pointer to vector.
  /// @param min  Pointer to buffer into which offset of minimum value is to be
  ///             stored.
  /// @param max  Pointer to buffer into which offset of maximum value is to be
  ///             stored.
  static void minmax_index(vector *v, size_t *min, size_t *max) {
    gsl_vector_minmax_index(v, min, max);
  }

  /// True only if every element have zero value.
  /// @param v  Pointer to vector.
  /// @return  True only if every element have zero value.
  static bool isnull(vector *v) { return gsl_vector_isnull(v); }

  /// True only if every element be positive.
  /// @param v  Pointer to vector.
  /// @return  True only if every element be positive.
  static bool ispos(vector *v) { return gsl_vector_ispos(v); }

  /// True only if every element be negative.
  /// @param v  Pointer to vector.
  /// @return  True only if every element be negative.
  static bool isneg(vector *v) { return gsl_vector_isneg(v); }

  /// True only if every element be non-negative.
  /// @param v  Pointer to vector.
  /// @return  True only if every element be non-negative.
  static bool isnonneg(vector *v) { return gsl_vector_isnonneg(v); }

  /// Test equality of two vectors.
  /// @param a  Pointer to one vector.
  /// @param b  Pointer to other vector.
  /// @return  True only if vectors be equal.
  static bool equal(vector *a, vector *b) { return gsl_vector_equal(a, b); }
};


/// \anchor xf_double
/// Specialization for `double`.
/// \sa \ref xf_generic
template<> struct xf<double>: public xf<double const> {
  /// GSL's C-library type for non-const elements.
  using vector= gsl_vector;

  /// GSL's C-library type for view of non-const elements.
  using vector_view= gsl_vector_view;

  /// GSL's native view of array.
  /// @param b  Pointer to first element of view.
  /// @param s  Stride of successive elements relative to pointer.
  /// @param n  Number of elements in view.
  /// @return  GSL's native, C-style view.
  static vector_view vector_view_array(double *b, size_t s, size_t n) {
    return gsl_vector_view_array_with_stride(b, s, n);
  }

  /// GSL's native view of subvector.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset in gsl_vector of first element in view.
  /// @param s  Stride of elements in view relative to offsets in `v`.
  /// @param n  Number of elements in view.
  /// @return  GSL's native, C-style view.
  static vector_view subvector(vector *v, size_t i, size_t s, size_t n) {
    return gsl_vector_subvector_with_stride(v, i, s, n);
  }

  /// Fetch pointer to element at offset `i` with bounds-checking.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset of element.
  /// @return  Pointer to element.
  static double *ptr(vector *v, size_t i) { return gsl_vector_ptr(v, i); }

  /// Set value of element at offset `i` with bounds-checking.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset of element.
  /// @param x  New value for element.
  static void set(vector *v, size_t i, double const &x) {
    gsl_vector_set(v, i, x);
  }

  /// Set same value into every element of vector.
  /// @param v  Pointer to gsl_vector.
  /// @param x  Same new value for every element.
  static void set_all(vector *v, double const &x) { gsl_vector_set_all(v, x); }

  /// Set zero into every element of vector.
  /// @param v  Pointer to gsl_vector.
  static void set_zero(vector *v) { gsl_vector_set_zero(v); }

  /// Set element at offset `i` to unity and every other element to zero.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset of element to set to unity.
  /// @return  TBD: GSL's documentation does not specify.
  static int set_basis(vector *v, size_t i) {
    return gsl_vector_set_basis(v, i);
  }

  /// Read non-portable binary-image of vector from file.
  /// @param f  Pointer to structure for buffered interface.
  /// @param v  Pointer to gsl_vector.
  /// @return  Zero only on success.
  static int fread(FILE *f, vector *v) { return gsl_vector_fread(f, v); }

  /// Read ASCII-formatted representation of vector from file.
  /// @param f  Pointer to structure for buffered interface.
  /// @param v  Pointer to vector.
  /// @return  Zero only on success.
  static int fscanf(FILE *f, vector *v) { return gsl_vector_fscanf(f, v); }

  /// Swap elements within vector.
  /// @param v  Pointer to vector.
  /// @param i  Offset of one element.
  /// @param j  Offset of other element.
  /// @return  TBD: GSL's documentation does not specify.
  static int swap_elements(vector *v, size_t i, size_t j) {
    return gsl_vector_swap_elements(v, i, j);
  }

  /// Reverse order of elements.
  /// @param v  Pointer to vector.
  /// @return  TBD: GSL's documentation does not specify.
  static int reverse(vector *v) { return gsl_vector_reverse(v); }

  /// Add contents of `cv` into `v` in place.
  /// @param v  Pointer to vector into which `cv` should be accumulated.
  /// @param cv  Pointer to vector to be added into `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int add(vector *v, vector const *cv) { return gsl_vector_add(v, cv); }

  /// Subtract contents of `cv` from `v` in place.
  /// @param v  Pointer to vector that should be reduced by `cv`.
  /// @param cv  Pointer to vector to be subtracted from `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int sub(vector *v, vector const *cv) { return gsl_vector_sub(v, cv); }

  /// Multiply contents of `cv` into `v` in place.
  /// @param v  Pointer to vector into which `cv` should be multiplied.
  /// @param cv  Pointer to vector to be multiplied into `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int mul(vector *v, vector const *cv) { return gsl_vector_mul(v, cv); }

  /// Dive `cv` into `v` in place.
  /// @param v  Pointer to vector that should be divided by `cv`.
  /// @param cv  Pointer to vector whose contents should be divided into `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int div(vector *v, vector const *cv) { return gsl_vector_div(v, cv); }

  /// Multiply scalar into vector in place.
  /// @param v  Pointer to vector to be scaled.
  /// @param x  Scalar to multiply into `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int scale(vector *v, double const &x) {
    return gsl_vector_scale(v, x);
  }

  /// Add constant into each element of `v` in place.
  /// @param v  Pointer to vector whose elements are to be added to.
  /// @param x  Constant to add into `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int add_constant(vector *v, double const &x) {
    return gsl_vector_add_constant(v, x);
  }

  /// Linearly combine in place as `y = a*x + b*y`. This is implemented via
  /// Eigen if the installed GSL have version less than 2.7.
  /// @param a  Coefficient of first vector.
  /// @param x  Pointer to first vector.
  /// @param b  Coefficient of second vector.
  /// @param y  Pointer to second vector and to result.
  /// @return  TBD for GSL, zero if Eigen be used.
  static int
  axpby(double const &a, vector const *x, double const &b, vector *y) {
#if GSL_AT_LEAST(2, 7)
    return gsl_vector_axpby(a, x, b, y);
#else
    return axpby_for_gsl_lt_2p7(a, *x, b, *y);
#endif
  }

  /// Copy data from source to destination.
  /// @param d  Pointer to destination-vector.
  /// @param s  Pointer to source-vector.
  /// @return TBD: GSL's documentation does not specify.
  static int memcpy(vector *d, vector const *s) {
    return gsl_vector_memcpy(d, s);
  }

  /// Swap contents of one and other vector, each with same length.
  /// @param a  Pointer to one vector.
  /// @param b  Pointer to other vector.
  /// @return  TBD: GSL's documentation does not specify.
  static int swap(vector *a, vector *b) { return gsl_vector_swap(a, b); }
};


} // namespace gsl::c

// EOF
