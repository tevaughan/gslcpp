/// @file       test/vector-test.cpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Tests for gsl::vector.

#include "gslcpp/vector-view.hpp"
#include "gslcpp/vector.hpp"
#include <catch.hpp>

using gsl::v_iface;
using gsl::vector;
using gsl::vector_view;


TEST_CASE("Static vector's default constructor works.", "[vector]") {
  vector<double, 3> v;
  REQUIRE(v.size() == 3);
}


TEST_CASE("Dynamic vector's base-constructor works.", "[vector]") {
  vector<double> v(15);
  REQUIRE(v.size() == 15);
}


TEST_CASE("Static vector's constructor from array works.", "[vector]") {
  double d[]= {2.0, 4.0, 6.0, 8.0};
  vector v(d); // No template-parameter required!
  REQUIRE(v.size() == 4);
  REQUIRE(v[0] == 2.0);
  REQUIRE(v[1] == 4.0);
  REQUIRE(v[2] == 6.0);
  REQUIRE(v[3] == 8.0);
}


TEST_CASE("Dynamic vector's constructor from array works.", "[vector]") {
  double d[]= {2.0, 4.0, 6.0, 8.0};
  double const *e= d;

  vector v(e, 4); // No template-parameter required!
  REQUIRE(v.size() == 4);
  REQUIRE(v[0] == 2.0);
  REQUIRE(v[1] == 4.0);
  REQUIRE(v[2] == 6.0);
  REQUIRE(v[3] == 8.0);
}


TEST_CASE("Static vector's assignment from array works.", "[vector]") {
  double d[]= {2.0, 4.0, 6.0, 8.0};

  vector v(d); // No template-parameter required!
  REQUIRE(v[0] == 2.0);
  REQUIRE(v[1] == 4.0);
  REQUIRE(v[2] == 6.0);
  REQUIRE(v[3] == 8.0);

  v.set_zero();
  REQUIRE(v[0] == 0.0);
  REQUIRE(v[1] == 0.0);
  REQUIRE(v[2] == 0.0);
  REQUIRE(v[3] == 0.0);

  v= d;
  REQUIRE(v[0] == 2.0);
  REQUIRE(v[1] == 4.0);
  REQUIRE(v[2] == 6.0);
  REQUIRE(v[3] == 8.0);
}


TEST_CASE("Static vector's copy-constructor works.", "[vector]") {
  vector v({1.0, 2.0, 3.0});
  vector w= v; // Copy.
  REQUIRE(v == w);

  vector_view view= v.view();
  vector<double, 3> x= view; // Copy from other kind of vector.
  REQUIRE(x == v);
}


TEST_CASE("Static vector's copy-assignment works.", "[vector]") {
  vector v({1.0, 2.0, 3.0});
  vector<double, 3> w;
  w= v; // Assign.
}


// EOF
