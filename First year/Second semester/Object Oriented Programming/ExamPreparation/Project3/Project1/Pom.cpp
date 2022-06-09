#include "Pom.h"
#include "Planta.h"

Pom::Pom(const bool fructifer, const string zona, const string specie, const double pret):Planta(zona, specie, pret)
{
    m_fructifer = fructifer;
}


ostream& Pom::afisare(ostream& COUT)const
{
    if (this->m_fructifer == 1) COUT << "Pomul este fructifer";
    else COUT << "Pomul nu este fructifer";

    return COUT;
}


ostream& operator << (ostream& COUT, const Pom& obj) { return obj.afisare(COUT); }
