#include <iostream>
#include "Comisie.h"
#include "Examen.h"
using namespace std;


Examen** citire(int nrExamene)
{

    Examen** arr = new Examen * [nrExamene];

    for (int i = 0; i < nrExamene; ++i)
    {
        int ora; cin >> ora; cin.ignore();
        int numar; cin >> numar; cin.ignore();

        arr[i] = new Examen(ora, numar);
    }

    return arr;
}


void afisare(Examen** arr, int nrExamene)
{
    for (int i = 0; i < nrExamene; ++i)
    {
        cout << *arr[i];
    }
}


int numarare(Examen** arr, int nrExamene, char* numeMembru)
{
    int cnt = 0;

    for (int i = 0; i < nrExamene; ++i)
    {
        for(int j = 0; j < arr[i]->getComisie()->getNumar(); ++j)
        { 
            if (strcmp(arr[i]->getComisie()->getMembri()[j], numeMembru) == 0) ++cnt;
        }
    }

    return cnt;
}

int main()
{
    int nrExamene; cin >> nrExamene; cin.ignore();

    Examen** arr = citire(nrExamene);

    char numeMembru[255]; cin.getline(numeMembru, 254);
    int cnt = numarare(arr, nrExamene, numeMembru);

    cout << cnt;
    return 0;
}