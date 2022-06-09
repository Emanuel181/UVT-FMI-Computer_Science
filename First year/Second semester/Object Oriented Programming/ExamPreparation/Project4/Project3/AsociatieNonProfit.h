#pragma once

#include <iostream>
#include <string>
#include "Asociatie.h"
using namespace std;


class AsociatieNonProfit : public Asociatie
{
private:
    string m_dmeniu;
    double m_valoareMedie;
public:
    AsociatieNonProfit(const string = "default", const double = -99999.900, const string = "default", const string = "default");
    friend ostream& operator << (ostream&, const AsociatieNonProfit&);
    virtual ostream& afisare(ostream&)const;
};

