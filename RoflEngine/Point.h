#pragma once
#include <iostream>

namespace fi{
	class Point{
	public:
		Point();
		Point(double x, double y);
		Point& operator+(const Point& b);
		Point& operator-(const Point& b);
		Point& operator*(const double b);
		Point& operator/(const double b);
		double getX();
		double getY();
		void setX(double x);
		void setY(double y);
		void setPosition(double x, double y);
		friend std::ostream& operator<< (std::ostream& stream, const Point& p);
	private:
		double x;
		double y;
	};
}