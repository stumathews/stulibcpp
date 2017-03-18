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
extern "C" {
#endif

LIBRARY_API void test();

#ifdef __cplusplus
}
#endif

class TestClass
{
public:
	TestClass(){}
	LIBRARY_API void one();
};

#endif
