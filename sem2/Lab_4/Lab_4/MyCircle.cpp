#include <iostream>
#include "node_coord.h"
#include "MyCircle.h"
#define _USE_MATH_DEFINES
#include "math.h"

MyCircle::MyCircle(int npt, double radius) {
	nopoints = npt;
	r = radius;
	ptr = new NODE_COORD[npt];
}

MyCircle::~MyCircle() {
	delete[] ptr;
}

void MyCircle::Prepare() {
	double pi = M_PI;

	for (int i = 0; i < nopoints; i++) {
		double fi = 2 * pi * i / nopoints;
		double x = r * cos(fi);
		double y = r * sin(fi);

		ptr[i].set(x, y);
	}
}

void MyCircle::disp() {
	for (size_t i = 0; i < nopoints; i++) {
		ptr[i].disp();
	}
}