#include "2d.h"
#include <string>
#include <iostream>
#include <exception>

namespace TwoDimensional 
{
	std::ostream& operator<<(std::ostream& output, const TwoDimensional::Point& point)
	{
		output << "(" << point.GetX() << "," << point.GetY()  << ")" << std::endl;
		return output;
	}


}
	float TwoDimensional::Point::GetStdSlope() const 
	{
		float denominator = GetX();
		if(denominator == 0 ) { throw std::exception(); };
	       	return GetY() / denominator; 
	};
