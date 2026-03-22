#include <iostream>
 #include <stdlib.h>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#include "MyCircle.h"

using namespace std;

void crash_memory();

int main()
{
	try
	{
		int npt, r;
		cout << "Enter number of points and radius r: ";
		cin >> npt >> r;
		MyCircle circle(npt, r);
		circle.Prepare(); //stwórz punkty równomiernie umieszczone na okrêgu
		circle.disp(); //wyœwietli te punkty
	}
	 catch (std::bad_alloc)
	{
		crash_memory();
	}
	
	if (_CrtDumpMemoryLeaks())
	{
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Memory leaks detected! \ n";
	}
	else
	{
		cout << "No memory leaks detected. \ n";
	}

	return 0;
}

void crash_memory()
 {
	cout << "mem_alloc_err \ n";
	 system("pause");
}