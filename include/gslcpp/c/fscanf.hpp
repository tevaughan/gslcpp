/// @file       include/gslcpp/c/fscanf.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gsl::c::fscanf.

#pragma once
#include "type-map.hpp"

namespace gsl::c {

inline int fscanf(FILE *f, c::vector<double> * v) { return gsl_vector_fscanf(f,v); }

inline int fscanf(FILE *f, c::vector<float> * v) { return gsl_vector_float_fscanf(f,v); }

inline int fscanf(FILE *f, c::vector<long double> * v) { return gsl_vector_long_double_fscanf(f,v); }

inline int fscanf(FILE *f, c::vector<int> * v) { return gsl_vector_int_fscanf(f,v); }

inline int fscanf(FILE *f, c::vector<unsigned> * v) { return gsl_vector_uint_fscanf(f,v); }

inline int fscanf(FILE *f, c::vector<long> * v) { return gsl_vector_long_fscanf(f,v); }

inline int fscanf(FILE *f, c::vector<unsigned long> * v) { return gsl_vector_ulong_fscanf(f,v); }

inline int fscanf(FILE *f, c::vector<short> * v) { return gsl_vector_short_fscanf(f,v); }

inline int fscanf(FILE *f, c::vector<unsigned short> * v) { return gsl_vector_ushort_fscanf(f,v); }

inline int fscanf(FILE *f, c::vector<char> * v) { return gsl_vector_char_fscanf(f,v); }

inline int fscanf(FILE *f, c::vector<unsigned char> * v) { return gsl_vector_uchar_fscanf(f,v); }

inline int fscanf(FILE *f, c::vector<gsl_complex> * v) { return gsl_vector_complex_fscanf(f,v); }

inline int fscanf(FILE *f, c::vector<gsl_complex_float> * v) { return gsl_vector_complex_float_fscanf(f,v); }

inline int fscanf(FILE *f, c::vector<gsl_complex_long_double> * v) { return gsl_vector_complex_long_double_fscanf(f,v); }


} // namespace gsl::c

// EOF
