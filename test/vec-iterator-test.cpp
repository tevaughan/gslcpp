/// @file       test/vec-iterator-test.cpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Tests for gsl::vec_iterator.

#include "gslcpp/vector.hpp"
#include <catch.hpp>


using gsl::vec_iterator;
using gsl::vector;


using v3= vector<3>;


TEST_CASE("Construction and dereference work.", "[vec-iterator]") {
  v3 const a({1.0, 2.0, 3.0});
  v3 b({-1.0, -2.0, -3.0});

  vec_iterator<v3 const, double const> ia(a, 0);
  REQUIRE(*ia == 1.0);

  vec_iterator<v3, double> ib(b, 2);
  REQUIRE(*ib == -3.0);
}


// EOF

