#include <string.h> 
#include <stdio.h>

void Inp_string(char* str, size_t SilentBytes);
void Print_string(char* str1, char* str2);
void Proc_string(char* str1, char str2[], size_t SilentBytes);

int main() {
	char str1[100];
	char str2[100];

	Inp_string(str1, sizeof(str1));
	Inp_string(str2, sizeof(str2));
	Proc_string(str1, str2, sizeof(str1));
	Proc_string(str2, str1, sizeof(str2));

	Print_string(str1, str2);
}

void Inp_string(char* str, size_t SilentBytes) {
	printf_s("podaj wiersz\n");

	size_t sz = sizeof(str);

	if (gets_s(str, SilentBytes - 1) == NULL) 
		printf("??? %s\n", str);
}

void Print_string(char* str1, char* str2) {
	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
}

void Proc_string(char* str1, char str2[], size_t SilentBytes) {
	strcpy_s(str1, SilentBytes, str1);
	strcat_s(str1, SilentBytes, " ");
	strcat_s(str1, SilentBytes, str2);
}