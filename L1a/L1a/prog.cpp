#include <iostream>
#include <vector>

using namespace std;

int cpp(int argc, char* argv[]) {

	//const int liczba = 30;
	

	/*int osiem = 8;
	double pi = 3.14;
	char zet = 'Z';*/


	//string miasto_1 = "Bygoszcz";
	//char miasto_2[10] = "";


	//miasto_1 = "Darmstadt";

	//int fibonnaci[liczba];

	/*cout << "Wynik: " << osiem << '\t' << pi << "\t" << zet;*/

	/*for (int i = 0; i < liczba; i++) {
		if (i > 2) {
			
			fibonnaci[i] = fibonnaci[i-1] + fibonnaci[i - 2];
		}
		else if(i>0){
			fibonnaci[i] = 1;
		}
		else {
			fibonnaci[i] = 0;
		}
	}*/

	//cout << endl <<  "Fibonnaci: ";

	/*for (int i = 0; i < liczba; i++) {
		cout << fibonnaci[i] << '\t';
	}*/


	int siedem;
	double e;
	char pe;
	string liverpool;
	double tab[10];

	cin >> siedem >> e >> pe >> liverpool;

	cout << siedem << endl << e << endl << pe << endl << liverpool << endl;

	for (int i = 0; i < 3; i++)
		cin >> tab[i];

	for (int i = 0; i < 3; i++)
		cout << tab[i]<< '\t';

	return 0;
}

