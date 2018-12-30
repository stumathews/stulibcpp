#include "stucpp_export.h"
#include "ApiClass.h"

#include <iostream>
#include <cstdio>
ApiClass* ptr = 0;

extern "C"
{
  STUCPP_EXPORT void initLib() { ptr = new ApiClass(); }
  STUCPP_EXPORT void closeLib() { delete ptr; }
  STUCPP_EXPORT int sub(int a, int b) {
	  printf("calling sub in C API...\n");
	  return ptr->sub(a,b); 
  }
}
