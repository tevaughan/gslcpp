/// @file       test/v-iface-test.cpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Tests for gsl::v_iface.

#include "gslcpp/vector-view.hpp"
#include "gslcpp/vector.hpp"
#include <catch.hpp>
#include <cinttypes> // PRId8, etc.
#include <sstream> // ostringstream


using gsl::axpby;
using gsl::complex;
using gsl::v_iface;
using gsl::vector;
using gsl::vector_view;
using std::is_same_v;
using std::ostringstream;


/// Globals for tests.
/// \tparam E  Type of each element in vector.
template<typename E> struct g {
  /// Global C-array with three elements.
  constexpr static E ca[]= {1, 2, 3};
};


/// Verify that begin() works for v_iface<E>.
/// For non-const type E, this exercises both const and non-const begin().
/// \tparam E  Type of each element in vector.
template<typename E> void verify_begin() {
  vector const a= g<E>::ca;
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
TEST_CASE("v_iface::begin() works.", "[v-iface]") {
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
  vector const a= g<E>::ca;
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
TEST_CASE("v_iface::end() works.", "[v-iface]") {
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
template<typename E> void verify_size() {
  vector const a= g<E>::ca;
  REQUIRE(a.size() == 3);
}


/// Verify that size() works for each kind of v_iface.
TEST_CASE("v_iface::size() works.", "[v-iface]") {
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
  vector const a= g<E>::ca;
  REQUIRE(a.data() == &a[0]);
  E b[]= {1, 2, 3, 4, 5, 6};
  vector_view d= b;
  auto c= d.subvector(3, 1, 2);
  REQUIRE(c.data() == b + 1);
}


/// Verify that data() points to right place for each kind of v_iface.
TEST_CASE("v_iface::data() works.", "[v-iface]") {
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
  vector const a= g<E>::ca;
  REQUIRE(a.get(1) == E(2));
  REQUIRE(a[0] == E(1));
}


/// Verify that get() works for each kind of v_iface.
TEST_CASE("v_iface's getters work.", "[v-iface]") {
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
  vector b= g<E>::ca;
  b[0]= E(10);
  b.set(1, E(20));
  REQUIRE(b[0] == E(10));
  REQUIRE(b[1] == E(20));
}


/// Verify that set() works for each kind of v_iface.
TEST_CASE("v_iface's setters work.", "[v-iface]") {
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
  vector const b({E(1), E(2), E(3), E(4), E(5), E(6)});
  vector c= b;
  vector_view d= b.subvector(3, 1, 2);
  vector_view e= c.subvector(3, 1, 2);
  REQUIRE(d.ptr(1) == b.ptr(3));
  REQUIRE(e.ptr(1) == c.ptr(3));
  REQUIRE(d.ptr(1) == b.data() + 3);
  REQUIRE(e.ptr(1) == c.data() + 3);
  *e.ptr(1)= E(9);
  REQUIRE(c[3] == E(9));
}


TEST_CASE("v_iface::ptr() retrieves pointer of element.", "[v-iface]") {
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
  vector<E, 3> b;
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
  vector<E, 3> b;
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
TEST_CASE("v_iface::set_basis() works.", "[v-iface]") {
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
  vector const a= g<E>::ca;
  a.fwrite(f);
  fclose(f);
  vector<E, 3> b;
  b.set_zero();
  f= fopen("io-test.dat", "rb");
  b.fread(f);
  fclose(f);
  REQUIRE(a == b);
}


/// Verify that fwrite() and fread() work for each kind of v_iface.
TEST_CASE("v_iface::fwrite() and v_iface::fread() work.", "[v-iface]") {
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


/// Format-string for fprintf().
/// \tparam E  Type of each element in vector.
/// \return  Format-string for fprintf().
template<typename E> constexpr auto fmt() {
  if constexpr(is_same_v<E, complex<double>>) return "%g";
  if constexpr(is_same_v<E, complex<float>>) return "%g";
  if constexpr(is_same_v<E, complex<long double>>) return "%Lg";
  if constexpr(std::is_integral_v<E>) {
    if constexpr(sizeof(E) == 1) return "%" PRId8;
    if constexpr(sizeof(E) == 2) return "%" PRId16;
    if constexpr(sizeof(E) == 4) return "%" PRId32;
    return "%" PRId64;
  }
  if constexpr(sizeof(E) == 4 || sizeof(E) == 8) return "%g";
  return "%Lg";
}


/// Verify that fprintf() and fscanf() work for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_fprintf_fscanf() {
  FILE *f= fopen("output-test.txt", "w");
  vector const a= g<E>::ca;
  a.fprintf(f, fmt<E>());
  fclose(f);
  vector<E, 3> b;
  b.set_zero();
  f= fopen("output-test.txt", "r");
  b.fscanf(f);
  fclose(f);
  REQUIRE(a == b);
}


/// Verify that fprintf() and fscanf() work for each kind of v_iface.
TEST_CASE("v_iface::fprintf() and v_iface::fscanf() work.", "[v-iface]") {
  verify_fprintf_fscanf<double>();
  verify_fprintf_fscanf<float>();
  verify_fprintf_fscanf<long double>();
  verify_fprintf_fscanf<int>();
  verify_fprintf_fscanf<short>();
  verify_fprintf_fscanf<long>();
  verify_fprintf_fscanf<unsigned>();
  verify_fprintf_fscanf<unsigned short>();
  verify_fprintf_fscanf<unsigned long>();
  verify_fprintf_fscanf<char>();
  verify_fprintf_fscanf<unsigned char>();
  verify_fprintf_fscanf<complex<double>>();
  verify_fprintf_fscanf<complex<float>>();
  verify_fprintf_fscanf<complex<long double>>();
}


/// Verify that subvector() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_subvector() {
  E const cb[]= {1, 2, 3, 4, 5, 6};
  vector const b= cb;
  vector c= b;
  auto vb= b.subvector(3, 1, 2);
  auto vc= c.subvector(3, 1, 2);
  REQUIRE(vb[0] == E(2));
  REQUIRE(vc[0] == E(2));
  REQUIRE(vb[1] == E(4));
  REQUIRE(vc[1] == E(4));
  REQUIRE(vb[2] == E(6));
  REQUIRE(vc[2] == E(6));
  vc[0]= E(7);
  vc[1]= E(8);
  vc[2]= E(9);
  REQUIRE(c[1] == E(7));
  REQUIRE(c[3] == E(8));
  REQUIRE(c[5] == E(9));
  auto vvc= vc.subvector(2, 0, 2);
  REQUIRE(vvc[0] == vc[0]);
  REQUIRE(vvc[1] == vc[2]);
  REQUIRE(vvc[0] == c[1]);
  REQUIRE(vvc[1] == c[5]);
}


/// Verify that subvector() works for any kind of v_iface.
TEST_CASE("v_iface::subvector() works.", "[v-iface]") {
  verify_subvector<double>();
  verify_subvector<float>();
  verify_subvector<long double>();
  verify_subvector<int>();
  verify_subvector<short>();
  verify_subvector<long>();
  verify_subvector<unsigned>();
  verify_subvector<unsigned short>();
  verify_subvector<unsigned long>();
  verify_subvector<char>();
  verify_subvector<unsigned char>();
  verify_subvector<complex<double>>();
  verify_subvector<complex<float>>();
  verify_subvector<complex<long double>>();
}


/// Verify that swap_elements() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_swap_elements() {
  vector const a= g<E>::ca;
  vector b= a;
  b.swap_elements(0, 1);
  REQUIRE(a[0] == b[1]);
  REQUIRE(a[1] == b[0]);
  REQUIRE(a[2] == b[2]);
}


/// Verify that swap_elements() works for each kind of v_iface.
TEST_CASE("v_iface::swap_elements() works.", "[v-iface]") {
  verify_swap_elements<double>();
  verify_swap_elements<float>();
  verify_swap_elements<long double>();
  verify_swap_elements<int>();
  verify_swap_elements<short>();
  verify_swap_elements<long>();
  verify_swap_elements<unsigned>();
  verify_swap_elements<unsigned short>();
  verify_swap_elements<unsigned long>();
  verify_swap_elements<char>();
  verify_swap_elements<unsigned char>();
  verify_swap_elements<complex<double>>();
  verify_swap_elements<complex<float>>();
  verify_swap_elements<complex<long double>>();
}


/// Verify that reverse() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_reverse() {
  vector const a= g<E>::ca;
  auto b= a;
  b.reverse();
  REQUIRE(b[0] == a[2]);
  REQUIRE(b[1] == a[1]);
  REQUIRE(b[2] == a[0]);
}


/// Verify that reverse() works for any kind of v_iface.
TEST_CASE("v_iface::reverse() works.", "[v-iface]") {
  verify_reverse<double>();
  verify_reverse<float>();
  verify_reverse<long double>();
  verify_reverse<int>();
  verify_reverse<short>();
  verify_reverse<long>();
  verify_reverse<unsigned>();
  verify_reverse<unsigned short>();
  verify_reverse<unsigned long>();
  verify_reverse<char>();
  verify_reverse<unsigned char>();
  verify_reverse<complex<double>>();
  verify_reverse<complex<float>>();
  verify_reverse<complex<long double>>();
}


/// Verify that add() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_add() {
  vector const a= g<E>::ca;
  vector<E, 3> b;

  b.set_all(E(1));
  b.add(a);
  REQUIRE(b[0] == E(2));
  REQUIRE(b[1] == E(3));
  REQUIRE(b[2] == E(4));

  b.set_all(E(1));
  b+= a;
  REQUIRE(b[0] == E(2));
  REQUIRE(b[1] == E(3));
  REQUIRE(b[2] == E(4));
}


/// Verify that add() works for any kind of iface.
TEST_CASE("v_iface::add() works.", "[v-iface]") {
  verify_add<double>();
  verify_add<float>();
  verify_add<long double>();
  verify_add<int>();
  verify_add<short>();
  verify_add<long>();
  verify_add<unsigned>();
  verify_add<unsigned short>();
  verify_add<unsigned long>();
  verify_add<char>();
  verify_add<unsigned char>();
  verify_add<complex<double>>();
  verify_add<complex<float>>();
  verify_add<complex<long double>>();
}


/// Verify that sub() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_sub() {
  vector const a= g<E>::ca;
  vector<E, 3> b;

  b.set_all(E(3));
  b.sub(a);
  REQUIRE(b[0] == E(2));
  REQUIRE(b[1] == E(1));
  REQUIRE(b[2] == E(0));

  b.set_all(E(3));
  b-= a;
  REQUIRE(b[0] == E(2));
  REQUIRE(b[1] == E(1));
  REQUIRE(b[2] == E(0));
}


/// Verify that sub works for any kind of iface.
TEST_CASE("v_iface::sub() works.", "[v-iface]") {
  verify_sub<double>();
  verify_sub<float>();
  verify_sub<long double>();
  verify_sub<int>();
  verify_sub<short>();
  verify_sub<long>();
  verify_sub<unsigned>();
  verify_sub<unsigned short>();
  verify_sub<unsigned long>();
  verify_sub<char>();
  verify_sub<unsigned char>();
  verify_sub<complex<double>>();
  verify_sub<complex<float>>();
  verify_sub<complex<long double>>();
}


/// Verify that mul() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_mul() {
  vector const a= g<E>::ca;
  vector<E, 3> b;

  b.set_all(E(1));
  b.mul(a);
  REQUIRE(b[0] == E(1));
  REQUIRE(b[1] == E(2));
  REQUIRE(b[2] == E(3));

  b.set_all(E(1));
  b*= a;
  REQUIRE(b[0] == E(1));
  REQUIRE(b[1] == E(2));
  REQUIRE(b[2] == E(3));
}


/// Verify that mul() works for any kind of v_iface.
TEST_CASE("v_iface::mul() works.", "[v-iface]") {
  verify_mul<double>();
  verify_mul<float>();
  verify_mul<long double>();
  verify_mul<int>();
  verify_mul<short>();
  verify_mul<long>();
  verify_mul<unsigned>();
  verify_mul<unsigned short>();
  verify_mul<unsigned long>();
  verify_mul<char>();
  verify_mul<unsigned char>();
  verify_mul<complex<double>>();
  verify_mul<complex<float>>();
  verify_mul<complex<long double>>();
}


/// Verify that div() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_div() {
  vector<E, 3> const a({2, 4, 8});
  vector<E, 3> b;

  b.set_all(E(16));
  b.div(a);
  REQUIRE(b[0] == E(8));
  REQUIRE(b[1] == E(4));
  REQUIRE(b[2] == E(2));

  b.set_all(E(16));
  b/= a;
  REQUIRE(b[0] == E(8));
  REQUIRE(b[1] == E(4));
  REQUIRE(b[2] == E(2));
}


/// Verify that div() works for any kind of v_iface.
TEST_CASE("v_iface::div() works.", "[v-iface]") {
  verify_div<double>();
  verify_div<float>();
  verify_div<long double>();
  verify_div<int>();
  verify_div<short>();
  verify_div<long>();
  verify_div<unsigned>();
  verify_div<unsigned short>();
  verify_div<unsigned long>();
  verify_div<char>();
  verify_div<unsigned char>();
  verify_div<complex<double>>();
  verify_div<complex<float>>();
  verify_div<complex<long double>>();
}


/// Verify that scale() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_scale() {
  vector b= g<E>::ca;
  b.scale(E(2));
  REQUIRE(b[0] == E(2));
  REQUIRE(b[1] == E(4));
  REQUIRE(b[2] == E(6));
  b*= E(2);
  REQUIRE(b[0] == E(4));
  REQUIRE(b[1] == E(8));
  REQUIRE(b[2] == E(12));
}


/// Verify that scale works for any kind of v_iface.
TEST_CASE("v_iface::scale() works.", "[v-iface]") {
  verify_scale<double>();
  verify_scale<float>();
  verify_scale<long double>();
  verify_scale<int>();
  verify_scale<short>();
  verify_scale<long>();
  verify_scale<unsigned>();
  verify_scale<unsigned short>();
  verify_scale<unsigned long>();
  verify_scale<char>();
  verify_scale<unsigned char>();
  verify_scale<complex<double>>();
  verify_scale<complex<float>>();
  verify_scale<complex<long double>>();
}


/// Verify that add_constant() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_add_constant() {
  vector const a= g<E>::ca;
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


/// Verify that add_constant() works for any kind of v_iface.
TEST_CASE("v_iface::add_constant() works.", "[v-iface]") {
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


/// True if type E be complex.
/// \tparam E  Type of each element in vector.
/// \return  True if E be complex.
template<typename E> constexpr bool is_complex() {
  constexpr bool cd= is_same_v<E, complex<double>>;
  constexpr bool cf= is_same_v<E, complex<float>>;
  constexpr bool cld= is_same_v<E, complex<long double>>;
  return cd || cf || cld;
}


/// True if type E be unsigned.
/// \tparam E  Type of each element in vector.
/// \return  True if E be unsigned.
template<typename E> constexpr bool is_unsigned() {
  constexpr bool uc= is_same_v<E, unsigned char>;
  constexpr bool us= is_same_v<E, unsigned short>;
  constexpr bool ui= is_same_v<E, unsigned int>;
  constexpr bool ul= is_same_v<E, unsigned long>;
  return uc || us || ui || ul;
}


/// Verify that statistical functions work for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_stats() {
  vector const a= g<E>::ca; // (1, 2, 3)
  auto b= a.subvector(2, 0, 2); // (1, 3)
  REQUIRE(a.sum() == E(6)); // 1 + 2 + 3
  REQUIRE(b.sum() == E(4)); // 1 + 3

  // Complex numbers are not ordered, and so no order-related statistics.
  if constexpr(is_complex<E>()) {
    return;
  } else {
    REQUIRE(a.max() == E(3));
    REQUIRE(a.min() == E(1));

    E min, max;
    a.minmax(min, max);
    REQUIRE(min == E(1));
    REQUIRE(max == E(3));

    auto b= a;
    b.reverse();
    REQUIRE(b.max_index() == 0);
    REQUIRE(b.min_index() == 2);

    size_t imin, imax;
    b.minmax_index(imin, imax);
    REQUIRE(imax == 0);
    REQUIRE(imin == 2);
  }
}


/// Verify that statistical functions work for any kind of v_iface.
TEST_CASE("v_iface's statistical functions work.", "[v-iface]") {
  verify_stats<double>();
  verify_stats<float>();
  verify_stats<long double>();
  verify_stats<int>();
  verify_stats<unsigned>();
  verify_stats<long>();
  verify_stats<unsigned long>();
  verify_stats<short>();
  verify_stats<unsigned short>();
  verify_stats<char>();
  verify_stats<unsigned char>();
  verify_stats<complex<double>>();
  verify_stats<complex<float>>();
  verify_stats<complex<long double>>();
}


/// Verify that isnull() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_isnull() {
  vector b= g<E>::ca;
  REQUIRE(b.isnull() == false);
  b.set_zero();
  REQUIRE(b.isnull() == true);
}


/// Verify that isnull works for any kind of v_iface.
TEST_CASE("v_iface::isnull() works.", "[v-iface]") {
  verify_isnull<double>();
  verify_isnull<float>();
  verify_isnull<long double>();
  verify_isnull<int>();
  verify_isnull<unsigned>();
  verify_isnull<long>();
  verify_isnull<unsigned long>();
  verify_isnull<short>();
  verify_isnull<unsigned short>();
  verify_isnull<char>();
  verify_isnull<unsigned char>();
  verify_isnull<complex<double>>();
  verify_isnull<complex<float>>();
  verify_isnull<complex<long double>>();
}


/// Verify that ispos() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_ispos() {
  vector b= g<E>::ca;
  if constexpr(is_complex<E>()) {
    REQUIRE(b.ispos() == false);
    vector const c({E(1, 1), E(2, 1), E(3, 1)});
    REQUIRE(c.ispos() == true);
  } else {
    REQUIRE(b.ispos() == true);
  }
  b.set_zero();
  REQUIRE(b.ispos() == false);
}


/// Verify that ispos() works for any kind of v_iface.
TEST_CASE("v_iface::ispos() works.", "[v-iface]") {
  verify_ispos<double>();
  verify_ispos<float>();
  verify_ispos<long double>();
  verify_ispos<int>();
  verify_ispos<unsigned>();
  verify_ispos<long>();
  verify_ispos<unsigned long>();
  verify_ispos<short>();
  verify_ispos<unsigned short>();
  verify_ispos<char>();
  verify_ispos<unsigned char>();
  verify_ispos<complex<double>>();
  verify_ispos<complex<float>>();
  verify_ispos<complex<long double>>();
}


/// Verify that isnonneg() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_isnonneg() {
  vector b= g<E>::ca;
  REQUIRE(b.isnonneg() == true);
  b.add_constant(E(-1));
  REQUIRE(b.isnonneg() == true);
  b.add_constant(E(-1));
  if constexpr(is_unsigned<E>()) {
    REQUIRE(b.isnonneg() == true);
  } else {
    REQUIRE(b.isnonneg() == false);
  }
}


/// Verify that isnonneg() works for any kind of v_iface.
TEST_CASE("v_iface::isnonneg() works.", "[v-iface]") {
  verify_isnonneg<double>();
  verify_isnonneg<float>();
  verify_isnonneg<long double>();
  verify_isnonneg<int>();
  verify_isnonneg<unsigned>();
  verify_isnonneg<long>();
  verify_isnonneg<unsigned long>();
  verify_isnonneg<short>();
  verify_isnonneg<unsigned short>();
  verify_isnonneg<char>();
  verify_isnonneg<unsigned char>();
  verify_isnonneg<complex<double>>();
  verify_isnonneg<complex<float>>();
  verify_isnonneg<complex<long double>>();
}


/// Verify that isneg() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_isneg() {
  vector b= g<E>::ca;
  REQUIRE(b.isneg() == false);
  if constexpr(is_complex<E>()) {
    b.add_constant(E(-4, -1));
  } else {
    b.add_constant(E(-4));
  }
  if constexpr(is_unsigned<E>()) {
    REQUIRE(b.isneg() == false);
  } else {
    REQUIRE(b.isneg() == true);
  }
}


/// Verify that isneg() works for any kind of v_iface.
TEST_CASE("v_iface::isneg() works.", "[v-iface]") {
  verify_isneg<double>();
  verify_isneg<float>();
  verify_isneg<long double>();
  verify_isneg<int>();
  verify_isneg<unsigned>();
  verify_isneg<long>();
  verify_isneg<unsigned long>();
  verify_isneg<short>();
  verify_isneg<unsigned short>();
  verify_isneg<char>();
  verify_isneg<unsigned char>();
  verify_isneg<complex<double>>();
  verify_isneg<complex<float>>();
  verify_isneg<complex<long double>>();
}


/// Verify that axpby() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_axpby() {
  vector const x({E(1), E(2), E(3)});
  vector y({E(2), E(3), E(1)});
  E const a= 1;
  E const b= 2;
  axpby(a, x, b, y);
  vector const r({E(5), E(8), E(5)});
  REQUIRE(y == r);
}


/// Verify the axpby() works for any kind of v_iface.
TEST_CASE("v_iface::axpby() works.", "[v-iface]") {
  verify_axpby<double>();
  verify_axpby<float>();
  verify_axpby<long double>();
  verify_axpby<int>();
  verify_axpby<unsigned>();
  verify_axpby<long>();
  verify_axpby<unsigned long>();
  verify_axpby<short>();
  verify_axpby<unsigned short>();
  verify_axpby<char>();
  verify_axpby<unsigned char>();
  verify_axpby<complex<double>>();
  verify_axpby<complex<float>>();
  verify_axpby<complex<long double>>();
}


/// Verify that equal() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_equal() {
  vector const x({E(1), E(2), E(3)});
  vector const y({E(2), E(3), E(1)});
  vector const z({E(2), E(3), E(1)});
  REQUIRE(!equal(x, y));
  REQUIRE(x != y);
  REQUIRE(equal(y, z));
  REQUIRE(y == z);
}


/// Verify that equal() works for any kind of v_iface.
TEST_CASE("v_iface::equal() works.", "[v-iface]") {
  verify_equal<double>();
  verify_equal<float>();
  verify_equal<long double>();
  verify_equal<int>();
  verify_equal<unsigned>();
  verify_equal<long>();
  verify_equal<unsigned long>();
  verify_equal<short>();
  verify_equal<unsigned short>();
  verify_equal<char>();
  verify_equal<unsigned char>();
  verify_equal<complex<double>>();
  verify_equal<complex<float>>();
  verify_equal<complex<long double>>();
}


/// Verify that memcpy() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_memcpy() {
  vector y({E(2), E(3), E(1)});
  vector const z({E(1), E(2), E(3)});
  REQUIRE(!equal(y, z));
  memcpy(y, z);
  REQUIRE(equal(y, z));
}


/// Verify that memcpy() works for any v_iface.
TEST_CASE("v_iface::memcpy() works.", "[v-iface]") {
  verify_memcpy<double>();
  verify_memcpy<float>();
  verify_memcpy<long double>();
  verify_memcpy<int>();
  verify_memcpy<unsigned>();
  verify_memcpy<long>();
  verify_memcpy<unsigned long>();
  verify_memcpy<short>();
  verify_memcpy<unsigned short>();
  verify_memcpy<char>();
  verify_memcpy<unsigned char>();
  verify_memcpy<complex<double>>();
  verify_memcpy<complex<float>>();
  verify_memcpy<complex<long double>>();
}


/// Verify that swap() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_swap() {
  vector const a({E(2), E(3), E(1)});
  vector const b({E(1), E(2), E(3)});
  auto c= a;
  auto d= b;
  REQUIRE(a == c);
  REQUIRE(b == d);
  gsl::swap(c, d); // WEIRD: was calling std::swap without ns-prefix!
  REQUIRE(a == d);
  REQUIRE(b == c);
}


/// Verify that swap() works for any kind of v_iface.
TEST_CASE("v_iface::swap() works.", "[v-iface]") {
  verify_swap<double>();
  verify_swap<float>();
  verify_swap<long double>();
  verify_swap<int>();
  verify_swap<unsigned>();
  verify_swap<long>();
  verify_swap<unsigned long>();
  verify_swap<short>();
  verify_swap<unsigned short>();
  verify_swap<char>();
  verify_swap<unsigned char>();
  verify_swap<complex<double>>();
  verify_swap<complex<float>>();
  verify_swap<complex<long double>>();
}


/// Verify that stream-operator works.
TEST_CASE("Stream-operator works.", "[v-iface]") {
  vector const a({2.0, 3.0, 1.0});
  ostringstream oss;
  oss << a;
  REQUIRE(oss.str() == "[2,3,1]");
}


/// Verify that view() works for v_iface<E>.
/// \tparam E  Type of each element in vector.
template<typename E> void verify_view() {
  vector const a({E(2), E(3), E(1)});
  auto const b= a.view();
  REQUIRE(a == b);
  REQUIRE(&a[0] == &b[0]);
  REQUIRE(&a[1] == &b[1]);
  REQUIRE(&a[2] == &b[2]);
}


/// Verify that view() works for any kind of v_iface.
TEST_CASE("v_iface::view() works.", "[v-iface]") {
  verify_view<double>();
  verify_view<float>();
  verify_view<long double>();
  verify_view<int>();
  verify_view<unsigned>();
  verify_view<long>();
  verify_view<unsigned long>();
  verify_view<short>();
  verify_view<unsigned short>();
  verify_view<char>();
  verify_view<unsigned char>();
  verify_view<complex<double>>();
  verify_view<complex<float>>();
  verify_view<complex<long double>>();
}


// EOF
