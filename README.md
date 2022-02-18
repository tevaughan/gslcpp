# gslcpp

C++-library wrapping portions of GSL and providing interoperability with Eigen.
  - The initial portions of GSL wrapped by this library will be
    - GSL's vector and
    - GSL's minimization-routines (which depend on GSL's vector).
  - Interoperability with Eigen will provided for GSL's vector (and, eventually
    for GSL's matrix).
  - A version of `clang++` capable of compiling C++-20 is required to build
    unit-tests.
    - `clang++-10` or later is known to work.
    - `clang++` (as opposed to `g++`) is required because of the tooling used
      here for coverage-analysis.

## Documentation

The source for the page that you are viewing now is the [README.md][0]
at the top of the source-tree.  It is rendered on-line
  - at the top-level directory of [the github-project][1] and
  - as the [main page of the Doxygen-generated documentation][2].

[0]: https://github.com/tevaughan/gslcpp/blob/main/README.md
[1]: https://github.com/tevaughan/gslcpp
[2]: https://tevaughan.github.io/gslcpp/index.html

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

### Unit-Tests

The unit-tests are built, run, and reported on for coverage by way of `cmake`.

`clang++-10` or later will work, but `clang++-12` is recommended.
- [Makefile](Makefile) calls out near the top the default `clang` and `clang++`.
- Edit [Makefile](Makefile), if necessary, to specify a version.
- Note that, for coverage-analysis, my cmake-script requires that, if
  specified, the version of `clang` must be provided by a numeric suffix on the
  executable.

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

### Generating Documentation

In order to build the documentation, one needs `Doxygen` with version at least
1.9.2 (to support concepts in C++20) and linked against `clang`. In order to
build `Doxygen` from source against `clang-12`, one might first, for example,
do
```
apt install flex bison graphviz libclang12-dev
```
on a machine like Debian or Ubuntu.

After unpacking `Doxygen`'s source and changing into a build-directory just
under the top-level of the source-tree, do
```
cmake -DClang_DIR:PATH=/usr/lib/cmake/clang-12 -Duse_libclang=YES -G "Unix Makefiles" ..
```
on a unix-like machine.

After `Doxygen` has been installed, one can then, from the top-level of
`gslcpp`'s tree, do
```
make doc
```

After that, products of the `Doxygen`-build end up in the local copy under
  - `docs/html`.

Every push to the repository causes a [github-action][3] to regenerate the
[github-pages site][2].  The rule for this action is [here][4].

[3]: https://github.com/features/actions
[4]: https://github.com/tevaughan/gslcpp/blob/main/.github/workflows/doxygen-gh-pages.yml

