#include <iostream>
#include "Depozit.h"
using namespace std;


/*
    [TASK]:

    Realizati o aplicatie care creeaza clasa Depozit, ce contine o lista de produse.

        ->Adaugati atribute claselor astfel incat sa aiba fiecare cel putin 2-3
        ->Creati o lista de depozite si identificatii depozitul cu cele mai multe produse
        -Supraincarcati operatorul de scriere
        ->Supraincarcati operatorii +=/-= pentru cresterea/scaderea cantitatii unui produs din depozit
        ->Supraincarcati operatorul [] pentru a obtine informatii despre un produs cu indexul dat.
*/


void init(Depozit**& listaDepozite, unsigned long long &size)
{
    cout << "Numarul de depozite: "; cin >> size; cin.ignore(); cout << endl;
    listaDepozite = new Depozit * [size];
    for (unsigned long long i = 0; i < size; ++i)
    {
        char str[255]; cout << "Nume depozit: "; cin.get(str, 255); cin.ignore(); cout << endl;
        double suprafata; cout << "Suprafata: "; cin >> suprafata;  cin.ignore(); cout << endl;
        unsigned long long nrProduse; cout << "Numar produse: "; cin >> nrProduse; cin.ignore(); cout << endl;
        listaDepozite[i] = new Depozit(nrProduse, str, suprafata);
    }
}


int main()
{
    unsigned long long* size = new unsigned long long;
    Depozit** listaDepozite;
    init(listaDepozite, *size);

    //1
    cout << "Depozitul cu cele mai multe produse:";
    NrProdMax(listaDepozite, *size);
    cout << "\n\nAfisare depozite:\n";

    //2
    for (unsigned long long i = 0; i < *size; ++i)
    {

        cout << (*(listaDepozite[i]));
    }

    //3
   scadeCantitate(listaDepozite, *size);
   for (unsigned long long i = 0; i < *size; ++i)
   {
       cout << (*(listaDepozite[i]));
   }

   adunaCantitate(listaDepozite, *size);

   for (unsigned long long i = 0; i < *size; ++i)
   {
       cout << (*(listaDepozite[i]));
   }

    //4
    for (unsigned long long i = 0; i < *size; ++i)
    {
        unsigned long long index; cout << "Indexul produsului din depozit: ";  cin >> index; cin.ignore(); cout << endl;
        Produs obj = (* (listaDepozite[i]))[index];
        cout << "Detaliile produsului: \n";
        cout << "Nume: " << obj.getNume() << "\nCantitate: " << obj.getCantitate() << "\nPret: " << obj.getPret() << "\n\n";
    }
   
    return 0;
}