/// @file       test/vector-view-test.cpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Tests for gsl::vector_view.

#include "gslcpp/vector-view.hpp"
#include <catch.hpp>

using gsl::v_iface;
using gsl::vector_view;


/// See that C-array matches gsl::v_iface with stride.
/// @tparam T  Type of storage for v_iface<T>.
/// @param a  C-array.
/// @param b  Reference to instance of v_iface<T>.
/// @param s  Stride.
template<typename T, unsigned N, template<typename, unsigned> class V>
void check(double const *a, v_iface<T, N, V> const &b, size_t s= 1) {
  for(size_t j= 0, i= 0; j < b.size(); ++j) {
    REQUIRE(a[i] == b[j]);
    i+= s; // Explicitly step with stride through memory.
  }
}


TEST_CASE("vector_view provides right view of array.", "[vector-view]") {
  double a[]= {1.0, 1.0, 2.0, 3.0, 5.0, 8.0}; // Mutable, non-decayed C-array.
  double const *b= a; // Decayed, immutable C-array.

  auto mv= vector_view<double>(a, 3, 0, 2); // Mutable view of a[].
  REQUIRE(mv.size() == 3);
  check(a, mv, 2);

  // Immutable view, ultimately of a[].
  auto iv= vector_view<double const>(4, b);
  REQUIRE(iv.size() == 4);
  check(a, iv);

  // Modify mutable view.
  mv[0]= -1.0;
  mv[1]= -2.0;
  mv[2]= -3.0;

  // Verify that immutable view, ultimately of a[], shows appropriate change.
  // - Immutable view does NOT guarantee immutability of what is viewed.
  // - Rather, immutable view is just like const-pointer in C: What's pointed
  //   to might change, but const-pointer cannot be used to make change.
  double const c[]= {-1.0, 1.0, -2.0, 3.0, -3.0, 8.0};
  check(c, iv);
}


TEST_CASE(
      "vector_view with offset provides right view of array.",
      "[vector-view]") {
  double a[]= {1.0, 1.0, 2.0, 3.0, 5.0, 8.0}; // Mutable, non-decayed C-array.
  double const(&b)[6]= a; // Immutable, non-decayed C-array.

  // Mutable view of a[], starting at Offset 1 and with Stride 2.
  auto mv= vector_view<double>(a, 3, 1, 2);
  REQUIRE(mv.size() == 3);
  check(a + 1, mv, 2);

  // Immutable view of a[], starting at Offset 0 and with Stride 1.
  auto iv= vector_view<double const>(b);
  REQUIRE(iv.size() == 6);
  check(b, iv);

  // Modify mutable view.
  mv[0]= -1.0;
  mv[1]= -2.0;
  mv[2]= -3.0;

  // Verify that immutable view, ultimately of a[], shows appropriate change.
  double const c[]= {1.0, -1.0, 2.0, -2.0, 5.0, -3.0};
  check(c, iv);
}


// EOF
