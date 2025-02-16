## To perform tests compile project with cmake

`cmake -G "MinGW Makefiles" ..`

or with explisit specifying g++ as compiller:

`cmake -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ ..`

then

`mingw32-make`