// ApiClass.h
// Interface for all API Calls
#include "stucpp_export.h"
#include "Timing.h"

using namespace Api;
using namespace std;

class STUCPP_EXPORT CppApi 
{
public:
   CppApi();
   ~CppApi();

   int add(int a, int b);
   int sub(int a, int b);
   double GetDurationOfIn(void (*function)(), InDuration duration);

public:
	Timing* mTimingFunctionsPtr;
};
