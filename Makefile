
.PHONY : all build clean

all : build

build:
	@rm -fr build
	@mkdir build
	@(cd build; CC=clang CXX=clang++ cmake ..)

clean :
	@rm -frv build

