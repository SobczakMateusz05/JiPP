// Lab_4_wiersze_tekstowe.cpp : Defines the entry point for the console application.
// Wiersze tekstowe

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <crtdbg.h>  // For _CrtSetReportMode


void fun_statyczne_alokowanie();
void fun_wczytanie_z_klawiatury(char *str, size_t SilentBytes);
void fun_sklejanie_kopiowanie(char *str, char str1[], size_t SilentBytes);
void fun_sortowanie_wierszy();
void stdin_clear();
int my_compare_desc(const void *a1, const void *a2);
int my_compare_asc(const void *a1, const void *a2);

//Many C runtime functions check the validity of arguments passed to them. 
//If an invalid argument is passed, the function can set the errno error number or return an error code. 
//In such cases, the invalid parameter handler is also called. 
//The C runtime supplies a default global invalid parameter handler that terminates the program and displays a runtime error message. 
//You can use the _set_invalid_parameter_handler to set your own function as the global invalid parameter handler.

void myInvalidParameterHandler(const wchar_t* expression,
	const wchar_t* function,
	const wchar_t* file,
	unsigned int line,
	uintptr_t pReserved)
{
	wprintf(L"Invalid parameter detected in function %s."
		L" File: %s Line: %d\n", function, file, line);
	wprintf(L"Expression: %s\n", expression);
	wprintf(L"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	system("pause");
	//abort();  //it is a default bechaviour. Now we change it.
}

int main()
{
	char str[64], str1[32];

	//Set terminate handler
	_invalid_parameter_handler old_param_hadler = _set_invalid_parameter_handler(myInvalidParameterHandler);

	// Disable the message box for assertions.
	_CrtSetReportMode(_CRT_ASSERT, 0);

	fun_statyczne_alokowanie();
	fun_wczytanie_z_klawiatury(str, sizeof(str));
	fun_wczytanie_z_klawiatury(str1, sizeof(str1));
	fun_sklejanie_kopiowanie(str, str1, sizeof(str));
	
	printf("str : %s\n", str);
	printf("str1: %s\n", str1);

	fun_sortowanie_wierszy();

	system("pause");

    return 0;
}

void fun_statyczne_alokowanie()
{
	//declaracje wiersza oraz jego inicjowanie
	char str[] = "abcde";

	//To jest podobne, jednak zajmuje wiecej pamieci
	char sstr[64] = "abcde";

	//Wyjasniamy, ile pamieci pozostalo wydzielone:
	size_t sz_mem = sizeof(str);

	//Ile symboli, za wyjatkiem '/0', miesci tablica?
	size_t len_str = strlen(str);

	sz_mem  = sizeof(sstr);
	len_str = strlen(sstr);
}

void fun_wczytanie_z_klawiatury(char *str, size_t SilentBytes)
{
	printf_s("podaj wiersz\n");
	
	//Uwaga! str - to jest wskaznik typu char - sizeof(str) = 4 lub 8. Nie jest to rozmiar tablicy!!!
	//Rozmiar tablicy - to jest SilentBytes.
	size_t sz = sizeof(str);

	if (gets_s(str, SilentBytes-1) == NULL)  //gets, gets_s - patrz MSDN
		printf("??? %s\n", str);

	//stdin_clear();
}

void fun_sklejanie_kopiowanie(char *str, char str1[], size_t SilentBytes)
{
	//kopiowanie  strcpy, strcpy_s - patrz MSDN
	strcpy_s(str + 2, SilentBytes-2, str1 + 4);

	//sklejanie strcat, strcat_s - patrz MSDN
	strcat_s(str, SilentBytes, str1 + 6);

	//A to jest przyklad stosowania memcpy - patrz MSDN
	char sstr[] = "abcdef";
	char sstr1[] = "123456";
	int shift = 1;
	memcpy_s(sstr + shift, sizeof(sstr)-sizeof(char)*shift, sstr1 + 2, 2 * sizeof(char));
}

void fun_sortowanie_wierszy()
{
	char str[128];
	fun_wczytanie_z_klawiatury(str, sizeof(str));
	printf("przed sortowaniem      : %s\n", str);
	
	//qsort - patrz MSDN 
	qsort((void *)str, strlen(str), sizeof(str[0]), my_compare_desc);
	printf("po sortowaniu malujacym: %s\n", str);
	
	qsort((void *)str, strlen(str), sizeof(str[0]), my_compare_asc);
	printf("po sortowaniu rostnacym: %s\n", str);
}

//-------------------Funkcji porownawcze-----------------------------//
int my_compare_desc(const void *a1, const void *a2)
{
	char *e1 = (char *)(a1);
	char *e2 = (char *)(a2);
	
	//strcmp - patrz MSDN
	return (strcmp(e2, e1));
}

int my_compare_asc(const void *a1, const void *a2)
{
	char *e1 = (char *)(a1);
	char *e2 = (char *)(a2);

	return (strcmp(e1, e2));
}

//------------------------------------------------------------------
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




