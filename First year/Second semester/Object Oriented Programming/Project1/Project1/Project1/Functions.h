#include <iostream>
using namespace std;

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