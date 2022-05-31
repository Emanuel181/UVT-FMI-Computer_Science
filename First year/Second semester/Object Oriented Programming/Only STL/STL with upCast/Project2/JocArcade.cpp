#include "JocArcade.h"
#include "Joc.h"
#include "JocStrategie.h"


JocArcade::JocArcade(const std::string firmaProducatoare, const unsigned long long year, const double pret, const std::string nume): Joc(year, pret, nume)
{
    m_firmaProducatoare = firmaProducatoare;
    m_nume = nume;
}



std::ostream& JocArcade::afisare(std::ostream& COUT)const
{
    
    // Joc::afisare(COUT);
    COUT << this->m_nume << ' ' << " anAparitie=" << this->m_year << ' ' << " pret=" << this->m_pret << " producator=" << this->m_firmaProducatoare << '\n';

    return COUT;
}


std::ostream& operator << (std::ostream& COUT, const JocArcade& obj) { return obj.afisare(COUT); }


std::string JocArcade::GetFirmaProducatoare()const { return m_firmaProducatoare; }

