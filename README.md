# Header-Only C++-Library Wrapping GNU Scientific Library

`gslcpp` is a header-only, modern C++-library intended to wrap all of GSL.
  - The first release covers functions and types related to `gsl_vector`.
  - The second release will cover multidimensional minimization.
  - The third release will cover `gsl_matrix` and expand the capabilities of
    vectors by way of integration with [Eigen](https://eigen.tuxfamily.org).
  - I have not yet planned further ahead.

## Products of Github Action

- [Documentation via Doxygen][doxy]

- Code-Coverage after Running Unit-Tests
  - [Summary][summary]
  - [Details][details]

[doxy]: https://tevaughan.github.io/gslcpp/html/index.html
[summary]: https://tevaughan.github.io/gslcpp/tests_cov-summary.txt
[details]: https://tevaughan.github.io/gslcpp/tests_cov.html

Every push to the repository causes a [github-action][3] to regenerate the
[github-pages site][pages].  The rule for this action is [here][4].

[pages]: https://tevaughan.github.io/gslcpp/index.html
[3]: https://github.com/features/actions
[4]: https://github.com/tevaughan/gslcpp/blob/main/.github/workflows/doxygen-gh-pages.yml

## Status

The first release is done.

Next up will be support for multidimensional miminization.

## How to Build

A compiler for C++-17 or later is required to use `gslcpp`.
  - `gslcpp` is a header-only library.
  - The only dependencies are Eigen and GSL.
  - Because Eigen is also a header-only library, the requirements for linking
    are the same as those for GSL.

By default, `gslcpp` assumes that the installed version of GSL is at least 2.5
and that the installed version of Eigen is at least 3.3.  But each of these can
be set by way of
  - `-DGSL_MAJOR=<integer>`
  - `-DGSL_MINOR=<integer>`
  - `-DEIGEN_MAJOR=<integer>`
  - `-DEIGEN_MAJOR=<integer>`

See [CMakeLists.txt][CMakeLists.txt] at the top level of `gslcpp`'s tree for
examples of how to detect and to set these version-numbers on the basis of what
is installed on the system.

`gslcpp` provides an interface with all of the features of GSL-2.7 (for
functionality that is covered). If GSL-2.5 be installed, the extra functions
for vectors are emulated by way of Eigen.

[CMakeLists.txt]: https://github.com/tevaughan/gslcpp/blob/main/CMakeLists.txt

### Unit-Tests

`clang++` is required to build the unit-tests.
  - `clang++-10` or later is known to work.
  - `clang++` is required because the build-system uses `llvm-cov` for
    coverage-analysis performed when running the unit-tests.

The unit-tests are built, run, and reported on for coverage by way of `cmake`.
  - [Makefile][Makefile] calls out near the top the default `clang` and `clang++`.
  - Edit [Makefile][Makefile], if necessary, to specify a version.
  - Note that, for coverage-analysis, the cmake-script requires that, if
    specified, the version of `clang++` must be provided by a numeric suffix
    (for example, `clang++-12`) on the name of the executable.

[Makefile]: https://github.com/tevaughan/gslcpp/blob/main/Makefile

[Makefile][Makefile] at the top is not a product of `cmake`. The default target
  - generates a directory, `build`,
  - invokes `cmake` therein, and
  - invokes the generated file, `build/Makefile`
    - to build the tests for coverage-analysis,
    - to run them, and
    - to build the reports of coverage.

To get started, just run
```
make
```
at the top of the tree.

After that, products of the coverage-analysis end up in
  - `docs/tests_cov-summary.txt`,
  - `docs/tests_cov.txt`, and
  - `docs/tests_cov.html`.

### Generating Documentation

In order to build the documentation, one needs `Doxygen`.  Either install the
package from the operating system, or build it from source in case one want a
version newer than that provided by the operating system.

#### Building Doxygen from Source

In order to build `Doxygen` from source against, say, `clang-12`, one might
first, for example, do
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

#### Using Doxygen

After `Doxygen` has been installed, one can then, from the top-level of
`gslcpp`'s tree, do
```
make doc
```

After that, products of the `Doxygen`-build end up in the local copy under
`docs/html`.

