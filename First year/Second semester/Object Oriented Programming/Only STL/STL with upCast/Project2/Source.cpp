#include "Header.h"


void init(std::vector <Joc*>& jocuri, std::map <int, int>& dict)
{
    int n; std::cin >> n; std::cin.ignore();

    for (int i = 0; i < n; ++i)
    {
        std::string str;
        std::cin >> str; std::cin.ignore();

        if (str == "Joc") { initJoc(jocuri, dict); }

        else if (str == "Arcade") { initArcade(jocuri, dict); }

        else if (str == "Strategie") { initStrategie(jocuri, dict); }

        else if (str == "WarCraft") { initWarCraft(jocuri, dict); }

        else throw "Tip necunoscut";
    }

    std::cout << "\n\n";
}


void afisare(const std::vector <Joc*>& jocuri, std::map <int, int> dict)
{

    for (Joc* it : jocuri){ std::cout << *it;}

    for (auto it : dict)
    {
        std::cout << it.first << " - " << it.second << '\n';
    }
}


bool ascending(Joc* a, Joc* b)
{
    if (a->GetPret() == b->GetPret()) return a->GetNume() < b->GetNume();
    else return a->GetPret() < b->GetPret();
}


void sortare(std::vector <Joc*> jocuri)
{
    sort(jocuri.begin(), jocuri.end(), ascending);

    std::cout << "\n";

    for (Joc* it : jocuri) {std::cout << *it;}

}

int main()
{
    std::vector <Joc*> jocuri;
    std::map <int, int> dict;

    init(jocuri, dict);

    std::cout << "\n\n";

    afisare(jocuri, dict);

    std::cout << "\n\n";

    sortare(jocuri); 

    return 0;
}