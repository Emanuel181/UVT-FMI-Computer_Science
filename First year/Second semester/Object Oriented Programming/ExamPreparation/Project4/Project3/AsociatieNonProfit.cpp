#include "AsociatieNonProfit.h"


AsociatieNonProfit::AsociatieNonProfit(const string domeniu, const double valMedie, const string nume, const string data): Asociatie(nume, data)
{
    m_dmeniu = domeniu;
    m_valoareMedie = valMedie;
}


ostream& AsociatieNonProfit::afisare(ostream& COUT)const
{
    COUT << "Domeniul asociatiei non-profit: " << this->m_dmeniu << '\n' << "Valoarea medie a donatiilor: " << this->m_valoareMedie;

    return COUT;
}


ostream& operator << (ostream& COUT, const AsociatieNonProfit& obj)
{

    return obj.afisare(COUT);
}
