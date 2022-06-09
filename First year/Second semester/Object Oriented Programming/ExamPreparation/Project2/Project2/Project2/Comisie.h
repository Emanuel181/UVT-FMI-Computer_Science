#pragma once
#include <iostream>
using namespace std;

class Comisie 
{
private:
    char* m_descriere;
    int m_numarMembri;
    char** m_numeMembri;
public:
    Comisie(const int = 0, const char* const = "default", const char* const = "default");
    Comisie(const Comisie&);
    Comisie& operator =(const Comisie&);
    ~Comisie();
    int getNumar()const;
    char** getMembri()const;
    char* getDescriere()const;
    friend ostream& operator << (ostream&, const Comisie&);
    void addMembru(const char* const);
    void setDescriere(const char* const);
    void setNumar(const int);
};
