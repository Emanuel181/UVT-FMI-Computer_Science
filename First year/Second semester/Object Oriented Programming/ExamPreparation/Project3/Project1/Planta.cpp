#include "Planta.h"


Planta::Planta(const string zona, const string specie, const double pret)
{
    if (zona == "default") throw "Zona nevalida";
    else if (specie == "default") throw "Specie nevalida";
    else if (pret == -99999.900) throw "Pret nevalid";

    m_zona = zona;
    m_pret = pret;
    m_specie = specie;
}


ostream& Planta::afisare(ostream& COUT)const
{
    COUT << "Zona plantei este: " << this->m_zona << '\n' << "Specia plantei este: " << this->m_zona << '\n' << "Pretul este: " << this->m_pret;

    return COUT;
}


ostream& operator << (ostream& COUT, const Planta& obj) { return obj.afisare(COUT); }

double Planta::getPret()const { return m_pret; }
