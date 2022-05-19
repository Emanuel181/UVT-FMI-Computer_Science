#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <Windows.h>
#include <string.h>
#include <math.h>
#include "UtilityFunctions.h"

int main()
{

    system("pause");
    Sleep(0.016666);  system("clS");
    utility_storeLocationsData();
    utility_storeReviews();

    utility_loadingScreen();

    utility_logare();

    while (1)
    {

        Sleep(0.016666); system("cls");
        fflush(stdin);
        utility_welcome();
        printf("\n***************************************************************************** MENIU PRINCIPAL *******************************************************************************\n\n\n\n\n");

        utility_mainMenus();

        printf("\n");
        printf("*****************************************************************************************************************************************************************************\n\n\n\n\n");

        int option = utility_readUserOptionMeniuPrincipal(); getchar();

        if (option == 1) optiuniLocatii();

        else if (option == 2) pareri_fosti_clienti();

        else if (option == 3) rezerva_loc();

        else if (option == 4) anuleaza_rezervare();

        else if (option == 5) filtrare_optiuni();

        else if (option == 6) adauga_parere();

        else if (option == 7) vezi_cazarileMele();

        else if (option == 8) adauga_locatii();

        else if (option == 9) utility_exit();

    }
    return 0;
}
