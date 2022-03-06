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


template<typename E> void verify_fast_forward_in_place() {
  auto i= a<E>.begin();
  REQUIRE(*(i+= 2) == E(3));
  REQUIRE(*i == E(3));
}


TEST_CASE("Fast foward in place works.", "[v-iterator]") {
  verify_fast_forward_in_place<double>();
  verify_fast_forward_in_place<float>();
  verify_fast_forward_in_place<long double>();
  verify_fast_forward_in_place<int>();
  verify_fast_forward_in_place<unsigned>();
  verify_fast_forward_in_place<long>();
  verify_fast_forward_in_place<unsigned long>();
  verify_fast_forward_in_place<short>();
  verify_fast_forward_in_place<unsigned short>();
  verify_fast_forward_in_place<char>();
  verify_fast_forward_in_place<unsigned char>();
  verify_fast_forward_in_place<complex<double>>();
  verify_fast_forward_in_place<complex<float>>();
  verify_fast_forward_in_place<complex<long double>>();
}


template<typename E> void verify_fast_reverse_in_place() {
  auto i= a<E>.end() - 1;
  REQUIRE(*(i-= 2) == E(1));
  REQUIRE(*i == E(1));
}


TEST_CASE("Fast reverse in place works.", "[v-iterator]") {
  verify_fast_reverse_in_place<double>();
  verify_fast_reverse_in_place<float>();
  verify_fast_reverse_in_place<long double>();
  verify_fast_reverse_in_place<int>();
  verify_fast_reverse_in_place<unsigned>();
  verify_fast_reverse_in_place<long>();
  verify_fast_reverse_in_place<unsigned long>();
  verify_fast_reverse_in_place<short>();
  verify_fast_reverse_in_place<unsigned short>();
  verify_fast_reverse_in_place<char>();
  verify_fast_reverse_in_place<unsigned char>();
  verify_fast_reverse_in_place<complex<double>>();
  verify_fast_reverse_in_place<complex<float>>();
  verify_fast_reverse_in_place<complex<long double>>();
}


template<typename E> void verify_fast_forward() {
  auto i= a<E>.begin() + 2;
  auto j= 2 + a<E>.begin();
  REQUIRE(*i == E(3));
  REQUIRE(*j == E(3));
}


TEST_CASE("Fast foward works.", "[v-iterator]") {
  verify_fast_forward<double>();
  verify_fast_forward<float>();
  verify_fast_forward<long double>();
  verify_fast_forward<int>();
  verify_fast_forward<unsigned>();
  verify_fast_forward<long>();
  verify_fast_forward<unsigned long>();
  verify_fast_forward<short>();
  verify_fast_forward<unsigned short>();
  verify_fast_forward<char>();
  verify_fast_forward<unsigned char>();
  verify_fast_forward<complex<double>>();
  verify_fast_forward<complex<float>>();
  verify_fast_forward<complex<long double>>();
}


template<typename E> void verify_fast_reverse() {
  auto i= a<E>.end() - 2;
  REQUIRE(*i == E(2));
}


TEST_CASE("Fast reverse works.", "[v-iterator]") {
  verify_fast_reverse<double>();
  verify_fast_reverse<float>();
  verify_fast_reverse<long double>();
  verify_fast_reverse<int>();
  verify_fast_reverse<unsigned>();
  verify_fast_reverse<long>();
  verify_fast_reverse<unsigned long>();
  verify_fast_reverse<short>();
  verify_fast_reverse<unsigned short>();
  verify_fast_reverse<char>();
  verify_fast_reverse<unsigned char>();
  verify_fast_reverse<complex<double>>();
  verify_fast_reverse<complex<float>>();
  verify_fast_reverse<complex<long double>>();
}


template<typename E> void verify_difference_of_iterators() {
  b<E> = a<E>;
  auto ia= a<E>.begin();
  auto ib= b<E>.begin();
  REQUIRE_THROWS(ia - ib);
  auto iae= a<E>.end();
  REQUIRE(iae - ia == a<E>.size());
}


TEST_CASE("Difference between iterators works.", "[v-iterator]") {
  verify_difference_of_iterators<double>();
  verify_difference_of_iterators<float>();
  verify_difference_of_iterators<long double>();
  verify_difference_of_iterators<int>();
  verify_difference_of_iterators<unsigned>();
  verify_difference_of_iterators<long>();
  verify_difference_of_iterators<unsigned long>();
  verify_difference_of_iterators<short>();
  verify_difference_of_iterators<unsigned short>();
  verify_difference_of_iterators<char>();
  verify_difference_of_iterators<unsigned char>();
  verify_difference_of_iterators<complex<double>>();
  verify_difference_of_iterators<complex<float>>();
  verify_difference_of_iterators<complex<long double>>();
}


template<typename E> void verify_equality_comparison() {
  auto i= a<E>.begin();
  auto j= a<E>.begin();
  REQUIRE(i == j);
  for(++j; j != a<E>.end(); ++j) { REQUIRE(!(i == j)); }
  auto k= b<E>.begin();
  REQUIRE_THROWS(i == k);
}


TEST_CASE("Comparison of iterators for equality works.", "[v-iterator]") {
  verify_equality_comparison<double>();
  verify_equality_comparison<float>();
  verify_equality_comparison<long double>();
  verify_equality_comparison<int>();
  verify_equality_comparison<unsigned>();
  verify_equality_comparison<long>();
  verify_equality_comparison<unsigned long>();
  verify_equality_comparison<short>();
  verify_equality_comparison<unsigned short>();
  verify_equality_comparison<char>();
  verify_equality_comparison<unsigned char>();
  verify_equality_comparison<complex<double>>();
  verify_equality_comparison<complex<float>>();
  verify_equality_comparison<complex<long double>>();
}


template<typename E> void verify_inequality_comparison() {
  auto i= a<E>.begin();
  auto j= a<E>.begin();
  REQUIRE(!(i != j));
  for(++j; j != a<E>.end(); ++j) { REQUIRE(i != j); }
  auto k= b<E>.begin();
  REQUIRE_THROWS(i != k);
}


TEST_CASE("Comparison of iterators for inequality works.", "[v-iterator]") {
  verify_inequality_comparison<double>();
  verify_inequality_comparison<float>();
  verify_inequality_comparison<long double>();
  verify_inequality_comparison<int>();
  verify_inequality_comparison<unsigned>();
  verify_inequality_comparison<long>();
  verify_inequality_comparison<unsigned long>();
  verify_inequality_comparison<short>();
  verify_inequality_comparison<unsigned short>();
  verify_inequality_comparison<char>();
  verify_inequality_comparison<unsigned char>();
  verify_inequality_comparison<complex<double>>();
  verify_inequality_comparison<complex<float>>();
  verify_inequality_comparison<complex<long double>>();
}


template<typename E> void verify_less_than_comparison() {
  auto i= a<E>.begin();
  auto j= a<E>.begin() + 1;
  REQUIRE(i < j);
  for(++i; i != a<E>.end(); ++i) { REQUIRE(!(i < j)); }
  auto k= b<E>.begin();
  REQUIRE_THROWS(i < k);
}


TEST_CASE("Comparison of iterators for less-than works.", "[v-iterator]") {
  verify_less_than_comparison<double>();
  verify_less_than_comparison<float>();
  verify_less_than_comparison<long double>();
  verify_less_than_comparison<int>();
  verify_less_than_comparison<unsigned>();
  verify_less_than_comparison<long>();
  verify_less_than_comparison<unsigned long>();
  verify_less_than_comparison<short>();
  verify_less_than_comparison<unsigned short>();
  verify_less_than_comparison<char>();
  verify_less_than_comparison<unsigned char>();
  verify_less_than_comparison<complex<double>>();
  verify_less_than_comparison<complex<float>>();
  verify_less_than_comparison<complex<long double>>();
}


template<typename E> void verify_greater_than_comparison() {
  auto i= a<E>.begin() + 1;
  auto j= a<E>.begin();
  REQUIRE(i > j);
  for(++j; j != a<E>.end(); ++j) { REQUIRE(!(i > j)); }
  auto k= b<E>.begin();
  REQUIRE_THROWS(i > k);
}


TEST_CASE("Comparison of iterators for greater-than works.", "[v-iterator]") {
  verify_greater_than_comparison<double>();
  verify_greater_than_comparison<float>();
  verify_greater_than_comparison<long double>();
  verify_greater_than_comparison<int>();
  verify_greater_than_comparison<unsigned>();
  verify_greater_than_comparison<long>();
  verify_greater_than_comparison<unsigned long>();
  verify_greater_than_comparison<short>();
  verify_greater_than_comparison<unsigned short>();
  verify_greater_than_comparison<char>();
  verify_greater_than_comparison<unsigned char>();
  verify_greater_than_comparison<complex<double>>();
  verify_greater_than_comparison<complex<float>>();
  verify_greater_than_comparison<complex<long double>>();
}


template<typename E> void verify_lthoet_comparison() {
  auto i= a<E>.begin();
  auto j= a<E>.begin() + 1;
  REQUIRE(i++ <= j);
  REQUIRE(i <= j);
  for(++i; i != a<E>.end(); ++i) { REQUIRE(!(i <= j)); }
  auto k= b<E>.begin();
  REQUIRE_THROWS(i <= k);
}


TEST_CASE("Comp of iters for less-than-or-equal-to works.", "[v-iterator]") {
  verify_lthoet_comparison<double>();
  verify_lthoet_comparison<float>();
  verify_lthoet_comparison<long double>();
  verify_lthoet_comparison<int>();
  verify_lthoet_comparison<unsigned>();
  verify_lthoet_comparison<long>();
  verify_lthoet_comparison<unsigned long>();
  verify_lthoet_comparison<short>();
  verify_lthoet_comparison<unsigned short>();
  verify_lthoet_comparison<char>();
  verify_lthoet_comparison<unsigned char>();
  verify_lthoet_comparison<complex<double>>();
  verify_lthoet_comparison<complex<float>>();
  verify_lthoet_comparison<complex<long double>>();
}


template<typename E> void verify_gthoet_comparison() {
  auto i= a<E>.begin() + 1;
  auto j= a<E>.begin();
  REQUIRE(i >= j++);
  REQUIRE(i >= j);
  for(++j; j != a<E>.end(); ++j) { REQUIRE(!(i >= j)); }
  auto k= b<E>.begin();
  REQUIRE_THROWS(i >= k);
}


TEST_CASE("Comp of iters for grtr-than-or-equal-to works.", "[v-iterator]") {
  verify_gthoet_comparison<double>();
  verify_gthoet_comparison<float>();
  verify_gthoet_comparison<long double>();
  verify_gthoet_comparison<int>();
  verify_gthoet_comparison<unsigned>();
  verify_gthoet_comparison<long>();
  verify_gthoet_comparison<unsigned long>();
  verify_gthoet_comparison<short>();
  verify_gthoet_comparison<unsigned short>();
  verify_gthoet_comparison<char>();
  verify_gthoet_comparison<unsigned char>();
  verify_gthoet_comparison<complex<double>>();
  verify_gthoet_comparison<complex<float>>();
  verify_gthoet_comparison<complex<long double>>();
}


template<typename E> void verify_eq_other_comparison() {
  REQUIRE_THROWS(a<E>.begin() == b<E>.begin());
  REQUIRE_THROWS(b<E>.begin() == a<E>.begin());
}


TEST_CASE("Comp to iterator of different vector throws.", "[v-iterator]") {
  verify_eq_other_comparison<double>();
  verify_eq_other_comparison<float>();
  verify_eq_other_comparison<long double>();
  verify_eq_other_comparison<int>();
  verify_eq_other_comparison<unsigned>();
  verify_eq_other_comparison<long>();
  verify_eq_other_comparison<unsigned long>();
  verify_eq_other_comparison<short>();
  verify_eq_other_comparison<unsigned short>();
  verify_eq_other_comparison<char>();
  verify_eq_other_comparison<unsigned char>();
  verify_eq_other_comparison<complex<double>>();
  verify_eq_other_comparison<complex<float>>();
  verify_eq_other_comparison<complex<long double>>();
}


// EOF
