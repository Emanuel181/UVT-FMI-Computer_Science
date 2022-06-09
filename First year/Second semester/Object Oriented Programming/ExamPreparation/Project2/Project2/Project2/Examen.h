#pragma once
#include "Comisie.h"
#include <iostream>;
using namespace std;

class Examen
{
private:
    int m_oraInceput;
    Comisie* m_comisie;
public:
    Examen(const int = 0, const int = 0);
    Examen(const Examen&);
    int getOra()const;
    ~Examen();
    Examen& operator =(const Examen&);
    friend ostream& operator << (ostream&, const Examen&);
    Comisie* getComisie()const;
};
