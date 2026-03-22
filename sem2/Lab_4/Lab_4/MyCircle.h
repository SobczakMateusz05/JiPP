#pragma once

#include "node_coord.h"

class MyCircle {
	NODE_COORD* ptr;
	int nopoints;
	double r;
public:
	MyCircle(int npt, double radius);
	~MyCircle();
	void Prepare();
	void disp();
};
