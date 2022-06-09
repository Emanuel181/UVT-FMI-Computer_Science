#include <iostream>
#include "Articol.h"
#include "Autor.h"
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


bool sortare(Articol a, Articol b)
{
    if (a.getSirAutori().size() > b.getSirAutori().size()) return 1;
    else if(a.getSirAutori().size() < b.getSirAutori().size()) return 0;
    else if ((a.getSirAutori().size() == b.getSirAutori().size()))
    {
        if (a.getTitlu() > b.getTitlu()) return 1;
        return 0;
    }
}

int main()
{
    //a)
    //Creare obiect Autor
    vector <string> domeniiInteres;

    domeniiInteres.push_back("AI");
    domeniiInteres.push_back("Securitate");
    domeniiInteres.push_back("Criptografie");

    Autor a1("Raul Marinescu", domeniiInteres);
    cout << a1;


    vector <string> domeniiInteres2;

    domeniiInteres2.push_back("CyerSecurity");
    domeniiInteres2.push_back("Securitate");
    Autor a2("Rusu Emanuel", domeniiInteres2);

    
    cout << "\n\n";

    // Creare obiect Articol

    vector <Autor> autori;
    autori.push_back(a1);

    Articol articol1("Articol 1", "Revista 1", autori);

    vector <Autor> autori2;
    autori2.push_back(a1);
    autori2.push_back(a2);

    Articol articol2("Articol 2", "Revista 2", autori2);

    cout << articol1 << "\n\n";

    //a)----------------------------------------------------------------------


    //b) Afisare articole
    vector <Articol> listaArticole;
    listaArticole.push_back(articol1);
    listaArticole.push_back(articol2);
    for (const auto& it : listaArticole) cout << it << ' ';

    cout << "\n\n";

    //b)-------------------------------------------------------------------------


    //c)
    sort(listaArticole.begin(), listaArticole.end(), sortare);
    for (const auto& it : listaArticole) cout << it << ' ';

    cout << "\n\n";

    //c)--------------------------------------------------------------------------


    //d)
    string numeAutor; getline(cin, numeAutor);
    Articol::sterge(articol2, numeAutor);
    cout << articol2;
    //d)---------------------------------------------------------------------------

    return 0;
}