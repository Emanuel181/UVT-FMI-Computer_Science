#include <iostream>
#include "Galaxie.h"
using namespace std;


int main()
{
    //[a] - Creare obiecte de tip galaxie si afisarea lor
    Galaxie g1("Galaxia Andromeda", 3, "Eliptica");
    Galaxie g2("Galaxiile Antennae", 3, "Eliptica");
    Galaxie g3("Galaxia Retrograda", 3, "Spirala");
    Galaxie g4("Galaxia Ochilor Negri", 3, "Lenticulara");

    cout << "Afisare obiecte de tip galaxie:\n\n";
    cout << "   Galaxia 1: " << endl;
    cout << "   " << g1 << endl;
    cout << "   Galaxia 2: " << endl;
    cout << "   " << g2 << endl;
    cout << "   Galaxia 3: " << endl;
    cout << "   " << g3 << endl;
    cout << "   Galaxia 4: " << endl;
    cout << "   " << g4 << endl;
    cout << "---------------------------------------------------\n\n";


    int n; cout << "Numarul galaxiilor: ";  cin >> n; cin.ignore(); cout << endl;
    const int size = n;
    Galaxie** arr;

    arr = new Galaxie * [size];

    cout << "Citire galaxii:\n\n";
    // [b] citire lista galaxii
    for (int i = 0; i < size; ++i)
    {
        char str[255]; cout << "Numele galaxiei " << i << ": "; cin.get(str, 254); cin.ignore(); cout << endl;
        int nrStele; cout << "Numele de stele al galaxiei " << i << ": "; cin >> nrStele; cin.ignore(); cout << endl;
        char str2[255]; cout << "Forma galaxiei " << i << ": "; cin.get(str2, 254); cin.ignore(); cout << endl;

        arr[i] = new Galaxie(str, nrStele, str2);
    }

    cout << endl << "Afisare lista de galaxii: \n";

    for (int i = 0; i < size; ++i)
    {
        cout << (*(arr[i]));
    }

    cout << "---------------------------------------------------\n\n";

    cout << "Compararea galaxiilor\nSe compara prima si a doua galaxie din lista\n\n";
    // [c]
    int rez = ((*(arr[0])) < (*(arr[1])));

    if (rez == 1) cout << "Prima galaxie are mai putine stele\n";
    else cout << "A doua are mai putine stele\n";

    cout << "---------------------------------------------------\n\n";

    cout << "Se afiseaza lista de forme unice ale galaxiilor:\n\n";

    char* listaForme[100];
    int dim = 0;
    for (int i = 0; i < size; ++i)
    {
        if (dim == 0)
        {
            listaForme[dim] = new char[strlen(arr[i]->getForma()) + 1];
            strcpy(listaForme[dim], arr[i]->getForma());
            ++dim;
        }

        else
        {
            int ok = 1;
            for (int j = 0; j < dim; ++j)
            {
                if (strcmp(listaForme[j], arr[i]->getForma()) == 0) ok = 0;
            }
            if (ok)
            {
                listaForme[dim] = new char[strlen(arr[i]->getForma()) + 1];
                strcpy(listaForme[dim], arr[i]->getForma());
                ++dim;
            }
        }
    }

    for (int i = 0; i < dim; ++i)
    {
        cout << listaForme[i] << endl;
    }

    cout << "\n---------------------------------------------------\n\n";

    cout << "Se afiseaza numarul de stele din fiecare galaxie:\n\n";
    // [d]
    for (int i = 0; i < dim; ++i)
    {
        int sum = 0;
        cout << listaForme[i] << ": ";
        for (int j = 0; j < size; ++j)
        {
            if (strcmp(arr[j]->getForma(), listaForme[i]) == 0) sum += arr[j]->getStele();
        }
        cout << sum << endl;
    }


    cout << "\n---------------------------------------------------\n\n";

    cout << "Se afiseaza galaxiile care apartin unui interval citit:\n\n";
    // [e]
    int st, dr;
    cout << "Numar stele minim: "; cin >> st; cin.ignore(); cout << endl;
    cout << "Numar stele maxim: "; cin >> dr; cin.ignore(); cout << endl;
    char* tablouGalaxii[100];
    int k = 0;

    for (int i = 0; i < size; ++i)
    {
        if (arr[i]->getStele() >= st && arr[i]->getStele() <= dr)
        {
            tablouGalaxii[k] = new char[strlen(arr[i]->getNume()) + 1];
            strcpy(tablouGalaxii[k], arr[i]->getNume());
            ++k;
        }
    }

    for (int i = 0; i < k; ++i)
    {
        cout << tablouGalaxii[i] << endl;
    }

    cout << "\n\n--------------------END OF PROGRAM--------------------\n\n";


    


    return 0;
}