#include "Produse.h"
#include <string.h>
#include <cstring>

Produs::Produs(const char* const Nume, const unsigned long long Cantitate, const double Pret)
	:m_Cantitate{ Cantitate }, m_Pret{ Pret }
{
	m_Nume = new char[strlen(Nume) + 1];
	strcpy(m_Nume, Nume);
}


Produs::~Produs() { delete[] m_Nume; }


ostream& operator << (ostream& COUT, Produs** listaProduse)
{
	for (unsigned long long i = 0; i < Produs::nrProduse; ++i)
	{
		COUT << listaProduse[i]->m_Nume << ' ' << listaProduse[i]->m_Cantitate << ' ' << listaProduse[i]->m_Pret << endl;
	}
	return COUT;
}


void Produs::setNumarProduse(const unsigned long long Size) { nrProduse = Size; }


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


unsigned long long Produs::nrProduse;


unsigned long long getNrProduse() { return Produs::nrProduse; }


char* Produs::getNume()const { return m_Nume; }


int operator < (const Produs& obj1, const Produs& obj2)
{
	return strcmp(obj1.getNume(), obj2.getNume());
}


void SortDescendingByName(Produs** arr)
{
	unsigned long long size = getNrProduse();

	for (unsigned long long i = 0; i < size - 1; ++i)
	{
		for (unsigned long long j = i + 1; j < size; ++j)
		{
			if (*(arr[i]) < *(arr[j]) > 0) { swap(arr[i], arr[j]); }
		}
	}
}

