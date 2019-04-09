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
		std::cout << "here " << std::endl;
		float denominator = GetX();
		std::cout << "got x " << std::endl;
		if(denominator == 0 ) { throw std::exception("Can't devide by zero!"); };
	       	return GetY() / denominator; 
	};
