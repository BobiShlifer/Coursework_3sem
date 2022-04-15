#ifndef EDGE_H
#define EDGE_H
#include "Point.h"
#include <iostream>

class Edge
{
private:
	Point a, b;
public:
	Edge(Point a, Point b);
	Edge(Edge const& e);
	Edge& operator = (Edge e);
	friend std::ostream& operator << (std::ostream& out, const Edge& e);
	bool IsPointInEdge(const Point& p) const; 
	bool IsEdgeCrossWith(const Edge& e); 
	bool operator == (Edge e); 
	bool IsPointInLine(const Point& p) const; 

};
#endif

