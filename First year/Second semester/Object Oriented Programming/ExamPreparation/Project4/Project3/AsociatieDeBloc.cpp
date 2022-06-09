#include "AsociatieDeBloc.h"


AsociatieDeBloc::AsociatieDeBloc(const vector <string> arr, const string nume, const string data): Asociatie(nume, data)
{
    if (arr.size() == 0) throw "Lista de persoane goala";

    m_membri = arr;
}


ostream& AsociatieDeBloc::afisare(ostream& COUT)const
{
    COUT << "Lista membrii asociatie de bloc: ";
    for (const auto& it : this->m_membri) cout << it << ' ';

    return COUT;
}


ostream& operator << (ostream& COUT, const AsociatieDeBloc& obj)
{
    return obj.afisare(COUT);
}


