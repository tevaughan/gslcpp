
.PHONY : all build clean

all : build

build:
	@rm -fr build
	@mkdir build
	@(cd build; CXX=clang++ cmake ..)

clean :
	@rm -frv build

