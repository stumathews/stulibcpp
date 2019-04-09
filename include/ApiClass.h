// ApiClass.h
// Interface for all API Calls
#include "stucpp_export.h"
#include "Timing.h"

using namespace Api;
using namespace std;

/*
 The main entry point of the API. This is a convienience class that wraps all the functionality that the API provides.
 This is useful becauase it ties all the functionality in one place so that it can be provided uniformly to another language API
 such as the C API
*/
class STUCPP_EXPORT CppApi 
{
public:
   CppApi();
   ~CppApi();

   /* General frunctions */
   int add(int a, int b);
   int sub(int a, int b);

   /* Timing functions */
   double GetDurationOfIn(void (*function)(), InDuration duration);

public:
	TimingApi TimingFunctions;
};
