#include <iostream>
#include "Point.h"
#include "Equal.h"

Point::Point(double x, double y) : x(x), y(y) {}
Point::Point(Point const& p) : x(p.x), y(p.y) {}
Point& Point::operator = (Point p) {
	if (&p == this)
		return *this;
	x = p.x;
	y = p.y;
	return *this;
}
std::ostream& operator << (std::ostream& out, const Point& p)
{
	out << "[" << p.x << "," << p.y << "]";
	return out;
}

std::istream& operator >> (std::istream& in, Point& p)
{
	in >> p.x >> p.y;
	return in;
}
double Point::GetX() const
{
	return x;
}

double Point::GetY() const
{
	return y;
}

bool Point::operator == (const Point& p)
{
	return is_equal(x, p.x) && is_equal(y, p.y);
}