#pragma once

class NODE_COORD
{
	double* pcoord; //pcoord[0] - x, pcoord[1] - y
public:
	NODE_COORD() : pcoord(NULL) { std::cout << "default constructor: NODE_COORD\n"; }
	NODE_COORD(double x, double y); //parameterized constructor
	~NODE_COORD(); //destructor
	void set(double x, double y); //set x, y coordinates
	void disp(); //display x, y coordinates on screen
};
