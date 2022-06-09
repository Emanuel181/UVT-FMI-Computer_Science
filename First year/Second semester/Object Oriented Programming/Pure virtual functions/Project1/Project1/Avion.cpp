#include "Avion.h"
#include <iostream>
using namespace std;


Avion::Avion(const string nume)
{
    m_nume = nume;
}


void Avion::poateZbura()
{
    cout << "Avion " << this->m_nume << " poate zbura\n";
}