#pragma once
#include "Planta.h"


class Pom:public Planta
{
private:
    bool m_fructifer;
public:
    Pom(const bool, const string = "default", const string = "default", const double = -99999.900);
    friend ostream& operator << (ostream&, const Pom&);
    ostream& afisare(ostream& COUT)const;

};

