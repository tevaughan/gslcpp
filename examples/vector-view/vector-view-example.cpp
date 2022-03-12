
#include <gslcpp/vector-view.hpp>

using gsl::complex;
using gsl::vector_view;
using std::cout;
using std::endl;

// Example-usage of gsl::vector_view.
int main() {
  complex<float> const a1[]= {{1.0f, -1.0f}, {0.5f, 0.6f}};
  // Deduce vector_view<complex<float>,2>.
  vector_view v1= a1;
  cout << "\n"
       << "Instance of gsl_vector_view consumes 40 bytes on 64-bit hardware.\n"
       << "sizeof(v1)=" << sizeof(v1) << " v1=" << v1 << "\n"
       << "v1.get(1)=" << v1.get(1) << endl;

  float a4[]= {1, 2, 3, 4, 5, 6};
  // Deduce vector_view<float,0>, and set size to four. The output contains
  // a subvector of v4: length 2, starting at offset 1 into v4, and with stride
  // 2 relative to v4.
  vector_view v4(a4, 4);
  cout << "\n"
       << "sizeof(v4)=" << sizeof(v4) << " v4=" << v4 << "\n"
       << "v4.subvector(2, 1, 2)=" << v4.subvector(2, 1, 2) << endl;

  short a5[]= {1, 2, 3, 4, 5, 6};
  // Deduce vector_view<short,0>, set size to 3, and set stride to 2.
  vector_view v5(a5, 3, 2);
  cout << "\n"
       << "sizeof(v5)=" << sizeof(v5) << " v5=" << v5 << "\n"
       << "v5.max_index()=" << v5.max_index() << endl;
}

