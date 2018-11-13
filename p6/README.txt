Create a makefile that builds 2 items when the user simply types:
    make

First, build a shared object named  p6.so  which contains a function that
can be dynamically linked or loaded:

    double timestamp()

Second, build a program named  p6  which takes command-line arguments.
The number of command-line args may vary from 2 to 4 inclusive, e.g.:

    ./p6  libname funcname [arg1] [arg2]

p6 should dynamically load funcname from the library named libname and
invoke it with the given arguments.  You may assume that LD_LIBRARY_PATH
will be set prior to execution of p6 if necessary.
All arguments to functions, and return values from them, can be assumed
to be of type double.

Sample executions:

    ./p6  libm-2.19.so   sqrt 4.0

    ./p6  libm-2.19.so   pow  4.0  2.0

    export LD_LIBRARY_PATH=.
    ./p6  p6.so  timestamp