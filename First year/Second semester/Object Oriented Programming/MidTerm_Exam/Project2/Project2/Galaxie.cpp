#include "Galaxie.h"
#include <iostream>
#include <cstring>
using namespace std;


Galaxie::Galaxie(const char* nume = nullptr, int nrStele = -1, const char* forma = nullptr)
    :m_nrStele{nrStele}
{
    if (nume == nullptr)
    {
        cout << "Nume invalid";
        exit(1);
    }
    m_nume = new char[strlen(nume) + 1];
    strcpy(m_nume, nume);

    if (nume == nullptr)
    {
        cout << "Nume de forma invalida";
        exit(1);
    }

    m_forma = new char[strlen(forma) + 1];
    strcpy(m_forma, forma);
}


ostream& operator << (ostream& COUT, const Galaxie& obj)
{
    COUT << "Forma: " << obj.m_forma << endl << "Numar stele: " << obj.m_nrStele << endl << "Nume: " << obj.m_nume << endl;
    return COUT;
}


bool operator < (const Galaxie& obj1, const Galaxie& obj2)
{
    return obj1.m_nrStele < obj2.m_nrStele;
}


char* Galaxie::getForma()const { return m_forma; }


int Galaxie::getStele()const { return m_nrStele; }


char* Galaxie::getNume()const { return m_nume; }


Galaxie::Galaxie(const Galaxie& obj)
{
    
    m_forma = new char[strlen(obj.m_forma) + 1];
    strcpy(m_forma, obj.m_forma);

    m_nume = new char[strlen(obj.m_nume) + 1];
    strcpy(m_nume, obj.m_nume);

    m_nrStele = obj.m_nrStele;
}


bool Galaxie::operator = (const Galaxie& obj)
{
    this->m_nume = new char[strlen(obj.m_nume)];
    this->m_forma = new char[strlen(obj.m_forma)];
    this->m_nrStele = obj.m_nrStele;
}


Galaxie::~Galaxie()
{
    if(m_forma) delete[]m_forma;
    if(m_nume) delete[]m_nume;
}