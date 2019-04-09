#pragma once
#include "stucpp_export.h"
#include <iostream>

enum InDuration { Seconds, MilliSeconds, NanoSeconds };

namespace Api {

	
	class STUCPP_EXPORT TimingApi
	{
	public:
		TimingApi()
		{
			std::cout << "TimingApi() called" << std::endl;
		};
		~TimingApi()
		{
			std::cout << "~TimingApi() called" << std::endl;
		};
		typedef void(*VoidReturningFunctionWithNoArgs)();
		/* Measures the number of nano seconds it takes the run the provided code */
		double GetTimeIn(VoidReturningFunctionWithNoArgs fn, InDuration inDuration);
	};
}

