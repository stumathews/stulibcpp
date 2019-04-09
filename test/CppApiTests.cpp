// basic.cpp
// Basic smoke tests. Uses the C++ Classes in the library

#include <iostream>
#include "ApiClass.h"
#include "basic.h"
#include "Timing.h"
#include "3d.h"
#include <cassert>
#include <memory>

using namespace std;

void ThreeDTests();
void TestSharedPointers();

int main(int argc, char** argv)
{
	cout << "CppApiTests Commencing..." << std::endl;
	CppApi api;

	TestSharedPointers();
	TestApiFunctions(api);
	TestTimingFunctions(api);
	ThreeDTests();
	
}

void TestSharedPointers()
{
	unique_ptr<ThreeDimensional::Point> pInt(new ThreeDimensional::Point(1,2,3));	
}

void ThreeDTests(){
	cout << "Running 3D Tests..." << std::endl;
	ThreeDimensional::Point point(1,2,3);
	assert( point.GetX() == 1);
	assert( point.GetY() == 2);
	assert( point.GetZ() == 3);
	
	
	
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

