#include "Asociatie.h"
#include <iostream>
using namespace std;


Asociatie::Asociatie(const string nume, const string data)
{
    if (nume == "dafault") throw "Numele nu poate fi default";
    else if (data == "defalt") throw "Data nu poate fi default";

    m_nume = nume;
    m_dataInfiintarii = data;
}


ostream& Asociatie:: afisare (ostream& COUT)const
{
    COUT << "Nume asociatie: " << this->m_nume << '\n' << "Data infiintarii: " << this->m_dataInfiintarii;

    return COUT;
}


ostream& operator << (ostream& COUT, const Asociatie& obj)
{
    return obj.afisare(COUT);
}


bool operator < (const Asociatie& obj1, const Asociatie& obj2)
{
    if (obj1.m_nume > obj2.m_nume) return 1;
    else return 0;
}

