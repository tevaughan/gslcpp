
.PHONY : all build clean

all : build

build:
	@if ! test -d build; then\
	  mkdir build && cd build && CC=clang CXX=clang++ cmake ..;\
	 fi
	@cd build && make tests_cov

clean :
	@rm -frv build

