#pragma once
#include <iostream>
#include "Joc.h"

class JocArcade: public Joc
{
private:
    std::string m_firmaProducatoare;
public:
    JocArcade(const std::string, const unsigned long long year, const double pret, const std::string nume);
    std::string GetFirmaProducatoare()const;
    friend std::ostream& operator << (std::ostream&, const JocArcade&);
    virtual std::ostream& afisare(std::ostream&)const;
};

