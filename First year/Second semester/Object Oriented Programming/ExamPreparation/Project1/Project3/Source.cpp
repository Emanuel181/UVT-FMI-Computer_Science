#include <iostream>
#include <vector>
#include "Gradinar.h"
#include "Header.h"
using namespace std;


int main()
{
    vector <Gradinar> arr;
    init(arr);
    cout << '\n';
    print(arr);
    cout << '\n';
    createMap(arr);
    cout << '\n';
    faraMap(arr);

    return 0;
}

/*
210.532
324.3
324.63
234.63
22.2
12312.56
*/