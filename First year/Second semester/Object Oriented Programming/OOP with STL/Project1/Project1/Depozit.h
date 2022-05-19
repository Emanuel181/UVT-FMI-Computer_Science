#pragma once
#include <string>
#include <iostream>
#include <list>
#include "Produs.h"
using namespace std;


class Depozit
{
private:
    string m_nume;
    string m_locatie;
    list <Produs> m_produse;
public:
    Depozit(const string&, const string&);
    void adauga(const Produs&);
    friend ostream& operator << (ostream&, const Depozit&);
    double calculeazaPretTotal()const;
    Produs aparitiiMaxime();
    list <Produs> getProduse()const;
    bool contineProduse(list<string>)const;
};

