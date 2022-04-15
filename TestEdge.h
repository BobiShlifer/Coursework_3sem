#include "Edge.h"
#include "Point.h"
#include "Polygon.h"
#include <iostream>
#include <vector>
using namespace std;

void TestIsPointInEdge()
{
	cout << ((Edge(Point(1, 8), Point(6, 3)).IsPointInEdge(Point(2, 7))) ? "passed" : "failed") << endl;
	/*cout << ((Edge(Point(2, 2), Point(1, 1)).IsPointInEdge(Point(2, 2))) ? "passed" : "failed") << endl;
	cout << ((Edge(Point(3, 1), Point(2, 2)).IsPointInEdge(Point(2, 2))) ? "passed" : "failed") << endl;
	cout << ((Edge(Point(2, 2), Point(3, 1)).IsPointInEdge(Point(2, 2))) ? "passed" : "failed") << endl;*/

	/*cout << Edge(Point(3, 3), Point(1, 1)).IsPointInEdge(Point(2, 2)) << endl;
	cout << Edge(Point(1, 1), Point(3, 3)).IsPointInEdge(Point(1, 1)) << endl;
	cout << Edge(Point(3, 3), Point(1, 1)).IsPointInEdge(Point(1, 1)) << endl;
	cout << Edge(Point(1, 1), Point(3, 3)).IsPointInEdge(Point(3, 3)) << endl;
	cout << Edge(Point(3, 3), Point(1, 1)).IsPointInEdge(Point(3, 3)) << endl;
	cout << Edge(Point(3, 3), Point(1, 1)).IsPointInEdge(Point(0, 0)) << endl;
	cout << Edge(Point(3, 3), Point(1, 1)).IsPointInEdge(Point(4, 4)) << endl;
	cout << Edge(Point(1, 1), Point(3, 3)).IsPointInEdge(Point(0, 0)) << endl;
	cout << Edge(Point(1, 1), Point(3, 3)).IsPointInEdge(Point(4, 4)) << endl;
	cout << ((!Edge(Point(1, 1), Point(3, 3)).IsPointInEdge(Point(4, 4))) ? "passed" : "failed") << endl;*/
	//cout << Edge(Point(0, 0), Point(1, 0)).IsPointInEdge(Point(1, 0)) << endl;

}
void TestIsEdgeCrossWith()
{
	/*cout << ((Edge(Point(0, 1), Point(0, -1)).IsEdgeCrossWith(Edge(Point(-1, 0), Point(1, 0)))) ? "passed" : "failed") << endl;
	cout << ((Edge(Point(1, 1), Point(2, 2)).IsEdgeCrossWith(Edge(Point(2, 1), Point(1, 2)))) ? "passed" : "failed") << endl;
	cout << ((!Edge(Point(3, 3), Point(4, 4)).IsEdgeCrossWith(Edge(Point(2, 1), Point(1, 2)))) ? "passed" : "failed") << endl;
	cout << ((!Edge(Point(1, 1), Point(2, 1)).IsEdgeCrossWith(Edge(Point(1, 2), Point(2, 2)))) ? "passed" : "failed") << endl;
	cout << ((!Edge(Point(1, 1), Point(2, 1)).IsEdgeCrossWith(Edge(Point(3, 1), Point(4, 1)))) ? "passed" : "failed") << endl;*/
	/*cout << ((Edge(Point(1, 1), Point(2, 2)).IsEdgeCrossWith(Edge(Point(2, 2), Point(3, 1)))) ? "passed" : "failed") << endl;*/
	cout << ((Edge(Point(0, 0), Point(1, 0)).IsEdgeCrossWith(Edge(Point(1, 1), Point(1, 0)))) ? "passed" : "failed") << endl;
}

void TestGetEdges()
{
	Point a(0, 0);
	Point b(1, 0);
	Point c(0, 1);
	vector<Point> points;
	points.push_back(a);
	points.push_back(b);
	points.push_back(c);
	Polygon P(points);
	vector<Edge> Edges = P.GetEdges();
	cout << ((Edges[0] == Edge(a, b)) ? "passed" : "failed") << endl;
	cout << ((Edges[1] == Edge(b, c)) ? "passed" : "failed") << endl;
	cout << ((Edges[2] == Edge(c, a)) ? "passed" : "failed") << endl;

}

void TestIsPointInLine ()
{
		//cout << ((Edge(Point(10, 0), Point(4, 0)).IsPointInLine(Point(7, 0))) ? "passed" : "failed") << endl;
		cout << ((Edge(Point(1, 8), Point(6, 3)).IsPointInLine(Point(2, 7))) ? "passed" : "failed") << endl;

}

void TestLineWithEdge()
{
	Point A(4, -1);
	Point B(6, 9);
	Point C(1, 8);
	Point D(9, 6);
	Point E(2, 7);
	Point F(4, 3);
	Point G(7, 0);

	Point p1(4, 0);
	Point p2(6, 3);
	Point p3(1, 8);
	Point p4(6, 11);
	Point p5(12, 6);
	Point p6(10, 0);
	


	vector<Point> points;

	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);
	points.push_back(p4);
	points.push_back(p5);
	points.push_back(p6);


	Polygon polygon(points);
	
	cout << ((polygon.CheckPoint(A) == CheckPointResponse::OUT) ? "passed" : "failed") << endl;
	/*cout << ((polygon.CheckPoint(B) == CheckPointResponse::IN) ? "passed" : "failed") << endl;
	cout << ((polygon.CheckPoint(C) == CheckPointResponse::VERTEX) ? "passed" : "failed") << endl;
	cout << ((polygon.CheckPoint(D) == CheckPointResponse::IN) ? "passed" : "failed") << endl;
	cout << ((polygon.CheckPoint(E) == CheckPointResponse::EDGE) ? "passed" : "failed") << endl;
	cout << ((polygon.CheckPoint(F) == CheckPointResponse::OUT) ? "passed" : "failed") << endl;
	cout << ((polygon.CheckPoint(G) == CheckPointResponse::EDGE) ? "passed" : "failed") << endl;*/
	cout << "-------------------------------------" << endl;
	/*Point A1(13, 4);
	Point B1(13, 3);
	Point C1(13, 2);

	Point p31(15, 2);
	Point p11(11, 2);
	Point p21(13, 4);

	vector<Point> point;
	point.push_back(p11);
	point.push_back(p21);
	point.push_back(p31);

	Polygon polygo(point);

	cout << ((polygo.CheckPoint(A1) == CheckPointResponse::VERTEX) ? "passed" : "failed") << endl;
	cout << ((polygo.CheckPoint(B1) == CheckPointResponse::IN) ? "passed" : "failed") << endl;
	cout << ((polygo.CheckPoint(C1) == CheckPointResponse::EDGE) ? "passed" : "failed") << endl;

	Point A2(1, 2);
	Point B2(2, 1);
	

	Point p20(1, 1);
	Point p22(1, 3);
	Point p23(3, 3);
	Point p24(3, 1);

	vector<Point> pointor;
	pointor.push_back(p20);
	pointor.push_back(p22);
	pointor.push_back(p23);
	pointor.push_back(p24);

	Polygon polygot(pointor);
	cout << ((polygot.CheckPoint(A2) == CheckPointResponse::EDGE) ? "passed" : "failed") << endl;
	cout << ((polygot.CheckPoint(B2) == CheckPointResponse::EDGE) ? "passed" : "failed") << endl;
	*/


	////Point B(6, 1.25);

	//Point b1(1, 1);
	//Point b2(1, 2);
	//Point b3(2, 2);
	//Point b4(2, 1);

	//vector<Point> point;
	//point.push_back(b1);
	//point.push_back(b2);
	//point.push_back(b3);
	//point.push_back(b4);
	//cout << ((polygon.CheckPoint(B) == CheckPointResponse::OUT) ? "passed" : "failed") << endl;
}
