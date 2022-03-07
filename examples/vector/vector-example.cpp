
#include <gslcpp/vector.hpp>

using gsl::CALLOC;
using gsl::vector;
using std::cout;
using std::endl;

int main() {
  vector v1({2.0, 4.0, 6.0, 8.0});
  vector v2({1.0, 3.0, 5.0, 7.0, 9.0});
  vector<double> v3(4, CALLOC); // CALLOC causes initialization to zero.
  cout << "sizeof(v1)=" << sizeof(v1) << " v1=" << v1 << endl;
  cout << "sizeof(v2)=" << sizeof(v2) << " v2=" << v2 << endl;
  cout << "sizeof(v3)=" << sizeof(v3) << " v3=" << v3 << endl;
}

