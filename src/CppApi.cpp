// ApiClass.cpp
// Wrapper interface for all library functions. Called into by CApi

//#include "stucpp_export.h"
#include "ApiClass.h"
#include "3d.h"
#include <memory>

using namespace Api;


CppApi::CppApi() 
	: mTimingFunctionsPtr(new Timing()) { }

CppApi::~CppApi() {}
 
int CppApi::add(int a, int b)
{
	return a + b;
}

int CppApi::sub(int a, int b )
{
	return a - b;
}


double CppApi::GetDurationOfIn(void(*function)(), InDuration duration)
{
	return mTimingFunctionsPtr->GetTimeIn(function, duration);
}

