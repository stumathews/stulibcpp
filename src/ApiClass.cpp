// ApiClass.cpp
// Wrapper interface for all library functions. Called into by CApi

//#include "stucpp_export.h"
#include "ApiClass.h"
#include "3d.h"

ApiClass::ApiClass() {}
ApiClass::~ApiClass() {}
 
int ApiClass::add(int a, int b)
{
	return a + b;
}

int ApiClass::sub(int a, int b )
{
	return a - b;
}
