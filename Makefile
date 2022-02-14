
# If necessary, supply version number as in
#
# CC:=clang-11
# CXX:=clang++-11
#
# Use whatever version you like, but probably need at least clang++-10.

CC:=clang
CXX:=clang++

.PHONY : all build clean

all : build

build:
	@if ! test -d build; then\
	  mkdir build && cd build && CC=$(CC) CXX=$(CXX) cmake ..;\
	 fi
	@cd build && make tests_cov

clean :
	@rm -frv build
	@rm -fv default.profraw
	@rm -fv io-test.dat
	@rm -fv output-test.txt

