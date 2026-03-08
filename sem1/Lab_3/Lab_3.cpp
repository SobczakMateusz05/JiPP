// Lab_3.cpp : Defines the entry point for the console application.
// Obliczyc sume pierwszych n skladowych ciagu arytmetycznego

#include "stdafx.h"
#include <stdlib.h>
#include <math.h>

void input_data(int * p_n, double * p_a, double *p_d);
void outp_res(double S, double S1, double err);
double GetSum(double a, double d, int n);
double GetSum1(double a, double d, int n);


int main()
{
	double a, d, Sum, S;  //a - pierwsza składowa szeregu, d - roznica ciagu, Sum oraz S - sumy ciagu
	int n;                //ilosc skladowych.
	double err;

	input_data(&n, &a, &d);
	S = GetSum(a, d, n);
	Sum = GetSum1(a, d, n);
	err = fabs(S - Sum);
	outp_res(S, Sum, err);

	system("pause");

    return 0;
}

void input_data(int * p_n, double * p_a, double *p_d)
{
	printf_s("Input n, a, d\n");
	int ret = scanf_s("%d%lf%lf", p_n, p_a, p_d);
	if (ret != 3)
	{
		printf("blad!\n");
		exit(1);
	}
}

void outp_res(double S, double S1, double err)
{
	printf_s("S = %le\n", S);
	printf_s("S1 = %le\n", S1);
	printf_s("err = %le\n", err);
}

double GetSum(double a, double d, int n)
/*======================================================================
Szereg arytmetyczny:  a(i+1) = a(i) + d
Sn = a1 + a2 + ... + an
========================================================================*/
{
	int i;
	double retval = a;   //S1 = a
	double tmp = a;      //a(1) = a

	for (i = 0; i < n-1; ++i)
	{
		tmp += d;  //a(i+1) = a(i) + d
		retval += tmp;  //S(i+1) = S(i) + a(i+1)
	}

	return retval;
}

double GetSum1(double a, double d, int n)
/*=========================================================
a(2) = a(1) + d
a(3) = a(2) + d = a(1) + 2*d
a(4) = a(3) + d = a(1) + 3*d
...............................
a(n) = a(1) + (n - 1)*d
Sn = (a(1) + a(n))*n/2.0;
=============================================================*/
{
	double last_a = a + (n - 1)*d;
	return (a + last_a) / 2.0*n;
}

