#include "Autor.h"

Autor::Autor()
{

}


Autor::Autor(string nume, vector <string> domenii)
{
    m_nume = nume;
    m_domenii = domenii;
}

ostream& operator << (ostream& COUT, const Autor& obj)
{
    COUT << "Numele autorului este: " << obj.m_nume << '\n';
    COUT << "Domeniile sale de interes sunt:\n";
    for (const auto& it : obj.m_domenii) COUT << it << ' ';

    return COUT;
}


string Autor::getNume()const { return m_nume; }