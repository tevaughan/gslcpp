/// \file       include/gslcpp/doc/d-vector-view.hpp
/// \brief      Narrative documentation for gsl::vector_view.
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.

/// \page d_vector_view About gsl::vector_view
///
/// The template-class gsl::vector_view is one of two descendants of
/// gsl::v_iface.
///
/// The other is gsl::vector.
///
/// gsl::vector_view exists to provide constructors for gsl::v_iface.
///
/// - gsl::vector_view provides no interface other than construction.
///
/// - gsl::v_iface provides almost all of the interfaces that GSL's native
///   vector provides.
///
/// - An instance constructed via one of the template-specializations of
///   gsl::vector_view does *not* own memory allocated for elements in
///   a vector.
///
/// - Internally, the return-value of `gsl_vector_view_array()` is stored on
///   the stack in the instance of gsl::vector_view.
///   - The instance of `gsl_vector_view` returned by `gsl_vector_view_array()`
///     consumes about 40 bytes on a 64-bit machine.
///
/// - There is on the stack no pointer to the virtual-function table.
///   - There is no virtual destructor in the inheritance-chain.
///
/// ## Example
///
/// The template-parameters to gsl::vector_view often need not be specified
/// because they are deduced by the compiler.
///
/// Here is an example-program:
/// \include vector-view-example.cpp
///
/// And here is its output:
/// \include vector-view-example.out

// EOF

