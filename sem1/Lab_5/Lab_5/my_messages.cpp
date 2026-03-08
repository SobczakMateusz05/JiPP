#include "stdafx.h"
#include "my_messages.h"
#include <stdlib.h>
#include <string.h>

static char *my_message_str_tab[] = {
	"E memory allocation error",	//MY_MESS_MEM_ALOC_ERROR
	"W nastepny komunikat",			//MY_MESS_COS_TAM_WARN	
	"W aaaaaaa"						//MY_MESS_KOMUNIK_AAAA   
};

void my_mess_fun(enum MY_MESSAGES mess)
/*===================================================================================
Przy podanym numerowaniu enum MY_MESSAGES komunikat mess jest poprostu
numierem wiersza w tablice my_message_str_tab.
====================================================================================*/
{
	puts(my_message_str_tab[mess] + 1);
	
	//Analizujemy komunikat: błąd (przerywamy program) albo komunikat 
	//(drukujemy i kontynujemy dalej)
	if (my_message_str_tab[mess][0] == 'E')
	{
		//to jest błąd. Przerywamy wykonanie programu.
		system("pause");
		MY_Dealloc();
		exit(1);
	}
}