#pragma once
#include "JocStrategie.h"
#include <iostream>
#include <vector>
#include <string>


class WarCraft : public JocStrategie
{
private:
    std::string m_versiune;
    unsigned long long m_anAparitie;
    std::vector <std::string> m_caracteristici;
public:
    WarCraft(const std::string, const unsigned long long, const std::string, const std::string tema,
             const unsigned long long, const double, const std::string);
    std::string GetVersiune()const;
    unsigned long long GetAnAparitie()const;
    std::vector <std::string> GetCaracteristici()const;
    friend std::ostream& operator << (std::ostream&, const WarCraft&);
    virtual std::ostream& afisare(std::ostream&)const;
};

