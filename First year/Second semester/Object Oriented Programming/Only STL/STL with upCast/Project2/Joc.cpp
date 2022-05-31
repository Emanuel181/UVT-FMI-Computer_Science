#include "Joc.h"


Joc::Joc(const unsigned long long year = 0, const double pret = 0.0, const std::string nume = "\0")
    :m_year{year}, m_pret{pret}, m_nume{nume}{}


std::ostream& Joc::afisare(std::ostream& COUT)const
{

    COUT << this->m_nume << ' ' << "anAparitie=" << this->m_year << ' ' << "pret=" << this->m_pret << '\n';

    return COUT;
}


std::ostream& operator << (std::ostream& COUT, const Joc& obj) { return obj.afisare(COUT); }


unsigned long long Joc::GetYear()const { return m_year; }


double Joc::GetPret()const { return m_pret; }


std::string Joc::GetNume() { return m_nume; }