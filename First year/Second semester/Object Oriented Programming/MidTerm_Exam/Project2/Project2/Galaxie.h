#pragma once
#include <iostream>
using namespace std;

class Galaxie
{
private:
    char* m_nume;
    int m_nrStele;
    char* m_forma;
public:
    Galaxie(const char*, int, const char*);
    friend ostream& operator << (ostream& COUT, const Galaxie&);
    friend bool operator < (const Galaxie&, const Galaxie&);
    bool operator = (const Galaxie&);
    Galaxie(const Galaxie&);
    char* getForma()const;
    int getStele()const;
    char* getNume()const;
    ~Galaxie();
};

