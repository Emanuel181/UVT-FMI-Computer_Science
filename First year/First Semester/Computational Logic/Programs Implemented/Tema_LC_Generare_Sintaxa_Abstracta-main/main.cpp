#include <iostream>
#include <vector>
#include <map>


using namespace std;

struct nod
{
	nod* st, * dr, * parinte;
	char val;
};


nod* radacina = NULL;


// Adaugare separata a nodului din stanga
void adauga_st(nod*& poz, char val)
{
	nod* nou = new nod();

	nou->st = nou->dr = NULL;
	nou->val = '?';
	nou->parinte = poz;

	poz->st = nou;

}


// Adaugare separata a nodului din dreapta
void adauga_dr(nod*& poz, char val)
{
	nod* nou2 = new nod();

	nou2->st = nou2->dr = NULL;
	nou2->val = '?';
	nou2->parinte = poz;

	poz->dr = nou2;

}


// Afisare arbore
void printBT(const std::string& prefix, const nod* node, bool isLeft)
{
	if (node != nullptr)
	{
		std::cout << prefix;

		std::cout << (isLeft ? " |-- " : " |-- ");

		// print the value of the node
		std::cout << node->val << std::endl;

		// enter the next tree level - left and right branch
		printBT(prefix + (isLeft ? " |   " : "     "), node->st, true);
		printBT(prefix + (isLeft ? " |   " : "     "), node->dr, false);
	}
}


// Afisare lista de ordine
void printPreorder(struct nod* node)
{
	if (node == NULL)
		return;

	cout << node->val << " ";

	printPreorder(node->st);

	printPreorder(node->dr);
}


// Crearea radacinii
void root(nod*& poz)
{
	nod* nou = new nod();
	nou->dr = nou->st = NULL;
	nou->val = '?';

	poz = radacina = nou;

}


// Functie pentru adaugarea nodului de negatie
void adauga_neg(nod*& poz)
{
	nod* nou = new nod();

	nou->st = NULL;
	poz->st = nou;
	nou->parinte = poz;
}


int main()
{
	nod* poz = NULL;
	char p[1001];
	// A se citi propozitia fara spatii !!
	// A se respecta conventiile facute de la linia 148 !!
	cin >> p;
	cout << endl;
	cout << "Construirea Sintaxei abstracte: " << endl << endl;

	for (unsigned i = 0; i < strlen(p); i++)
	{
		if (p[i] == '(')
		{	//Creez radacina
			if (radacina == NULL)
			{
				root(poz);
				cout << "Pozitia " << "[ " << i << " ] : " << p[i] << endl << endl;
				printBT("", radacina, false);
				cout << endl << endl;
			}
			// Daca pe urmatoarea pozitie se afla atom sau paranteza deschisa, initializez radacina cu 2 fii
			if ((p[i + 1] >= 'A' && p[i + 1] <= 'Z') || p[i + 1] == '(')
			{
				adauga_st(poz, '?');
				adauga_dr(poz, '?');
				poz = poz->st;
				cout << "Pozitia " << "[ " << i << " ] : " << p[i] << endl << endl;
				printBT("", radacina, false);
				cout << endl << endl;
			}
			// Daca am negatie, initializez radacina cu un fiu
			else if (p[i + 1] == '!')
			{
				adauga_neg(poz);
				poz->val = '!';
				poz = poz->st;
				cout << "Pozitia " << "[ " << i << " ] : " << p[i] << endl << endl;
				printBT("", radacina, false);
				cout << endl << endl;

			}

		}

		// Cazul cand am atom, am lasat cu "if" si nu am pus "else if", in cazul
		// in care se indeplineste conditia ca dupa paranteza deschisa sa urmeze atom
		if (p[i] >= 'A' && p[i] <= 'Z')
		{
			poz->val = p[i];
			// Daca introduc un literal, urc in sus
			poz = poz->parinte;
			cout << "Pozitia " << "[ " << i << " ] : " << p[i] << endl << endl;
			printBT("", radacina, false);
			cout << endl << endl;
		}

		else if (p[i] == '=' || p[i] == '|' || p[i] == '&' || p[i] == '#' || p[i] == '~' || p[i] == '|' || p[i] == '^' || p[i] == '*' || p[i] == '/')
		{
			poz->val = p[i];
			// Daca introduc un conector merg e celalalt fiu
			poz = poz->dr;
			cout << "Pozitia " << "[ " << i << " ] : " << p[i] << endl << endl;
			printBT("", radacina, false);
			cout << endl << endl;
		}

		else if (p[i] == ')')
			if (poz->parinte != NULL)
			{
				//Daca dau de paranteza inchisa, urc in sus o pozitie
				poz = poz->parinte;
				cout << "Pozitia " << "[ " << i << " ] : " << p[i] << endl << endl;
				printBT("", radacina, false);
				cout << endl << endl;
			}

			else if (p[i] == '!')
			{
				adauga_neg(poz);
				poz->val = '!';
				// Daca introduc o negatie, inserez un singur nod si ma plasez o pozitie in jos
				poz = poz->st;
				cout << "Pozitia " << "[ " << i << " ] : " << p[i] << endl << endl;
				printBT("", radacina, false);
				cout << endl << endl;
			}

	}

	cout << "[ FINAL ]" << endl << endl;
	printBT("", radacina, false);

	cout << endl << endl;

	cout << "Lista de ordine: "; printPreorder(radacina);
	
	cout << endl << endl;



	return 0;
}

// Conventii din cauza codifiarii in C++ a caracterelor
//  ! e negatie
//  / e disjunctie
//  ~ e implicatie
//  = e echivalenta
//  &, ^, * sunt conjunctii

// Nefolosirea conventiilor duce la eroare


// [EXEMPLE]

/*
 (((P=Q)/S)~T)
 ((P=Q)&((!Q)&(!P)))
 ((P=Q)/((!Q)/P))
 ((P~Q)~((Q~S)~((P/Q)~R)))
 ((!(P~Q))=((P/Q)^((!P)~Q)))
 ((P=Q)=(!(P~(!Q))))
 ((P=Q)=(!(P~(!Q))))
 ((!(P~Q))=((P/R)^((!P)~Q)))
 ((P~Q)~((Q~S)~((P/Q)~R)))
 */
