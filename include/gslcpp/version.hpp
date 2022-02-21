/// @file       include/gsl/version.hpp
/// @brief      Definition of gsl::version.
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.

#if !defined(GSL_MAJOR) && !defined(GSL_MINOR)
#  define GSL_MAJOR 2
#  define GSL_MINOR 5
#elif !defined(GSL_MAJOR) || !defined(GSL_MINOR)
#  error "Only one of GSL_MAJOR and GSL_MINOR defined."
#endif

#if !defined(EIGEN_MAJOR) && !defined(EIGEN_MINOR)
#  define EIGEN_MAJOR 3
#  define EIGEN_MINOR 3
#elif !defined(EIGEN_MAJOR) || !defined(EIGEN_MINOR)
#  error "Only one of EIGEN_MAJOR and EIGEN_MINOR defined."
#endif

namespace gsl {


struct version {
  int major; ///< Major number detected by cmake.
  int minor; ///< Minor number detected by cmake.

  /// Initialize number detected by cmake.
  constexpr version(int maj, int min): major(maj), minor(min) {}

  /// Return true only if major and minor numbers detected by cmake amount to
  /// version at least that indicated by parameters.
  /// @param maj  Major number.
  /// @param min  Minor number.
  /// @return  True only if detected version be at least specified version.
  constexpr bool at_least(int maj, int min) const {
    if(major > maj || (major == maj && minor >= min)) { return true; }
    return false;
  }
};


/// GSL's version as detected by build-system or assumed by default.
constexpr version VERSION{GSL_MAJOR, GSL_MINOR};


} // namespace gsl


namespace Eigen {


/// Eigen's version as detected by build-system or assumed by default.
constexpr gsl::version VERSION{EIGEN_MAJOR, EIGEN_MINOR};


} // namespace Eigen

// EOF
