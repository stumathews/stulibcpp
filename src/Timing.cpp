#include "Timing.h"
#include <chrono>
#include <functional>

using namespace Api;
using namespace std;

/*
	Determines how long the provided function ran for
*/

double Api::Timing::GetTimeIn(void (*functionToMeasure)(), InDuration inDuration)
{
	auto start = std::chrono::high_resolution_clock::now();
	functionToMeasure();	
	auto finish = std::chrono::high_resolution_clock::now();
	double elapsed;
	switch(inDuration)
	{
	case InDuration::Seconds:
		elapsed = chrono::duration_cast<chrono::seconds>(finish - start).count();
		break;
	case InDuration::MilliSeconds:
		elapsed = chrono::duration_cast<chrono::milliseconds>(finish - start).count();
		break;
	case InDuration::NanoSeconds:
		elapsed = chrono::duration_cast<chrono::nanoseconds>(finish - start).count();
		break;		
	}	
	return elapsed;
}