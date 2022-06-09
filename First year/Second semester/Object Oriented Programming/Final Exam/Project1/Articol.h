#pragma once
#include <iostream>
#include <string>
#include "Autor.h"
#include <vector>
using namespace std;


class Articol
{
private:
    string m_titlu;
    string m_numeRevista;
    vector <Autor> m_sirAutori;
public:
    Articol(string, string, vector <Autor>);
    friend ostream& operator << (ostream&, const Articol&);
    vector <Autor> getSirAutori()const;
    string getTitlu()const;
    static void sterge(Articol&, string);
};

