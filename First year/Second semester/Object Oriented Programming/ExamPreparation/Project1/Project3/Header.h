#pragma once
#include <iostream>
#include <vector>
#include "Gradinar.h"
#include <map>
using namespace std;


void init(vector <Gradinar>& arr)
{
    int n; cin >> n; cin.ignore();

    for (int i = 0; i < n; ++i)
    {
        double salariu; cin >> salariu; cin.ignore();
        arr.push_back(Gradinar(salariu));
    }
}


void print(const vector <Gradinar>& arr)
{
    for (const auto& it : arr)
    {
        cout << it.getSalariu() << '\n';
    }
}


void printMap(const map <double, int>& dict)
{
    for (const auto& it : dict)
    {
        cout << it.first << " -> " << it.second << '\n';
    }
}


void createMap(const vector <Gradinar>& arr)
{
    map <double, int> dict;

    for (const auto& it : arr)
    {
        if (dict.find(it.getSalariu()) != dict.end()) ++dict[it.getSalariu()];
        else dict[it.getSalariu()] = 1;
    }

    printMap(dict);
}


void faraMap(const vector <Gradinar>& arr)
{
    int size = arr.size();

    for (int i = 0; i < size - 1; ++i)
    {
        int cnt = 1;
        double salariu_i = arr[i].getSalariu();

        for (int j = i + 1; j < size; ++j)
        {
            if (salariu_i == arr[j].getSalariu()) ++cnt;
        }

        cout << salariu_i << " -> " << cnt << '\n';
    }
}