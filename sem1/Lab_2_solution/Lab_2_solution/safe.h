#ifndef MY_INCLUDE___H
#define MY_INCLUDE___H

#define UZYWAMY_BEZPIECZNE_FUNKCJE_ODCZYTU

//To sa prototypy (deklaracji funkcji)

#ifdef UZYWAMY_BEZPIECZNE_FUNKCJE_ODCZYTU
int fun_inp_s(char* name, char* surname, int* year, double* mark, unsigned int name_length, unsigned int surname_length);
#else
	//dorobiæ bez _s funkcji
#endif

void stdin_clear();
void fun_print(char* name, char* surname, int year, double mark);

#endif