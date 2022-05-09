#include "Patinator.h"


Patinator::Patinator(char* nume, int varsta)
    :m_varsta{ varsta }
{
    m_nume = new char[strlen(nume) + 1];
    strcpy(m_nume, nume);

    cout << "Numar competitii: "; cin >> m_nrComp; cin.ignore(); cout << endl;

    m_competitii = new char* [m_nrComp];
    for (int i = 0; i < m_nrComp; ++i)
    {
        char str[255]; cout << "Nume competitie: "; cin.get(str, 254); cin.ignore(); cout << endl;
        m_competitii[i] = new char[strlen(str) + 1];
        strcpy(m_competitii[i], str);
    }
}


char* Patinator::getNume()const { return m_nume; }


int Patinator::getVarsta()const { return m_varsta; }


int Patinator::getNrComp()const { return m_nrComp; }


char** Patinator::getComp()const { return m_competitii; }


ostream& operator << (ostream& COUT, const Patinator& obj)
{
    COUT << obj.getNume() << endl << obj.getVarsta() << endl;
    for (int i = 0; i < obj.getNrComp(); ++i)
    {
        cout << obj.getComp()[i] << endl;
    }

    return COUT;
}


bool operator !=(const Patinator& obj1, const Patinator& obj2)
{
    if (obj1.getNrComp() != obj2.getNrComp()) return 1;
    return 0;
}

