/// \dir        include/gslcpp/doc
/// \brief      Narrative-documentation.

/// \file       include/gslcpp/doc/mainpage.hpp
/// \brief      Documentation for main page in output of Doxygen.
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.

/// \mainpage
///
/// `gslcpp` implements a modern-C++ wrapper around GSL.
///
/// For the first release (2022 March), a wrapper for GSL's vector is provided.
///
/// See the [repository at GitHub](https://github.com/tevaughan/gslcpp).
///
/// Here is an example-program:
/// \include vector-example.cpp
///
/// And here is its output:
/// \include vector-example.out
///
/// The move-constructor is also defined for gsl::vector<T,0>, and so one could
/// also do something like this:
///
/// ~~~{.cpp}
/// #include <gsl/vector.hpp>
///
/// vector<float,0> read_big_file_into_array();
///
/// int main() {
///   vector v= read_big_file_into_array();
///   return 0;
/// }
/// ~~~
///
/// In compiling the code above, the compiler might elide copying of the
/// return-value from `read_big_file_into_array()` but is not *required* to
/// elide copying (according to C++-17), depending on how the vector inside the
/// function is obtained.
///
/// However, even if there were no copy-elision, the big array would still not
/// be copied into `v` because there is a move-constructor that would be
/// called.

// EOF
