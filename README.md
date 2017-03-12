RomanCal
========

A Roman number calculator

This is a example project to setup a C/C++ project with autoconf/automake, static/dynamic library, unit test, [continuous integration](http://docs.platformio.org/en/stable/ci/index.html), doxygen doc etc.


COMPILING
---------

Travis | Appveyor | Coverity
------ | -------- | --------
[![romancal Travis Build status](https://travis-ci.org/yhfudev/cpp-romancal.svg?branch=master)](https://travis-ci.org/yhfudev/cpp-romancal) | [![romancal Appveyor Build status](https://ci.appveyor.com/api/projects/status/github/yhfudev/cpp-romancal?branch=master&svg=true)](https://ci.appveyor.com/project/yhfudev/cpp-romancal) | [![Coverity Scan Build Status](https://scan.coverity.com/projects/11753/badge.svg)](https://scan.coverity.com/projects/yhfudev-cpp-romancal)

You need to download the C unit test library [check](https://github.com/libcheck/check.git), or C++ unit test libary [catch](https://github.com/philsquared/Catch.git).

To compile the software from distribution file, try

    ./configure --enable-static --disable-shared --enable-debug --with-libcheck=$(pwd)/../check-0.11.0/
    make

For the developer who want to regenerate the Makefile, try

    autogen.sh

If you want to generate the document of the project, you may need to install following packages:

    doxygen

RUN DEMO
--------

The command line format is

    ./src/romancal <left> <op> <right>

where 'left' and 'right' are the Roman numbers, and 'op' is one of '+', '-'.


RUN TESTS
---------

Run the command to test the Roman Number library:

    make check


