#include <iostream>
#include "Asociatie.h"
#include "AsociatieDeBloc.h"
#include "AsociatieNonProfit.h"
#include <vector>
#include <string>
using namespace std;


int main()
{
    //a)
    Asociatie a1("Asociatia 1", "27/05/2019");
    cout << a1 << "\n\n";


    vector <string> arr;
    arr.push_back("Ion Ilea");
    arr.push_back("Jurca Elena");
    arr.push_back("Dan Costache");
    arr.push_back("Dumitru Rusu");
    AsociatieDeBloc ab1(arr, "Asociatie bloc 1", "13/02/2017");
    cout << ab1 << "\n\n";


    AsociatieNonProfit anp1("mediu", 897.56, "Salvati natura", "14/04/2018");
    cout << anp1 << "\n\n";

    //b)
    vector <Asociatie*> arrA;

    Asociatie* pAsociatie = &a1;

    AsociatieDeBloc* pAsociatieDeBloc = &ab1;

    AsociatieNonProfit* pAsociatieNonProfit = &anp1;

    arrA.push_back(pAsociatie);
    arrA.push_back(pAsociatieDeBloc);
    arrA.push_back(pAsociatieNonProfit);

    for (const auto& it : arrA) cout << *it << "\n\n";

    //c)

    for (int i = 0; i < 3; ++i)
    {
        for (int j = i + 1; j < 3; ++j)
        {
            if (arrA[i] > arrA[j]) swap(arrA[i], arrA[j]);
        }
    }

    cout << "\n\n";

    for (const auto& it : arrA) cout << *it << "\n\n";


    //d)

    int cnt = 0;

    for (int i = 0; i < 3; ++i)
    {
        if (dynamic_cast <AsociatieNonProfit*>(arrA[i])) ++cnt;
    }

    cout << cnt;

    return 0;
}