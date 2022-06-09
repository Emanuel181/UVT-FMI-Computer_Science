#include "Arbust.h"
#include "Planta.h"

Arbust::Arbust(const bool ornamental, const string zona, const string specie, const double pret):Planta(zona, specie, pret)
{
    m_ornamental = ornamental;
}


ostream& Arbust::afisare(ostream& COUT)const
{
    if (this->m_ornamental == 1) COUT << "Arbustul este ornamental";
    else COUT << "Arbustul nu este ornamental";
    return COUT;
}



ostream& operator << (ostream& COUT, const Arbust& obj) { return obj.afisare(COUT); }


bool Arbust::getValue()const { return m_ornamental; }

