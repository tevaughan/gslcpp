/// \file       include/gslcpp/c/xf-double.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::c::xf<double>, gsl::c::xf<double const>.

#pragma once
#include "vector-view.hpp"
#include "vector.hpp"
#include "xf.hpp"

namespace gsl::c {


/// \anchor xf_double_const
/// Specialization for `double const`.
/// \sa \ref xf_generic
template<> struct xf<double const> {
  /// Test equality of two vectors.
  /// @param a  Pointer to one vector.
  /// @param b  Pointer to other vector.
  /// @return  True only if vectors be equal.
  static bool equal(vector<double const> *a, vector<double const> *b) {
    return gsl_vector_equal(a, b);
  }
};


/// \anchor xf_double
/// Specialization for `double`.
/// \sa \ref xf_generic
template<> struct xf<double>: public xf<double const> {
  /// Set element at offset `i` to unity and every other element to zero.
  /// @param v  Pointer to gsl_vector.
  /// @param i  Offset of element to set to unity.
  /// @return  TBD: GSL's documentation does not specify.
  static int set_basis(vector<double> *v, size_t i) {
    return gsl_vector_set_basis(v, i);
  }

  /// Read non-portable binary-image of vector from file.
  /// @param f  Pointer to structure for buffered interface.
  /// @param v  Pointer to gsl_vector.
  /// @return  Zero only on success.
  static int fread(FILE *f, vector<double> *v) {
    return gsl_vector_fread(f, v);
  }

  /// Read ASCII-formatted representation of vector from file.
  /// @param f  Pointer to structure for buffered interface.
  /// @param v  Pointer to vector.
  /// @return  Zero only on success.
  static int fscanf(FILE *f, vector<double> *v) {
    return gsl_vector_fscanf(f, v);
  }

  /// Swap elements within vector.
  /// @param v  Pointer to vector.
  /// @param i  Offset of one element.
  /// @param j  Offset of other element.
  /// @return  TBD: GSL's documentation does not specify.
  static int swap_elements(vector<double> *v, size_t i, size_t j) {
    return gsl_vector_swap_elements(v, i, j);
  }

  /// Reverse order of elements.
  /// @param v  Pointer to vector.
  /// @return  TBD: GSL's documentation does not specify.
  static int reverse(vector<double> *v) { return gsl_vector_reverse(v); }

  /// Add contents of `cv` into `v` in place.
  /// @param v  Pointer to vector into which `cv` should be accumulated.
  /// @param cv  Pointer to vector to be added into `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int add(vector<double> *v, vector<double> const *cv) {
    return gsl_vector_add(v, cv);
  }

  /// Subtract contents of `cv` from `v` in place.
  /// @param v  Pointer to vector that should be reduced by `cv`.
  /// @param cv  Pointer to vector to be subtracted from `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int sub(vector<double> *v, vector<double> const *cv) {
    return gsl_vector_sub(v, cv);
  }

  /// Multiply contents of `cv` into `v` in place.
  /// @param v  Pointer to vector into which `cv` should be multiplied.
  /// @param cv  Pointer to vector to be multiplied into `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int mul(vector<double> *v, vector<double> const *cv) {
    return gsl_vector_mul(v, cv);
  }

  /// Dive `cv` into `v` in place.
  /// @param v  Pointer to vector that should be divided by `cv`.
  /// @param cv  Pointer to vector whose contents should be divided into `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int div(vector<double> *v, vector<double> const *cv) {
    return gsl_vector_div(v, cv);
  }

  /// Multiply scalar into vector in place.
  /// @param v  Pointer to vector to be scaled.
  /// @param x  Scalar to multiply into `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int scale(vector<double> *v, double const &x) {
    return gsl_vector_scale(v, x);
  }

  /// Add constant into each element of `v` in place.
  /// @param v  Pointer to vector whose elements are to be added to.
  /// @param x  Constant to add into `v`.
  /// @return  TBD: GSL's documentation does not specify.
  static int add_constant(vector<double> *v, double const &x) {
    return gsl_vector_add_constant(v, x);
  }

  /// Copy data from source to destination.
  /// @param d  Pointer to destination-vector.
  /// @param s  Pointer to source-vector.
  /// @return TBD: GSL's documentation does not specify.
  static int memcpy(vector<double> *d, vector<double> const *s) {
    return gsl_vector_memcpy(d, s);
  }

  /// Swap contents of one and other vector, each with same length.
  /// @param a  Pointer to one vector.
  /// @param b  Pointer to other vector.
  /// @return  TBD: GSL's documentation does not specify.
  static int swap(vector<double> *a, vector<double> *b) {
    return gsl_vector_swap(a, b);
  }
};


} // namespace gsl::c

// EOF
