#pragma once
#include "Joc.h"
#include <iostream>
#include <string>

class JocStrategie:public Joc
{
protected:
    std::string m_tema;
    std::string m_nume;
public:
    JocStrategie(const std::string tema, const unsigned long long year, const double pret, const std::string nume);
    std::string GetTema()const;
    friend std::ostream& operator << (std::ostream&, const JocStrategie&);
    virtual std::ostream& afisare(std::ostream&)const;
    operator Joc()const;
};

