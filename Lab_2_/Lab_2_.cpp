// Lab_2_.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include "my_incl.h"

int main()
{
	int i;
	double a;
	char str[20];

#ifdef UZYWAMY_BEZPIECZNE_FUNKCJE_ODCZYTU
	fun_inp_s(&i, &a, str, sizeof(str));
#else
	fun_inp(&i, &a, str);
#endif

	fun_print(i, a, str);

	system("pause");
	return 0;
}

#ifdef UZYWAMY_BEZPIECZNE_FUNKCJE_ODCZYTU

	int fun_inp_s(int *p_i, double *p_a, char *str, unsigned int sz_str)
	/*===========================================================================
	Wczytuje dane z monitoru. Kontroluje nie przekroczenie rozmiaru wiersza str.
		 p_i    - wskaznik do int
		 p_a    - wskaznik do double
		 str    - wiersz tekstowy
		 sz_str - ilosc pozycji w str razem z \0.

	RetVal - 0 - OK, !0 - blad.
	============================================================================*/
	{
		int k;
		char format[64];

		printf("podaj int, double\n");

		//Wczytujemy int, double. scanf_s tu dzila dokladnie tak samo, jak i scanf z CRT.
		k = scanf_s("%ld%lf", p_i, p_a);
		if (k < 2)
			return 1;

		//Wyczyszczamy nie odczytane symboli z stdin, jesli takie sa.
		stdin_clear();

		printf("podaj string\n");

		//Przygotowujemy format
		sprintf_s(format, "%%%ds", sz_str-1);
	
		//Wczytujemy bezpiecznie wiersz tekstowy.
		k = scanf_s(format, str, sz_str);   //scanf_s("%9s", str, sz_str);
		if (k <= 0)
			return 1;

		//Wyczyszczamy nie odczytane symboli z stdin, jesli takie sa.
		stdin_clear();

		return 0;
	}
#else
	#pragma warning (disable : 4996)  //Ta funkcja uzywa scanf, ktora Microsoft blokuje. Zezwalamy na jej uzycie.

	int fun_inp(int *p_i, double *p_a, char *str)
	/*===========================================================================
	Wczytuje dane z monitoru. Nie kontroluje nie przekroczenie rozmiaru wiersza str.
	p_i    - wskaznik do int
	p_a    - wskaznik do double
	str    - wiersz tekstowy

	RetVal - 0 - OK, !0 - blad.
	============================================================================*/
	{
		int k;

		printf("podaj int, double, string\n");

		//Wczytujemy int, double. scanf_s tu dzila dokladnie tak samo, jak i scanf z CRT.
		k = scanf("%ld%lf", p_i, p_a);
		if (k < 2)
			return 1;

		//Wczytujemy wiersz tekstowy.
		k = scanf("%s", str);
		if (k < 1)
			return 1;
		return 0;
	}

	#pragma warning (default : 4996)  //Resetujemy opcje kompilatora do stanu domyslnego.
#endif

void stdin_clear()
	/*==============================================================
	Wyczyszczamy stdin.
	===============================================================*/
{
	int ch;
	printf("wyczyszczamy stdin:   ");
	while ((ch = getchar()) != '\n')
	{
		printf("%c", ch);
	}
	printf(" ; \n");
}

void fun_print(int i, double a, char *str)
/*===========================================================================
Wyprowadzi na monitor i, a, str
============================================================================*/
{
	printf_s("%ld\n", i);
	printf_s("%lf\n", a );
	printf_s("%s\n", str);
}

#undef UZYWAMY_BEZPIECZNE_FUNKCJE_ODCZYTU