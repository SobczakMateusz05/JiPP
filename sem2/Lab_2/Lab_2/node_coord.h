#pragma once

class NODE_COORD
{
	double* pcoord; //pcoord[0] - x, pcoord[1] - y
public:
	NODE_COORD() : pcoord(NULL) {} //default constructor
	NODE_COORD(double x, double y); //parameterized constructor
	NODE_COORD(const NODE_COORD& ob); // copy constructor
	NODE_COORD(NODE_COORD&& ob); // move constructor
	~NODE_COORD(); //destructor
	void disp(); //output x, y to screen
private:
	void crash(); // handles memory allocation error
};
