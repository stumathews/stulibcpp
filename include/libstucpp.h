#ifndef LIBSTUCPP_H
#define LIBSTUCPP_H

#define LIBRARY_API	__declspec(dllexport)

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
