/// @file       gsl/vector-test.cpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Tests for gsl::vector.

#include "gslcpp/vector.hpp"
#include <catch.hpp>

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
}


TEST_CASE("Stack-vector's copy-constructor works.", "[vector]") {
  vector v({1.0, 2.0, 3.0});
  vector w= v;
  REQUIRE(v == w);
}


TEST_CASE("Stack-vector's copy-assignment operator works.", "[vector]") {
  vector v({1.0, 2.0, 3.0});
  vector<3> w;
  w= v;
}


// EOF
