#include "Produs.h"


void Produs::setPret(const unsigned long long pret)
{
    if (pret < 0) throw "Pretul nu poate fi negativ!";
    m_pret = pret ;
}


Produs::Produs(const unsigned long long cantitate = 0, const double pret = -1, string nume = "")
    :m_cantitate{ cantitate }, m_nume{ nume }
{
    setPret(pret);
}


ostream& operator <<(ostream& COUT, const Produs& obj)
{
    COUT << "Nume produs: " << obj.m_nume << " Cantitate: " << obj.m_cantitate;
    COUT << " Pret: " << obj.m_pret;

    return COUT;
}


double Produs::getPret()const { return m_pret; }


unsigned long long Produs::getCantitate() const {return m_cantitate;}


string Produs::getNume()const { return m_nume; };


bool operator < (const Produs& obj1, const Produs& obj2)
{
    return (obj1.m_nume < obj2.m_nume);
}


