#include "Scuter.h"



Scuter::Scuter(const string nume)
{
    m_nume = nume;
}


void Scuter::poateZbura()
{
    cout << "Scuter " << this->m_nume << " nu poate zbura";
}