/// @file       test/vec-iface-test.cpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Tests for gsl::vec_iface.

#include "gslcpp/static-vector.hpp"
#include "gslcpp/vector-view.hpp"
#include <catch.hpp>
#include <sstream> // ostringstream


using gsl::axpby;
using gsl::static_vector;
using gsl::v_iface;
using gsl::vector_view;
using gsl::w_array_elem;
using std::ostringstream;


using v3= static_vector<3>;
v3 const a({1.0, 2.0, 3.0});


/// Globals for tests.
/// \tparam E  Type of each element in vector.
template<typename E> struct g {
  constexpr static w_array_elem<E> ca[]= {1, 2, 3};
  // 'inline' keyword required to initialize static member in-line.
  static inline static_vector const a= ca;
};


/// Verify that begin() works for v_iface<E>.
/// For non-const type E, this exercises both const and non-const begin().
/// \tparam E  Type of each element in vector.
template<typename E> void verify_begin() {
  auto &a= g<E>::a;
  auto b= a;
  auto ia= a.begin();
  REQUIRE(*ia == 1);
  auto ib= b.begin();
  *ib++= 4;
  *ib++= 5;
  *ib= 6;
  REQUIRE(*b.begin() == 4);
  REQUIRE(*(b.begin() + 1) == 5);
  REQUIRE(*(b.begin() + 2) == 6);
}


TEST_CASE("vec_iface::begin() works.", "[vec-iface]") {
  verify_begin<double>();
  verify_begin<float>();
  verify_begin<long double>();
  verify_begin<int>();
  verify_begin<unsigned>();
  verify_begin<long>();
  verify_begin<unsigned long>();
  verify_begin<short>();
  verify_begin<unsigned short>();
  verify_begin<char>();
  verify_begin<unsigned char>();
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


TEST_CASE("vec_iface::size() works.", "[vec-iface]") {
  REQUIRE(a.size() == 3);
}


TEST_CASE("vec_iface::stride() works.", "[vec-iface]") {
  REQUIRE(a.v().stride == 1);
  static_vector<6> b({1.0, -1.0, 2.0, -2.0, 3.0, -3.0});
  auto c= b.subvector(3, 1, 2);
  REQUIRE(c.v().stride == 2);
}


TEST_CASE("vec_iface::data() works.", "[vec-iface]") {
  REQUIRE(a.data() == &a[0]);
  double b[]= {1.0, -1.0, 2.0, -2.0, 3.0, -3.0};
  vector_view<double> c(b, 3, 1, 2);
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
  static_vector<6> const b({1.0, -1.0, 2.0, -2.0, 3.0, -3.0});
  static_vector<6> c= b;
  vector_view d= b.subvector(3, 1, 2);
  vector_view e= c.subvector(3, 1, 2);
  REQUIRE(d.ptr(1) == b.ptr(3));
  REQUIRE(e.ptr(1) == c.ptr(3));
  REQUIRE(d.ptr(1) == b.v().data + 3);
  REQUIRE(e.ptr(1) == c.v().data + 3);
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
      "vec_iface::set_basis() constructs simple basis-vector.",
      "[vec-iface]") {
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
  static_vector<6> const b({1.0, -1.0, 2.0, -2.0, 3.0, -3.0});
  static_vector<6> c= b;
  auto vb= b.subvector(3, 1, 2);
  auto vc= c.subvector(3, 1, 2);
  REQUIRE(vb[0] == -1.0);
  REQUIRE(vc[0] == -1.0);
  REQUIRE(vb[1] == -2.0);
  REQUIRE(vc[1] == -2.0);
  REQUIRE(vb[2] == -3.0);
  REQUIRE(vc[2] == -3.0);
  vc[0]= -7.0;
  vc[1]= -8.0;
  vc[2]= -9.0;
  REQUIRE(c[1] == -7.0);
  REQUIRE(c[3] == -8.0);
  REQUIRE(c[5] == -9.0);
  auto vvc= vc.subvector(2, 0, 2);
  REQUIRE(vvc[0] == vc[0]);
  REQUIRE(vvc[1] == vc[2]);
  REQUIRE(vvc[0] == c[1]);
  REQUIRE(vvc[1] == c[5]);
}


TEST_CASE("vec_iface::swap_elements() works.", "[vec-iface]") {
  v3 b= a;
  b.swap_elements(0, 1);
  REQUIRE(a[0] == b[1]);
  REQUIRE(a[1] == b[0]);
  REQUIRE(a[2] == b[2]);
}


TEST_CASE("vec_iface::reverse() works.", "[vec-iface]") {
  v3 b= a;
  b.reverse();
  REQUIRE(b[0] == a[2]);
  REQUIRE(b[1] == a[1]);
  REQUIRE(b[2] == a[0]);
}


TEST_CASE("vec_iface's addition in place works.", "[vec-iface]") {
  v3 b;

  b.set_all(1.0);
  b.add(a);
  REQUIRE(b[0] == 2.0);
  REQUIRE(b[1] == 3.0);
  REQUIRE(b[2] == 4.0);

  b.set_all(1.0);
  b+= a;
  REQUIRE(b[0] == 2.0);
  REQUIRE(b[1] == 3.0);
  REQUIRE(b[2] == 4.0);
}


TEST_CASE("vec_iface's subtraction in place works.", "[vec-iface]") {
  v3 b;

  b.set_all(1.0);
  b.sub(a);
  REQUIRE(b[0] == +0.0);
  REQUIRE(b[1] == -1.0);
  REQUIRE(b[2] == -2.0);

  b.set_all(1.0);
  b-= a;
  REQUIRE(b[0] == +0.0);
  REQUIRE(b[1] == -1.0);
  REQUIRE(b[2] == -2.0);
}


TEST_CASE("vec_iface's multiplication in place works.", "[vec-iface]") {
  v3 b;

  b.set_all(1.0);
  b.mul(a);
  REQUIRE(b[0] == 1.0);
  REQUIRE(b[1] == 2.0);
  REQUIRE(b[2] == 3.0);

  b.set_all(1.0);
  b*= a;
  REQUIRE(b[0] == 1.0);
  REQUIRE(b[1] == 2.0);
  REQUIRE(b[2] == 3.0);
}


TEST_CASE("vec_iface's division in place works.", "[vec-iface]") {
  v3 b;

  b.set_all(1.0);
  b.div(a);
  REQUIRE(b[0] == 1.0 / 1.0);
  REQUIRE(b[1] == 1.0 / 2.0);
  REQUIRE(b[2] == 1.0 / 3.0);

  b.set_all(1.0);
  b/= a;
  REQUIRE(b[0] == 1.0 / 1.0);
  REQUIRE(b[1] == 1.0 / 2.0);
  REQUIRE(b[2] == 1.0 / 3.0);
}


TEST_CASE("vec_iface's scaling works.", "[vec-iface]") {
  v3 b= a;
  b.scale(2.0);
  REQUIRE(b[0] == 2.0);
  REQUIRE(b[1] == 4.0);
  REQUIRE(b[2] == 6.0);
  b*= 2.0;
  REQUIRE(b[0] == 4.0);
  REQUIRE(b[1] == 8.0);
  REQUIRE(b[2] == 12.0);
}


TEST_CASE("vec_iface's adding constant works.", "[vec-iface]") {
  v3 b= a;
  b.add_constant(1.0);
  REQUIRE(b[0] == 2.0);
  REQUIRE(b[1] == 3.0);
  REQUIRE(b[2] == 4.0);
  b+= 1.0;
  REQUIRE(b[0] == 3.0);
  REQUIRE(b[1] == 4.0);
  REQUIRE(b[2] == 5.0);
}


TEST_CASE("vec_iface's statistical functions work.", "[vec-iface]") {
  REQUIRE(a.sum() == 6.0);
  REQUIRE(a.max() == 3.0);
  REQUIRE(a.min() == 1.0);

  double min, max;
  a.minmax(min, max);
  REQUIRE(min == 1.0);
  REQUIRE(max == 3.0);

  v3 b= a;
  b.reverse();
  REQUIRE(b.max_index() == 0);
  REQUIRE(b.min_index() == 2);

  size_t imin, imax;
  b.minmax_index(imin, imax);
  REQUIRE(imax == 0);
  REQUIRE(imin == 2);
}


TEST_CASE("vec_iface::isnull() works.", "[vec-iface]") {
  v3 b= a;
  REQUIRE(b.isnull() == false);

  b.set_zero();
  REQUIRE(b.isnull() == true);
}


TEST_CASE("vec_iface::ispos() works.", "[vec-iface]") {
  v3 b= a;
  REQUIRE(b.ispos() == true);

  b.add_constant(-1.0);
  REQUIRE(b.ispos() == false);
}


TEST_CASE("vec_iface::isnonneg() works.", "[vec-iface]") {
  v3 b= a;
  REQUIRE(b.isnonneg() == true);

  b.add_constant(-1.0);
  REQUIRE(b.isnonneg() == true);

  b.add_constant(-0.001);
  REQUIRE(b.isnonneg() == false);
}


TEST_CASE("axpby() accumulates correctly into y.", "[vec]") {
  static_vector<3> const x({1.0, 2.0, 3.0});
  static_vector<3> y({2.0, 3.0, 1.0});
  double const a= 0.5;
  double const b= 1.5;
  axpby(a, x, b, y);
  static_vector<3> const r({3.5, 5.5, 3.0});
  REQUIRE(y == r);
}


TEST_CASE("equal() compares correctly.", "[vec]") {
  static_vector<3> const x({1.0, 2.0, 3.0});
  static_vector<3> const y({2.0, 3.0, 1.0});
  static_vector<3> const z({2.0, 3.0, 1.0});
  REQUIRE(!equal(x, y));
  REQUIRE(x != y);
  REQUIRE(equal(y, z));
  REQUIRE(y == z);
}


TEST_CASE("memcpy() works.", "[vec]") {
  static_vector<3> y({2.0, 3.0, 1.0});
  static_vector<3> const z({1.0, 2.0, 3.0});
  REQUIRE(!equal(y, z));
  memcpy(y, z);
  REQUIRE(equal(y, z));
}


TEST_CASE("swap() works.", "[vec]") {
  static_vector<3> const a({2.0, 3.0, 1.0});
  static_vector<3> const b({1.0, 2.0, 3.0});
  static_vector<3> c= a;
  static_vector<3> d= b;
  REQUIRE(a == c);
  REQUIRE(b == d);
  swap(c, d);
  REQUIRE(a == d);
  REQUIRE(b == c);
}


TEST_CASE("Stream-operator works.", "[vec]") {
  static_vector<3> const a({2.0, 3.0, 1.0});
  ostringstream oss;
  oss << a;
  REQUIRE(oss.str() == "[2,3,1]");
}


TEST_CASE("vec_iface::view() works.", "[vec-iface]") {
  static_vector<3> const a({2.0, 3.0, 1.0});
  auto const b= a.view();
  REQUIRE(a == b);
  REQUIRE(&a[0] == &b[0]);
  REQUIRE(&a[1] == &b[1]);
  REQUIRE(&a[2] == &b[2]);
}


TEST_CASE("vec_iface::sum() works.", "[vec-iface]") {
  static_vector<3> const a({2.0, 3.0, 1.0});
  REQUIRE(a.sum() == 6.0);
}


TEST_CASE("vec_iface::isneg() works.", "[vec-iface]") {
  static_vector<3> const a({-2.0, -3.0, 1.0});
  static_vector<3> const b({-2.0, -3.0, -1.0});
  REQUIRE(a.isneg() == false);
  REQUIRE(b.isneg() == true);
}

// EOF
