#include "Produse.h"
#include <string.h>
#include <cstring>


Produs::Produs(const char* const Nume = nullptr, const unsigned long long Cantitate = 0, const double Pret = 0)
	:m_Cantitate{ Cantitate }, m_Pret{ Pret }
{
	m_Nume = new char[strlen(Nume) + 1];
	strcpy(m_Nume, Nume);
}


Produs::~Produs() { delete[] m_Nume; }


ostream& operator << (ostream& OUT, const Produs& obj)
{

	OUT << obj.getNume() << ' ' << obj.getCantitate() << ' ' << obj.getPret() << endl;
	
	return OUT;
}



void Produs::operator +=(const unsigned long long num)
{
	this->m_Cantitate += num;
	this->m_Pret += num;
}


void Produs::operator -=(const unsigned long long num)
{
	this->m_Cantitate -= num;
	this->m_Pret -= num;
}


void Produs::operator %=(const unsigned long long num)
{
	this->m_Pret *= num;
	this->m_Pret /= 100;
}


double Produs::getPret()const { return m_Pret; }


char* Produs::getNume()const { return m_Nume; }


int operator < (const Produs& obj1, const Produs& obj2)
{
	return strcmp(obj1.getNume(), obj2.getNume());
}


unsigned long long Produs::getCantitate()const { return m_Cantitate; }


