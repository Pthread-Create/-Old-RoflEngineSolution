#include "Point.h"

fi::Point::Point(int x, int y): x(x), y(y){
}

fi::Point& fi::Point::operator+(const Point& b){
	Point temp(this->x + b.x, this->y + b.y);
	return temp;
}

fi::Point & fi::Point::operator-(const Point & b){
	Point temp(this->x - b.x, this->y - b.y);
	return temp;
}

fi::Point & fi::Point::operator*(const double b){
	Point temp(this->x * b, this->y * b);
	return temp;
}

fi::Point & fi::Point::operator/(const double b){
	Point temp(this->x / b, this->y / b);
	return temp;
}

std::ostream & fi::operator<<(std::ostream & stream, const Point & p){
	stream << "(" << p.x << ", " << p.y << ")";
	return stream;
}
