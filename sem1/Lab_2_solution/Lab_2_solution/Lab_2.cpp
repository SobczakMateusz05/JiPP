#include <stdio.h>
#include <stdlib.h>
#include "safe.h"

int main() {
	char name[20];
	char surname[20];
	int year;
	double mark;

#ifdef UZYWAMY_BEZPIECZNE_FUNKCJE_ODCZYTU
	fun_inp_s(name, surname, &year, &mark, sizeof(name), sizeof(surname));
#else
	//dorobiæ bez _s funkcji
#endif

	fun_print(name, surname, year, mark);

	system("pause");
	return 0;

}


#ifdef UZYWAMY_BEZPIECZNE_FUNKCJE_ODCZYTU

int fun_inp_s(char *name, char *surname, int *year, double *mark, unsigned int name_length, unsigned int surname_length){
	int k;
	char format[64];

	printf("podaj imie: ");

	sprintf_s(format, "%%%ds", name_length-1);
	k = scanf_s(format, name, name_length);   
	if (k <= 0)
		return 1;

	stdin_clear();


	printf("podaj nazwisko: ");

	sprintf_s(format, "%%%ds", surname_length - 1);
	k = scanf_s(format, surname, surname_length);   
	if (k <= 0)
		return 1;

	stdin_clear();

	printf("podaj rok urodzenia i ocene: ");

	k = scanf_s("%ld%lf", year, mark);
	if (k < 2)
		return 1;

	stdin_clear();

	return 0;
}
#else
	//dorobiæ bez _s funkcji
#endif

void stdin_clear(){
	int ch;
	printf("wyczyszczamy stdin:   ");
	while ((ch = getchar()) != '\n')
	{
		printf("%c", ch);
	}
	printf(" ; \n");
}

void fun_print(char  *name, char *surname, int year, double mark){
	printf_s("%s\n", name);
	printf_s("%s\n", surname);
	printf_s("%ld\n", year);
	printf_s("%.2lf\n", mark);
}

#undef UZYWAMY_BEZPIECZNE_FUNKCJE_ODCZYTU