/// @file       test/vec-iface-test.cpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Tests for gsl::vec_iface.

#include "gslcpp/vector.hpp"
#include <catch.hpp>


using gsl::vec_iface;
using gsl::vector;
using gsl::vectorcv;
using gsl::vectorv;


using v3= vector<3>;


v3 const a({1.0, 2.0, 3.0});


TEST_CASE("vec_iface::begin() works.", "[vec-iface]") {
  v3 b= a;
  auto ia= a.begin();
  REQUIRE(*ia == 1.0);
  auto ib= b.begin();
  *ib++= -1.0;
  *ib++= -2.0;
  *ib= -3.0;
  REQUIRE(*b.begin() == -1.0);
}


TEST_CASE("vec_iface::end() works.", "[vec-iface]") {
  v3 b= a;
  auto ia= a.end() - 1;
  REQUIRE(*ia == 3.0);
  for(auto ib= b.begin(); ib != b.end(); ++ib) { *ib= a[ib - b.begin()]; }
  REQUIRE(a[0] == b[0]);
  REQUIRE(a[1] == b[1]);
  REQUIRE(a[2] == b[2]);
  REQUIRE(a.end() - a.begin() == b.size());
  REQUIRE(b.end() - b.begin() == b.size());
}


TEST_CASE("vec_iface::vec() works.", "[vec-iface]") {
  REQUIRE(gsl_vector_get(&a.vec(), 0) == 1.0);
  v3 b= a;
  gsl_vector_set(&b.vec(), 0, -1.0);
  REQUIRE(gsl_vector_get(&b.vec(), 0) == -1.0);
}


TEST_CASE("vec_iface::size() works.", "[vec-iface]") {
  REQUIRE(a.size() == 3);
}


TEST_CASE("vec_iface::stride() works.", "[vec-iface]") {
  REQUIRE(a.stride() == 1);
  vector<6> b({1.0, -1.0, 2.0, -2.0, 3.0, -3.0});
  auto c= b.subvector(3, 1, 2);
  REQUIRE(c.stride() == 2);
}


TEST_CASE("vec_iface::data() works.", "[vec-iface]") {
  REQUIRE(a.data() == &a[0]);
  double b[]= {1.0, -1.0, 2.0, -2.0, 3.0, -3.0};
  vectorv c(b, 3, 1, 2);
  REQUIRE(c.data() == b + 1);
}


TEST_CASE("vec_iface's getters work.", "[vec-iface]") {
  REQUIRE(a.get(1) == 2.0);
  REQUIRE(a[0] == 1.0);
}


TEST_CASE("vec_iface's setters work.", "[vec-iface]") {
  v3 b= a;
  b[0]= -1.0;
  b.set(1, -2.0);
  REQUIRE(b[0] == -1.0);
  REQUIRE(b[1] == -2.0);
}


TEST_CASE("vec_iface::ptr() retrieves pointer of element.", "[vec-iface]") {
  vector<6> const b({1.0, -1.0, 2.0, -2.0, 3.0, -3.0});
  vector<6> c= b;
  vectorcv d(b, 3, 1, 2);
  vectorv e(c, 3, 1, 2);
  REQUIRE(d.ptr(1) == b.ptr(3));
  REQUIRE(e.ptr(1) == c.ptr(3));
  REQUIRE(d.ptr(1) == b.vec().data + 3);
  REQUIRE(e.ptr(1) == c.vec().data + 3);
  *e.ptr(1)= 9.0;
  REQUIRE(c[3] == 9.0);
}


TEST_CASE(
  "vec_iface::set_all() and vec_iface::set_zero() work.", "[vec-iface]") {
  v3 b;
  b.set_all(3.1);
  REQUIRE(b[0] == 3.1);
  REQUIRE(b[1] == 3.1);
  REQUIRE(b[2] == 3.1);
  b.set_zero();
  REQUIRE(b[0] == 0.0);
  REQUIRE(b[1] == 0.0);
  REQUIRE(b[2] == 0.0);
}


TEST_CASE(
  "vec_iface::set_basis() constructs simple basis-vector.", "[vec-iface]") {
  v3 b;
  for(unsigned i= 0; i < b.size(); ++i) {
    b.set_basis(i);
    for(unsigned j= 0; j < b.size(); ++j) {
      if(i == j) {
        REQUIRE(b[j] == Approx(1.0));
      } else {
        REQUIRE(b[j] == Approx(0.0));
      }
    }
  }
}


TEST_CASE("vec_iface::fwrite() and vec_iface::fread() work.", "[vec-iface]") {
  FILE *f= fopen("io-test.dat", "wb");
  a.fwrite(f);
  fclose(f);

  v3 b;
  b.set_zero();

  f= fopen("io-test.dat", "rb");
  b.fread(f);
  fclose(f);

  REQUIRE(a == b);
}


TEST_CASE(
  "vec_iface::fprintf() and vec_iface::fscanf() work.", "[vec-iface]") {
  FILE *f= fopen("output-test.txt", "w");
  a.fprintf(f, "%g");
  fclose(f);

  v3 b;
  b.set_zero();

  f= fopen("output-test.txt", "r");
  b.fscanf(f);
  fclose(f);

  REQUIRE(a == b);
}


TEST_CASE("vec_iface::subvector() works.", "[vec-iface]") {
  vector<6> const b({1.0, -1.0, 2.0, -2.0, 3.0, -3.0});
  vector<6> c= b;
  auto vb= b.subvector(3, 1, 2);
  auto vc= c.subvector(3, 1, 2);
  REQUIRE(vb[0] == -1.0);
  REQUIRE(vc[0] == -1.0);
  REQUIRE(vb[1] == -2.0);
  REQUIRE(vc[1] == -2.0);
  REQUIRE(vb[2] == -3.0);
  REQUIRE(vc[2] == -3.0);
  vc[0] = -7.0;
  vc[1] = -8.0;
  vc[2] = -9.0;
  REQUIRE(c[1] == -7.0);
  REQUIRE(c[3] == -8.0);
  REQUIRE(c[5] == -9.0);
  auto vvc= vc.subvector(2, 0, 2);
  REQUIRE(vvc[0] == vc[0]);
  REQUIRE(vvc[1] == vc[2]);
  REQUIRE(vvc[0] == c[1]);
  REQUIRE(vvc[1] == c[5]);
}


// EOF
