/// @file       gsl/vector-test.cpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Tests for gsl::vector.

#include "gslcpp/vector.hpp"
#include <catch.hpp>

using gsl::vector;
using gsl::vectorcv;
using gsl::vectord;
using gsl::vectorv;


template<int S> void set_get(vector<S> &v) {
  v.set_all(0.0);
  for(size_t i= 0; i < v.size(); ++i) { REQUIRE(v.get(i) == 0.0); }

  for(size_t i= 0; i < v.size(); ++i) { v.set(i, 1.23 + i); }
  for(size_t i= 0; i < v.size(); ++i) { REQUIRE(v.get(i) == 1.23 + i); }

  for(size_t i= 0; i < v.size(); ++i) { v[i]= 2.46 + i; }
  for(size_t i= 0; i < v.size(); ++i) { REQUIRE(v[i] == 2.46 + i); }
}


TEST_CASE("gsl::vector works properly.", "[vector]") {
  double a[]= {1.1, 1.2, 1.4, 1.8};

  vector v0(a); // Template-value parameter (number of elements) deduced!
  REQUIRE(v0.size() == 4);
  REQUIRE(v0[0] == 1.1);
  REQUIRE(v0[1] == 1.2);
  REQUIRE(v0[2] == 1.4);
  REQUIRE(v0[3] == 1.8);

  vector<3> v1;
  set_get(v1);

  vectord v2(10);
  set_get(v2);

  vectorv v3= v2.subvector(4, 1, 2);
  REQUIRE(v3.size() == 4);
  REQUIRE(v3[0] == 2.46 + 1);
  REQUIRE(v3[1] == 2.46 + 3);
  REQUIRE(v3[2] == 2.46 + 5);
  REQUIRE(v3[3] == 2.46 + 7);
  set_get(v3);

  vectorcv v4= v3.subvector(v3.size());
  REQUIRE(v4.size() == v3.size());
  REQUIRE(v4[0] == 2.46 + 0);
  REQUIRE(v4[1] == 2.46 + 1);
  REQUIRE(v4[2] == 2.46 + 2);
  REQUIRE(v4[3] == 2.46 + 3);
}

// EOF
