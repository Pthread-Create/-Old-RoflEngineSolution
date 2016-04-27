#include "Segment.h"
#include <iostream>

#define EPS 1.0E-40

fi::Segment::Segment(fi::Point &a, fi::Point &b) : a(&a), b(&b){
}

fi::Point* fi::Segment::intersect(fi::Segment & b){
	double ax = this->a->getX();
	double ay = this->a->getY();
	double bx = this->b->getX();
	double by = this->b->getY();
	double cx = b.a->getX();
	double cy = b.a->getY();
	double dx = b.b->getX();
	double dy = b.b->getY();
	double bax = bx - ax;
	double bay = by - ay;
	double dcx = dx - cx;
	double dcy = dy - cy;
	double autre = bax * dcy - bay * dcx;
	if(autre*autre <= EPS)
		return nullptr;
	bool bl = autre < 0.0;
	double autre2 = bay * (cx - ax) + bax * (ay - cy);
	if(bl){
		autre = -autre;
		autre2 = -autre2;
	}
	if(autre2 <= EPS || autre2 >= autre - EPS){
		return nullptr;
	}
	autre2 = dcy * (cx - ax) + dcx * (ay - cy);;
	if(bl){
		autre2 = -autre2;
	}
	if(autre2 <= EPS || autre2 >= autre - EPS){
		return nullptr;
	}
	return new fi::Point(bax * (autre2 /= autre) + ax, bay * autre2 + ay);
}

std::ostream & fi::operator<<(std::ostream & stream, const Segment & s){
	stream << "[" << *s.a << "," << *s.b << "]";
	return stream;
}
