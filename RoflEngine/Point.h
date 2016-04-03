#pragma once
#include <iostream>

namespace fi{
	class Point{
	public:
		Point(int x, int y);
		Point& operator+(const Point& b);
		Point& operator-(const Point& b);
		Point& operator*(const double b);
		Point& operator/(const double b);
		friend std::ostream& operator<< (std::ostream& stream, const Point& p);
	private:
		double x;
		double y;
	};
}