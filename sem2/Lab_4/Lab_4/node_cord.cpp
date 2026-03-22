#include <iostream>;
#include "node_coord.h"

using namespace std;

NODE_COORD::NODE_COORD(double x, double y) {
	pcoord = new double[2];
	set(x, y);
}

NODE_COORD::~NODE_COORD() {
	if (pcoord) {
		delete[] pcoord;
		pcoord = nullptr;
	}
}

void NODE_COORD::set(double x, double y) {
	if (pcoord == NULL) {
		pcoord = new double[2];	
	}

	pcoord[0] = x;
	pcoord[1] = y;
}

void NODE_COORD::disp() {
	if (pcoord) {
		cout << "x: " << pcoord[0] << " y: " << pcoord[1] << endl;
	}
}
