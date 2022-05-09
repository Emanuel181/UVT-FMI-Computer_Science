#include <iostream>
#include <cstring>
#include "Produse.h"

using namespace std;


int main()
{
	Produs * *listaProduse;

	unsigned long long* size; size = new unsigned long long; cout << "Numar de produse: "; cin >> (*size); cin.ignore(); cout << endl;
	const unsigned long long nrProduse = (*size); delete size;	

	listaProduse = new Produs *[nrProduse];

	for (unsigned long long i = 0; i < nrProduse; ++i)
	{
		char numeProdus[256]; cout << "Numele produsului: "; cin.get(numeProdus, 255); cin.ignore(); cout << endl;
		unsigned long long cantitateProdus; cout << "Cantitatea produsului: "; cin >> cantitateProdus; cin.ignore(); cout << endl;
		double pretProdus; cout << "Pretul produsului: "; cin >> pretProdus; cin.ignore(); cout << endl;

		listaProduse[i] = new Produs(numeProdus, cantitateProdus, pretProdus);
	}

	Produs::setNumarProduse(nrProduse);
	cout << listaProduse << endl;

	cout << "Pentru a creste cantitatea si pretul: "; 
	cout << endl;

	unsigned long long increase; cout << "Valoarea de crestere: "; cin >> increase;
	(*(listaProduse[0])) += increase;


	cout << listaProduse << endl;

	cout << "Pentru a scadea cantitatea si pretul: ";
	cout << endl;

	cout << "Valoarea de scadere: "; cin >> increase;
	(*(listaProduse[0])) -= increase;


	cout << listaProduse << endl;


	cout << "Pentru a creste pretul cu un anumit procent: ";
	cout << endl;

	cout << "Procentul de crestere: "; cin >> increase;
	(*(listaProduse[0])) %= increase;


	cout << listaProduse << endl;

	SortDescendingByName(listaProduse);

	cout << listaProduse << endl;

	cout << "\n\nEND OF PROGRAM\n\n";
}

/*
* Test Input
5
Creion
100
45
Salam
45
60
Masa
45
23
Masina
34
56
Pat
67A
89
*/