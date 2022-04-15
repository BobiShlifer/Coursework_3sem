#ifndef POLYGON_H
#define POLYGON_H
#include "Point.h"
#include "Edge.h"
#include <vector>
using namespace std;

enum class CheckPointResponse { VERTEX, EDGE, OUT, IN };

class Polygon
{
private:
	vector<Point> points;
public:
	Polygon(vector<Point> points);
	vector<Edge> GetEdges(); 
	double SearchMaxRightX(); 
	CheckPointResponse CheckPoint(Point const& p); 
	friend istream& operator>> (istream& in, Polygon& p);
	friend ostream& operator<< (std::ostream& out, const Polygon& p);

};

#endif POLYGON_H

