#pragma once
#include <iostream>
#include <string>
using namespace std;



class Planta
{
protected:
    string m_zona;
    string m_specie;
    double m_pret;
public:
    Planta(const string = "default", const string = "default", const double = -99999.900);
    friend ostream& operator << (ostream&, const Planta&);
    virtual ostream& afisare(ostream&)const;
    double getPret()const;
};

