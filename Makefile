
# If necessary, supply version number as in
#
# CC:=clang-13
# CXX:=clang++-13
#
# Use whatever version you like, but probably need at least clang++-10.

CC:=clang
CXX:=clang++

VER:=$(patsubst clang++-%,%,$(CXX))
CLANG_FORMAT:=$(if $(VER),clang-format-$(VER),clang-format)

.PHONY : all build_prep clean doc format tests_cov

all : tests_cov

tests_cov: build_prep
	@cd build && make tests_cov

doc: build_prep
	@cd build && make vector-example.out && make vector-view-example.out
	@cd build && make doc

build_prep:
	@if ! test -d build; then\
	  mkdir build && cd build && CC=$(CC) CXX=$(CXX) cmake ..;\
	 fi

format:
	find . -name '*.hpp' -exec $(CLANG_FORMAT) -i {} \;

clean :
	@rm -frv build
	@rm -frv docs/html docs/tests_cov* docs/examples
	@rm -fv default.profraw
	@rm -fv io-test.dat
	@rm -fv output-test.txt

