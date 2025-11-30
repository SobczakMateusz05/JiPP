// Lab_5.cpp : Defines the entry point for the console application.
// Tablicy o dwoch indeksach

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include "my_messages.h"

static char **char_tab;  //wskaznik do wskaznika

int main()
{
	//Test:
	my_mess_fun(MY_MESS_COS_TAM_WARN);
	//my_mess_fun(MY_MESS_MEM_ALOC_ERROR);

	fun_example_1();
	fun_example_2();
	fun_example_3();
	return 0;
}

void fun_example_1()
/*===========================================================
Statyczne alokowanie.
Deklarujemy tablice wskaznikow typu char i wykonujemy inicjowanie
=============================================================*/
{
	char *str_tab[] = {
		"abcd",			//wiersz 0
		"my row",       //wiersz 1
		"last row",      //wiersz 2
		"marker_end"	//markier - to jest zawsze ostatni wiersz 
						//nadaje możliwoc obliczyc ilosc wierszy w tablice
	};

	int n = 0;    //ilosc wierszy w tablice

	while (strcmp(str_tab[n++], "marker_end"))
		;

	for (int i = 0; strcmp(str_tab[i], "marker_end"); ++i)
		puts(str_tab[i]);

	system("pause");
}

void fun_example_2()
/*===========================================================
Statyczne alokowanie.
Deklarujemy tablice wskaznikow typu char o 3 wierszy o maksymalnym rozmiarze 5.
Wady:
1. Ilosc wierszy jest stala i nie zalezy od danych zadania
2. Dlugosc kazdego wiersza jest taka sama.

Wniosek: nieskuteczne uzycie pamieci i nie elastyczny kod!!!
=============================================================*/
{
	//Inicjowanie pierwszych dwoch wierszy tablicy
	char str_tab[3][5] = {
		'a', 'b', 'c', 'd', 'e',
		'1', '2', '3', '4', '5'
	};

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			printf("%c ", str_tab[i][j]);
		}
		printf("\n");
	}

	system("pause");

	//Elementy tablicy sa umieszczone w pamieci wiersz po wiersze!
	char *ptr = &str_tab[0][0];
	for (int ij = 0; ij < 3 * 5; ++ij, ++ptr)
	{
		printf("%c ", *ptr);
		if ((ij + 1) % 5 == 0)
			printf("\n");
	}
	//printf("\n");

	system("pause");
}

void fun_example_3()
/*===========================================================
Dynamiczne alokowanie pamieci
=============================================================*/
{
	int M, N;   //granicy indeksow i oraz j
	int i, j;
	
	printf("podaj M\n");
	scanf_s("%d", &M);

	//alokujemy pamiec dla tablicy wskaznikow. 
	//Kazdy z tych wskaznikow wskazuje na odpowiedni wiersz macierzy:
	//char_tab[0] - zerowy wiersz,
	//char_tab[1] - pierwszy wiersz,
	//..............................

	char_tab = (char **)malloc(M * sizeof(char *));
	if (!char_tab)
	{
		my_mess_fun(MY_MESS_MEM_ALOC_ERROR);
	}

	memset(char_tab, 0, M * sizeof(char *));

	for (i = 0; i < M; ++i)
	{
		printf("wiersz %d podaj N\n", i);
		scanf_s("%d", &N);

		char_tab[i] = (char *)malloc(N * sizeof(char));
		if (!char_tab[i])
		{
			my_mess_fun(MY_MESS_MEM_ALOC_ERROR);
		}

		memset(char_tab[i], 0, _msize(char_tab[i]));   //!!!
	}

	//wypełniamy tablicę
	int symb = 'a';
	for (i = 0; i < M; ++i)
	{
		N = (int)(_msize(char_tab[i]) / sizeof(char));  //ilosc elementow char w wiersze i
		for (j = 0; j < N; ++j)
		{
			char_tab[i][j] = symb++;
			printf("%c ", char_tab[i][j]);
		}
		printf("\n");
	}

	//zwalniamy pamiec
	MY_Dealloc();

	//testujemy na podwojne zwolnienie mamieci
	MY_Dealloc();

	system("pause");
}


void MY_Dealloc()
{
	if (char_tab)
	{
		int M = (int)(_msize(char_tab) / sizeof(char *));  //ilosc wierszy w macierzy str

		//zwalniamy pamiec alokowana dla kazdego wiersza
		for (int i = 0; i < M; ++i)
		{
			if (char_tab[i])
			{
				free(char_tab[i]);
				char_tab[i] = NULL;
			}
		}

		free(char_tab);
		char_tab = NULL;
	}
}

