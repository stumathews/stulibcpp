#include <iostream>
#include "ApiClass.h"

using namespace std;

extern int sub(int,int);
extern int closeLib();
extern int initLib();

int main(int argc, char** argv)
{
	cout << "Basic smoke test started." << endl;
	ApiClass a;
	cout << "Calling ApiClass.add(1,2) = " << a.add(1,2) << endl;
}

