#include <iostream>
#include <libstucpp.h>
using namespace std;

LIBRARY_API void test() {}

LIBRARY_API void TestClass::one()
{
	cout << "TestClass::one()" << endl;
}
