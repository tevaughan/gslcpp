/// @file       test/vec-iterator-test.cpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Tests for gsl::vec_iterator.

#include "gslcpp/vector.hpp"
#include <catch.hpp>


using gsl::vec_iterator;
using gsl::vector;


using v3= vector<3>;


v3 const a({1.0, 2.0, 3.0});
v3 b;


TEST_CASE("Construction and dereference work.", "[vec-iterator]") {
  b= v3({-1.0, -2.0, -3.0});

  vec_iterator<v3 const> ia(a, 0);
  REQUIRE(*ia == 1.0);

  vec_iterator<v3> ib(b, 2);
  REQUIRE(*ib == -3.0);
}


TEST_CASE("Relative dereference works.", "[vec-iterator]") {
  b= a;
  vec_iterator<v3> ib(b, 1);
  REQUIRE(ib[+0] == 2.0);
  REQUIRE(ib[-1] == 1.0);
  REQUIRE(ib[+1] == 3.0);
  ib[-1]= -10.0;
  REQUIRE(ib[-1] == -10.0);
  REQUIRE(b[0] == -10.0);
}


// EOF

