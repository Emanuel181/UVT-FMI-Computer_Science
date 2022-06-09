#pragma once
#include "Vehicul.h"
using namespace std;


class Scuter:public Vehicul
{
private:
    string m_nume;
public:
    Scuter(const string);
    void poateZbura();
};

