#include <iostream>
#include "class.h"

using namespace std;

class A;
void fun(A par);
void fun(A* par);
A fun();
void crash();

int main()
{
	try {
		A ob("aaaaa");
		fun(ob);
		fun(&ob);
		A bbb;
		fun(bbb);
		A cc = fun();
		cc.disp();
	}
	catch (bad_alloc) {
		crash();
	}
	
	return 0;
}

void crash() {
	cout << "memory allocation error" << endl;
	exit(1);
}

void fun(A par) {
	par.disp();
}

void fun(A* par) {
	par->disp();
}

A fun() {
	A ob("bbb");
	return ob;
}
