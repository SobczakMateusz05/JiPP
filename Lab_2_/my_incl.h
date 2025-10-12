#ifndef MY_INCLUDE___H
#define MY_INCLUDE___H

#define UZYWAMY_BEZPIECZNE_FUNKCJE_ODCZYTU

//To sa prototypy (deklaracji funkcji)

#ifdef UZYWAMY_BEZPIECZNE_FUNKCJE_ODCZYTU
	int fun_inp_s(int *, double *, char *, unsigned int);
#else
	int fun_inp(int* p_i, double* p_a, char* str);
#endif

void stdin_clear();
void fun_print(int i, double a, char *str);

#endif