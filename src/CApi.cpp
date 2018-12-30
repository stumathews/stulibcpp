// CApi.cpp
// Exposes the C interface of API. Note: Uses underlying C++ wrapper ApiClass to service calls.

#include "stucpp_export.h"
#include "ApiClass.h"
#include <iostream>
#include <cstdio>

ApiClass* ptr = 0;

extern "C"
{
	STUCPP_EXPORT void initLib() { ptr = new ApiClass(); }
	STUCPP_EXPORT void closeLib() { delete ptr; }
	STUCPP_EXPORT int sub(int a, int b) 
	{
	  return ptr->sub(a,b); 
	}
}
