#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Autor
{
private:
    string m_nume;
    vector <string> m_domenii;
public:
    Autor();
    Autor(string, vector <string>);
    friend ostream& operator << (ostream&, const Autor&);
    string getNume()const;
};

