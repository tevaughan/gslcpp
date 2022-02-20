
# If necessary, supply version number as in
#
# CC:=clang-11
# CXX:=clang++-11
#
# Use whatever version you like, but probably need at least clang++-10.

CC:=clang
CXX:=clang++

.PHONY : all build_prep clean doc tests_cov

all : tests_cov

tests_cov: build_prep
	@cd build && make tests_cov

doc: build_prep
	@cd build && make doc

build_prep:
	@if ! test -d build; then\
	  mkdir build && cd build && CC=$(CC) CXX=$(CXX) cmake ..;\
	 fi

clean :
	@rm -frv build
	@rm -frv docs/html docs/tests_cov*
	@rm -fv default.profraw
	@rm -fv io-test.dat
	@rm -fv output-test.txt

