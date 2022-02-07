/// @file       gsl/vec-base-test.cpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Tests for gsl::vec_base.

#include "gslcpp/vector.hpp"
#include <catch.hpp>

using gsl::memcpy;
using gsl::vec_base;
using gsl::vec_iface;


/// See that C-array matches gsl::vec_iface with stride.
/// @tparam T  Type of descendant of vec_iface<T>.
/// @param a  C-array.
/// @param b  Reference to instance of vec_iface<T>.
/// @param s  Stride.
template<typename T>
void check(double const *a, vec_iface<T> const &b, size_t s= 1) {
  for(size_t j= 0, i= 0; j < b.size(); ++j) {
    REQUIRE(a[i] == b[j]);
    i+= s; // Explicitly step with stride through memory.
  }
}


TEST_CASE("vec_base::view_array() provides right view.", "[vec_base]") {
  double a[]= {1.0, 1.0, 2.0, 3.0, 5.0, 8.0}; // Mutable, non-decayed C-array.
  double const *b= a; // Decayed, immutable C-array.

  auto mv= vec_base::view_array(a, 3, 2); // Mutable view of a.
  REQUIRE(mv.size() == 3);
  check(a, mv, 2);

  auto iv= vec_base::view_array(b, 4); // Immutable view, ultimately of a.
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


TEST_CASE("vec_base::subarray provides right view.", "[vec_base]") {
  double a[]= {1.0, 1.0, 2.0, 3.0, 5.0, 8.0}; // Mutable, non-decayed C-array.
  double const(&b)[6]= a; // Immutable, non-decayed C-array.

  // Mutable view of a[], starting at Offset 1 and with Stride 2.
  auto mv= vec_base::subarray(a, 3, 1, 2);
  REQUIRE(mv.size() == 3);
  check(a + 1, mv, 2);

  // Immutable view of a[], starting at Offset 0 and with Stride 1.
  auto iv= vec_base::subarray(b);
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
