/// @file       test/vec-iface-test.cpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Tests for gsl::vec_iface.

#include "gslcpp/vector.hpp"
#include <catch.hpp>


using gsl::vec_iface;
using gsl::vector;


using v3= vector<3>;


TEST_CASE("Iterators work.", "[vec-iface]") {
  v3 const a({1.0, 2.0, 3.0});
  v3 b;
  auto ib= b.begin();
  for(auto ia= a.begin(); ia != a.end(); ++ia) {
    REQUIRE((*ib++= *ia) == *ia);
  }
  REQUIRE(a == b);
  REQUIRE(*(a.begin() + 2) == 3.0);
  REQUIRE(*(b.end() - 3) == 1.0);
  *(b.end() - 2)= -2.0;
  REQUIRE(b[1] == -2.0);
}


// EOF
