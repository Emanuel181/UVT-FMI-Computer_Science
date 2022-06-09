#pragma once
#include <iostream>
#include "Vehicul.h"
using namespace std;


class Avion:public Vehicul
{
private:
    string m_nume;
public:
    Avion(const string);
    void poateZbura();
};

