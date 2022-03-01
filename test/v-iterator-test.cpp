/// @file       test/v-iterator-test.cpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Tests for gsl::v-iterator.

#include "gslcpp/static-vector.hpp"
#include <catch.hpp>


using gsl::static_vector;
using gsl::v_iterator;


using v3= static_vector<3>;


v3 const a({1.0, 2.0, 3.0});
v3 b;


TEST_CASE("Construction and dereference work.", "[v-iterator]") {
  b= v3({-1.0, -2.0, -3.0});

  v_iterator<v3 const> ia(a, 0);
  REQUIRE(*ia == a[0]);

  v_iterator<v3> ib(b, 2);
  REQUIRE(*ib == b[2]);
}


TEST_CASE("Relative dereference works.", "[v-iterator]") {
  b= a;
  v_iterator<v3> ib(b, 1);
  REQUIRE(ib[+0] == 2.0);
  REQUIRE(ib[-1] == 1.0);
  REQUIRE(ib[+1] == 3.0);
  ib[-1]= -10.0;
  REQUIRE(ib[-1] == -10.0);
  REQUIRE(b[0] == -10.0);
}


TEST_CASE("Pre-increment works.", "[v-iterator]") {
  auto i= a.begin();
  REQUIRE(*++i == 2.0);
  REQUIRE(*i == 2.0);
}


TEST_CASE("Post-increment works.", "[v-iterator]") {
  auto i= a.begin();
  REQUIRE(*i++ == 1.0);
  REQUIRE(*i == 2.0);
}


TEST_CASE("Pre-decrement works.", "[v-iterator]") {
  auto i= a.end();
  REQUIRE(*--i == 3.0);
  REQUIRE(*i == 3.0);
}


TEST_CASE("Post-decrement works.", "[v-iterator]") {
  auto i= a.end() - 1;
  REQUIRE(*i-- == 3.0);
  REQUIRE(*i == 2.0);
}


TEST_CASE("Fast foward in place works.", "[v-iterator]") {
  auto i= a.begin();
  REQUIRE(*(i+= 2) == 3.0);
  REQUIRE(*i == 3.0);
}


TEST_CASE("Fast reverse in place works.", "[v-iterator]") {
  auto i= a.end() - 1;
  REQUIRE(*(i-= 2) == 1.0);
  REQUIRE(*i == 1.0);
}


TEST_CASE("Fast foward works.", "[v-iterator]") {
  auto i= a.begin() + 2;
  auto j= 2 + a.begin();
  REQUIRE(*i == 3.0);
  REQUIRE(*j == 3.0);
}


TEST_CASE("Fast reverse works.", "[v-iterator]") {
  auto i= a.end() - 2;
  REQUIRE(*i == 2.0);
}


TEST_CASE("Difference between iterators works.", "[v-iterator]") {
  b= a;
  auto ia= a.begin();
  auto ib= b.begin();
  REQUIRE_THROWS(ia - ib);
  auto iae= a.end();
  REQUIRE(iae - ia == a.size());
}


TEST_CASE("Comparison of iterators for equality works.", "[v-iterator]") {
  auto i= a.begin();
  auto j= a.begin();
  REQUIRE(i == j);
  for(++j; j != a.end(); ++j) { REQUIRE(!(i == j)); }
  auto k= b.begin();
  REQUIRE_THROWS(i == k);
}


TEST_CASE("Comparison of iterators for inequality works.", "[v-iterator]") {
  auto i= a.begin();
  auto j= a.begin();
  REQUIRE(!(i != j));
  for(++j; j != a.end(); ++j) { REQUIRE(i != j); }
  auto k= b.begin();
  REQUIRE_THROWS(i != k);
}


TEST_CASE("Comparison of iterators for less-than works.", "[v-iterator]") {
  auto i= a.begin();
  auto j= a.begin() + 1;
  REQUIRE(i < j);
  for(++i; i != a.end(); ++i) { REQUIRE(!(i < j)); }
  auto k= b.begin();
  REQUIRE_THROWS(i < k);
}


TEST_CASE(
      "Comparison of iterators for greater-than works.", "[v-iterator]") {
  auto i= a.begin() + 1;
  auto j= a.begin();
  REQUIRE(i > j);
  for(++j; j != a.end(); ++j) { REQUIRE(!(i > j)); }
  auto k= b.begin();
  REQUIRE_THROWS(i > k);
}


TEST_CASE(
      "Comparison of iterators for less-than-or-equal-to works.",
      "[v-iterator]") {
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
      "[v-iterator]") {
  auto i= a.begin() + 1;
  auto j= a.begin();
  REQUIRE(i >= j++);
  REQUIRE(i >= j);
  for(++j; j != a.end(); ++j) { REQUIRE(!(i >= j)); }
  auto k= b.begin();
  REQUIRE_THROWS(i >= k);
}


TEST_CASE(
      "Comparison to iterator of different vector throws.", "[v-iterator]") {
  REQUIRE_THROWS(a.begin() == b.begin());
}


// EOF
