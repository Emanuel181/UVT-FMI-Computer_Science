#include "Header.h"
#include <iostream>
using namespace std;


int main()
{
    int n; cin >> n; cin.ignore();
    Vehicul** arr = nullptr;
    arr = init(arr, n);

    print(arr, n);
    return 0;
}