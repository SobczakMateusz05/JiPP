#include <stdio.h>
#include <iostream>

char menu();
void inp_number(int* number);
void inp_looking_for(int* lookingFor, size_t SilentBytes);
void find(int* tab, int number);

void main() {
	int number[100];
	int lookingFor;
	
	char symbol = ' ';

	while (symbol != 'z') {
		symbol = menu();

		switch(symbol){
		case 'w':
			inp_number(number);
			break;
		case 'k':
			inp_looking_for(&lookingFor, sizeof(lookingFor));
			break;
		case 's':
			find(number, lookingFor);
			break;
		default: 
			break;
		}
	}
}

char menu() {
	char symbol = ' ';
	
	printf_s("%s\n", "Wpisz liczbe - n");
	printf_s("%s\n", "Wpisz kontekst - k");
	printf_s("%s\n", "wyszukaj - s");
	printf_s("%s\n", "Zakoncz - z");

	std::cin >> symbol;

	return symbol;
}

void inp_number(int* number) {
}

void inp_looking_for(int* lookingFor, size_t SilentBytes) {
	if (!gets_s(lookingFor, SilentBytes))
	{
		printf("inp_string problem\n");
	}

}

void find(int* tab, int number) {



}

