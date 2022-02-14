# gslcpp

C++-library wrapping portions of GSL and providing interoperability with Eigen.
  - The portions of GSL are
    - GSL's vector and
    - GSL's minimization-routines (which depend on GSL's vector).
  - Interoperability with Eigen is provided for GSL's vector.
  - A compiler for C++-20 is required.

## Status

- The C++-interface to `gsl_vector` is implemented.
  - The designed allows adding types easily.
  - Initially, the only type supported is `double`.
  - The unit-tests are almost done.
    - Class `vector_s` for stack-allocation is fully tested.
    - Class `vector_v` for vector-views is fully tested.
    - Class `vector_d` for dynamic allocation is not yet tested.
- The C++-interface to the minimizers is not implemented yet.
- Interfaces with Eigen are not yet implemented.

## How to Build

The unit-tests are built, run, and reported on for coverage by way of `cmake`.

`clang++-12` is required at the moment by [Makefile](Makefile), but
`clang++-10` or later will work if you edit [Makefile](Makefile).

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

