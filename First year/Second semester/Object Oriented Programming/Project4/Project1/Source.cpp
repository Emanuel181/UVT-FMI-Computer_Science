#include <iostream>
#include <cstring>
#include "Patinator.h"
using namespace std;


int main()
{
    int n; cout << "Numar patinatori: ";  cin >> n; cin.ignore(); cout << endl;
    const int size = n;
    Patinator** arr;
    arr = new Patinator * [size];

    for (int i = 0; i < size; ++i)
    {
        char str[255]; cout << "Nume patinator: "; cin.get(str, 254); cin.ignore(); cout << endl;
        int varsta; cout << "Varsta patinator: "; cin >> varsta; cin.ignore(); cout << endl;
        arr[i] = new Patinator(str, varsta);
    }

    cout << "\nAfisare patinatori:\n\n";
    for (int i = 0; i < size; ++i)
    {
        cout << (*(arr[i])) << endl;
    }

    cout << endl << "Afisare patinatori intre 2 varste:\n\n";

    int st, dr;
    cout << "Varsta minima: ";  cin >> st; cin.ignore(); cout << endl;
    cout << "Varsta maxima: "; cin >> dr; cin.ignore(); cout << endl;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i]->getVarsta() >= st && arr[i]->getVarsta() <= dr)
        {
            cout << (*(arr[i])) << endl;
        }
    }

    cout << endl << endl;

    cout << "Afisare daca concurentii au participat laa celas numar de concursuri:\n";
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            cout << arr[i]->getNume() << " si " << arr[j]->getNume() << ' ' << ((*(arr[i])) != (*(arr[j]))) << endl;
        }
    }


    char* listaComp[1000];
    int dim = 0;

    cout << endl << endl << "Afisare competitii distincte: " << endl;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < arr[i]->getNrComp(); ++j)
        {
            if (dim == 0)
            {
                listaComp[dim] = new char[strlen(arr[i]->getComp()[j])];
                strcpy(listaComp[dim++], arr[i]->getComp()[j]);
            }

            else
            {
                bool ok = 1;
                for (int k = 0; k < dim; ++k)
                {
                    if (strcmp(listaComp[k], arr[i]->getComp()[j]) == 0) ok = 0;
                }

                if (ok)
                {
                    listaComp[dim] = new char[strlen(arr[i]->getComp()[j])];
                    strcpy(listaComp[dim++], arr[i]->getComp()[j]);
                }
            }
        }
    }

    for (int i = 0; i < dim; ++i)
    {
        cout << listaComp[i] << endl;
    }

    cout << endl << endl << "Afisare competitii si participanti: " << endl;

    for (int i = 0; i < dim; ++i)
    {
        cout << listaComp[i] << ": ";
        for (int j = 0; j < size; ++j)
        {
            for (int k = 0; k < arr[j]->getNrComp(); ++k)
            {
                if (strcmp(listaComp[i], arr[j]->getComp()[k]) == 0) cout << arr[j]->getNume() << ' ';
            }
        }

        cout << endl;
    }

    cout << endl;


    return 0;
}