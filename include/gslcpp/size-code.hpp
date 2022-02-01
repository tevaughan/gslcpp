/// @file       gsl/size-code.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition for gsl::size_code.

#pragma once

namespace gsl {


/// Non-positive size-codes, each of which is legal to use as template-value
/// argument to class vector.
/// - When positive, template-value argument to class vector is number of
///   elements stored inside instance of vector.
/// - Two non-positive size-codes are defined, each with different meaning.
/// - Each non-positive code indicates that size of vector is determined not at
///   compile-time but at run-time.
enum size_code {
  /// `DCON` (indicating that vector is *dynamic container*) specifies that
  /// vector's data, allocated on construction, are external to instance but
  /// *owned* by it.
  DCON= 0,
  /// `VIEW` (indicating that vector is *view of external data*) specifies that
  /// vector's data are external to instance and *not* owned by it.
  VIEW= -1,
};


} // namespace gsl

// EOF
