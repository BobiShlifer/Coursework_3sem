#include "Polygon.h"
#include "Edge.h"
#include "Point.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

Polygon::Polygon(vector<Point> points)
{
	this->points = points;
}

vector<Edge> Polygon::GetEdges() 
{ 
	vector<Edge> Edges;
	for (size_t i = 1; i < points.size(); i++)
		Edges.push_back(Edge(points[i], points[i - 1]));
	Edges.push_back(Edge(points[points.size() - 1], points[0]));
	return Edges;
}

double Polygon::SearchMaxRightX()
{
	double m = points[0].GetX();
	for (size_t i = 1; i < points.size(); i++)
		if (points[i].GetX() > m)
			m = points[i].GetX();
	return m;	
}

CheckPointResponse Polygon::CheckPoint(Point const& p)
{
	for (size_t i = 0; i < points.size(); i++)
		if (points[i] == p)
			return CheckPointResponse::VERTEX;
	vector<Edge> Edges = GetEdges();
	for (size_t i = 0; i < Edges.size(); i++)		
		if (Edges[i].IsPointInLine(p) && Edges[i].IsPointInEdge(p))
			return CheckPointResponse::EDGE;	
	Edge line(p, Point(SearchMaxRightX() + 1, p.GetY())); 
	int count = 0;
	for (size_t i = 0; i < Edges.size(); i++)
		if (Edges[i].IsEdgeCrossWith(line))
			count++;
	return (count % 2) ? CheckPointResponse::IN : CheckPointResponse::OUT;
}

istream& operator>> (istream& in, Polygon& p)
{
	while (in) {
		Point P;
		in >> P;
		if (!in)
			break; 
		p.points.push_back(P);
	}
	return in;
}
ostream& operator<< (ostream& out, const Polygon& p)
{
	for (size_t i = 0; i < p.points.size(); i++)
		out << p.points[i];
	return out;
}
