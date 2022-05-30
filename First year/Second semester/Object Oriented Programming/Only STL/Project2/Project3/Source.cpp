#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <set>
using namespace std;

/*
    [TASK]:
    Cititi cuvintele dintr-un fisier text folosind iteratorii de 
    intrare si pentru fisiere (ifstream). Se considera ca cuvintele 
    se separa prin spatiu. Stocati cuvintele într-un vector, sortati 
    vectorul si eliminati duplicatele din vector.

*/

ifstream fin("Text.txt");

bool ascending(string a, string b) { return a < b; }

int main()
{

    vector <string> arr;
    istream_iterator <string> eos;
    istream_iterator <string> it (fin);

    string word;

    while (it != eos)
    {
        arr.push_back(* it);
        ++it;
    }

   sort(arr.begin(), arr.end(), ascending);

   for (auto it : arr) cout << it << '\n';

   
   set <string> arrUnique;

   for (auto it : arr) { arrUnique.insert(it); }

   cout << '\n';

   for (auto it : arrUnique) cout << it << '\n';

    return 0;
}