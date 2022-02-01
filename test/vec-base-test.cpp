/// @file       gsl/vec-base-test.cpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Tests for gsl::vec_base.

#include "gslcpp/vector.hpp"
#include <catch.hpp>

using gsl::memcpy;
using gsl::vec_base;
using gsl::vec_iface;


/// See that C-array matches gsl::vec_iface with stride.
/// @tparam T  Type of descendant of vec_iface<T>.
/// @param a  C-array.
/// @param b  Reference to instance of vec_iface<T>.
/// @param s  Stride.
template<typename T>
void check(double const *a, vec_iface<T> const &b, size_t s= 1) {
  for(size_t j= 0, i= 0; j < b.size(); ++j) {
    REQUIRE(a[i] == b[j]);
    i+= s; // Explicitly step with stride through memory.
  }
}


TEST_CASE("vec_base works properly.", "[vec_base]") {
  double a[]= {1, 1, 2, 3, 5, 8};
  double const *b= a;

  auto pv= vec_base::view_array(b, 3, 2);
  REQUIRE(pv.size() == 3);
  check(a, pv, 2);

  auto av= vec_base::subarray(a, 3, 0, 2);
  REQUIRE(av.size() == 3);
  check(a, av, 2);

  REQUIRE(pv == av);

  auto av2= vec_base::subarray(a);
  REQUIRE(av2.size() == 6);
  check(a, av2);

  auto mv1= av2.subvector(3, 0, 2);
  REQUIRE(mv1.size() == 3);
  check(a, mv1, 2);

  REQUIRE(pv == mv1);

  auto const &av3= av2;
  auto mv2= av3.subvector(av3.size());
  REQUIRE(mv2.size() == av3.size());
  REQUIRE(mv2 == av3);

  double c[]= {9, 8, 7, 6, 5, 4};
  memcpy(av2, vec_base::subarray(c));
  REQUIRE(vec_base::subarray(a) == vec_base::subarray(c));
}


// EOF
