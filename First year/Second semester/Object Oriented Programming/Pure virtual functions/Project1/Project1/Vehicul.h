#pragma once
#include <iostream>
using namespace std;


class Vehicul
{
private:
    string m_nume;
public:
    virtual void poateZbura() = 0;
};

