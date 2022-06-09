#pragma once
#include "Planta.h"


class Arbust:public Planta
{
private:
    bool m_ornamental;
public:
    Arbust(const bool, const string = "default", const string = "default", const double = -99999.900);
    friend ostream& operator << (ostream&, const Arbust&);
    ostream& afisare(ostream&)const;
    bool getValue()const;
};

