// CApi.cpp
// Exposes the C interface of API. Note: Uses underlying C++ wrapper ApiClass to service calls.

#include "stucpp_export.h"
#include "ApiClass.h"
#include <iostream>
#include <cstdio>
#include "Timing.h"
CppApi* ptr = 0;

extern "C"
{
	STUCPP_EXPORT void initLib() { ptr = new CppApi(); }
	STUCPP_EXPORT void closeLib() { delete ptr; }
	STUCPP_EXPORT int sub(int a, int b) 
	{
	  return ptr->sub(a,b); 
	}
	STUCPP_EXPORT double GetDurationOfIn(void (*function)(), InDuration duration)
	{
		return ptr->GetDurationOfIn(function, duration);
	}
	
}
