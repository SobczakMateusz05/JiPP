#include <stdio.h>
#include <math.h>
#include "calc.h"

int main() {
	long double a, b, c, d;

	input(&a, &b, &c, &d);

	calc(a, b, c, d);

	return 0;
}

void input(long double* a, long double* b, long double* c, long double* d) {
	printf_s("Wprowadz a, b, c, d: ");

	scanf_s("%lf%lf%lf%lf", a, b, c, d);
}

void calc(long double a, long double b, long double c, long double d) {
	if (a == 0 || b == 0 || c == 0 || d == 0 || c - d == 0 || a / (b - c) < 0) {
		printf_s("Niepoprawne wartosci");
		return;
	}
	
	double f = ((a + b) / (c - d)) - ((c + d) / a) + b;
	double f1 = a - (sin(b / c + d));
	double f2 = log(a / (b - c)) + d;

	printf_s("f: %lf\n", f);
	printf_s("f1: %lf\n", f1);
	printf_s("f2: %lf\n", f2);
}

