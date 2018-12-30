// basic.cpp
// Basic smoke tests. Uses the C++ Classes in the library

#include <iostream>
#include "ApiClass.h"

using namespace std;

int main(int argc, char** argv)
{
	cout << "Basic smoke test started." << endl;
	ApiClass a;
	cout << "Calling ApiClass.add(1,2) = " << a.add(1,2) << endl;
}

