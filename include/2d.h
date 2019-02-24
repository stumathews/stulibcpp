#ifndef TWO_D_H
#define TWO_D_H
#include "stucpp_export.h"

namespace TwoDimensional
{
	class STUCPP_EXPORT Point
	{
	
	public:
		Point(): x(0), y(0){}
		Point(float x, float y): x(x), y(y){}
		float GetX() const { return this->x; }
		float GetY() const { return this->y; }
		void SetX(float x) { this->x = x; }
		void SetY(float y) { this->y = y; }

		// Get the ratio aka the slope beteen the rise and the run when using the standard coridinate system, ie Origin at (0,0)
		float GetStdSlope() const;

		// Get the Slope of the line perpendicular to ourselves
		float GetStdPerpSlope() const { return -1 / GetStdSlope(); }

		// Get slope between ourselves an another point2
		float GetStdSlopeWith( const Point& point2 ) { return (point2.GetY() - this->GetY()) / (point2.GetX() - this->GetX()); }

		bool IsPerpToMe(const Point& point2) { return GetStdSlope() * point2.GetStdSlope() == -1 ? true: false;  }

		Point operator+(const Point& point2) const
		{
			Point temp;
				temp.SetX(GetX() + point2.GetX());
				temp.SetY(GetY() + point2.GetY());
			return temp;
		}
	private: 
		float x, y;
	
	};	
}
#endif
