#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point
{
private:
	double x, y;
public:
	Point(double x = 0, double y = 0);
	Point(Point const& p);
	Point& operator = (Point p);
	friend std::ostream& operator << (std::ostream& out, const Point& p);
	friend std::istream& operator >> (std::istream& in, Point& p);  
	double GetX() const;
	double GetY() const;
	bool operator == (const Point& p);
};
#endif