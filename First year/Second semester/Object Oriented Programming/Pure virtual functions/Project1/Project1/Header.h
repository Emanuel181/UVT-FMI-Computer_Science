#pragma once
#include <iostream>
#include "Scuter.h"
#include "Avion.h"
#include "Vehicul.h"
using namespace std;


Vehicul** init(Vehicul** arr, const unsigned long long n)
{
    arr = new Vehicul*[n];

    for (int i = 0; i < n; ++i)
    {
        string nume; cin >> nume;
        if (nume == "avion")
        {
            string numeAvion; cin >> numeAvion;
            arr[i] = new Avion(numeAvion);
        }
        else
        {
            string numeScuter; cin >> numeScuter;
            arr[i] = new Scuter(numeScuter);
        }
    }

    return arr;
}


void print(Vehicul* const* const arr, unsigned long long n)
{
    for (int i = 0; i < n; ++i)
    {
        arr[i]->poateZbura();
    }
}
