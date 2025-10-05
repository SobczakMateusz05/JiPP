#include <stdio.h>

int main(int argc, char* argv[]) {

	/*int osiem = 8;
	double pi = 3.14;
	char zet = 'Z';*/

	/*cout << "Wynik: " << osiem << '\t' << pi << "\t" << zet;*/


	//char miasto_1[10] = "Bygoszcz";
	//char miasto_2[10] = {'B', 'a', 'r', 'c', 'e', 'l', 'o', 'n', 'a', '\0'};
	//char miasto_3[10] = { 67, 97, 109, 98, 114, 105, 100, 103,101 ,0 };

	//printf("%s\n", miasto_1);
	//printf("%s\n", miasto_2);
	//printf("%s\n", miasto_3);

	//for (int i = 0; i < 10; i++) {
	//	miasto_1[i] = "Darmstadt"[i];
	//}

	//printf("%s\n", miasto_1);


	double fibonnaci[30];

	size_t len = sizeof(fibonnaci) / sizeof(fibonnaci[0]);

	for (int i = 0; i < len; i++) {
		if (i > 2) {
			fibonnaci[i] = fibonnaci[i - 1] + fibonnaci[i - 2];
		}
		else {
			fibonnaci[i] = 1;
		}
	}

	int rows;

	if (len % 10 == 0)
		rows = len / 10;
	else
		rows = len / 10 + 1;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < 160; j++)
			printf("-");
		printf("\n");

		for (int j = 0; j < 10; j++) {
			if (j + 10 * i < len)
				printf("|%-8.2lf\t", fibonnaci[j + 10 + i]);
			else
				break;
		}
		printf("|\n");
	}

	for (int j = 0; j < 160; j++)
		printf("-");

	
	//int siedem;
	//double e;
	//char pe;
	//char liverpool[10];

	//scanf_s("%d", siedem);
	//printf("%d\n", siedem);


	/*scanf_s("%s\n", pe);
	printf("%d\n", pe);*/
	
	return 0;
}

