#pragma once
#include <cstring>
#include <iostream>
using namespace std;

class Patinator
{
private:
    char* m_nume;
    int m_varsta;
    char** m_competitii;
    int m_nrComp;
public:
    Patinator(char*, int);
    friend ostream& operator << (ostream&, const Patinator&);
    friend bool operator !=(const Patinator&, const Patinator&);
    char* getNume()const;
    int getVarsta()const;
    int getNrComp()const;
    char** getComp()const;
};