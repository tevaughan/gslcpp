/// @file       gsl/vec-base-test.cpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Tests for gsl::vec_base.

#include "gslcpp/vector.hpp"
#include <catch.hpp>
#include <sstream> // ostringstream

#if defined(GSL_VER) && GSL_VER > 26
using gsl::axpby;
#endif

using gsl::vec_base;
using gsl::vec_iface;
using gsl::vector;
using std::ostringstream;


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

  auto mv= vec_base::view_array(a, 3, 2); // Mutable view of a[].
  REQUIRE(mv.size() == 3);
  check(a, mv, 2);

  auto iv= vec_base::view_array(b, 4); // Immutable view, ultimately of a[].
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


TEST_CASE("vec_base::subarray() provides right view.", "[vec_base]") {
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


#if defined(GSL_VER) && GSL_VER > 26
TEST_CASE("axpby() accumulates correctly into y.", "[vec_base]") {
  vector<3> const x({1.0, 2.0, 3.0});
  vector<3> y({2.0, 3.0, 1.0});
  double const a= 0.5;
  double const b= 1.5;
  axpby(a, x, b, y);
  double const r[]= {3.5, 5.5, 3.0};
  check(r, y);
}
#endif


TEST_CASE("equal() compares correctly.", "[vec_base]") {
  vector<3> const x({1.0, 2.0, 3.0});
  vector<3> const y({2.0, 3.0, 1.0});
  vector<3> const z({2.0, 3.0, 1.0});
  REQUIRE(!equal(x, y));
  REQUIRE(x != y);
  REQUIRE(equal(y, z));
  REQUIRE(y == z);
}


TEST_CASE("memcpy() works.", "[vec_base]") {
  vector<3> y({2.0, 3.0, 1.0});
  vector<3> const z({1.0, 2.0, 3.0});
  REQUIRE(!equal(y, z));
  memcpy(y, z);
  REQUIRE(equal(y, z));
}


TEST_CASE("swap() works.", "[vec_base]") {
  vector<3> const a({2.0, 3.0, 1.0});
  vector<3> const b({1.0, 2.0, 3.0});
  vector<3> c= a;
  vector<3> d= b;
  REQUIRE(a == c);
  REQUIRE(b == d);
  swap(c, d);
  REQUIRE(a == d);
  REQUIRE(b == c);
}


TEST_CASE("Stream-operator works.", "[vec_base]") {
  vector<3> const a({2.0, 3.0, 1.0});
  ostringstream oss;
  oss << a;
  REQUIRE(oss.str() == "[2,3,1]");
}


// EOF
