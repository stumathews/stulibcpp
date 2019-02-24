#include <iostream>
#include "3d.h"
#include <cassert>

namespace ThreeDimensional 
{
	std::ostream& operator<<(std::ostream& output, const ThreeDimensional::Point& point)
	{
		output << "(" << point.GetX() << "," << point.GetY() << "," << point.GetZ() << ")" << std::endl;
		return output;
	}
}
int main(int argc, char** argv)
{
	ThreeDimensional::Point point1(1,2,3);
	ThreeDimensional::Point point2(4,5,6);
	ThreeDimensional::Point sum = point1 + point2;

	std::cout << "Point 1 =" << point1 << std::endl << "Point 2=" << point2 << std::endl;
	std::cout << "Point 1 + Point 2 = " << sum << std::endl;
	assert( sum.GetX() == 5);
	assert( sum.GetY() == 7);
	assert( sum.GetZ() == 9);
}
