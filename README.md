# gslcpp

C++-library wrapping portions of GSL and providing interoperability with Eigen.
  - The initial portions of GSL wrapped by this library will be
    - GSL's vector and
    - GSL's minimization-routines (which depend on GSL's vector).
  - Interoperability with Eigen will provided for GSL's vector (and, eventually
    for GSL's matrix).
  - A compiler for C++-20 is required.

## Status

- The C++-interface to `gsl_vector` is implemented.
  - The design allows adding element-types easily.
  - Initially, the only type supported is `double`.
  - The unit-tests are almost done.
    - Class `vector_s` for stack-allocation is fully tested.
    - Class `vector_v` for vector-views is fully tested.
    - Class `vector_d` for dynamic allocation is not yet tested.
- The C++-interface to the minimizers is not implemented yet.
- Interfaces with Eigen are not yet implemented.
- The design allows adding support for matrices easily.
  - Adding support for GSL-matrices will likely be the next feature after the
    initial goal is met.

## How to Build

The unit-tests are built, run, and reported on for coverage by way of `cmake`.

`clang++-10` or later will work.
- [Makefile](Makefile) calls out the default `clang` and `clang++`.
- Edit [Makefile](Makefile), if necessary, to specify a version.
- For example, change
  - `CC=clang` to `CC=clang-11` and
  - `CXX=clang++` to `CXX=clang++-11`.
- Note that, for coverage-analysis, my cmake-script requires that, if
  specified, the version of `clang` must be provided by a numeric suffix as in
  the example above.

[Makefile](Makefile) at the top is not a product of `cmake`. The default target
  - generates a directory, `build`,
  - properly invokes `cmake` therein, and
  - invokes the generated file, `build/Makefile`
    - to build the tests for coverage-analysis,
    - to run them, and
    - to build the reports of coverage.

So, to get started, just run
```
make
```
at the top of the tree.

After that, products of the coverage-analysis end up in
  - `build/tests_cov-summary.txt`,
  - `build/tests_cov.txt`, and
  - `build/tests_cov.html`.

