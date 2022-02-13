/// @file       gsl/vector-test.cpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Tests for gsl::vector.

#include "gslcpp/vector.hpp"
#include <catch.hpp>

using gsl::vec_iface;
using gsl::vector;
using gsl::vectorcv;
using gsl::vectord;
using gsl::vectorv;


TEST_CASE("Stack-vector's default constructor works.", "[vector]") {
  vector<3> v;
  REQUIRE(v.size() == 3);
}


TEST_CASE("Stack-vector's constructor from array works.", "[vector]") {
  double d[]= {2.0, 4.0, 6.0, 8.0};

  vector v(d); // No template-parameter required!
  REQUIRE(v.size() == 4);
  REQUIRE(v[0]==2.0);
  REQUIRE(v[1]==4.0);
  REQUIRE(v[2]==6.0);
  REQUIRE(v[3]==8.0);

  vector<2> w(d, 1, 2);
  REQUIRE(w[0] == 4.0);
  REQUIRE(w[1] == 8.0);

  REQUIRE_THROWS(vector<3>(d, 0, 2));
  REQUIRE_THROWS(vector<2>(d, 2, 2));
}


TEST_CASE("Stack-vector's copy-constructor works.", "[vector]") {
  vector v({1.0, 2.0, 3.0});
  vector w= v; // Copy.
  REQUIRE(v == w);

  vectorv view= v;
  vector<3> x= view; // Copy from other kind of vector.
  REQUIRE(x == v);
}


TEST_CASE("Stack-vector's copy-assignment operator works.", "[vector]") {
  vector v({1.0, 2.0, 3.0});
  vector<3> w;
  w= v; // Assign.
}


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


TEST_CASE("vector<VIEW> provides right view.", "[vector]") {
  double a[]= {1.0, 1.0, 2.0, 3.0, 5.0, 8.0}; // Mutable, non-decayed C-array.
  double const *b= a; // Decayed, immutable C-array.

  auto mv= vectorv(a, 3, 0, 2); // Mutable view of a[].
  REQUIRE(mv.size() == 3);
  check(a, mv, 2);

  auto iv= vectorcv(4, b); // Immutable view, ultimately of a[].
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


TEST_CASE("vec::subarray() provides right view.", "[vec]") {
  double a[]= {1.0, 1.0, 2.0, 3.0, 5.0, 8.0}; // Mutable, non-decayed C-array.
  double const(&b)[6]= a; // Immutable, non-decayed C-array.

  // Mutable view of a[], starting at Offset 1 and with Stride 2.
  auto mv= vectorv(a, 3, 1, 2);
  REQUIRE(mv.size() == 3);
  check(a + 1, mv, 2);

  // Immutable view of a[], starting at Offset 0 and with Stride 1.
  auto iv= vectorcv(b);
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
