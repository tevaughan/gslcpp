/// \file       include/gslcpp/doc/d-vector.hpp
/// \brief      Narrative documentation for gsl::vector.
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.

/// \page d_vector About gsl::vector
///
/// The template-class gsl::vector is one of two descendants of gsl::v_iface.
///
/// The other is gsl::vector_view.
///
/// gsl::vector exists to provide constructors for gsl::v_iface.
///
/// - gsl::vector provides no interface other than construction.
///
/// - gsl::v_iface provides almost all of the interfaces that GSL's native
///   vector provides.
///
/// - Any instance constructed via one of the template-specializations of
///   gsl::vector owns memory allocated both for the elements in the vector and
///   for some metadata referring to that memory.
///
///
/// ## Dynamic Allocation of Memory
///
/// For any element-type `T` (`double`, `float`, `complex<long double>`, etc.),
/// any instance of `gsl::vector<T,0>` has the number of elements determined at
/// run-time.
///
/// - Internally, construction involves a call
///   - to `gsl_vector_alloc()` or
///   - to `gsl_vector_calloc()`.
///
/// - The pointer returned is stored on the stack inside the instance.
///
/// - There is also on the stack a pointer to the virtual-function table.
///   - The ultimate base-class gsl::v_stor<T>, which manages the pointer, has
///     a virtual destructor.
///
///
/// ## Static Allocation of Memory
///
/// For any element-type `T` and positive compile-time integer `N`, any
/// instance of `gsl::vector<T,N>` has the number of elements determined at
/// compile-time.
///
/// - Internally, the elements are allocated on the stack in a C-style array.
///
/// - The return-value of `gsl_vector_view_array()` is also stored on the
///   stack in the instance of gsl::vector.
///   - The instance of `gsl_vector_view` returned by `gsl_vector_view_array()`
///     consumes about 40 bytes on a 64-bit machine.
///
/// - There is on the stack no pointer to the virtual-function table.
///   - There is no virtual destructor in the inheritance-chain.
///
///
/// ## Example
///
/// The template-parameters to gsl::vector often need not be specified because
/// they are deduced by the compiler.
///
/// Here is an example-program:
/// \include vector-example.cpp
///
/// And here is its output:
/// \include vector-example.out
///
///
/// ## Move-Construction
///
/// The move-constructor is also defined for `gsl::vector<T>`, and so one could
/// also do something like this:
///
/// ~~~{.cpp}
/// #include <gsl/vector.hpp>
///
/// using gsl::vector;
///
/// vector<float,0> read_big_file_into_array();
///
/// int main() {
///   vector v= read_big_file_into_array();
///   return 0;
/// }
/// ~~~
///
/// In compiling the code above, the compiler,
///
/// - *might* elide the constructor-call in the installation of the
///   return-value from `read_big_file_into_array()` into `v`, but
///
/// - is not *required* to elide the call (according to C++-17), depending on
///   how the vector inside the function is obtained.
///
/// However, even if the compiler do not elide the call to a constructor, the
/// big array would still not be *copied* into `v` because there is
/// a move-constructor that would be called.

// EOF

