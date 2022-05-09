#pragma once
#include "Produse.h"

class Depozit
{
private:
    Produs** m_Produse;
    char* m_Nume;
    double m_Suprafata;
    unsigned long long m_nrProduse;
public:
    Depozit(unsigned long long size, char* nume, double area);
    friend void NrProdMax(Depozit**, const unsigned long long);
    unsigned long long getM_NrProduse()const;
    char* getM_Nume()const;
    friend ostream& operator << (ostream& COUT, const Depozit&);
    double getM_Suprafata()const;
    unsigned long long getNrProduse()const;
    friend void scadeCantitate(Depozit**, const unsigned long long);
    friend void adunaCantitate(Depozit**, const unsigned long long);
    Produs** getArr()const;
    void AfisareProdus(const unsigned long long);
    Produs operator[](const unsigned long long index);
};


