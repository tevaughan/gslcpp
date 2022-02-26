#pragma once
#include "vector-view.hpp"
#include "vector.hpp"
#include "xf.hpp"

namespace gsl::c {


template<> struct xf<float> {
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
