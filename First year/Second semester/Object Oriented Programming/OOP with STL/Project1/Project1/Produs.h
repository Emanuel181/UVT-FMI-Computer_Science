#pragma once
#include <string>
#include <iostream>
using namespace std;

class Produs
{
private:
    unsigned long long m_cantitate;
    double m_pret;
    string m_nume;
public:
    Produs(const unsigned long long, const double, string);
    friend ostream& operator <<(ostream&, const Produs&);
    void setPret(unsigned long long);
    double getPret()const;
    string getNume()const;
    unsigned long long getCantitate()const;
    friend bool operator < (const Produs&, const Produs&);
};

