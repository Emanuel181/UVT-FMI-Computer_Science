#include <iostream>
#include <algorithm>
#include <map>
#include "Produs.h"
#include "Depozit.h"

using namespace std;


int main()
{
    Produs obj(12, 120, "Pixuri");

    //Afisare obiect
    cout << obj << "\n\n";

    Depozit depo1("Depozit 1", "Timisoara");
    depo1.adauga(obj);
    depo1.adauga(Produs(13, 121, "Caiete"));

    //Afisare depozit
    cout << depo1 << "\n\n";

    //Afisare pret total
    cout << "Pret total: " << depo1.calculeazaPretTotal() << '\n';

    map <Produs, unsigned long long> frq;

    Depozit depo2("Depozit 2", "Brasov");
    depo2.adauga(obj);
    depo2.adauga(Produs(13, 121, "Carioci"));

    list <Depozit> listaDepozite;

    listaDepozite.push_back(depo1);
    listaDepozite.push_back(depo2);

    unsigned long long cantitateMax = 0;

    for (auto depozit : listaDepozite)
    {
        for (auto produs : depozit.getProduse())
        {
            if (frq.find(produs) != frq.end()) frq[produs] += produs.getCantitate();
            else frq[produs] = produs.getCantitate();

            if (frq[produs] > cantitateMax) cantitateMax = frq[produs];
        }
    }

    cout << "<--------------------------------------------------------------------------------->\n";

    for (auto element : frq)
    {
        if (frq[element.first] == cantitateMax) { cout << "\nProdusul are apare de cele mai multe ori: " << '\n' << element.first << '\n'; }
 
        cout << "Produs: " << element.first << ' ' << element.second << '\n';
    }

    cout << '\n';

    list <string> produse = { "Pixuri", "Caiete" };

    int nr = count_if(listaDepozite.begin(), listaDepozite.end(), [produse](auto dep) {return dep.contineProduse(produse); });

    cout << nr << '\n';

    return 0;
}