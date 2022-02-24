/// @file       include/gslcpp/version.hpp
/// @brief      Definition of GSL_AT_LEAST and EIGEN_AT_LEAST.
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.

#pragma once


#if !defined(GSL_MAJOR) && !defined(GSL_MINOR)
#  define GSL_MAJOR 2 ///< Default assumption for GSL's major version-number.
#  define GSL_MINOR 5 ///< Default assumption for GSL's minor version-number.
#elif !defined(GSL_MAJOR) || !defined(GSL_MINOR)
#  error "Only one of GSL_MAJOR and GSL_MINOR defined."
#endif


#if !defined(EIGEN_MAJOR) && !defined(EIGEN_MINOR)
#  define EIGEN_MAJOR 3 ///< Default assumption for Eigen's major version.
#  define EIGEN_MINOR 3 ///< Default assumption for Eigen's minor version.
#elif !defined(EIGEN_MAJOR) || !defined(EIGEN_MINOR)
#  error "Only one of EIGEN_MAJOR and EIGEN_MINOR defined."
#endif


#define GSL_AT_LEAST(maj, min) \
  GSL_MAJOR > (maj) || (GSL_MAJOR == (maj) && GSL_MAJOR >= (min))


#define EIGEN_AT_LEAST(maj, min) \
  EIGEN_MAJOR > (maj) || (EIGEN_MAJOR == (maj) && EIGEN_MAJOR >= (min))


// EOF
