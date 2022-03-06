/// @file       test/v-iterator-test.cpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Tests for gsl::v-iterator.

#include "gslcpp/vector.hpp"
#include <catch.hpp>


using gsl::complex;
using gsl::v_iterator;
using gsl::vector;


template<typename E> constexpr E ca[]= {1, 2, 3};
template<typename E> vector const a= ca<E>;
template<typename E> vector<E, 3> b;


template<typename E> void verify_construct_and_dereference() {
  b<E> = a<E>;
  v_iterator i(b<E>, 0);
  v_iterator j(b<E>, 2);
  REQUIRE(*i == b<E>[0]);
  REQUIRE(*j == b<E>[2]);
}


TEST_CASE("Construction and dereference work.", "[v-iterator]") {
  verify_construct_and_dereference<double>();
  verify_construct_and_dereference<float>();
  verify_construct_and_dereference<long double>();
  verify_construct_and_dereference<int>();
  verify_construct_and_dereference<unsigned>();
  verify_construct_and_dereference<long>();
  verify_construct_and_dereference<unsigned long>();
  verify_construct_and_dereference<short>();
  verify_construct_and_dereference<unsigned short>();
  verify_construct_and_dereference<char>();
  verify_construct_and_dereference<unsigned char>();
  verify_construct_and_dereference<complex<double>>();
  verify_construct_and_dereference<complex<float>>();
  verify_construct_and_dereference<complex<long double>>();
}


template<typename E> void verify_relative_dereference() {
  b<E> = a<E>;
  v_iterator ib(b<E>, 1);
  REQUIRE(ib[+0] == E(2));
  REQUIRE(ib[-1] == E(1));
  REQUIRE(ib[+1] == E(3));
  ib[-1]= E(10);
  REQUIRE(ib[-1] == E(10));
  REQUIRE(b<E>[0] == E(10));
}


TEST_CASE("Relative dereference works.", "[v-iterator]") {
  verify_relative_dereference<double>();
  verify_relative_dereference<float>();
  verify_relative_dereference<long double>();
  verify_relative_dereference<int>();
  verify_relative_dereference<unsigned>();
  verify_relative_dereference<long>();
  verify_relative_dereference<unsigned long>();
  verify_relative_dereference<short>();
  verify_relative_dereference<unsigned short>();
  verify_relative_dereference<char>();
  verify_relative_dereference<unsigned char>();
  verify_relative_dereference<complex<double>>();
  verify_relative_dereference<complex<float>>();
  verify_relative_dereference<complex<long double>>();
}


template<typename E> void verify_pre_increment() {
  auto i= a<E>.begin();
  REQUIRE(*++i == E(2));
  REQUIRE(*i == E(2));
}


TEST_CASE("Pre-increment works.", "[v-iterator]") {
  verify_pre_increment<double>();
  verify_pre_increment<float>();
  verify_pre_increment<long double>();
  verify_pre_increment<int>();
  verify_pre_increment<unsigned>();
  verify_pre_increment<long>();
  verify_pre_increment<unsigned long>();
  verify_pre_increment<short>();
  verify_pre_increment<unsigned short>();
  verify_pre_increment<char>();
  verify_pre_increment<unsigned char>();
  verify_pre_increment<complex<double>>();
  verify_pre_increment<complex<float>>();
  verify_pre_increment<complex<long double>>();
}


template<typename E> void verify_post_increment() {
  auto i= a<E>.begin();
  REQUIRE(*i++ == E(1));
  REQUIRE(*i == E(2));
}


TEST_CASE("Post-increment works.", "[v-iterator]") {
  verify_post_increment<double>();
  verify_post_increment<float>();
  verify_post_increment<long double>();
  verify_post_increment<int>();
  verify_post_increment<unsigned>();
  verify_post_increment<long>();
  verify_post_increment<unsigned long>();
  verify_post_increment<short>();
  verify_post_increment<unsigned short>();
  verify_post_increment<char>();
  verify_post_increment<unsigned char>();
  verify_post_increment<complex<double>>();
  verify_post_increment<complex<float>>();
  verify_post_increment<complex<long double>>();
}


template<typename E> void verify_pre_decrement() {
  auto i= a<E>.end();
  REQUIRE(*--i == E(3));
  REQUIRE(*i == E(3));
}


TEST_CASE("Pre-decrement works.", "[v-iterator]") {
  verify_pre_decrement<double>();
  verify_pre_decrement<float>();
  verify_pre_decrement<long double>();
  verify_pre_decrement<int>();
  verify_pre_decrement<unsigned>();
  verify_pre_decrement<long>();
  verify_pre_decrement<unsigned long>();
  verify_pre_decrement<short>();
  verify_pre_decrement<unsigned short>();
  verify_pre_decrement<char>();
  verify_pre_decrement<unsigned char>();
  verify_pre_decrement<complex<double>>();
  verify_pre_decrement<complex<float>>();
  verify_pre_decrement<complex<long double>>();
}


template<typename E> void verify_post_decrement() {
  auto i= a<E>.end() - 1;
  REQUIRE(*i-- == E(3));
  REQUIRE(*i == E(2));
}


TEST_CASE("Post-decrement works.", "[v-iterator]") {
  verify_post_decrement<double>();
  verify_post_decrement<float>();
  verify_post_decrement<long double>();
  verify_post_decrement<int>();
  verify_post_decrement<unsigned>();
  verify_post_decrement<long>();
  verify_post_decrement<unsigned long>();
  verify_post_decrement<short>();
  verify_post_decrement<unsigned short>();
  verify_post_decrement<char>();
  verify_post_decrement<unsigned char>();
  verify_post_decrement<complex<double>>();
  verify_post_decrement<complex<float>>();
  verify_post_decrement<complex<long double>>();
}


TEST_CASE("Fast foward in place works.", "[v-iterator]") {
  auto i= a<double>.begin();
  REQUIRE(*(i+= 2) == 3.0);
  REQUIRE(*i == 3.0);
}


TEST_CASE("Fast reverse in place works.", "[v-iterator]") {
  auto i= a<double>.end() - 1;
  REQUIRE(*(i-= 2) == 1.0);
  REQUIRE(*i == 1.0);
}


TEST_CASE("Fast foward works.", "[v-iterator]") {
  auto i= a<double>.begin() + 2;
  auto j= 2 + a<double>.begin();
  REQUIRE(*i == 3.0);
  REQUIRE(*j == 3.0);
}


TEST_CASE("Fast reverse works.", "[v-iterator]") {
  auto i= a<double>.end() - 2;
  REQUIRE(*i == 2.0);
}


TEST_CASE("Difference between iterators works.", "[v-iterator]") {
  b<double> = a<double>;
  auto ia= a<double>.begin();
  auto ib= b<double>.begin();
  REQUIRE_THROWS(ia - ib);
  auto iae= a<double>.end();
  REQUIRE(iae - ia == a<double>.size());
}


TEST_CASE("Comparison of iterators for equality works.", "[v-iterator]") {
  auto i= a<double>.begin();
  auto j= a<double>.begin();
  REQUIRE(i == j);
  for(++j; j != a<double>.end(); ++j) { REQUIRE(!(i == j)); }
  auto k= b<double>.begin();
  REQUIRE_THROWS(i == k);
}


TEST_CASE("Comparison of iterators for inequality works.", "[v-iterator]") {
  auto i= a<double>.begin();
  auto j= a<double>.begin();
  REQUIRE(!(i != j));
  for(++j; j != a<double>.end(); ++j) { REQUIRE(i != j); }
  auto k= b<double>.begin();
  REQUIRE_THROWS(i != k);
}


TEST_CASE("Comparison of iterators for less-than works.", "[v-iterator]") {
  auto i= a<double>.begin();
  auto j= a<double>.begin() + 1;
  REQUIRE(i < j);
  for(++i; i != a<double>.end(); ++i) { REQUIRE(!(i < j)); }
  auto k= b<double>.begin();
  REQUIRE_THROWS(i < k);
}


TEST_CASE("Comparison of iterators for greater-than works.", "[v-iterator]") {
  auto i= a<double>.begin() + 1;
  auto j= a<double>.begin();
  REQUIRE(i > j);
  for(++j; j != a<double>.end(); ++j) { REQUIRE(!(i > j)); }
  auto k= b<double>.begin();
  REQUIRE_THROWS(i > k);
}


TEST_CASE(
      "Comparison of iterators for less-than-or-equal-to works.",
      "[v-iterator]") {
  auto i= a<double>.begin();
  auto j= a<double>.begin() + 1;
  REQUIRE(i++ <= j);
  REQUIRE(i <= j);
  for(++i; i != a<double>.end(); ++i) { REQUIRE(!(i <= j)); }
  auto k= b<double>.begin();
  REQUIRE_THROWS(i <= k);
}


TEST_CASE(
      "Comparison of iterators for greater-than-or-equal-to works.",
      "[v-iterator]") {
  auto i= a<double>.begin() + 1;
  auto j= a<double>.begin();
  REQUIRE(i >= j++);
  REQUIRE(i >= j);
  for(++j; j != a<double>.end(); ++j) { REQUIRE(!(i >= j)); }
  auto k= b<double>.begin();
  REQUIRE_THROWS(i >= k);
}


TEST_CASE(
      "Comparison to iterator of different vector throws.", "[v-iterator]") {
  REQUIRE_THROWS(a<double>.begin() == b<double>.begin());
}


// EOF
