/// @file       include/gslcpp/c/fwrite.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition of gslcpp::FILE *f, c::fwrite.

#pragma once
#include "vector.hpp"

namespace gsl::c {

inline int fwrite(FILE *f, c::vector<double const> * v) { return gsl_vector_fwrite(f,v); }

inline int fwrite(FILE *f, c::vector<float const> * v) { return gsl_vector_float_fwrite(f,v); }

inline int fwrite(FILE *f, c::vector<long double const> * v) { return gsl_vector_long_double_fwrite(f,v); }

inline int fwrite(FILE *f, c::vector<int const> * v) { return gsl_vector_int_fwrite(f,v); }

inline int fwrite(FILE *f, c::vector<unsigned const> * v) { return gsl_vector_uint_fwrite(f,v); }

inline int fwrite(FILE *f, c::vector<long const> * v) { return gsl_vector_long_fwrite(f,v); }

inline int fwrite(FILE *f, c::vector<unsigned long const> * v) { return gsl_vector_ulong_fwrite(f,v); }

inline int fwrite(FILE *f, c::vector<short const> * v) { return gsl_vector_short_fwrite(f,v); }

inline int fwrite(FILE *f, c::vector<unsigned short const> * v) { return gsl_vector_ushort_fwrite(f,v); }

inline int fwrite(FILE *f, c::vector<char const> * v) { return gsl_vector_char_fwrite(f,v); }

inline int fwrite(FILE *f, c::vector<unsigned char const> * v) { return gsl_vector_uchar_fwrite(f,v); }

inline int fwrite(FILE *f, c::vector<gsl_complex const> * v) { return gsl_vector_complex_fwrite(f,v); }

inline int fwrite(FILE *f, c::vector<gsl_complex_float const> * v) { return gsl_vector_complex_float_fwrite(f,v); }

inline int fwrite(FILE *f, c::vector<gsl_complex_long_double const> * v) { return gsl_vector_complex_long_double_fwrite(f,v); }


} // namespace gsl::c

// EOF