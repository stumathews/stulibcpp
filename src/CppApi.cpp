// ApiClass.cpp
// Wrapper interface for all library functions. Called into by CApi

//#include "stucpp_export.h"
#include "ApiClass.h"
#include "3d.h"
#include <memory>
#include <iostream>
#include <ostream>
using namespace Api;

static int sequenceNumber = 0;


CppApi::CppApi() 
	: TimingFunctions(TimingApi()) 
{
	
	std::cout << sequenceNumber++ << " CppApi() called." <<  std::endl;
}

CppApi::~CppApi() {
	std::cout << sequenceNumber++ << " ~CppApi() called." << std::endl;
}
 
int CppApi::add(int a, int b) { return a + b; }

int CppApi::sub(int a, int b ) { return a - b; }


double CppApi::GetDurationOfIn(void(*function)(), InDuration duration)
{
	return TimingFunctions.GetTimeIn(function, duration);
}

