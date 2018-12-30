# libstucpp

Simple C++ cross platform shared library 

to build in 64bit windows: cmake -G "Visual Studio 15 2017 Win64" .

Resources:
https://atomheartother.github.io/c++/2018/07/12/CPPDynLib.html
https://rosettacode.org/wiki/Call_a_function_in_a_shared_library
https://stackoverflow.com/questions/23407808/function-pointers-void-fun-dlsym-lib-fun-how-its-work

# build packages,issue these commands for binary and source redistributables
cpack --config CPackConfig.cmake
cpack --config CPackSourceConfig.cmake
