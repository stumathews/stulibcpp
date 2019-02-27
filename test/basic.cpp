// basic.cpp
// Basic smoke tests. Uses the C++ Classes in the library

#include <iostream>
#include "ApiClass.h"
#include "basic.h"
#include "Timing.h"

using namespace std;

int main(int argc, char** argv)
{
	CppApi api;

	TestApiFunctions(api);
	TestTimingFunctions(api);
}

void TestApiFunctions(CppApi &api)
{
	cout << "Basic smoke test started." << endl;
	cout << "Calling ApiClass.add(1,2) = " << api.add(1, 2) << endl;
}

void TestTimingFunctions(CppApi &api)
{
	cout << "It took " << api.GetDurationOfIn([]() {
		_sleep(1);
		std::cout << "Sup dog" << std::endl;
	}, MilliSeconds) << " miliseconds to run that." << std::endl;
}

