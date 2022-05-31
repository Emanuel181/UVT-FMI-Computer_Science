#pragma once
#include <iostream>
#include <string>


class Joc
{
protected:
    unsigned long long m_year;
    double m_pret;
    std::string m_nume;
public:
    Joc(const unsigned long long, const double, const std::string);
    unsigned long long GetYear()const;
    double GetPret()const;
    std::string GetNume();

    friend std::ostream& operator << (std::ostream&, const Joc&);
    virtual std::ostream& afisare(std::ostream&)const;
};

