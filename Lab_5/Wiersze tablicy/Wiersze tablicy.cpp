// Wiersze tablicy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "my_mess.h"
#include "tablica.h"
#include <stdlib.h>
#include <string.h>


int main()
{
	int M, ii, jj;
	printf("podaj M\n");
	scanf_s("%d", &M);

	//Testujemy system komunikatow
	//my_mess_fun(MY_MESS_MEM_ALLOC_NOT_FATAL);
	//my_mess_fun(MY_MESS_MEM_ALOC_ERROR);

	tab_alloc(M);
	tab_fill();
	tab_print();
	system("pause");

	printf("wymieni pomiedzy soba wiersze ii oraz jj\n");
	scanf_s("%d%d", &ii, &jj);
	//swap_rows(ii, jj);  //is deprecated
	swap_rows_enh(ii, jj);
	tab_print();
	system("pause");

	printf("poza wierszem ii wstaw nowy wiersz\n");
	scanf_s("%d", &ii);
	insert_row_after_ii_enh(ii);
	tab_print();
	system("pause");

	GLOB_Dealloc();
	
	return 0;
}


void GLOB_Dealloc()
/*========================================================================
Zwalnia pamiec dla wszystkich obiektow, uzywanych w programie.
Zamyka pliki, jesli podany program otwieral ich.
Jest uzywana jako dla normalnego zakonczenia zadania, tak i w przypadku awaryjnego.
=========================================================================*/
{
	tab_free();
}

void GLOB_Exit()
/*=============================================================================
Wywoluje sie dla awaryjnego zakonczenia programu. Przed wywolaniem tej funkcji
trzeba wywolac GLOB_Dealloc().
===============================================================================*/
{
	system("pause");
	exit(1);
}


