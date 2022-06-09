#include "Articol.h"


Articol::Articol(string titlu, string numeRevista, vector <Autor> arr)
{
    m_titlu = titlu;
    m_numeRevista = numeRevista;
    m_sirAutori = arr;
}

ostream& operator << (ostream& COUT, const Articol& obj)
{
    COUT << "Titlul articolului este: " << obj.m_titlu << '\n';
    COUT << "Numele revistei este: " << obj.m_numeRevista << '\n';
    COUT << "Sirul de autori este: ";
    for (const auto& it : obj.m_sirAutori) COUT << it.getNume() << ' ';
    COUT << '\n';

    return COUT;

}

vector <Autor> Articol::getSirAutori()const { return m_sirAutori; }

string Articol::getTitlu()const { return m_titlu; }


void Articol::sterge(Articol& obj, string numeAutor)
{
    vector <Autor> sirAutori;

    for (const auto& it : obj.getSirAutori())
    {
        if (it.getNume() != numeAutor)
        {
            sirAutori.push_back(it);
        }
    }

    obj.getSirAutori() = sirAutori;
}