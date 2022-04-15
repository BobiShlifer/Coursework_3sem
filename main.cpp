#include <iostream>
#include "Point.h"
#include "Edge.h"
#include "TestEdge.h"
#include <vector>
#include <fstream>
#include <strstream> // ввод вывод в строку
using namespace std;
void Test()
{
	//TestIsPointInEdge();
	//TestIsEdgeCrossWith();
	/*TestGetEdges();*/
	/*TestIsPointInLine();*/
	TestLineWithEdge();
}

int main(int argc, char* argv[])
{
	char s[1024] = { 0 };
	ostrstream error(s, 1024);
	try {

		if (argc != 3)
		{
			error << "Filename is not set"; 
			throw s;
		}

		ifstream fin(argv[1]);
		if (!fin) {
			error << "The file" << argv[1] << " was not detected";
			throw s;
		}

		ofstream fout(argv[2]);
		if (!fout) {
			error << "The file" << argv[2] << "was not created";
			throw s;
		}

		Point P;
		fin >> P;
		vector<Point> V;
		Polygon R(V);
		fin >> R;
		switch (R.CheckPoint(P)) {
		case CheckPointResponse::EDGE: fout << "Point " << P << " is on the EDGE" << endl;
			break;
		case CheckPointResponse::VERTEX: fout << "Point " << P << " is on the VERTEX" << endl;
			break;
		case CheckPointResponse::OUT: fout << "Point " << P << " is OUT" << endl;
			break;
		case CheckPointResponse::IN: fout << "Point " << P << " is IN" << endl;
			break;
		}
		cout << "Okey!" << endl;
		fin.close();
		fout.close();
	}
	catch (char* str)
	{
		cout << str << endl;
	}
		
	/*Test();*/
	return 0;

}
//cd /d D:\Лабы инфа\Coursework\Debug
//D:\Лабы инфа\Coursework\Debug>Coursework.exe ..\PointAndPolygon.txt ..\Result.txt

