#pragma once
#include "vector-view.hpp"
#include "vector.hpp"
#include "xf.hpp"

namespace gsl::c {


template<> struct xf<double> {
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
