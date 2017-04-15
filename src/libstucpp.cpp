#include <iostream>
#include <libstucpp.h>
using namespace std;

LIBRARY_API void test() 
{
	cout << "libstucpp test" << endl;

}

void TestClass::one()
{
	cout << "one from class" << endl;
}
