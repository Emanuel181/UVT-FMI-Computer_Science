#include <iostream>
#include "Planta.h"
#include "Arbust.h"
#include "Pom.h"
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;


int val;


bool arbust(Planta* i)
{
    if (dynamic_cast <Arbust*>(i)) return 1;
    return 0;
}


bool biggerThan(Planta* i)
{
    if (i->getPret() > val)
    {
        cout << *i << "\n\n";
        return 1;
    }
    return 0;
}


bool arbustNeornamental(Planta* i)
{
    if (dynamic_cast <Arbust*>(i))
    {
        Arbust* arb = dynamic_cast <Arbust*>(i);
        if (arb->getValue() == 1) return 1;
    }
    return 0;
}


bool arbustOrnamental(Planta* i)
{
    if (dynamic_cast <Arbust*>(i))
    {
        Arbust* arb = dynamic_cast <Arbust*>(i);
        if (arb->getValue() == 0) return 1;
    }
    return 0;
}


int main()
{
    vector <Planta*> arr;

    Planta* planta1 = new Planta("Africa", "specie 1", 213.45);
    Planta* planta2 = new Planta("Asia", "specie 2", 89.45);
    Planta* planta3 = new Planta("Europa", "specie 3", 73.45);

    Pom* pom1 = new Pom(1, "Europa", "Specie 7", 500.78);
    Pom* pom2 = new Pom(0, "Finlanda", "Specie 10", 60.78);

    Arbust* arbust1 = new Arbust(0, "America", "Specie 45", 567.90);
    Arbust* arbust2 = new Arbust(1, "America", "Specie 49", 7.90);

    arr.push_back(planta1);
    arr.push_back(planta2);
    arr.push_back(planta3);
    arr.push_back(pom1);
    arr.push_back(pom2);
    arr.push_back(arbust1);
    arr.push_back(arbust2);


    for (const auto& it : arr) cout << *it << "\n\n";

    int cnt = count_if(arr.begin(), arr.end(), arbust);

    cout << cnt;

    cout << "\n\n";

    cin >> val; cin.ignore();

    int cnt2 = count_if(arr.begin(), arr.end(), biggerThan);

    cout << cnt << "\n\n";

    int cnt3 = 0, cnt4 = 0;

    cnt3 = count_if(arr.begin(), arr.end(), arbustNeornamental);

    cnt4 = count_if(arr.begin(), arr.end(), arbustOrnamental);

    cout << "Sunt " << cnt3 << " arbusti neornamentali\n\n";

    cout << "Sunt " << cnt3 << " arbusti Ornamentali\n\n";

    map <string, bool> dict;

    for (int i = 0; i < arr.size(); ++i)
    {

        if (dynamic_cast <Arbust*>(arr[i]))
        {
            if (dict.find("Arbust") == dict.end()) dict["Arbust"] = 1;
        }

        else if (dynamic_cast <Pom*>(arr[i]))
        {
            if (dict.find("Pom") == dict.end()) dict["Pom"] = 1;
        }
        
        else if (dynamic_cast <Planta*>(arr[i]))
        {
            if (dict.find("Planta") == dict.end()) dict["Planta"] = 1;
        }
    }

    for (const auto& it : dict)
    {
        cout << it.first << '\n';
    }

    cout << "\n\n";


    return 0;
}