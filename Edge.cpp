#include "Edge.h"
#include <iostream>
#include "Equal.h"

using namespace std;
Edge::Edge(Point a, Point b) : a(a), b(b) {}
Edge::Edge(Edge const& e) : a(e.a), b(e.b) {}
Edge& Edge::operator = (Edge e) 
{
	if (&e == this)
		return *this;
	a = e.a;
	b = e.b;
	return *this;
}

std::ostream& operator << (std::ostream& out, const Edge& e)
{
	out << e.a << " - " << e.b;
	return out;
}

bool Edge::IsPointInLine(const Point& p) const
{
	if (is_equal(a.GetX(), b.GetX()))
		return is_equal(p.GetX(), a.GetX()); 
	if (is_equal(a.GetY(), b.GetY()))
		return is_equal(p.GetY(), a.GetY());
	return is_equal(((p.GetX() - a.GetX()) / (b.GetX() - a.GetX())), ((p.GetY() - a.GetY()) / (b.GetY() - a.GetY())));

}

bool Edge::IsPointInEdge(const Point& p) const
{
	if (is_equal(a.GetY(), b.GetY()))
		return ((b.GetX() < p.GetX() || is_equal(b.GetX(), p.GetX())) && (p.GetX() < a.GetX())) ||
		((a.GetX() < p.GetX() || is_equal(a.GetX(), p.GetX())) && (p.GetX() < b.GetX()));
	return 	(((b.GetY() < p.GetY() || is_equal(b.GetY(), p.GetY())) && (p.GetY() < a.GetY())) ||
		((a.GetY() < p.GetY() || is_equal(a.GetY(), p.GetY())) && (p.GetY() < b.GetY())));
}

bool Edge::IsEdgeCrossWith(const Edge& e)
{
	double x1 = a.GetX();
	double x2 = b.GetX();
	double x3 = e.a.GetX();
	double x4 = e.b.GetX();

	double y1 = a.GetY();
	double y2 = b.GetY();
	double y3 = e.a.GetY();
	double y4 = e.b.GetY();

	double A = y1 - y2;
	double B = x2 - x1;
	double C = x1 * y2 - x2 * y1;
	double D = y3 - y4;
	double E = x4 - x3;
	double F = x3 * y4 - x4 * y3;

	double x = (B * F - C * E) / (A * E - D * B); 
	double y = (A * F - C * D) / (B * D - E * A);
	Point p(x, y);
	return IsPointInEdge(p) && e.IsPointInEdge(p); 
}
bool Edge::operator==(Edge e)
{
	return ((a == e.a) && (b == e.b)) || ((e.a == b) && (e.b == a));
}