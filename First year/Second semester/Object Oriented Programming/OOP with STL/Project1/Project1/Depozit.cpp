#include "Depozit.h"
#include <algorithm> // pentru for_each


ostream& operator << (ostream& COUT, const Depozit& obj)
{
    COUT << "Nume:   " << obj.m_nume << " Locatie: " << obj.m_locatie;
    COUT << " \n\tProduse: \n\t";
    for (auto produs : obj.m_produse)
    {
        COUT << produs << ' ';
    }

    return COUT;
}


void Depozit::adauga(const Produs& obj)
{
    m_produse.push_back(obj);
}


Depozit::Depozit(const string& nume, const string& locatie)
    :m_nume{nume}, m_locatie{locatie}{}


double Depozit::calculeazaPretTotal()const
{
    double sum = 0.0;

    /*for (auto produs : this->m_produse)
    {
        sum += produs.getPret() * produs.getCantitate() ;
    }*/

    for_each(m_produse.begin(), m_produse.end(), [&sum](auto prod) {sum += prod.getPret() * prod.getCantitate(); });

    return sum;
}


list <Produs> Depozit::getProduse()const { return m_produse; }


bool Depozit::contineProduse(list<string> listaProduse)const
{
    bool found;

    for (auto produs : listaProduse)
    {
        found = false;

        for (auto element : this->m_produse)
        {
            if (produs == element.getNume()){ found = true;  break; }
        }

       if(!found) return false;
    }

    return true;
}