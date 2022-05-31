#include "JocStrategie.h"
#include "Joc.h"


JocStrategie::JocStrategie(const std::string tema, const unsigned long long year, const double pret, const std::string nume): Joc(year, pret, nume)
{
    m_tema = tema;
    m_nume = nume;
}


std::ostream& JocStrategie::afisare(std::ostream& COUT)const
{
    // Joc::afisare(COUT);

    /* upCast
    Joc p = *this;
    p.afisare(COUT);
    */

    COUT << this->m_nume << ' ' << " anAparitie= " << this->m_year << ' ' << "pret= " << this->m_pret << " gen=" << this->m_tema << '\n';

    return COUT;
}


std::ostream& operator << (std::ostream& COUT, const JocStrategie& obj) { return obj.afisare(COUT); }



std::string JocStrategie::GetTema()const { return m_tema; }


JocStrategie::operator Joc()const
{
    return Joc(m_year, m_pret, m_nume);
}