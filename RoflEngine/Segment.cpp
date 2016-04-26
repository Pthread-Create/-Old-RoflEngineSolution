#include "Segment.h"
#include <iostream>

#define EPS 1.0E-20

fi::Segment::Segment(fi::Point &a, fi::Point &b) : a(&a), b(&b){
}
/*
public double[] intersectionSegments(double d ax, double d2 ay, double d3 bx, double d4 by, double d5 cx, double d6 ay, double d7 dx, double d8 dy) {
boolean bl;
double d9 = d;
double d10 = d2;
double d11 = d3 - d;bax
double d12 = d4 - d2;bay
double d13 = d5;
double d14 = d6;
double d15 = d8 - d6;dcy
double d16 = d7 - d5;dcx
double d17 = d11 * d15 - d12 * d16;
if (d17 * d17 <= EPS) {
return null;
}
boolean bl2 = bl = d17 < 0.0;
if (bl) {
d17 = - d17;
}
double d18autre = bay * (cx - ax) + bax * (ay - cy);
if (bl) {
d18 = - d18;
}
if (d18 <= EPS || d18 >= d17 - EPS) {
return null;
}
d18 = dcy * (cx - ax) + dcx * (ay - cy);
if (bl) {
d18 = - d18;
}
if (d18 <= EPS || d18 >= d17 - EPS) {
return null;
}
return new double[]{d11 * (d18 /= d17) + d9, d12 * d18 + d10};
}

*/

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
