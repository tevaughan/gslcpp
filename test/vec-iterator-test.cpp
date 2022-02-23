/// @file       test/vec::iterator-test.cpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Tests for gsl::vec::iterator.

#include "gslcpp/vector.hpp"
#include <catch.hpp>


using gsl::vector_s;
using gsl::vec::iterator;


using v3= vector_s<3>;


v3 const a({1.0, 2.0, 3.0});
v3 b;


TEST_CASE("Construction and dereference work.", "[vec::iterator]") {
  b= v3({-1.0, -2.0, -3.0});

  iterator<v3 const> ia(a, 0);
  REQUIRE(*ia == a[0]);

  iterator<v3> ib(b, 2);
  REQUIRE(*ib == b[2]);
}


TEST_CASE("Relative dereference works.", "[vec::iterator]") {
  b= a;
  iterator<v3> ib(b, 1);
  REQUIRE(ib[+0] == 2.0);
  REQUIRE(ib[-1] == 1.0);
  REQUIRE(ib[+1] == 3.0);
  ib[-1]= -10.0;
  REQUIRE(ib[-1] == -10.0);
  REQUIRE(b[0] == -10.0);
}


TEST_CASE("Pre-increment works.", "[vec::iterator]") {
  auto i= a.begin();
  REQUIRE(*++i == 2.0);
  REQUIRE(*i == 2.0);
}


TEST_CASE("Post-increment works.", "[vec::iterator]") {
  auto i= a.begin();
  REQUIRE(*i++ == 1.0);
  REQUIRE(*i == 2.0);
}


TEST_CASE("Pre-decrement works.", "[vec::iterator]") {
  auto i= a.end();
  REQUIRE(*--i == 3.0);
  REQUIRE(*i == 3.0);
}


TEST_CASE("Post-decrement works.", "[vec::iterator]") {
  auto i= a.end() - 1;
  REQUIRE(*i-- == 3.0);
  REQUIRE(*i == 2.0);
}


TEST_CASE("Fast foward in place works.", "[vec::iterator]") {
  auto i= a.begin();
  REQUIRE(*(i+= 2) == 3.0);
  REQUIRE(*i == 3.0);
}


TEST_CASE("Fast reverse in place works.", "[vec::iterator]") {
  auto i= a.end() - 1;
  REQUIRE(*(i-= 2) == 1.0);
  REQUIRE(*i == 1.0);
}


TEST_CASE("Fast foward works.", "[vec::iterator]") {
  auto i= a.begin() + 2;
  auto j= 2 + a.begin();
  REQUIRE(*i == 3.0);
  REQUIRE(*j == 3.0);
}


TEST_CASE("Fast reverse works.", "[vec::iterator]") {
  auto i= a.end() - 2;
  REQUIRE(*i == 2.0);
}


TEST_CASE("Difference between iterators works.", "[vec::iterator]") {
  b= a;
  auto ia= a.begin();
  auto ib= b.begin();
  REQUIRE_THROWS(ia - ib);
  auto iae= a.end();
  REQUIRE(iae - ia == a.size());
}


TEST_CASE("Comparison of iterators for equality works.", "[vec::iterator]") {
  auto i= a.begin();
  auto j= a.begin();
  REQUIRE(i == j);
  for(++j; j != a.end(); ++j) { REQUIRE(!(i == j)); }
  auto k= b.begin();
  REQUIRE_THROWS(i == k);
}


TEST_CASE("Comparison of iterators for inequality works.", "[vec::iterator]") {
  auto i= a.begin();
  auto j= a.begin();
  REQUIRE(!(i != j));
  for(++j; j != a.end(); ++j) { REQUIRE(i != j); }
  auto k= b.begin();
  REQUIRE_THROWS(i != k);
}


TEST_CASE("Comparison of iterators for less-than works.", "[vec::iterator]") {
  auto i= a.begin();
  auto j= a.begin() + 1;
  REQUIRE(i < j);
  for(++i; i != a.end(); ++i) { REQUIRE(!(i < j)); }
  auto k= b.begin();
  REQUIRE_THROWS(i < k);
}


TEST_CASE(
      "Comparison of iterators for greater-than works.", "[vec::iterator]") {
  auto i= a.begin() + 1;
  auto j= a.begin();
  REQUIRE(i > j);
  for(++j; j != a.end(); ++j) { REQUIRE(!(i > j)); }
  auto k= b.begin();
  REQUIRE_THROWS(i > k);
}


TEST_CASE(
      "Comparison of iterators for less-than-or-equal-to works.",
      "[vec::iterator]") {
  auto i= a.begin();
  auto j= a.begin() + 1;
  REQUIRE(i++ <= j);
  REQUIRE(i <= j);
  for(++i; i != a.end(); ++i) { REQUIRE(!(i <= j)); }
  auto k= b.begin();
  REQUIRE_THROWS(i <= k);
}


TEST_CASE(
      "Comparison of iterators for greater-than-or-equal-to works.",
      "[vec::iterator]") {
  auto i= a.begin() + 1;
  auto j= a.begin();
  REQUIRE(i >= j++);
  REQUIRE(i >= j);
  for(++j; j != a.end(); ++j) { REQUIRE(!(i >= j)); }
  auto k= b.begin();
  REQUIRE_THROWS(i >= k);
}


// EOF
