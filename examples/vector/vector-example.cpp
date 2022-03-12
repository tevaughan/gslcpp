
#include <gslcpp/vector.hpp>

using gsl::CALLOC;
using gsl::complex;
using gsl::vector;
using std::cout;
using std::endl;

// Example-usage of gsl::vector.
int main() {
  complex<float> const a1[]= {{1.0f, -1.0f}, {0.5f, 0.6f}};
  // Deduce vector<complex<float>,2> and copy from array.
  vector v1= a1;
  cout << "\n"
       << "v1 has, on stack, elements and internal vector-view.\n"
       << "Instance of gsl_vector_view consumes 40 bytes on 64-bit hardware.\n"
       << "sizeof(v1)=" << sizeof(v1) << " v1=" << v1 << "\n"
       << "v1.get(1)=" << v1.get(1) << endl;

  // Deduce vector<double,5>, and copy from initializer-list.
  vector v2({1.0, 3.0, 5.0, 7.0, 9.0});
  cout << "\n"
       << "v2 also has, on stack, elements and internal vector-view.\n"
       << "sizeof(v2)=" << sizeof(v2) << " v2=" << v2 << "\n"
       << "v2.max()=" << v2.max() << endl;

  // Deduce vector<double,0>, set size to four, and initialize elements to
  // zero.  Optional argument CALLOC causes initialization to zero.
  vector<double> v3(4, CALLOC);
  cout << "\n"
       << "v3 has, on stack, pointer to vtable and pointer to gsl_vector.\n"
       << "Pointer to vtable is stored because dynamic vector (with compile-\n"
       << "time size of 0) has virtual destructor.\n"
       << "sizeof(v3)=" << sizeof(v3) << " v3=" << v3 << "\n"
       << "v3.isnull()=" << v3.isnull() << endl;

  float a4[]= {1, 2, 3, 4, 5, 6};
  // Deduce vector<float,0>, set size to four, and copy first four elements
  // from array.  The output contains a subvector of v4: length 2, starting at
  // offset 1 into v4, and with stride 2 relative to v4.
  vector v4(a4, 4);
  cout << "\n"
       << "v4 also has, on stack, ptr to vtable and ptr to gsl_vector.\n"
       << "sizeof(v4)=" << sizeof(v4) << " v4=" << v4 << "\n"
       << "v4.subvector(2, 1, 2)=" << v4.subvector(2, 1, 2) << endl;

  short a5[]= {1, 2, 3, 4, 5, 6};
  // Deduce vector<short,0>, set size to 3, and copy first, third, and fifth
  // elements from array.  Optional third argument to constructor is stride.
  vector v5(a5, 3, 2);
  cout << "\n"
       << "v5 also has, on stack, ptr to vtable and ptr to gsl_vector.\n"
       << "sizeof(v5)=" << sizeof(v5) << " v5=" << v5 << "\n"
       << "v5.max_index()=" << v5.max_index() << endl;
}

