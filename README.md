# gslcpp

C++-library wrapping portions of GSL and providing interoperability with Eigen.
  - The portions of GSL are
    - GSL's vector and
    - GSL's minimization-routines (which depend on GSL's vector).
  - Interoperability with Eigen is provided for GSL's vector.

## Status

- The C++-interface to `gsl_vector` is implemented but not fully unit-tested.
- The C++-interface to the minimizers is not implemented yet.

## How to Build

The unit-tests are built, run, and reported on for coverage by way of `cmake`.

The top-level [Makefile](Makefile) is not a product of `cmake`. The default
target
  - generates a directory, `build`,
  - properly invokes `cmake` therein so that the test-code can be built, run,
    and reported on for covereage.

To get started:

```
$ make build
$ cd build
$ make tests_cov
```

After that, products of the coverage-analysis end up in
  - `build/tests_cov.txt` and
  - `build/tests_cov.html`.

