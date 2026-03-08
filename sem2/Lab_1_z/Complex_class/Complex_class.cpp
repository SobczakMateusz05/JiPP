// Complex_class.cpp : Defines the entry point for the console application.
//  lab_1

#include "stdafx.h"
#include <iostream>
using namespace std;

//class MY_POINT reprezents a point on the plain.
class MY_POINT
{
	double coord[2];  //coord[0] - x; coord[1] - y
public:
	MY_POINT() { memset((void *)coord, 0, sizeof(coord)); }  //default constructor
	MY_POINT(double xx, double yy) { coord[0] = xx; coord[1] = yy; }  //parameterized constructor
	void disp() { cout << " x = " << coord[0] << " y = " << coord[1] << endl; }
	void set(double xx, double yy) { coord[0] = xx; coord[1] = yy; }
};

//class MY_LINE represents a line on the plain
class MY_LINE
{
	MY_POINT PointStart;  //begin point
	MY_POINT PointEnd;    //end point
public:
	MY_LINE(MY_POINT start, MY_POINT end) : PointStart(start), PointEnd(end) {} //parameterized constructor
	void disp(char *str);
};

//------------Implementatiob of MY_LINE------------------

void MY_LINE::disp(char *str)
{
	cout << str << endl;
	cout << "begin : ";
	PointStart.disp();
	cout << "end   : ";
	PointEnd.disp();
}

//Create the class Triangle which defines the triangle on the plain using three vertices


int _tmain(int argc, _TCHAR* argv[])
{
	MY_POINT pt_begin(0, 0);  //create the beginning point of the line using a parameterized constructor
	MY_POINT pt_end;	      //create the ending point of the line using a default constructor
	pt_end.set(1, 2);         //put coordinates to ending point
	MY_LINE line_1(pt_begin, pt_end); //create line using a parameterized constructor
	line_1.disp("line 1");

	//Create points A, B, C as a vertices of triangle

	//Create triangle object and output to screen coordinates of their vertices 

	system("pause");
	return 0;
}

