#include "WarCraft.h"
#include <iostream>
#include <string>
#include <vector>


WarCraft::WarCraft(const std::string versiune, const unsigned long long anAparitie, const std::string arr, const std::string tema,
                   const unsigned long long year, const double pret, const std::string nume) : JocStrategie(tema, year, pret, nume)
{
    m_versiune = versiune;
    m_anAparitie = anAparitie;

    m_caracteristici.push_back(arr);
}



std::ostream& WarCraft::afisare(std::ostream& COUT)const
{
    // Joc::afisare(COUT);

    COUT << m_versiune << ' ' << "anAparitie: " << m_anAparitie << ' ' << "pret=" << m_pret << " gen=" << m_tema << ' ' << "istoric=";
    for (auto it : m_caracteristici) std::cout << it << ' ';

    COUT << '\n';

    return COUT;
}


std::ostream& operator << (std::ostream& COUT, const WarCraft& obj) { return obj.afisare(COUT); }


std::string WarCraft::GetVersiune()const { return m_versiune; }


unsigned long long WarCraft::GetAnAparitie()const { return m_anAparitie; }


std::vector <std::string> WarCraft::GetCaracteristici()const { return m_caracteristici; }
