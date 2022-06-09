#include "Comisie.h"
#include <cstring>


Comisie::Comisie(const int numar, const char* nume, const char* const descriere)
{
    if (numar <= 0) throw "Nu se poate un numar de membri mai mic decat 0";


    m_numarMembri = numar;
    m_descriere = new char[strlen(descriere) + 1];
    strcpy(m_descriere, descriere);
    m_numeMembri = new char*[numar];
    for (int i = 0; i < numar; ++i) m_numeMembri[i] = nullptr;
}


Comisie::Comisie(const Comisie& obj)
{
    this->m_numarMembri = obj.m_numarMembri;
    this->m_descriere = new char[strlen(obj.m_descriere) + 1];
    strcpy(this->m_descriere, obj.m_descriere);
    this->m_numeMembri = new char* [obj.m_numarMembri];
    for (int i = 0; i < obj.m_numarMembri; ++i)
    {
        this->m_numeMembri[i] = new char[strlen(obj.m_numeMembri[i]) + 1];
        strcpy(this->m_numeMembri[i], obj.m_numeMembri[i]);
    }
}


Comisie& Comisie::operator =(const Comisie& obj)
{
    this->m_numarMembri = obj.m_numarMembri;
    this->m_descriere = new char[strlen(obj.m_descriere) + 1];
    strcpy(this->m_descriere, obj.m_descriere);
    this->m_numeMembri = new char* [obj.m_numarMembri];
    for (int i = 0; i < obj.m_numarMembri; ++i)
    {
        this->m_numeMembri[i] = new char[strlen(obj.m_numeMembri[i]) + 1];
        strcpy(this->m_numeMembri[i], obj.m_numeMembri[i]);
    }

    return *this;
}


Comisie::~Comisie()
{
    delete[] m_descriere;
    for (int i = 0; i < m_numarMembri; ++i)
    {
        delete[] m_numeMembri[i];
    }

    delete[] m_numeMembri;

    m_numeMembri = nullptr;
}


ostream& operator << (ostream& COUT, const Comisie& obj)
{
    COUT << "Numar membri: " << obj.m_numarMembri << '\n' << "Descriere: " << obj.m_descriere << '\n' << "Nume membri:\n";
    for (int i = 0; i < obj.m_numarMembri; ++i)
    {
        COUT << obj.m_numeMembri[i] << '\n';
    }

    return COUT;
}


void Comisie::addMembru(const char* const nume)
{
    for (int i = 0; i < m_numarMembri; ++i)
    {
        if (m_numeMembri[i] == nullptr)
        {
            m_numeMembri[i] = new char[strlen(nume) + 1];
            strcpy(m_numeMembri[i], nume);
            break;
        }
    }
}


int Comisie::getNumar()const { return m_numarMembri; }


char** Comisie::getMembri()const { return m_numeMembri; }


void Comisie::setDescriere(const char* const descriere) { strcpy(m_descriere, descriere); }


char* Comisie::getDescriere()const { return m_descriere; }


void Comisie::setNumar(const int numar) { m_numarMembri = numar; }

