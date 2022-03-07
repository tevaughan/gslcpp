/// \dir        include/gslcpp
/// \brief      Top-level directory for gslcpp's header-only library.

/// \file       include/gslcpp/vector.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::vector.

#pragma once

#include "vec/v-iface.hpp" // v_iface
#include "vec/v-stor.hpp" // v_stor

namespace gsl {


using std::enable_if_t;
using std::is_const_v;


/// Constructor-type for vector whose storage is owned by instance of vector.
///
/// %vector has its interface to storage given by gsl::v_stor, and most of the
/// ordinary vector-interface is given by gsl::v_iface.
///
/// %vector inherits these and provides template-constructors for an instance
/// of type gsl::v_iface<T, S, v_stor>.
///
/// Each constructor copies data from the source identified as an argument or
/// (in the case of the move-constructor when both the instance and the source
/// have size determined at run-time) *moves* the data into the instance.
///
/// Template-value-parameter `S` indicates the number of elements in the vector
/// at compile-time.  If `S` be zero, then the number of elements in the vector
/// is determined at run-time.
///
/// When using %vector, one typically does not need to specify
/// template-parameters:
///
/// ~~~{.cpp}
/// #include <gslcpp/vector.hpp>
///
/// int main() {
///   double g[]= {1, 2, 3, 4, 5, 6};
///
///   // Deduce vector<double, 6> with stride=1, and copy the data:
///   gsl::vector v1= g;
///
///   // Deduce vector<double, 0> with three elements and stride=2, and copy
///   // the data:
///   gsl::vector v2(g, 3, 2);
///
///   // Deduce vector<double const, 0> with three elements and stride=2, and
///   // copy the data:
///   double const *h= g;
///   gsl::vector v3(h, 3, 2);
///
///   return 0;
/// }
/// ~~~
///
/// \tparam T  Type of each element in vector.
/// \tparam S  Compile-time number of elements (0 for number set at run-time).
template<typename T, size_t S= 0> struct vector: public v_iface<T, S, v_stor> {
  using P= v_iface<T, S, v_stor>; ///< Type of ancestor.
  using P::P;

  /// Copy data from other vector of same type.
  /// \param src  Reference to other vector.
  vector(vector const &src): P(src.v().size) { memcpy(*this, src); }

  /// Enable move-constructor in gsl::v_stor to work.
  vector(vector &&)= default;

  /// Enable explicitly defined copy-constructor in gsl::v_iface.
  /// \return  Reference to this instance after assignment.
  vector &operator=(vector const &)= default;

  /// Enable move-assignment operator in gsl::v_stor to work.
  /// \return  Reference to this instance after assignment.
  vector &operator=(vector &&)= default;

  /// Struct defining whether size of other vector allow copying its data.
  /// \tparam N  Number of elements in other vector.
  template<size_t N> struct sz_ok {
    enum { V= (N == S || N == 0 || S == 0) /**< True if N be OK. */ };
  };

  /// Copy data from vector of different type (different element-constness,
  /// different compile-time number of elements, or different
  /// storage-interface).
  /// \tparam N  Number of elements in other vector.
  /// \tparam V  Type of other vector's interface to storage.
  /// \param src  Reference to other vector.
  template<
        size_t N,
        template<typename, size_t>
        class V,
        typename= enable_if_t<sz_ok<N>::V && !is_const_v<T>>>
  vector(v_iface<T const, N, V> const &src): P(src.v().size) {
    memcpy(*this, src);
  }

  /// Copy data from vector of different type (different compile-time number of
  /// elements or different storage-interface).
  /// \tparam N  Number of elements in other vector.
  /// \tparam V  Type of other vector's interface to storage.
  /// \param src  Reference to other vector.
  template<
        size_t N,
        template<typename, size_t>
        class V,
        typename= enable_if_t<sz_ok<N>::V>>
  vector(v_iface<T, N, V> const &src): P(src.v().size) {
    memcpy(*this, src);
  }

  /// Copy from standard (decayed) C-array.
  ///
  /// Arguments are ordered differently from those given to
  /// gsl_vector_viewiew_array_with_stride().  Putting stride at *end* allows
  /// it to have default value of 1.
  ///
  /// \param d  Pointer to first element of array and of vector.
  /// \param n  Number of elements in vector.
  /// \param s  Stride of elements relative to array.
  vector(T const *d, size_t n, size_t s= 1): P(n) {
    auto const cview= w_vector_view_array(d, s, n);
    memcpy(*this, v_iface<T const, 0, v_view>(cview));
  }

  /// Copy from non-decayed C-array.
  /// \param d  Reference to non-decayed C-array.
  vector(T const (&d)[S]): P(S) {
    auto const cview= w_vector_view_array(d, 1, S);
    memcpy(*this, v_iface<T const, S, v_view>(cview));
  }
};


} // namespace gsl

// EOF
