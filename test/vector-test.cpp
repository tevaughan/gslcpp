/// @file       test/vector-test.cpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Tests for gsl::vector.

#include "gslcpp/vector-view.hpp"
#include "gslcpp/vector.hpp"
#include <catch.hpp>

using gsl::complex;
using gsl::v_iface;
using gsl::vector;
using gsl::vector_view;


template<typename E> void verify_static_default_constructor() {
  vector<E, 3> v;
  REQUIRE(v.size() == 3);
}


TEST_CASE("Static vector's default constructor works.", "[vector]") {
  verify_static_default_constructor<double>();
  verify_static_default_constructor<float>();
  verify_static_default_constructor<long double>();
  verify_static_default_constructor<int>();
  verify_static_default_constructor<unsigned>();
  verify_static_default_constructor<long>();
  verify_static_default_constructor<unsigned long>();
  verify_static_default_constructor<short>();
  verify_static_default_constructor<unsigned short>();
  verify_static_default_constructor<char>();
  verify_static_default_constructor<unsigned char>();
  verify_static_default_constructor<complex<double>>();
  verify_static_default_constructor<complex<float>>();
  verify_static_default_constructor<complex<long double>>();
}


template<typename E> void verify_dynamic_base_constructor() {
  vector<E> v(15);
  REQUIRE(v.size() == 15);

  vector<E> w(15, vector<E>::CALLOC);
  v.set_zero();
  REQUIRE(v == w);
}


TEST_CASE("Dynamic vector's base-constructor works.", "[vector]") {
  verify_dynamic_base_constructor<double>();
  verify_dynamic_base_constructor<float>();
  verify_dynamic_base_constructor<long double>();
  verify_dynamic_base_constructor<int>();
  verify_dynamic_base_constructor<unsigned>();
  verify_dynamic_base_constructor<long>();
  verify_dynamic_base_constructor<unsigned long>();
  verify_dynamic_base_constructor<short>();
  verify_dynamic_base_constructor<unsigned short>();
  verify_dynamic_base_constructor<char>();
  verify_dynamic_base_constructor<unsigned char>();
  verify_dynamic_base_constructor<complex<double>>();
  verify_dynamic_base_constructor<complex<float>>();
  verify_dynamic_base_constructor<complex<long double>>();
}


template<typename E> void verify_dynamic_movement() {
  vector<E> q(15, vector<E>::CALLOC);
  vector<E> r(15);
  for(int i=0; i < 15; ++i) r[i]= E(15 - i);
  vector<E> s= std::move(r); // Move-construction.
  REQUIRE(r.valid()==false); // Because s was invalid.
  for(int i=0; i< 15; ++i) REQUIRE(s[i] == E(15 - i));
  q= std::move(s); // Move-assignment.
  REQUIRE(s.valid()==true); // Because q was valid.
  for(int i= 0; i < 15; ++i) {
    REQUIRE(q[i] == E(15 - i));
    REQUIRE(s[i] == E(0));
  }
}


TEST_CASE("Dynamic vector's move-constructor works.", "[vector]") {
  verify_dynamic_movement<double>();
  verify_dynamic_movement<float>();
  verify_dynamic_movement<long double>();
  verify_dynamic_movement<int>();
  verify_dynamic_movement<unsigned>();
  verify_dynamic_movement<long>();
  verify_dynamic_movement<unsigned long>();
  verify_dynamic_movement<short>();
  verify_dynamic_movement<unsigned short>();
  verify_dynamic_movement<char>();
  verify_dynamic_movement<unsigned char>();
  verify_dynamic_movement<complex<double>>();
  verify_dynamic_movement<complex<float>>();
  verify_dynamic_movement<complex<long double>>();
}


template<typename E> void verify_static_base_constructor() {
  REQUIRE_THROWS((vector<E, 3>(4)));
}


TEST_CASE("Static vector's base-constructor works.", "[vector]") {
  verify_static_base_constructor<double>();
  verify_static_base_constructor<float>();
  verify_static_base_constructor<long double>();
  verify_static_base_constructor<int>();
  verify_static_base_constructor<unsigned>();
  verify_static_base_constructor<long>();
  verify_static_base_constructor<unsigned long>();
  verify_static_base_constructor<short>();
  verify_static_base_constructor<unsigned short>();
  verify_static_base_constructor<char>();
  verify_static_base_constructor<unsigned char>();
  verify_static_base_constructor<complex<double>>();
  verify_static_base_constructor<complex<float>>();
  verify_static_base_constructor<complex<long double>>();
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

  auto view= v.view();
  vector x= view; // Copy from other kind of vector.
  REQUIRE(x == v);
}


TEST_CASE("Static vector's copy-assignment works.", "[vector]") {
  vector v({1.0, 2.0, 3.0});
  vector<double, 3> w;
  w= v; // Assign.
}


// EOF
