/// \file       include/gslcpp/doc/d-v-iface.hpp
/// \brief      Narrative documentation for gsl::vector.
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.

/// \page d_v_iface About gsl::v_iface
///
/// The template-class gsl::v_iface provides the bulk of the C++ interface to
/// GSL's vector.
///
/// gsl::v_iface has two descendants, gsl::vector and gsl::vector_view.
///
/// - gsl::vector provides constructors, each of which allocates memory for
///   a new vector.
///
/// - gsl::vector_view provides constructors, each of which provides a view
///   into an existing C-style array.
///
/// Additionally, any instance of gsl::v_iface has member functions, each of
/// which provies a view like that provided by construction of
/// gsl::vector_view:
///
/// - gsl::vector::subvector() returns a view of a portion of an existing
///   vector.
///
/// - gsl::vector::view() return a view of the whole of an existing vector.
///
/// A good overview of the interface can be found by looking at the
/// documentation for
///
/// - gsl::v_iface (where the member-functions are listed) and
/// - v-iface.hpp (where the global functions are listed).

// EOF

