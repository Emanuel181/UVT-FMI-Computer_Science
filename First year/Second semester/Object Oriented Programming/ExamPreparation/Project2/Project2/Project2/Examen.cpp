#include "Examen.h"
#include "Comisie.h"
#include <iostream>
using namespace std;


Examen::Examen(const int ora, const int numar)
{
    if (ora < 0) throw "Ora nu e valida";
    m_oraInceput = ora;


    char numeComisie[255]; cin.getline(numeComisie, 254);
    char descriere[255]; cin.getline(descriere, 254);
    m_comisie = new Comisie(numar, numeComisie, descriere);

    for (int i = 0; i < numar; ++i)
    {
        char str[255]; cin.getline(str, 254);
        m_comisie->addMembru(str);
    }
}


int Examen::getOra()const { return m_oraInceput; }


Examen::Examen(const Examen& obj)
{
    this->m_oraInceput = obj.m_oraInceput;
    this->m_comisie->setNumar(obj.m_comisie->getNumar());

    for (int i = 0; i < obj.m_comisie->getNumar(); ++i)
    {
        this->m_comisie->getMembri()[i] = new char[strlen(obj.m_comisie->getMembri()[i] + 1)];
        strcpy(this->m_comisie->getMembri()[i], obj.m_comisie->getMembri()[i]);
    }

    this->m_comisie->setDescriere(obj.m_comisie->getDescriere());
}


Examen& Examen::operator =(const Examen& obj)
{
    this->m_oraInceput = obj.m_oraInceput;
    this->m_comisie->setNumar(obj.m_comisie->getNumar());

    for (int i = 0; i < obj.m_comisie->getNumar(); ++i)
    {
        this->m_comisie->getMembri()[i] = new char[strlen(obj.m_comisie->getMembri()[i] + 1)];
        strcpy(this->m_comisie->getMembri()[i], obj.m_comisie->getMembri()[i]);
    }

    this->m_comisie->setDescriere(obj.m_comisie->getDescriere());

    return *this;
}


Examen::~Examen()
{
    delete m_comisie;
    m_comisie = nullptr;
}


ostream& operator << (ostream& OUT, const Examen& obj)
{
    OUT << "Ora de inceput: " << obj.m_oraInceput << '\n';
    cout << *obj.m_comisie;

    return OUT;
}


Comisie* Examen::getComisie()const { return m_comisie; }