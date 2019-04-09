#ifndef THREED_H
#define THREED_H
#include "2d.h"
#include <iostream>
#include <string>
#include "stucpp_export.h"

namespace ThreeDimensional 
{
	class Point : public TwoDimensional::Point
	{
		friend std::ostream& operator<<(std::ostream&, const ThreeDimensional::Point&);
	public:
		Point(): TwoDimensional::Point() 
		{
			std::cout << "ThreeDimensional::Point() called" << std::endl;
		}
		Point(float x, float y, float z) : TwoDimensional::Point(x, y), z(z) 
		{
			this->z = z;
		};

		~Point()
		{
			std::cout << "ThreeDimensional::Point~() called" << std::endl;
		}
	
		float GetZ() const { return this->z; }
		void SetZ(float z) { this->z = z; }
		
		Point operator+(const Point& point2) const
		{
			Point temp;
				temp.SetX(GetX() + point2.GetX());
				temp.SetY(GetY() + point2.GetY());
				temp.SetZ(this->z + point2.z);
			return temp;
		}
	private:
		float z;
	};
}

#endif
