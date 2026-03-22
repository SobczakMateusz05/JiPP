#include <iostream>
#include <fstream>
#include "my_vector.h"

using namespace std;

int main() {
	my_vector v1(1, 2, -1), v2(2, 1, 1), res;
	v1.disp("v1");
	v2.disp("v2");
	res = v1 + v2;
	res.disp("v1 + v2");
	my_vector res1 = v1 * v2;
	res1.disp("v1 x v2");
	res1 = v2 * v1;
	res1.disp("v2 x v1");
	cout << "v1 * v2: " << v1 * (&v2) << endl;
	my_vector v3(0, 0, 0);
	cin >> v3;
	v3.disp("v3");
	ofstream my_file("my_output_file.txt");
	if (my_file.is_open())
	{
		my_file << "v1 * v2: " << v1 * (&v2);
		my_file.close();
		system("notepad.exe my_output_file.txt");
	}
	return 0;
}
