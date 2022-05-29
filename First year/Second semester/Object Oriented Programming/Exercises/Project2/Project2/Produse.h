#pragma once
#include <iostream>
#include <cstring>
using namespace std;


class Produs
{
private:
	char* m_Nume;
	unsigned long long m_Cantitate;
	double m_Pret;
public:
	Produs(const char* const, const unsigned long long, const double);
	~Produs();
	friend ostream& operator << (ostream&, const Produs&);
	static void setNumarProduse(const unsigned long long);
	void operator +=(const unsigned long long);
	void operator -=(const unsigned long long);
	void operator %=(const unsigned long long);
	double getPret()const;
	friend static unsigned long long getNrProduse();
	friend int operator < (const Produs& obj1, const Produs& obj2);
	char* getNume()const;
	friend void SortDescendingByName(Produs**);
	unsigned long long getCantitate()const;

};



