#pragma once
#include "stucpp_export.h"


namespace Api {

	enum InDuration { Seconds, MilliSeconds, NanoSeconds };
	class STUCPP_EXPORT Timing
	{
	public:
		Timing(){};
		~Timing(){};
		/* Measures the number of nano seconds it takes the run the provided code */
		   double GetTimeIn(void (*functionToMeasure)(), InDuration inDuration);
	};
}

