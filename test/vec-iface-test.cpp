/// @file       test/vec-iface-test.cpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Tests for gsl::vec_iface.

#include "gslcpp/vector.hpp"
#include <catch.hpp>


using gsl::vec_iface;
using gsl::vector;


using v3= vector<3>;


v3 const a({1.0, 2.0, 3.0});


TEST_CASE("vec_iface::begin() works.", "[vec-iface]") {
  v3 b= a;
  auto ia= a.begin();
  REQUIRE(*ia == 1.0);
  auto ib= b.begin();
  *ib++= -1.0;
  *ib++= -2.0;
  *ib= -3.0;
  REQUIRE(*b.begin() == -1.0);
}


TEST_CASE("vec_iface::end() works.", "[vec-iface]") {
  v3 b= a;
  auto ia= a.end() - 1;
  REQUIRE(*ia == 3.0);
  for(auto ib= b.begin(); ib != b.end(); ++ib) { *ib= a[ib - b.begin()]; }
  REQUIRE(a[0] == b[0]);
  REQUIRE(a[1] == b[1]);
  REQUIRE(a[2] == b[2]);
  REQUIRE(a.end() - a.begin() == b.size());
  REQUIRE(b.end() - b.begin() == b.size());
}


TEST_CASE("vec_iface::vec() works.", "[vec-iface]") {
  REQUIRE(gsl_vector_get(&a.vec(), 0) == 1.0);
  v3 b= a;
  gsl_vector_set(&b.vec(), 0, -1.0);
  REQUIRE(gsl_vector_get(&b.vec(), 0) == -1.0);
}


TEST_CASE("vec_iface::size() works.", "[vec-iface]") {
  REQUIRE(a.size() == 3);
}


TEST_CASE("vec_iface::stride() works.", "[vec-iface]") {
  REQUIRE(a.stride() == 1);
  vector<6> b({1.0, -1.0, 2.0, -2.0, 3.0, -3.0});
  auto c= b.subvector(3, 1, 2);
  REQUIRE(c.stride() == 2);
}


TEST_CASE("vec_iface::data() works.", "[vec-iface]") {
  REQUIRE(a.data() == &a[0]);
  double b[]= {1.0, -1.0, 2.0, -2.0, 3.0, -3.0};
  gsl::vectorv c(b, 3, 1, 2);
  REQUIRE(c.data() == b + 1);
}


TEST_CASE("vec_iface's getters work.", "[vec-iface]") {
  REQUIRE(a.get(1) == 2.0);
  REQUIRE(a[0] == 1.0);
}


TEST_CASE("vec_iface's setters work.", "[vec-iface]") {
  v3 b= a;
  b[0]= -1.0;
  b.set(1, -2.0);
  REQUIRE(b[0] == -1.0);
  REQUIRE(b[1] == -2.0);
}


// EOF
