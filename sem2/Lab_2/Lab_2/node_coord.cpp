#include <iostream>
#include "node_coord.h"


using namespace std;

NODE_COORD::NODE_COORD(double x, double y)
{
	try
	{
		pcoord = new double[2];
		pcoord[0] = x;
		pcoord[1] = y;
	}
	catch (bad_alloc)
	{
		crash();
	}
}

NODE_COORD::NODE_COORD(const NODE_COORD& ob) {
	try {
		if (ob.pcoord) {
			pcoord = new double[2];
			memcpy(pcoord, ob.pcoord, 2 * sizeof(double)); // copy ob.pcoord to pcoord 
		}
		else {
			pcoord = NULL;
		}
	}
	catch (bad_alloc) {
		crash();
	}
}

NODE_COORD::NODE_COORD(NODE_COORD&& ob) { // && - pointer but for move constructor
	pcoord = ob.pcoord;
	ob.pcoord = nullptr;
}

void NODE_COORD::crash()
{
	cout << "memory allocation error\n";
	system("pause");
	exit(1);
}

NODE_COORD::~NODE_COORD()
{
	if (pcoord)
	{
		delete[] pcoord;
		pcoord = NULL;
	}
}

void NODE_COORD::disp() {
	if (pcoord) {
		cout << "x = " << pcoord[0] << " y  = " << pcoord[1] << endl;
	}
}