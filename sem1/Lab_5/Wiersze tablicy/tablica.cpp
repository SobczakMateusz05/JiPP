
#include "stdafx.h"
#include "my_mess.h"
#include "tablica.h"
#include <stdlib.h>
#include <string.h>

static char ** str_tab;

void tab_alloc(const int M)
{
	int N;
	str_tab = (char **)malloc(M * sizeof(char *));
	if (!str_tab)
	{
		my_mess_fun(MY_MESS_MEM_ALOC_ERROR);
	}

	memset(str_tab, 0, M * sizeof(char *));

	for (int i = 0; i < M; ++i)
	{
		printf("wiersz %d podaj N\n", i);
		scanf_s("%d", &N);

		str_tab[i] = (char *)malloc(N * sizeof(char));
		if (!str_tab[i])
		{
			my_mess_fun(MY_MESS_MEM_ALOC_ERROR);
		}

		memset(str_tab[i], 0, sizeof(char)*N);
	}
}

void tab_free()
{
	if (str_tab)
	{
		size_t M = _msize(str_tab) / sizeof(char *);  //ilosc wierszy w macierzy str
											   
		for (int i = 0; i < M; ++i)		//zwalniamy pamiec alokowana dla kazdego wiersza
		{
			if (str_tab[i])
			{
				free(str_tab[i]);
				str_tab[i] = NULL;
			}
		}

		free(str_tab);
		str_tab = NULL;
	}
}

void tab_fill()
{
	//wypełniamy tablicę
	size_t N, M = _msize(str_tab) / sizeof(char *);  //number of rows
	int symb = 'a';
	for (int i = 0; i < M; ++i)
	{
		N = _msize(str_tab[i]) / sizeof(char);  //ilosc elementow char w wiersze i
		for (int j = 0; j < N; ++j)
		{
			str_tab[i][j] = symb++;
		}
	}
}

void swap_rows_enh(int ii, int jj)
{
	char *str_tmp = str_tab[ii];
	str_tab[ii] = str_tab[jj];
	str_tab[jj] = str_tmp;
}

void insert_row_after_ii_enh(int ii)
{
	size_t M = _msize(str_tab) / sizeof(char *);  //number of rows
	char str[256];

	//---------------Wczytujemy nowy wiersz-------------------//
	printf("podaj nowy wiersz\n");
	int ch;
	while ((ch = getchar()) != '\n')
		;
	gets_s(str, sizeof(str));

	size_t num_of_elem = strlen(str);  //ile elementow w tym wiersze?

	//Zwiekszamy ilosc wierszy o jeden
	str_tab = (char **)realloc(str_tab, (M + 1) * sizeof(char *));
	if (!str_tab)
	{
		my_mess_fun(MY_MESS_MEM_ALOC_ERROR);
	}

	//Kopiujemy wskazniki do wierszy
	//  0 - nowy wiersz w tablice
	//  a b c d e 0  ->   a b c d d e
	//  alokujemy pamiec dla nowego wiersza i wpisujemy wskaznik x do tego wiersza w poz.
	//        ! 
	//  a b c x d e 
	//kopiowanie na przekrywajacych sie adresach pamieci!!!
	str_tab[M] = NULL;
	memmove(str_tab + ii + 2, str_tab + ii + 1, (M - ii - 1) * sizeof(char *));
	
	//SF albo tak:
	//memmove(&str_tab[ii + 2], &str_tab[ii + 1], (M - ii - 1) * sizeof(char *));
	
	//Albo tak
	//for (size_t i = M; i > ii; --i)
	//	str_tab[i] = str_tab[i - 1];

	//Alokujemy pamiec dla nowego wiersza o num_of_elem, a wskaznik do tego wiersza 
	//wpisujemy do:
	str_tab[ii+1] = (char *)malloc(num_of_elem * sizeof(char));
	if (!str_tab[ii + 1])
	{
		my_mess_fun(MY_MESS_MEM_ALOC_ERROR);
	}

	//wstawiamy zawartosc nowego wiersza
	memcpy(str_tab[ii+1], str, (num_of_elem) * sizeof(char));
}

size_t numb_elem_in_row_ii(size_t ii)
{
	size_t M = _msize(str_tab) / sizeof(char *);  //number of rows
	if(ii < M)
		return _msize(str_tab[ii]) / sizeof(char);
	else
		my_mess_fun(MY_MESS_INCORR_INDEX_WARN);
	return 0;
}

void tab_print()
{
	size_t N, i, j, M = _msize(str_tab) / sizeof(char *);  //number of rows

	printf("\n");
	for (i = 0; i < M; ++i)
	{
		N = _msize(str_tab[i]) / sizeof(char);  //ilosc elementow char w wiersze i
		for (j = 0; j < N; ++j)
		{
			printf("%c ", str_tab[i][j]);
		}
		printf("\n");
	}
}

