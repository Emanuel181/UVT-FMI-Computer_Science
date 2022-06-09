#pragma once
#include <string>
using namespace std;


class Asociatie
{
protected:
    string m_nume;
    string m_dataInfiintarii;
public:
    Asociatie(const string = "default", const string = "default");
    friend ostream& operator << (ostream&, const Asociatie&);
    virtual ostream& afisare (ostream&)const;
    friend bool operator < (const Asociatie&, const Asociatie&);
};

