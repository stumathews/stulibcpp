#pragma once
#include "stucpp_export.h"

enum InDuration { Seconds, MilliSeconds, NanoSeconds };

namespace Api {

	
	class STUCPP_EXPORT Timing
	{
	public:
		Timing(){};
		~Timing(){};
		/* Measures the number of nano seconds it takes the run the provided code */
		   double GetTimeIn(void (*functionToMeasure)(), InDuration inDuration);
	};
}

