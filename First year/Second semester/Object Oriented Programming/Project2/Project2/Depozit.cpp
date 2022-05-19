#include "Depozit.h"
#include <iostream>
#include <climits>
using namespace std;


Depozit::Depozit(unsigned long long size, char* nume = nullptr, double area = 0)
    :m_Suprafata{area}, m_nrProduse{size}
{
    m_Nume = new char[strlen(nume) + 1];
    strcpy(m_Nume, nume);
    cout << "--" << m_Nume << "--";

    m_Produse = new Produs * [size];
    for (unsigned long long i = 0; i < size; ++i)
    {
        char numeProdus[256]; cout << "Numele produsului: "; cin.get(numeProdus, 255); cin.ignore(); cout << endl;
        unsigned long long cantitateProdus; cout << "Cantitatea produsului: "; cin >> cantitateProdus; cin.ignore(); cout << endl;
        double pretProdus; cout << "Pretul produsului: "; cin >> pretProdus; cin.ignore(); cout << endl;

        m_Produse[i] = new Produs(numeProdus, cantitateProdus, pretProdus);
    }
}


unsigned long long Depozit::getM_NrProduse()const { return m_nrProduse; }


char* Depozit::getM_Nume()const { return m_Nume; }


void NrProdMax(Depozit** listaProduse, const unsigned long long size)
{
    unsigned long long maxx = 0;
    Depozit* obj = nullptr;

    for (unsigned long long i = 0; i < size; ++i)
    {
        if (listaProduse[i]->getM_NrProduse() > maxx)
        {
            maxx = listaProduse[i]->getM_NrProduse();

            obj = listaProduse[i];
        }
    }

    if (obj)cout << obj->getM_Nume();
    else cout << "Nu exista";
}


unsigned long long Depozit::getNrProduse()const { return m_nrProduse; }
double Depozit::getM_Suprafata()const { return m_Suprafata; }


ostream& operator << (ostream& COUT, const Depozit& obj)
{
    COUT << "Nume depozit: " << obj.getM_Nume() << ',' << "Suprafata: " << obj.getM_Suprafata() << ',' << "Numar produse: " << obj.getM_NrProduse() << endl;
    COUT << "Produse: \n";

    for (unsigned long long i = 0; i < obj.getNrProduse(); ++i)
    {
        cout << (*(obj.getArr()[i]));
    }

    COUT << endl;

    return COUT;
}


Produs** Depozit::getArr()const { return m_Produse; }


void adunaCantitate(Depozit** listaDepozite, const unsigned long long size)
{
    unsigned long long decrease; cout << "Cata cantitate adaugati in plus: ";  cin >> decrease; cin.ignore(); cout << endl;


    for (unsigned long long i = 0; i < size; ++i)
    {
        for (unsigned long long j = 0; j < listaDepozite[i]->getM_NrProduse(); ++j)
        {
            (*listaDepozite[i]->getArr()[j]) += decrease;
        }
    }
}


void scadeCantitate(Depozit** listaDepozite, const unsigned long long size)
{
    unsigned long long decrease; cout << "Cata cantitate scoateti: ";  cin >> decrease; cin.ignore(); cout << endl;


    for (unsigned long long i = 0; i < size; ++i)
    {
        for (unsigned long long j = 0; j < listaDepozite[i]->getM_NrProduse(); ++j)
        {
            (*listaDepozite[i]->getArr()[j]) -= decrease;
        }
    }
}


Produs Depozit::operator[](const unsigned long long index)
{
    return *(this->getArr()[index - 1]);
}
