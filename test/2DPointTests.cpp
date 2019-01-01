#include <iostream>
#include "2d.h"
#include <cassert>

using namespace TwoDimensional;

void TestSumTwoPoints()
{

	Point twoPoint1(1,20);
	Point twoPoint2(1,40);
	Point twoSum = twoPoint1 + twoPoint2;

	assert( twoSum.GetX() == 2 );
	assert( twoSum.GetY() == 60 );
}

void TestGetStdSlope()
{
	Point p1(0,1);
	Point p2(4,3);

	std::cout << "P1 slope=" << p1.GetStdSlope() << std::endl;
	std::cout << "P2 slope=" << p2.GetStdSlope() << std::endl;
		

}
int main(int argc, char** argv)
{
	TestSumTwoPoints();
	TestGetStdSlope();




}
