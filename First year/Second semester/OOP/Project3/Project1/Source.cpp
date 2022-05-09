#include <iostream>
#include "DataCalendaristica.h"

using namespace std;

/*
    [TASK]:

    Definiti o clasa DataCalendaristica (zi/luna/an). Realizati un program care:

        ->compara doua date calendaristice

        ->afiseaza data calendaristica dupa ce s-au adaugat la ea un numar de zile (supraincarcarea  operatorului +=)

        ->afiseaza data calendaristica dupa ce s-au scazut la ea un numar de zile  (supraincarcarea operatorului -=)

        ->poate extrage ziua, luna, anul din data

*/


int main()
{
    unsigned short zi_1; cout << "Ziua pentru data 1: "; cin >> zi_1; cin.ignore(); cout << endl;
    unsigned short luna_1; cout << "Luna pentru data 1: "; cin >> luna_1; cin.ignore(); cout << endl;
    unsigned long long an_1; cout << "Anul pentru data 1: "; cin >> an_1; cin.ignore(); cout << endl << endl;

    unsigned short zi_2; cout << "Ziua pentru data 2: "; cin >> zi_2; cin.ignore(); cout << endl;
    unsigned short luna_2; cout << "Luna pentru data 2: "; cin >> luna_2; cin.ignore(); cout << endl;
    unsigned long long an_2; cout << "Anul pentru data 2: "; cin >> an_2; cin.ignore(); cout << endl << endl;

    DataCalendaristica data_1(zi_1, luna_1, an_1), data_2(zi_2, luna_2, an_2);


    // <
    int rez = data_1 < data_2;
    if (rez == 1) cout << data_1 << " este inaintea datei " << data_2 << "\n\n";
    else if (rez == 0) cout << data_1 << " este dupa data " << data_2 << "\n\n";
    else cout << "Ambele dati sunt egale\n\n";


    // >
    rez = data_1 > data_2;
    if (rez == 1) cout << data_1 << "este dupa datei " << data_2 << "\n\n";
    else if (rez == 0) cout << data_1 << "este inaintea datei " << data_2 << "\n\n";
    else cout << "ambele dati sunt egale\n\n";

    
    //+=
    int increase; cout << "Cate zile vreti sa adunati la data 1: "; cin >> increase; cin.ignore(); cout << endl;
    data_1 += increase;

    cout << "Data este: " << data_1 << endl << endl;

    
    int decrease; cout << "Cate zile vreti sa scadeti din data 1: "; cin >> decrease; cin.ignore(); cout << endl;
    data_1 -= decrease;

    cout << "Data este: " << data_1 << endl << endl;

    cout << "Extragere componente din data:\n";
    data_1.extrageDate();

    return 0;
}