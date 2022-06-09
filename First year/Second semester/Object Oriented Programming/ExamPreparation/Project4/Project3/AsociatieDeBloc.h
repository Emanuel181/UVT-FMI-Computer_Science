#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Asociatie.h"
using namespace std;


class AsociatieDeBloc:public Asociatie
{
private:
    vector <string> m_membri;
public:
    AsociatieDeBloc(const vector <string>, const string = "default", const string = "default");
    friend ostream& operator << (ostream&, const AsociatieDeBloc&);
    virtual ostream& afisare (ostream&)const;
};

