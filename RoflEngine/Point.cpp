#include "Point.h"

fi::Point::Point(): x(0.0), y(0.0){
}

fi::Point::Point(double x, double y): x(x), y(y){
}

fi::Point& fi::Point::operator+(const Point& b){
	return fi::Point(this->x + b.x, this->y + b.y);
}

fi::Point & fi::Point::operator-(const Point & b){
	return Point(this->x - b.x, this->y - b.y);
}

fi::Point & fi::Point::operator*(const double b){
	return Point(this->x * b, this->y * b);
}

fi::Point & fi::Point::operator/(const double b){
	return Point(this->x / b, this->y / b);
}

double fi::Point::getX(){
	return this->x;
}

double fi::Point::getY(){
	return this->y;
}

void fi::Point::setX(double x){
	this->x = x;
}

void fi::Point::setY(double y){
	this->y = y;
}

void fi::Point::setPosition(double x, double y){
	this->x = x;
	this->y = y;
}

std::ostream & fi::operator<<(std::ostream & stream, const fi::Point& p){
	stream << "(" << p.x << "," << p.y << ")";
	return stream;
}
