/// @file       test/static-vector-test.cpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Tests for gsl::static_vector.

#include "gslcpp/static-vector.hpp"
#include "gslcpp/vector-view.hpp"
#include <catch.hpp>

using gsl::static_vector;
using gsl::v_iface;
using gsl::vector_view;


TEST_CASE("Static vector's default constructor works.", "[static-vector]") {
  static_vector<3> v;
  REQUIRE(v.size() == 3);
}


TEST_CASE("Static vector's constructor from array works.", "[static-vector]") {
  double d[]= {2.0, 4.0, 6.0, 8.0};
  double const *e= d;

  static_vector v(d); // No template-parameter required!
  REQUIRE(v.size() == 4);
  REQUIRE(v[0] == 2.0);
  REQUIRE(v[1] == 4.0);
  REQUIRE(v[2] == 6.0);
  REQUIRE(v[3] == 8.0);

  static_vector<2> w(d, 1, 2);
  REQUIRE(w[0] == 4.0);
  REQUIRE(w[1] == 8.0);

  REQUIRE_THROWS(static_vector<3>(d, 0, 2));
  REQUIRE_THROWS(static_vector<2>(d, 2, 2));

  static_vector<2> x(2, e);
  REQUIRE(x[0]==2.0);
  REQUIRE(x[1]==6.0);
  REQUIRE(x.size() == 2);
}


TEST_CASE("Static vector's assignment from array works.", "[static-vector]") {
  double d[]= {2.0, 4.0, 6.0, 8.0};

  static_vector v(d); // No template-parameter required!
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


TEST_CASE("Static vector's copy-constructor works.", "[static-vector]") {
  static_vector v({1.0, 2.0, 3.0});
  static_vector w= v; // Copy.
  REQUIRE(v == w);

  vector_view view= v.view();
  static_vector<3> x= view; // Copy from other kind of vector.
  REQUIRE(x == v);
}


TEST_CASE(
      "Static vector's copy-assignment operator works.", "[static-vector]") {
  static_vector v({1.0, 2.0, 3.0});
  static_vector<3> w;
  w= v; // Assign.
}


// EOF
