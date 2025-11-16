// Poszukiwanie kontekstu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char menu(char *str, size_t SilentBytes);
void inp_string(char *str, size_t SilentBytes);
__int64 find(const char *str, const char *cont);
void interface_find_context(const char *my_string, const char *my_context);


int main()
{
	char my_cmd[8];       //rozkaz w postaci wiersza tekstowego
	char my_str[256];     //wiersz tekstowy dla poszukiwania kontekstu
	char my_cont[64];     //kontekst wchodzenia ktorego trzeba odnalezc.

	char symb = ' ';
	
	//realizuje menu uzytkownika
	while (symb != 'c')  //'c' - przerywa petle
	{
		symb = menu(my_cmd, sizeof(my_cmd));

		//parser: a co wprowadzil uzytkownik?
		switch (symb)
		{
		case 'w':  //wprowadzamy wiersz tekstowy do poszukiwania
			inp_string(my_str, sizeof(my_str));
			break;
		case 'k':  //wprowadzamy wiersz tekstowy dla kontekstu
			inp_string(my_cont, sizeof(my_cont));
			break;
		case 'z':  //probujemy odnalezc wszystkie wystapienia kontekstu my_cont w wiersze my_str
			interface_find_context(my_str, my_cont);
			break;
		case 'c':
			break;
		default:
			printf("unknown command\n");
		};
	}

    return 0;
}

char menu(char *str, size_t SilentBytes)
{
	//tablica wierszy tekstowych przy statycznym alokowaniu pamieci i inicjowaniu wierszy
	char *my_menu[] = {
		"wprowadz wiersz   - w",   //0
		"wprowadz kontekst - k",   //1
		"znajdz kontekst   - z",   //2
		"zakoncz           - c",   //3
	};

	//Ile wierszy zawiera ta tablica? 
	//tot_numb dynamicznie reaguje na zwiekszenie lub zmniejszenie ilosci wierszy.
	//my_menu[] - to jest tablica wskaznikow,
	//my_menu[0] wskazuje do poczatku wiersza o numierze 0
	//my_menu[1] -                                       1
	//....................................................
	//sizeof(my_menu) - rozmiar tablicy wskaznikow w bajtach,
	//sizeof(void *) - zwraca rozmiar wskaznika w bajtach, przy czym rozmiar wskaznika nie zalezy od typu danych, 
	//a zalezy tylko od i86 lub x64, dla tego moze byc i void *.
	//sizeof(my_menu)/sizeof(void *) - ilosc elementow w tablice my_menu[].
	
	const int tot_numb = sizeof(my_menu)/sizeof(void *);

	//wyprowadzamy menu na ekran
	for (int i = 0; i < tot_numb; ++i)
	{
		printf("%s\n", my_menu[i]);
	}

	//wczytujemy symbol sterujacy do wiersza tekstowego str
	if (!gets_s(str, SilentBytes))
		printf("menu function: problem with reading of command word\n");

	//zwracamy pierwszy symbol str
	return str[0];
}

void inp_string(char *str, size_t SilentBytes)
{
	if (!gets_s(str, SilentBytes))
	{
		printf("inp_string problem\n");
	}
}

__int64 find(const char *str, const char *cont)
/*=============================================================
Search context cont in string str.
Returns: position number in str, if found,
	     -1 - otherwise.
===============================================================*/
{
	const size_t len_cont = strlen(cont);
	size_t i;

	if (strlen(str) < len_cont)
		return -1;

	//loop over string str. 
	//*p == '\0' - current synbol is EOF - the end of string 
	for (const char *p = str; *p != '\0'; p++)
	{
		//compare symbol-by-symbol string str, starting with p, and context cont, starting at the beginning.
		for (i = 0; i < len_cont; ++i)
		{
			if (*(p + i) != *(cont + i))
				break;  //current symbols in str and in cont are different - is not found
		}

		if (i == len_cont)
			return p - str;  //all symbols in str, starting with p, and in cont are the same - is found and returns the position number of the first coinciding symbol in str.

		//Attention!  
		//The difference between the pointers of two different array elements in C gives the difference between their indices.
		//p - str is a number of elements in string str between the beginning (str point to the beginning of array)
		//and p (point to the first found element in str).
	}

	return -1;  //not found
}

void interface_find_context(const char* my_string, const char* my_context)
{
	const char* tmp_str = my_string; //ustalamy wskaznik pomocniczy do poczatku wiersza my_str
	__int64 last_i = -10; //last_i - numer pozycji (indeks) w my_str, od ktorej zaczyna sie wystapienie kontekstu my_conext.
	
	while (last_i != -1)
	{
		last_i = find(tmp_str, my_context);  //poszukujemy najblizsze wystapienie kontekstu my_cont
		if (last_i == -1)
		{
			//brak wystapien
			printf_s("%lld\n", last_i);
			break;  //przerywamy petle
		}

		//Sukces! drukujemy numer pozycji od ktorej zaczyna sie wystapienie kontekstu 
		//oraz wiersz tekstowy od poczatku tego wystapienia.
		printf_s("%lld    %s\n", tmp_str - my_string + last_i, tmp_str + last_i);

		//przestawiamy wskaznik pomocniczy do pierwsze pozycji poza odnalezionym wystapieniem
		//dla nastepnego przeszukiwania
		tmp_str = tmp_str + last_i + strlen(my_context);
	}
}

