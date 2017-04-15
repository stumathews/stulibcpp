/* 
* Basic header file for libstucpp 
*/
#ifndef LIBSTUCPP_H
#define LIBSTUCPP_H
#include <config.h>

#ifdef _WIN32
#define LIBRARY_API __declspec(dllexport)
#endif

#ifndef LIBRARY_API
# define LIBRARY_API    extern
#endif

#ifdef __cplusplus

// Note: This allows names to be exported as-is as thus callable from various compilers
// if not in a Extern C block, named are exported mangabled in a compiler specific way
// meaning only those compilers will be able to call those names/functions
extern "C" {
#endif

LIBRARY_API void test();

#ifdef __cplusplus
}
#endif

// Example of a compiler specific manged name candidate(see http://www.mingw.org/wiki/sampledll):
class TestClass
{
public:
	TestClass(){}
	LIBRARY_API void one();
};

#endif
