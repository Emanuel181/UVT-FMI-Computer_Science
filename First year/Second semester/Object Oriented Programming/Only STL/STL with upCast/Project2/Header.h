#pragma once
#include <iostream>
#include <vector>
#include "Joc.h"
#include "WarCraft.h"
#include "JocStrategie.h"
#include "JocArcade.h"
#include <map>
#include <algorithm>

void initJoc(std::vector <Joc*>& jocuri, std::map <int, int>& dict)
{
    std::string nume; getline(std::cin, nume);
    unsigned long long an; std::cin >> an; std::cin.ignore();

    if (dict.find(an) != dict.end()) ++dict[an];
    else dict[an] = 1;

    double pret; std::cin >> pret;
    jocuri.push_back(new Joc(an, pret, nume));
}


void initArcade(std::vector <Joc*>& jocuri, std::map <int, int>& dict)
{
    std::string nume; getline(std::cin, nume);
    unsigned long long an; std::cin >> an; std::cin.ignore();

    if (dict.find(an) != dict.end()) ++dict[an];
    else dict[an] = 1;

    double pret; std::cin >> pret; std::cin.ignore();

    std::string firma; getline(std::cin, firma);
    jocuri.push_back(new JocArcade(firma, an, pret, nume));
}


void initStrategie(std::vector <Joc*>& jocuri, std::map <int, int>& dict)
{
    std::string nume; getline(std::cin, nume);
    unsigned long long an; std::cin >> an; std::cin.ignore();

    if (dict.find(an) != dict.end()) ++dict[an];
    else dict[an] = 1;

    double pret; std::cin >> pret; std::cin.ignore();

    std::string tema; getline(std::cin, tema);
    jocuri.push_back(new JocStrategie(tema, an, pret, nume));
}


void initWarCraft(std::vector <Joc*>& jocuri, std::map <int, int>& dict)
{
    std::string versiune; getline(std::cin, versiune);
    unsigned long long an; std::cin >> an; std::cin.ignore();

    if (dict.find(an) != dict.end()) ++dict[an];
    else dict[an] = 1;

    double pret; std::cin >> pret; std::cin.ignore();

    std::string tema; getline(std::cin, tema);
    std::string infos; getline(std::cin, infos);
    jocuri.push_back(new WarCraft(versiune, an, infos, tema, an, pret, versiune));
}
