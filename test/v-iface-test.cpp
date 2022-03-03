/// @file       test/v-iface-test.cpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Tests for gsl::vec_iface.

#include "gslcpp/static-vector.hpp"
#include "gslcpp/vector-view.hpp"
#include <catch.hpp>
#include <sstream> // ostringstream


using gsl::axpby;
using gsl::complex;
using gsl::static_vector;
using gsl::v_iface;
using gsl::vector_view;
using std::ostringstream;


using v3= static_vector<3>;
v3 const a({1.0, 2.0, 3.0});


/// Globals for tests.
/// \tparam E  Type of each element in vector.
template<typename E> struct g {
  /// Global C-array with three elements.
  constexpr static E ca[]= {1, 2, 3};

  /// Global test-vector constructed from `ca`.
  /// 'inline' keyword required to initialize static member in-line.
  static inline static_vector const a= ca;
};


/// Verify that begin() works for v_iface<E>.
/// For non-const type E, this exercises both const and non-const begin().
/// \tparam E  Type of each element in vector.
template<typename E> void verify_begin() {
  auto &a= g<E>::a;
  auto b= a;
  auto ia= a.begin();
  REQUIRE(*ia == E(1));
  auto ib= b.begin();
  *ib++= 4;
  *ib++= 5;
  *ib= 6;
  REQUIRE(*b.begin() == E(4));
  REQUIRE(*(b.begin() + 1) == E(5));
  REQUIRE(*(b.begin() + 2) == E(6));
}


/// Verify that begin() works for each kind of v_iface.
TEST_CASE("vec_iface::begin() works.", "[v-iface]") {
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
  verify_begin<complex<double>>();
  verify_begin<complex<float>>();
  verify_begin<complex<long double>>();
}


/// Verify that end() works for v_iface<E>.
/// For non-const type E, this exercises both const and non-const end().
/// \tparam E  Type of each element in vector.
template<typename E> void verify_end() {
  auto &a= g<E>::a;
  auto b= a;
  auto ia= a.end() - 1;
  REQUIRE(*ia == E(3));
  for(auto ib= b.begin(); ib != b.end(); ++ib) { *ib= a[ib - b.begin()]; }
  REQUIRE(a[0] == b[0]);
  REQUIRE(a[1] == b[1]);
  REQUIRE(a[2] == b[2]);
  REQUIRE(a.end() - a.begin() == b.size());
  REQUIRE(b.end() - b.begin() == b.size());
}


/// Verify that end() works fo each kind of v_iface.
TEST_CASE("vec_iface::end() works.", "[v-iface]") {
  verify_end<double>();
  verify_end<float>();
  verify_end<long double>();
  verify_end<int>();
  verify_end<unsigned>();
  verify_end<long>();
  verify_end<unsigned long>();
  verify_end<short>();
  verify_end<unsigned short>();
  verify_end<char>();
  verify_end<unsigned char>();
  verify_end<complex<double>>();
  verify_end<complex<float>>();
  verify_end<complex<long double>>();
}


/// Verify that size() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_size() { REQUIRE(g<E>::a.size() == 3); }


/// Verify that size() works for each kind of v_iface.
TEST_CASE("vec_iface::size() works.", "[v-iface]") {
  verify_size<double>();
  verify_size<float>();
  verify_size<long double>();
  verify_size<int>();
  verify_size<unsigned>();
  verify_size<long>();
  verify_size<unsigned long>();
  verify_size<short>();
  verify_size<unsigned short>();
  verify_size<char>();
  verify_size<unsigned char>();
  verify_size<complex<double>>();
  verify_size<complex<float>>();
  verify_size<complex<long double>>();
}


/// Verify that data() points to right place for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_data() {
  REQUIRE(g<E>::a.data() == &g<E>::a[0]);
  E b[]= {1, 2, 3, 4, 5, 6};
  vector_view c(b, 3, 1, 2);
  REQUIRE(c.data() == b + 1);
}


/// Verify that data() points to right place for each kind of v_iface.
TEST_CASE("vec_iface::data() works.", "[v-iface]") {
  verify_data<double>();
  verify_data<float>();
  verify_data<long double>();
  verify_data<int>();
  verify_data<unsigned>();
  verify_data<long>();
  verify_data<unsigned long>();
  verify_data<short>();
  verify_data<unsigned short>();
  verify_data<char>();
  verify_data<unsigned char>();
  verify_data<complex<double>>();
  verify_data<complex<float>>();
  verify_data<complex<long double>>();

  verify_data<double const>();
  verify_data<float const>();
  verify_data<long double const>();
  verify_data<int const>();
  verify_data<unsigned const>();
  verify_data<long const>();
  verify_data<unsigned long const>();
  verify_data<short const>();
  verify_data<unsigned short const>();
  verify_data<char const>();
  verify_data<unsigned char const>();
  verify_data<complex<double> const>();
  verify_data<complex<float> const>();
  verify_data<complex<long double> const>();
}


/// Verify that get() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_get() {
  REQUIRE(g<E>::a.get(1) == E(2));
  REQUIRE(g<E>::a[0] == E(1));
}


/// Verify that get() works for each kind of v_iface.
TEST_CASE("vec_iface's getters work.", "[v-iface]") {
  verify_get<double>();
  verify_get<float>();
  verify_get<long double>();
  verify_get<int>();
  verify_get<unsigned>();
  verify_get<long>();
  verify_get<unsigned long>();
  verify_get<short>();
  verify_get<unsigned short>();
  verify_get<char>();
  verify_get<unsigned char>();
  verify_get<complex<double>>();
  verify_get<complex<float>>();
  verify_get<complex<long double>>();
}


/// Verify that set() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_set() {
  auto b= g<E>::a;
  b[0]= E(10);
  b.set(1, E(20));
  REQUIRE(b[0] == E(10));
  REQUIRE(b[1] == E(20));
}


/// Verify that set() works for each kind of v_iface.
TEST_CASE("vec_iface's setters work.", "[v-iface]") {
  verify_set<double>();
  verify_set<float>();
  verify_set<long double>();
  verify_set<int>();
  verify_set<unsigned>();
  verify_set<long>();
  verify_set<unsigned long>();
  verify_set<short>();
  verify_set<unsigned short>();
  verify_set<char>();
  verify_set<unsigned char>();
  verify_set<complex<double>>();
  verify_set<complex<float>>();
  verify_set<complex<long double>>();
}


/// Verify that ptr() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_ptr() {
  static_vector const b({E(1), E(2), E(3), E(4), E(5), E(6)});
  static_vector c= b;
  vector_view d= b.subvector(3, 1, 2);
  vector_view e= c.subvector(3, 1, 2);
  REQUIRE(d.ptr(1) == b.ptr(3));
  REQUIRE(e.ptr(1) == c.ptr(3));
  REQUIRE(d.ptr(1) == b.data() + 3);
  REQUIRE(e.ptr(1) == c.data() + 3);
  *e.ptr(1)= E(9);
  REQUIRE(c[3] == E(9));
}


TEST_CASE("vec_iface::ptr() retrieves pointer of element.", "[v-iface]") {
  verify_ptr<double>();
  verify_ptr<float>();
  verify_ptr<long double>();
  verify_ptr<int>();
  verify_ptr<unsigned>();
  verify_ptr<long>();
  verify_ptr<unsigned long>();
  verify_ptr<short>();
  verify_ptr<unsigned short>();
  verify_ptr<char>();
  verify_ptr<unsigned char>();
  verify_ptr<complex<double>>();
  verify_ptr<complex<float>>();
  verify_ptr<complex<long double>>();
}


/// Verify that set_all() and set_zero() work for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_set_all_zero() {
  static_vector<3, E> b;
  b.set_all(E(3));
  REQUIRE(b[0] == E(3));
  REQUIRE(b[1] == E(3));
  REQUIRE(b[2] == E(3));
  b.set_zero();
  REQUIRE(b.isnull());
}


/// Verify that set_all() and set_zero() work for each kind of v_iface.
TEST_CASE("v_iface::set_all() and v_iface::set_zero() work.", "[v-iface]") {
  verify_set_all_zero<double>();
  verify_set_all_zero<float>();
  verify_set_all_zero<long double>();
  verify_set_all_zero<int>();
  verify_set_all_zero<unsigned>();
  verify_set_all_zero<long>();
  verify_set_all_zero<unsigned long>();
  verify_set_all_zero<short>();
  verify_set_all_zero<unsigned short>();
  verify_set_all_zero<char>();
  verify_set_all_zero<unsigned char>();
  verify_set_all_zero<complex<double>>();
  verify_set_all_zero<complex<float>>();
  verify_set_all_zero<complex<long double>>();
}


/// Verify that set_basis() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_set_basis() {
  static_vector<3, E> b;
  for(unsigned i= 0; i < b.size(); ++i) {
    b.set_basis(i);
    for(unsigned j= 0; j < b.size(); ++j) {
      if(i == j) {
        REQUIRE(b[j] == E(1));
      } else {
        REQUIRE(b[j] == E(0));
      }
    }
  }
}


/// Verify that set_basis() works for each kind of v_iface.
TEST_CASE("vec_iface::set_basis() works.", "[v-iface]") {
  verify_set_basis<double>();
  verify_set_basis<float>();
  verify_set_basis<long double>();
  verify_set_basis<int>();
  verify_set_basis<short>();
  verify_set_basis<long>();
  verify_set_basis<unsigned>();
  verify_set_basis<unsigned short>();
  verify_set_basis<unsigned long>();
  verify_set_basis<char>();
  verify_set_basis<unsigned char>();
  verify_set_basis<complex<double>>();
  verify_set_basis<complex<float>>();
  verify_set_basis<complex<long double>>();
}


/// Verify that fwrite() and fread() work for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_fwrite_fread() {
  FILE *f= fopen("io-test.dat", "wb");
  g<E>::a.fwrite(f);
  fclose(f);
  static_vector<3, E> b;
  b.set_zero();
  f= fopen("io-test.dat", "rb");
  b.fread(f);
  fclose(f);
  REQUIRE(g<E>::a == b);
}


/// Verify that fwrite and fread() work for each kind of v_iface.
TEST_CASE("vec_iface::fwrite() and vec_iface::fread() work.", "[v-iface]") {
  verify_fwrite_fread<double>();
  verify_fwrite_fread<float>();
  verify_fwrite_fread<long double>();
  verify_fwrite_fread<int>();
  verify_fwrite_fread<short>();
  verify_fwrite_fread<long>();
  verify_fwrite_fread<unsigned>();
  verify_fwrite_fread<unsigned short>();
  verify_fwrite_fread<unsigned long>();
  verify_fwrite_fread<char>();
  verify_fwrite_fread<unsigned char>();
  verify_fwrite_fread<complex<double>>();
  verify_fwrite_fread<complex<float>>();
  verify_fwrite_fread<complex<long double>>();
}


TEST_CASE("vec_iface::fprintf() and vec_iface::fscanf() work.", "[v-iface]") {
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


TEST_CASE("vec_iface::subvector() works.", "[v-iface]") {
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


TEST_CASE("vec_iface::swap_elements() works.", "[v-iface]") {
  v3 b= a;
  b.swap_elements(0, 1);
  REQUIRE(a[0] == b[1]);
  REQUIRE(a[1] == b[0]);
  REQUIRE(a[2] == b[2]);
}


TEST_CASE("vec_iface::reverse() works.", "[v-iface]") {
  v3 b= a;
  b.reverse();
  REQUIRE(b[0] == a[2]);
  REQUIRE(b[1] == a[1]);
  REQUIRE(b[2] == a[0]);
}


TEST_CASE("vec_iface's addition in place works.", "[v-iface]") {
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


TEST_CASE("vec_iface's subtraction in place works.", "[v-iface]") {
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


TEST_CASE("vec_iface's multiplication in place works.", "[v-iface]") {
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


TEST_CASE("vec_iface's division in place works.", "[v-iface]") {
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


TEST_CASE("vec_iface's scaling works.", "[v-iface]") {
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


template<typename E> void verify_add_constant() {
  auto &a= g<E>::a;
  auto b= a;
  b.add_constant(1);
  REQUIRE(b[0] == E(2));
  REQUIRE(b[1] == E(3));
  REQUIRE(b[2] == E(4));
  b+= 1;
  REQUIRE(b[0] == E(3));
  REQUIRE(b[1] == E(4));
  REQUIRE(b[2] == E(5));
}


TEST_CASE("vec_iface's adding constant works.", "[v-iface]") {
  verify_add_constant<double>();
  verify_add_constant<float>();
  verify_add_constant<long double>();
  verify_add_constant<int>();
  verify_add_constant<unsigned>();
  verify_add_constant<long>();
  verify_add_constant<unsigned long>();
  verify_add_constant<short>();
  verify_add_constant<unsigned short>();
  verify_add_constant<char>();
  verify_add_constant<unsigned char>();
  verify_add_constant<complex<double>>();
  verify_add_constant<complex<float>>();
  verify_add_constant<complex<long double>>();
}


TEST_CASE("vec_iface's statistical functions work.", "[v-iface]") {
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


TEST_CASE("vec_iface::isnull() works.", "[v-iface]") {
  v3 b= a;
  REQUIRE(b.isnull() == false);

  b.set_zero();
  REQUIRE(b.isnull() == true);
}


TEST_CASE("vec_iface::ispos() works.", "[v-iface]") {
  v3 b= a;
  REQUIRE(b.ispos() == true);

  b.add_constant(-1.0);
  REQUIRE(b.ispos() == false);
}


TEST_CASE("vec_iface::isnonneg() works.", "[v-iface]") {
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


TEST_CASE("vec_iface::view() works.", "[v-iface]") {
  static_vector<3> const a({2.0, 3.0, 1.0});
  auto const b= a.view();
  REQUIRE(a == b);
  REQUIRE(&a[0] == &b[0]);
  REQUIRE(&a[1] == &b[1]);
  REQUIRE(&a[2] == &b[2]);
}


TEST_CASE("vec_iface::sum() works.", "[v-iface]") {
  static_vector<3> const a({2.0, 3.0, 1.0});
  REQUIRE(a.sum() == 6.0);
}


TEST_CASE("vec_iface::isneg() works.", "[v-iface]") {
  static_vector<3> const a({-2.0, -3.0, 1.0});
  static_vector<3> const b({-2.0, -3.0, -1.0});
  REQUIRE(a.isneg() == false);
  REQUIRE(b.isneg() == true);
}

// EOF
