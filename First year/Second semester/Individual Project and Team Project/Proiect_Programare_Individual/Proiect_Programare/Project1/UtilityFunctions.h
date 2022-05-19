#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <Windows.h>
#include <string.h>
#include <math.h>
#include<sys/stat.h>


int cntPareri, cntHoteluri, NumarDePersoane;
char NumePersoana[101], dataCazare[255];


struct datelocatii {
    char numeLocatie[151];
    char numeHotel[101];
    int id;
    float pret;
    int locuriRamase;
    int evaluare;
    float mediePareri;
    int numarPareri;
    int disponibilitate;
}locatie[100];


struct parereClienti {
    char Locatie[151];
    char Hotel[101];
    char numePrenume[55];
    char txt[401];
    float nota;
    int ID;
}parere[100];


struct persoana
{
    char nume[55];
    struct persoana* next;
};


struct persoana* head = NULL;


void adauga_locatii()
{
    Sleep(0.016666);  system("clS");
    printf("******************************************************************** MENIU DE ADAUGAT LOCATII - ADMIN ONLY ******************************************************************\n\n\n\n");
    char var[151];

    printf("\t\t\t\t\t\t\t\t\t     Numele locatiei: "); scanf("%s", var);
    printf("\n");

    printf("\t\t\t\t\t\t\t\t\t     Numele hotelului: "); scanf("%s", var);
    printf("\n");
    strcpy(locatie[cntHoteluri].numeHotel, var);

    printf("\t\t\t\t\t\t\t\t\t     ID: %i", cntHoteluri);
    printf("\n\n");
    locatie[cntHoteluri].id = cntHoteluri;

    printf("\t\t\t\t\t\t\t\t\t     Pretul pe noapte: "); scanf("%s", var);
    printf("\n");
    locatie[cntHoteluri].pret = atof(var);

    printf("\t\t\t\t\t\t\t\t\t     Locuri ramase: "); scanf("%s", var);
    printf("\n");
    locatie[cntHoteluri].locuriRamase = atoi(var);

    printf("\t\t\t\t\t\t\t\t\t     Numar de stele: "); scanf("%s", var);
    printf("\n");
    locatie[cntHoteluri].evaluare = atoi(var);

    printf("\t\t\t\t\t\t\t\t\t     Medie pareri clienti: "); scanf("%s", var);
    printf("\n");
    locatie[cntHoteluri].mediePareri = atof(var);

    printf("\t\t\t\t\t\t\t\t\t     Numarul de pareri: "); scanf("%s", var);
    printf("\n");
    locatie[cntHoteluri].numarPareri = atoi(var);

    printf("\t\t\t\t\t\t\t\t\t     Disponibilitate (1 sau 0): "); scanf("%s", var);
    printf("\n");
    locatie[cntHoteluri].disponibilitate = atoi(var);

    ++cntHoteluri;

}


void utility_welcome()
{
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t  Bine ai venit %s !\n\n\n\n", NumePersoana);
}


void utility_loadingScreen()
{
    printf("\n\n\n\n\n\n\n\n");
    system("color 0A");

    printf("******************************************************************** PROIECT - APLICATIE DE TURISM **************************************************************************\n\n\n\n");
    printf("                                                                              RUSU EMANUEL\n\n\n\n");
    system("color 0A");

    char a = 177, b = 219;

    printf("\n\n\n\t\t\t\t\t\t\t\t\t       Loading...\n\n");
    printf("\t\t\t\t\t");


    for (int i = 0; i < 80; i++)
        printf("%c", a);

    printf("\r");
    printf("\t\t\t\t\t");


    for (int i = 0; i < 80; i++) {
        printf("%c", b);
        Sleep(170);
    }

    printf("\n\n\n\n");

    printf("*****************************************************************************************************************************************************************************\n\n\n");

    printf("Finalizam imediat, se pregateste meniul de logare...");
    Sleep(7500);
}


void utility_createAcc()
{
    system("cls");
    printf("************************************************************************** MENIU CREARE CONT ******************************************************************************\n\n\n\n");

    char nume[101], pass[101], adresa[101], telefon[30];

    FILE* cont = fopen("conturi.txt", "a");

    printf("\t\t\t\t\t\t    Nume de utilizator(in loc de spatii folositi \"-\" sau \"_\" ): "); scanf("%s", nume); getchar();

    printf("\n");

    printf("\t\t\t\t\t\t\t\t\t    Parola(fara spatii): "); scanf("%s", pass); getchar();

    printf("\n");

    printf("\t\t\t\t\t\t\t\t\t    adresa gmail: "); scanf("%s", adresa); getchar();

    printf("\n");

    printf("\t\t\t\t\t\t\t\t\t    numar de telefon: "); scanf("%s", telefon); getchar();

    fprintf(cont, "%s\n", nume);
    fprintf(cont, "%s\n", pass);
    fprintf(cont, "%s\n", adresa);
    fprintf(cont, "%s\n", telefon);
    fprintf(cont, "%s\n", pass);
    fprintf(cont, "%s\n\n", nume);

    fclose(cont);

    strcpy(NumePersoana, nume);

    return;

}


int utility_intraInCont()
{
    char nume[101], pass[101];

    printf("\n\t\t\t\t\t\t\t\t\t    Nume de utilizator: "); scanf("%s", nume);

    printf("\n");

    printf("\t\t\t\t\t\t\t\t\t    Parola: "); scanf("%s", pass);

    FILE* cont = fopen("conturi.txt", "r");

    if (cont == NULL)
    {
        printf("\n\n\t\t\t\t    Utilizati aplicatia pentru prima data, nu exista conturi, redirectionam catre meniul de creare de cont...");
        Sleep(7000);
        utility_createAcc();
    }
    else
    {

        char checkName[101], checkPass[101];

        int ok = 0;

        while (fgets(checkName, 101, cont))
        {
            checkName[strlen(checkName) - 1] = '\0';
            if (strcmp(checkName, nume) == 0)
            {
                fgets(checkPass, 101, cont);
                checkPass[strlen(checkPass) - 1] = '\0';
                if (strcmp(checkPass, pass) == 0)
                {
                    ok = 1;
                    break;
                }
            }
        }

        if (ok == 0) return 0;


        else
        {
            strcpy(NumePersoana, nume);
            return 1;
        }
    }
}


void gasireParola()
{
    printf("\n\n\t\t\t\t\t\t\t\t\t    [1] Mai stiu adresa\n");
    printf("\t\t\t\t\t\t\t\t\t    [2] Mai stiu numarul de telefon\n");
    printf("\t\t\t\t\t\t\t\t\t    [3] Nu mai stiu niciuna\n\n\n");

    int option; 
    printf("\t\t\t\t\t\t\t\t\t    Ce va mai amintiti?: "); scanf("%i", &option);

    if (option == 1)
    {
        char adresa[101];

        printf("\n\t\t\t\t\t\t\t\t\t    Scrieti adresa: "); scanf("%s", adresa);

        printf("\n");

        FILE* cont = fopen("conturi.txt", "r");

        if (cont == NULL)
        {
            printf("\n\n\t\t\t\t    Utilizati aplicatia pentru prima data, nu exista conturi, redirectionam catre meniul de creare de cont...");
            Sleep(7000);
            utility_createAcc();
        }

        else
        {
            char check[101];

            int ok = 0;

            while (fgets(check, 101, cont))
            {
                check[strlen(check) - 1] = '\0';
                if (strcmp(check, adresa) == 0)
                {
                    fgets(check, 101, cont);
                    fgets(check, 101, cont);
                    printf("\n\t\t\t\t\t\t\t\t\t    Parola este: %s", check);
                    system("pause");
                }
            }
        }
   }

    if (option == 2)
    {
        char adresa[101];

        printf("\n\t\t\t\t\t\t\t\t\t    Scrieti numarul de telefon: "); scanf("%s", adresa);

        printf("\n");

        FILE* cont = fopen("conturi.txt", "r");

        if (cont == NULL)
        {
            printf("\n\n\t\t\t\t    Utilizati aplicatia pentru prima data, nu exista conturi, redirectionam catre meniul de creare de cont...");
            Sleep(7000);
            utility_createAcc();
        }

        else
        {
            char check[101];

            int ok = 0;

            while (fgets(check, 101, cont))
            {
                check[strlen(check) - 1] = '\0';
                if (strcmp(check, adresa) == 0)
                {
                    fgets(check, 101, cont);
                    printf("\n\t\t\t\t\t\t\t\t\t    Parola este: %s", check);
                    system("pause");
                }
            }
        }
    }

    else
    {
        printf("Contul este pierdut :(");
        exit(0);
    }

}


void gasireNumeUtilizator()
{
    printf("\n\n\t\t\t\t\t\t\t\t\t    [1] Mai stiu adresa\n");
    printf("\t\t\t\t\t\t\t\t\t    [2] Mai stiu numarul de telefon\n");
    printf("\t\t\t\t\t\t\t\t\t    [3] Mai stiu parola\n");
    printf("\t\t\t\t\t\t\t\t\t    [4] Nu mai stiu niciuna\n\n\n");

    int option;
    printf("\t\t\t\t\t\t\t\t\t    Ce va mai amintiti?: "); scanf("%i", &option);

    if (option == 1)
    {
        char adresa[101];

        printf("\n\t\t\t\t\t\t\t\t\t    Scrieti adresa: "); scanf("%s", adresa);

        printf("\n");

        FILE* cont = fopen("conturi.txt", "r");

        if (cont == NULL)
        {
            printf("\n\n\t\t\t\t    Utilizati aplicatia pentru prima data, nu exista conturi, redirectionam catre meniul de creare de cont...");
            Sleep(7000);
            utility_createAcc();
        }

        else
        {
            char check[101];

            int ok = 0;

            while (fgets(check, 101, cont))
            {
                check[strlen(check) - 1] = '\0';
                if (strcmp(check, adresa) == 0)
                {
                    fgets(check, 101, cont);
                    fgets(check, 101, cont);
                    fgets(check, 101, cont);
                    printf("\n\t\t\t\t\t\t\t\t\t    Numele de utilizator este: %s\n", check);
                    system("pause");
                    printf("\n\n");
                }
            }
        }
    }

    if (option == 2)
    {
        char adresa[101];

        printf("\n\t\t\t\t\t\t\t\t\t    Scrieti numarul de telefon: "); scanf("%s", adresa);

        printf("\n");

        FILE* cont = fopen("conturi.txt", "r");

        if (cont == NULL)
        {
            printf("\n\n\t\t\t\t    Utilizati aplicatia pentru prima data, nu exista conturi, redirectionam catre meniul de creare de cont...");
            Sleep(7000);
            utility_createAcc();
        }

        else
        {
            char check[101];

            int ok = 0;

            while (fgets(check, 101, cont))
            {
                check[strlen(check) - 1] = '\0';
                if (strcmp(check, adresa) == 0)
                {
                    fgets(check, 101, cont);
                    fgets(check, 101, cont);
                    printf("\n\t\t\t\t\t\t\t\t\t    Numele de utilizator este: %s", check);
                    system("pause");
                }
            }
        }
    }

    if (option == 3)
    {
        char adresa[101];

        printf("\n\t\t\t\t\t\t\t\t\t    Scrieti parola: "); scanf("%s", adresa);

        printf("\n");

        FILE* cont = fopen("conturi.txt", "r");

        if (cont == NULL)
        {
            printf("\n\n\t\t\t\t    Utilizati aplicatia pentru prima data, nu exista conturi, redirectionam catre meniul de creare de cont...");
            Sleep(7000);
            utility_createAcc();
        }

        else
        {
            char check[101];

            int ok = 0;

            while (fgets(check, 101, cont))
            {
                check[strlen(check) - 1] = '\0';
                if (strcmp(check, adresa) == 0)
                {
                    fgets(check, 101, cont);
                    fgets(check, 101, cont);
                    fgets(check, 101, cont);
                    fgets(check, 101, cont);
                    printf("\n\t\t\t\t\t\t\t\t\t    Numele de utilizator este: %s", check);
                    system("pause");
                }
            }
        }
    }

}

void utility_logare()
{
    Sleep(0.016666); system("cls");

    printf("\n\n\n\n\n\n");
    printf("************************************************************************** MENIU CREARE CONT ********************************************************************************\n\n\n\n");


    printf("\t\t\t\t\t\t\t\t\t    [1] Am cont\n\t\t\t\t\t\t\t\t\t    [2] Nu am cont\n\t\t\t\t\t\t\t\t\t    [3] Am uitat parola\n\t\t\t\t\t\t\t\t\t    [4] Am uitat numele de utilizator\n\n\n");

    int option = utility_readUserOptionLogare();

    if (option == 2)
    {
        utility_createAcc();
        return;
       
    }

    if (option == 3)
    {
        gasireParola();
        exit(0);
    }

    if (option == 4)
    {
        gasireNumeUtilizator();
        exit(0);
    }

    else
    {
        int raspuns = utility_intraInCont();
        if (raspuns == 0)
        {
            printf("\n");
            printf("\t\t\t\t\t\t\t\t\t    Se pare ca nu v-am gasit\n");
            printf("\t\t\t\t\t\t\t\t\t    Verificati datele si incercati din nou\n");
            printf("\t\t\t\t\t\t\t\t\t    [1] Reincearca\n");
            printf("\t\t\t\t\t\t\t\t\t    [2] Revino la meniul principal\n\n");

            option = utility_readUserOption();

            if (option == 1) utility_logare();

            else
            {
                strcpy(NumePersoana, "raport.txt");
                Sleep(0.016666); system("cls");
                return;
            }
        }
    }
}


void utility_ReviewMenu()
{
    system("cls");
    printf("\n\n\t\t\t\t\t\t    Multumim ca doriti sa ajutati comunitatea !\n\n");
    printf("\t\t\t\t\t\t    Pregatim pagina de adaugat pareri...");
    Sleep(4500);
}


void utility_exit()
{
    Sleep(0.016666); system("cls");

    FILE* ptr = fopen("raport.txt", "w");

    fprintf(ptr, "  ");

    fclose(ptr);

    exit(0);
}


int utility_readUserOptionAdaugaParere()
{
    int option;
    printf("\t\t\t\t\t\t\t\t\t    Numarul actiunii: ");
    scanf("%i", &option);

    return option;
}

void adauga_parere()
{
    Sleep(0.016666);  system("cls");
    fflush(stdin);

    printf("*********************************************************************** MENIUL DE ADAUGAT PARERI ****************************************************************************\n\n");
    ++cntPareri;

    char var[150], text[401];
    float mark;
    int poz;

    //printf("\t\t\t\t\t\t\t\t\t    ID-ul hotelului: ");
    int ID = utility_receiveIDForReview();

    printf("\n");

    int ok = utility_checkIDExistanceForReview(ID);

    if (ok == 2)
    {
        printf("\t\t\t\t\t\t    ID-ul nu exista, verificati inca odata\n\n");
        printf("\t\t\t\t\t\t    [1] Revino la meniul principal\n");
        printf("\t\t\t\t\t\t    [2] Opreste Programul\n\n");

        int option = utility_readUserOptionAdaugaParere();

        if (option == 1)
        {
            Sleep(0.016666);  system("cls");
            return;
        }

        utility_exit();

    }

    else
    {
        printf("\t\t\t\t\t\t    Hotelul s-a gasit! \n\n");
        printf("\n");
        poz = utility_findHotelByID(ID);
    }

    printf("\t\t\t\t\t\t    Redirectionam catre pagina de adaugat pareri...");
    Sleep(4500);
    utility_ReviewMenu(poz);
    Sleep(0.016666);  system("cls");
    printf("\n\n\t\t\t\t\t\t    Puteti inncepe: \n\n");

    printf("\t\t\t\t\t\t    Numele locatiei: ");
    strcpy(parere[cntPareri].Locatie, locatie[poz].numeLocatie);
    printf("%s\n", parere[cntPareri].Locatie);

    printf("\t\t\t\t\t\t    Numele Hotelului: ");
    strcpy(parere[cntPareri].Hotel, locatie[poz].numeHotel);
    printf("%s\n", parere[cntPareri].Hotel);

    printf("\t\t\t\t\t\t    Numele tau : ");
    scanf("%s", var);
    var[strlen(var) + 1] = '\0';
    strcpy(parere[cntPareri].numePrenume, var);
    printf("\n");
    while ((getchar()) != '\n');

    printf("\t\t\t\t\t\t    Parerea ta: ");
    fgets(text, 400, stdin);
    strcpy(parere[cntPareri].txt, text);
    printf("\n");


    printf("\t\t\t\t\t\t    Nota: ");
    scanf("%f", &mark);
    parere[cntPareri].nota = mark;
    printf("\n\n");


    printf("\t\t\t\t\t\t    Review-ul dumneavoastra a fost adaugat. Multumim !\n\n");
    printf("\t\t\t\t\t\t    [1] Adaugati alt review\n");
    printf("\t\t\t\t\t\t    [2] Reveniti la meniul principal\n\n");

    int option = utility_readUserOptionAdaugaParere();

    if (option == 1) adauga_parere();

    else
    {
        printf("\n\n\t\t\t\t\t\t    Redirectionam catre meniul principal...");
        Sleep(4500);
    }
}


void utility_printLocations()
{
    for (int i = 0; i < cntHoteluri; ++i)
    {
        if (locatie[i].locuriRamase > 0)
        {
            Sleep(2500);
            printf("                           -----------------------------------------------------------------\n\n");
            printf("                                        Locatie: ");
            printf("%s\n", locatie[i].numeLocatie);

            printf("                                        Nume Hotel: ");
            printf("%s\n", locatie[i].numeHotel);

            printf("                                        ID: ");
            printf("%i\n", locatie[i].id);

            printf("                                        Pret: ");
            printf("%f\n", locatie[i].pret);

            printf("                                        Locuri Ramase: ");
            printf("%i\n", locatie[i].locuriRamase);

            printf("                                        Numar de stele: ");
            printf("%i\n", locatie[i].evaluare);

            printf("                                        Medie Review-uri: ");
            printf("%f\n", locatie[i].mediePareri);

            printf("                                        Numar de Review-uri: ");
            printf("%i\n", locatie[i].numarPareri);

            printf("                                        Disponibilitate: ");
            printf(locatie[i].disponibilitate == 0 ? "Nu mai este disponibil\n\n" : "Este disponibil\n\n");

            printf("                           -----------------------------------------------------------------\n\n");
        }

    }

    //if ((n+1) % 2) 

}


void utility_printLocationsByLocationName(char arg[])
{
    int check = 0;

    for (int i = 0; i < cntHoteluri; i++)
    {
        int ok = 1;

        for (int j = 0; j < strlen(arg); j++)
        {
            if (tolower(arg[j]) != tolower(locatie[i].numeLocatie[j])) {
                ok = 0;
                break;
            }
        }

        if (ok == 1)
        {
            check = 1;
            printf("\t\t\t\t\t\t\t\t    ---------------------------------------\n\n");
            printf("\t\t\t\t\t\t\t\t    Locatie: ");
            printf("%s", locatie[i].numeLocatie);

            printf("\t\t\t\t\t\t\t\t    Nume Hotel: ");
            printf("%s", locatie[i].numeHotel);

            printf("\t\t\t\t\t\t\t\t    ID: ");
            printf("%i\n", locatie[i].id);

            printf("\t\t\t\t\t\t\t\t    Pret: ");
            printf("%f\n", locatie[i].pret);

            printf("\t\t\t\t\t\t\t\t    Locuri Ramase: ");
            printf("%i\n", locatie[i].locuriRamase);

            printf("\t\t\t\t\t\t\t\t    Numar de stele: ");
            printf("%i\n", locatie[i].evaluare);

            printf("\t\t\t\t\t\t\t\t    Medie Review-uri: ");
            printf("%f\n", locatie[i].mediePareri);

            printf("\t\t\t\t\t\t\t\t    Numar de Review-uri: ");
            printf("%i\n", locatie[i].numarPareri);

            printf("\t\t\t\t\t\t\t\t    Disponibilitate: ");
            printf(locatie[i].disponibilitate == 0 ? "Nu mai este disponibil\n\n" : "Este disponibil\n\n");

            printf("\t\t\t\t\t\t\t\t    ---------------------------------------\n\n");
        }
    }

    if (check == 0) printf("Nu exista hoteluri in aceasta locatie\n\n\n\n");

}


void utility_printLocationsByReviewsNumber(int num)
{
    int check = 0;

    for (int i = 0; i < cntHoteluri; i++)
    {
        if (locatie[i].numarPareri >= num)
        {
            check = 1;
            printf("\t\t\t\t\t\t\t\t    ---------------------------------------\n\n");
            printf("\t\t\t\t\t\t\t\t    Locatie: ");
            printf("%s", locatie[i].numeLocatie);

            printf("\t\t\t\t\t\t\t\t    Nume Hotel: ");
            printf("%s", locatie[i].numeHotel);

            printf("\t\t\t\t\t\t\t\t    ID: ");
            printf("%i\n", locatie[i].id);

            printf("\t\t\t\t\t\t\t\t    Pret: ");
            printf("%f\n", locatie[i].pret);

            printf("\t\t\t\t\t\t\t\t    Locuri Ramase: ");
            printf("%i\n", locatie[i].locuriRamase);

            printf("\t\t\t\t\t\t\t\t    Numar de stele: ");
            printf("%i\n", locatie[i].evaluare);

            printf("\t\t\t\t\t\t\t\t    Medie Review-uri: ");
            printf("%f\n", locatie[i].mediePareri);

            printf("\t\t\t\t\t\t\t\t    Numar de Review-uri: ");
            printf("%i\n", locatie[i].numarPareri);

            printf("\t\t\t\t\t\t\t\t    Disponibilitate: ");
            printf(locatie[i].disponibilitate == 0 ? "Nu mai este disponibil\n\n" : "Este disponibil\n\n");

            printf("\t\t\t\t\t\t\t\t    ---------------------------------------\n\n");
        }
    }

    if (check == 0) printf("\t\t\t\t\t\t\t\t    Nu exista hoteluri cu acest numar minim de pareri\n\n\n\n");

}


void utility_printLocationsByMean(int num)
{
    int check = 0;

    for (int i = 0; i < cntHoteluri; i++)
    {
        if ((int)((locatie[i].mediePareri)) >= num)
        {
            check = 1;
            printf("\t\t\t\t\t\t\t\t    ---------------------------------------\n\n");
            printf("\t\t\t\t\t\t\t\t    Locatie: ");
            printf("%s", locatie[i].numeLocatie);

            printf("\t\t\t\t\t\t\t\t    Nume Hotel: ");
            printf("%s", locatie[i].numeHotel);

            printf("\t\t\t\t\t\t\t\t    ID: ");
            printf("%i\n", locatie[i].id);

            printf("\t\t\t\t\t\t\t\t    Pret: ");
            printf("%f\n", locatie[i].pret);

            printf("\t\t\t\t\t\t\t\t    Locuri Ramase: ");
            printf("%i\n", locatie[i].locuriRamase);

            printf("\t\t\t\t\t\t\t\t    Numar de stele: ");
            printf("%i\n", locatie[i].evaluare);

            printf("\t\t\t\t\t\t\t\t    Medie Review-uri: ");
            printf("%f\n", locatie[i].mediePareri);

            printf("\t\t\t\t\t\t\t\t    Numar de Review-uri: ");
            printf("%i\n", locatie[i].numarPareri);

            printf("\t\t\t\t\t\t\t\t    Disponibilitate: ");
            printf(locatie[i].disponibilitate == 0 ? "Nu mai este disponibil\n\n" : "Este disponibil\n\n");

            printf("\t\t\t\t\t\t\t\t    ---------------------------------------\n\n");
        }
    }

    if (check == 0) printf("\t\t\t\t\t\t\t\t    Nu exista hoteluri cu aceasta medie minima\n\n\n\n");

}


void utility_printReviews(int n, int ID)
{
    printf("************************************************************************** PARERI FOSTI CLIENTI *****************************************************************************\n\n");

    if (ID == -1)
    {
        for (int i = 0; i <= n; ++i)
        {
            Sleep(2000);
            printf("                                            -------------------------------------------------------------------------\n\n");
            printf("                                                            Loc: ");
            printf("%s\n", parere[i].Locatie);

            printf("                                                            Nume Hotel: ");
            printf("%s\n", parere[i].Hotel);

            printf("                                                            Nume si Prenume: ");
            printf("%s\n", parere[i].numePrenume);

            printf("                          Parere: ");
            for (int j = 0; j < strlen(parere[i].txt); j++)
                if (parere[i].txt[j] != '\\')
                    printf("%c", parere[i].txt[j]);
                else
                {
                    printf(" ");
                    parere[i].txt[j + 1] = ' ';
                    strcpy(parere[i].txt + j, parere[i].txt + j + 1);
                }

            printf("\n");

            printf("                                                            Nota: ");
            printf("%f\n", parere[i].nota);
            printf("                                                            ID: %i\n\n", parere[i].ID);

            printf("                                            ----------------------------------------------------------------------------\n\n");

        }

        printf("*****************************************************************************************************************************************************************************\n\n");
    }

    else
    {
        for (int i = 0; i <= n; ++i)
        {
            if (parere[i].ID == ID)
            {
                Sleep(2000);
                printf("                                            -------------------------------------------------------------------------\n\n");
                printf("                                                            Loc: ");
                printf("%s\n", parere[i].Locatie);

                printf("                                                            Nume Hotel: ");
                printf("%s\n", parere[i].Hotel);

                printf("                                                            Nume si Prenume: ");
                printf("%s\n", parere[i].numePrenume);

                printf("                          Parere: ");
                for (int j = 0; j < strlen(parere[i].txt); j++)
                    if (parere[i].txt[j] != '\\')
                        printf("%c", parere[i].txt[j]);
                    else
                    {
                        printf(" ");
                        parere[i].txt[j + 1] = ' ';
                        strcpy(parere[i].txt + j, parere[i].txt + j + 1);
                    }

                printf("\n");

                printf("                                                            Nota: ");
                printf("%f\n", parere[i].nota);
                printf("                                                            ID: %i\n\n", parere[i].ID);

                printf("                                            ----------------------------------------------------------------------------\n\n");
            }

        }

        printf("*****************************************************************************************************************************************************************************\n\n");
    }



    //if ((n + 1) % 2) 
}


void utility_storeLocationsData()
{
    FILE* locatii = fopen("locuri.txt", "r");
    char var[151];

    while (fgets(var, 150, locatii))
    {
        if (var[0] == '-') cntHoteluri++;

        else
        {
            strcpy(locatie[cntHoteluri].numeLocatie, var);

            fgets(var, 150, locatii);
            strcpy(locatie[cntHoteluri].numeHotel, var);

            fgets(var, 150, locatii);
            locatie[cntHoteluri].id = atoi(var);

            fgets(var, 150, locatii);
            locatie[cntHoteluri].pret = atof(var);

            fgets(var, 150, locatii);
            locatie[cntHoteluri].locuriRamase = atoi(var);

            fgets(var, 150, locatii);
            locatie[cntHoteluri].evaluare = atoi(var);

            fgets(var, 150, locatii);
            locatie[cntHoteluri].mediePareri = atof(var);

            fgets(var, 150, locatii);
            locatie[cntHoteluri].numarPareri = atoi(var);

            fgets(var, 150, locatii);
            locatie[cntHoteluri].disponibilitate = atoi(var);
        }
    }
}


int utility_readUserOption()
{
    int option;
    printf("\t\t\t\t\t\t\t\t\t    Numarul actiunii: ");
    scanf("%i", &option);

    return option;
}

int utility_readUserOptionIDHotel()
{
    int option;
    printf("\t\t\t\t\t\t\t    Numarul actiunii: ");
    scanf("%i", &option);

    return option;
}

int utility_readUserOptionMeniuPrincipal()
{
    int option;
    printf("\t\t\t\t\t\t\t\t\t    Numarul actiunii: ");
    scanf("%i", &option);

    return option;
}

int utility_readUserOptionLogare()
{
    int option;
    printf("\t\t\t\t\t\t\t\t\t    Numarul actiunii: ");
    scanf("%i", &option);

    return option;
}


void utility_mainMenus()
{
    printf("                                                                            [1] Optiuni\n");
    printf("                                                                            [2] Pareri Fosti Clienti\n");
    printf("                                                                            [3] Rezerva loc\n");
    printf("                                                                            [4] Anuleaza Rezervarea\n");
    printf("                                                                            [5] Filtreaza optiuni\n");
    printf("                                                                            [6] Adauga un review\n");
    printf("                                                                            [7] Vezi cazarile mele\n");
    printf("                                                                            [8] Adauga locatii [ ADMIN ONLY ]\n");
    printf("                                                                            [9] Oprire Program\n\n\n\n\n");
}


void utility_storeReviews()
{
    FILE* opinii = fopen("pareri.txt", "r");
    char store[255];


    while (fgets(store, 255, opinii))
    {
        if (store[0] == '-') cntPareri++;

        else
        {
            strcpy(parere[cntPareri].Locatie, store);

            fgets(store, 255, opinii);
            strcpy(parere[cntPareri].Hotel, store);

            fgets(store, 255, opinii);
            strcpy(parere[cntPareri].numePrenume, store);

            fgets(store, 255, opinii);
            strcpy(parere[cntPareri].txt, store);

            fgets(store, 255, opinii);
            parere[cntPareri].nota = atof(store);

            fgets(store, 255, opinii);
            parere[cntPareri].ID = atoi(store);

        }
    }

}


void optiuniLocatii()
{
    Sleep(0.016666);  system("clS");
    fflush(stdin);
    printf("*************************************************************************** LOCATIILE DISPONIBILE **********************************************************************\n\n\n");

    utility_printLocations();

    printf("*********************************************************************************************************************************************************************\n\n\n");

    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t\t    [1] Revino la meniul principal\n");
    printf("\t\t\t\t\t\t\t\t\t    [2] Opreste Programul\n\n");

    getchar();
    int option = utility_readUserOption();

    if (option == 1)
    {
        system("cls");
        return;
    }

    else if (option == 2)  utility_exit();
}


int utility_Dubleaza(int num)
{
    if (num > 9) return ((num % 10) + (num / 10));

    return num;
}


int utility_CheckIBAN(char IBAN[])
{
    int sum = 0;

    for (int i = strlen(IBAN) - 1; i >= 0; --i)
    {
        if (i % 2 == 0)
        {
            int num = (int)((IBAN[i] - '0') * 2);
            sum = sum + utility_Dubleaza(num);
        }

        else sum = sum + (IBAN[i] - '0');
    }

    return ((sum % 10) == 0);
}


int utility_CheckPrefix(char IBAN[])
{
    return ((IBAN[0] - '0' == 4) || (IBAN[0] - '0' == 5) || (IBAN[0] - '0' == 6) || (IBAN[0] - '0' == 3 && IBAN[1] - '0' == 7));
}


int utility_CheckLength(char IBAN[])
{
    int a = strlen(IBAN);
    --a;

    return (a >= 13) && (a <= 16);
}


int utility_CheckLengthCVV(char cvv[])
{
    return (strlen(cvv) >= 3 && strlen(cvv) <= 4);
}


int utility_CheckCVV(char cvv[])
{
    for (int i = 0; i < strlen(cvv); ++i)
    {
        if (cvv[i] - '0' != 0 && cvv[i] - '0' != 1 && cvv[i] - '0' != 2 && cvv[i] - '0' != 3 && cvv[i] - '0' != 4 && cvv[i] - '0' != 5 && cvv[i] - '0' != 6 && cvv[i] - '0' != 7 && cvv[i] - '0' != 8 && cvv[i] - '0' != 9) return 0;
    }

    return 1;
}

int utility_readUserOptionPlata()
{
    int option;
    printf("\t\t\t\t\t\t\t    Numarul actiunii: ");
    scanf("%i", &option);

    return option;
}

void utility_SitemDePlata()
{
    Sleep(0.016666);  system("clS");
    fflush(stdin);

    printf("**************************************************************************** MENIUL DE PLATA ********************************************************************************\n\n\n\n");

    printf("\t\t\t\t\t\t\t    [1] Anularea procesului de plata\n");
    printf("\t\t\t\t\t\t\t    [2] Continua Plata\n\n");

    int option = utility_readUserOptionPlata();

    if (option == 1)  utility_exit();

    char IBAN[40], cvv[40];

    printf("\t\t\t\t\t\t\t    Pentru confirmarea cazarii trebuie sa platiti online cu cardul\n\t\t\t\t\t\t\t    si sa generati raportul de cazare\n\n");
    printf("\t\t\t\t\t\t\t    Neindeplinirea celor 2 pasi va duce la nealocarea cazarii si restituirea banilor \n\n");
    printf("\t\t\t\t\t\t\t    Introduceti IBAN: "); getchar();    scanf("%s", IBAN);

    int checkLength = utility_CheckLength(IBAN);
    int checkPrefix = utility_CheckPrefix(IBAN);
    int ok = utility_CheckIBAN(IBAN);

    if ((checkLength != 0 && checkPrefix != 0 && ok != 0))
    {
        printf("\t\t\t\t\t\t\t    Card Validat!\n");
        printf("\n");
    }

    else
    {
        printf("%i %i %i\n", checkLength, checkPrefix, ok);
        printf("\t\t\t\t\t\t\t    Cardul nu este valid. Procesul cazarii se opreste.\n");
        printf("\t\t\t\t\t\t\t    [1] Revino la meniul principal\n");
        printf("\t\t\t\t\t\t\t    [2] Reinitiaza plata\n");

        int option = utility_readUserOptionPlata();

        if (option == 1)
        {
            system("cls");
            return;
        }

        else utility_SitemDePlata();
    }


    printf("\t\t\t\t\t\t\t    Introduceti codul de securitate(CVV): "); scanf("%s", cvv);

    int checkLengthCVV = utility_CheckLengthCVV(cvv);
    int okCVV = utility_CheckCVV(cvv);

    if ((checkLengthCVV == 1 && okCVV == 1))
    {
        printf("\t\t\t\t\t\t\t    CVV valid\n");
        printf("\n");
    }

    printf("\t\t\t\t\t\t\t    Plata se proceseaza...\n\n");
    Sleep(3500);
    printf("\t\t\t\t\t\t\t    Plata efectuata cu succes\n\n");

}


void pareri_fosti_clienti()
{
    Sleep(0.016666);  system("clS");

    fflush(stdin);

    printf("********************************************************************* FILTRARE PARERI FOSTI CLIENTI *************************************************************************\n\n");
    printf("\t\t\t\t\t\t\t\t[1] Vreau sa vad parerile locatiilor dupa ID\n");
    printf("\t\t\t\t\t\t\t\t[2] Vreau sa vad parerile de la toate locatiile\n\n");
    int option = utility_readUserOption();

    if (option == 1)
    {
        Sleep(0.016666);  system("clS");

        int ID; printf("\t\t\t\t\t\t\t    ID-ul hotelului dupa care vreti sa cautati: ");  scanf("%i", &ID);

        int ok = utility_checkIDExistanceForReview(ID);

        if (ok == 2)
        {
            printf("ID-ul nu exista, verificati inca odata\n\n");
            printf("[1] Revino la meniul principal\n");
            printf("[2] Opreste Programul\n\n");

            int option = utility_readUserOption();

            if (option == 1)
            {
                Sleep(0.016666);  system("cls");
                return;
            }

            utility_exit();

        }

        else
        {
            printf("\n\n");
            utility_printReviews(cntPareri, ID);

            printf("\t\t\t\t\t\t\t\t\t    [1] Revino la meniul principal\n");
            printf("\t\t\t\t\t\t\t\t\t    [2] Opreste Programul\n\n");

            option = utility_readUserOption();

            if (option == 1)
            {
                Sleep(0.016666); system("cls");
                return;
            }

            if (option == 2) utility_exit();

        }
    }

    else
    {
        Sleep(0.016666); system("cls");
        utility_printReviews(cntPareri, -1);

        printf("\t\t\t\t\t\t\t\t\t    [1] Revino la meniul principal\n");
        printf("\t\t\t\t\t\t\t\t\t    [2] Opreste Programul\n\n");

        option = utility_readUserOption();

        if (option == 1)
        {
            system("cls");
            return;
        }

        if (option == 2) utility_exit();
    }
}

int utility_readUserOptionRaportText()
{
    int option;
    printf("\t\t\t\t\t\t\tNumarul actiunii: ");
    scanf("%i", &option);

    return option;
}

void utility_generare_raport(int i)
{
    Sleep(0.016666); system("cls");

    printf("\n\n\n\n\n************************************************************* MENIUL DE GENERARE RAPORT DE CAZARE IN FORMAT TEXT *********************************************************\n\n\n\n");

    printf("\t\t\t\t\t\t\t[1] Genereaza raport de cazare\n");
    printf("\t\t\t\t\t\t\t[2] Revino la meniul principal\n");
    printf("\t\t\t\t\t\t\t[3] Opreste Programul\n\n");

    int option = utility_readUserOptionRaportText();

    if (option == 1)
    {
        printf("\t\t\t\t\t\t\tSe incepe generarea raportului de cazare...\n\n");
        Sleep(4500);

        char Numeprs[101];

        strcpy(Numeprs, NumePersoana);
        strcat(Numeprs, ".txt");

        FILE* cazare = fopen(Numeprs, "a");
        fprintf(cazare, "Persoane\n");

        struct persoana* temp = head;


        while (temp != NULL)
        {
            fprintf(cazare, "%s\n", (*temp).nume);
            temp = (*temp).next;
        }

        fprintf(cazare, "*****************************\n");
        fprintf(cazare, "In data de: %s\n", dataCazare);
        fprintf(cazare, "Locatie: %s", locatie[i].numeLocatie);
        fprintf(cazare, "Nume Hotel: %s", locatie[i].numeHotel);
        fprintf(cazare, "ID: %i\n", locatie[i].id);
        fprintf(cazare, "Pret: %f\n", locatie[i].pret);
        fprintf(cazare, "Locuri Ramase: %i\n", locatie[i].locuriRamase);
        fprintf(cazare, "Stele: %i\n", locatie[i].evaluare);
        fprintf(cazare, "Medie Review-uri: %f\n", locatie[i].mediePareri);
        fprintf(cazare, "Numar Review-uri%i\n", locatie[i].numarPareri);
        fprintf(cazare, "Disponibilitate: %s\n\n", locatie[i].disponibilitate == 0 ? "Nu este disponibil" : "Este disponibil");
        fprintf(cazare, "*****************************\n\n");

        fclose(cazare);

        locatie[i].locuriRamase -= NumarDePersoane;
    }

    else if (option == 2)
    {
        Sleep(0.016666); system("cls");
        return;
    }

    else if (option == 3)  utility_exit();

    printf("\t\t\t\t\t\t\tRaportul a fost generat, se poate gasi in format text, cazarea\n\t\t\t\t\t\t\ta fost facuta, vom redirectiona catre meniul principal. Multumim!");
    Sleep(4500);
    fflush(stdin);
    Sleep(0.016666); system("cls");

}


int utility_checkLocuriRamase(int persoane, int i)
{
    return ((locatie[i].locuriRamase - persoane) >= 0);
}


int utility_readUserOptionRaportOnline()
{
    int option;
    printf("\t\t\t\t\t\t\t    Numarul actiunii: ");
    scanf("%i", &option);

    return option;
}


void utility_vizualizare_raport_cazare(int poz, int persoane)
{
    printf("**************************************************************************** RAPORT DE CAZARE ONLINE ************************************************************************\n\n\n\n\n");

    printf("\t\t\t\t\t\t\t    Ati ales:\n\n");

    printf("\t\t\t\t\t    ----------------------------------------------------------------------\n\n");
    printf("\t\t\t\t\t\t\t    In data de: "); 
    printf("%s\n", dataCazare);
    printf("\t\t\t\t\t\t\t    Locatie: ");
    printf("%s", locatie[poz].numeLocatie);

    printf("\t\t\t\t\t\t\t    Nume Hotel: ");
    printf("%s", locatie[poz].numeHotel);

    printf("\t\t\t\t\t\t\t    ID: ");
    printf("%i\n", locatie[poz].id);

    printf("\t\t\t\t\t\t\t    Pret: ");
    printf("%f\n", persoane * locatie[poz].pret);

    printf("\t\t\t\t\t\t\t    Locuri Ramase: ");
    printf("%i\n", locatie[poz].locuriRamase);

    printf("\t\t\t\t\t\t\t    Numar de stele: ");
    printf("%i\n", locatie[poz].evaluare);

    printf("\t\t\t\t\t\t\t    Medie Review-uri: ");
    printf("%f\n", locatie[poz].mediePareri);

    printf("\t\t\t\t\t\t\t    Numar de Review-uri: ");
    printf("%i\n", locatie[poz].numarPareri);

    printf("\t\t\t\t\t\t\t    Disponibilitate: ");
    printf(locatie[poz].disponibilitate == 0 ? "Nu mai este disponibil\n\n" : "Este disponibil\n\n");

    printf("\t\t\t\t\t    ----------------------------------------------------------------------\n\n\n\n\n");

    printf("***************************************************************************************************************************************************************************\n\n");


    printf("\t\t\t\t\t\t\t    [1] Confirmati\n");
    printf("\t\t\t\t\t\t\t    [2] Revino la meniul principal\n");
    printf("\t\t\t\t\t\t\t    [3] Opreste Programul\n\n");

    int option = utility_readUserOptionRaportOnline();

    if (option == 1)
    {
        printf("\t\t\t\t\t\t\t    Vom redirectiona catre zona de plata\n\n");
        printf("\t\t\t\t\t\t\t    Daca va razganditi in timpul platii, din motive de securitate a banilor, singura\n\t\t\t\t\t\t\t    posibilitate este de a opri programul\n");
        Sleep(15000);
        utility_SitemDePlata();
        printf("\t\t\t\t\t\t\t    Vom redirectiona catre generarea formularului de cazare...");
        Sleep(4500);
        utility_generare_raport(poz);
    }

    else if (option == 2)
    {
        system("cls");
        return;
    }

    else if (option == 3)  utility_exit();

}


void utility_adaugaPersoana()
{
    struct persoana* om = (struct persoana*)malloc(sizeof(struct persoana));
    char var[80];

    printf("\t\t\t\t\t\t\t    Nume si prenume Persoana(despartite prin linii): ");
    scanf("%s", var);
    var[strlen(var) + 1] = '\0';

    getchar();
    printf("\n");

    strcpy((*om).nume, var);
    (*om).next = NULL;

    if (head == NULL) head = om;

    else
    {
        struct persoana* ptr = head;
        while ((*ptr).next != NULL)
        {
            ptr = (*ptr).next;
        }

        (*ptr).next = om;
    }
}


int utility_findHotelByID(int ID)
{
    int i = 0;

    while (locatie[i].id != ID) i++;

    return i;
}


int utility_getPersonsNumber()
{
    int n;
    Sleep(0.016666); system("cls");

    printf("*********************************************************************** MENIU DE INTRODUCERE A PERSOANLEOR ***************************************************************\n\n");


    printf("\n\n\n");

    printf("\t\t\t\t\t\t\t    Pentru cate persoane se va face cazarea ?\n\n");
    printf("\t\t\t\t\t\t\t    Numar Persoane: "); scanf("%d", &n);
    printf("\n");
    printf("\t\t\t\t\t\t\t    Introduceti numele tuturor persoanelor: \n\n");

    return n;
}


void rezerva_loc()
{
    Sleep(0.016666); system("clS");

    printf("\n\n\n\n\n************************************************************************** MENIU DE REZERVARE A LOCULUI *********************************************************************\n\n\n\n\n");

    printf("\t\t\t\t\t\t\t\t\t    [1] Revino la meniul principal\n");
    printf("\t\t\t\t\t\t\t\t\t    [2] Opreste Programul\n");
    printf("\t\t\t\t\t\t\t\t\t    [3] Continuati\n\n\n\n\n");

    printf("*****************************************************************************************************************************************************************************\n\n\n\n\n");


    int option = utility_readUserOption();

    if (option == 1)
    {
        Sleep(0.016666);  system("cls");
        return;
    }

    else if (option == 2) utility_exit();

    int poz, check;

    printf("\n");
    int ID = utility_getIDForBooking();
    printf("\n");
    printf("\t\t\t\t\t\t\t\t    Se verifica daca ID-ul corespunde unui\n\t\t\t\t\t\t\t\t    hotel si disponibilitatea hotelului...\n\n");
    Sleep(3500);


    int ok = utility_checkAvailabilityAndExistanceForBookingByID(ID);

    if (ok == 3)
    {
        printf("\t\t\t\t\t\t\t\t    ID-ul nu exista, verificati inca odata\n\n");
        printf("\t\t\t\t\t\t\t\t    [1] Revino la meniul principal\n");
        printf("\t\t\t\t\t\t\t\t    [2] Opreste Programul\n\n");

        int option = utility_readUserOptionIDHotel();

        if (option == 1)
        {
            Sleep(0.016666); system("cls");
            return;
        }

        else if (option == 2) utility_exit();

    }

    else if (ok == 2)
    {
        printf("\t\t\t\t\t\t\t\t    Hotelul nu este disponibil deocamdata\n");
        printf("\t\t\t\t\t\t\t\t    Redirectionam catre pagina principala...");
        Sleep(13000);
        return;
    }

    else
    {
        printf("\t\t\t\t\t\t\t\t    Hotelul s-a gasit si este disponibil\n\n\n");
        printf("\t\t\t\t\t\t\t\t    Ati ales:\n\n");
        printf("\t\t\t\t\t\t\t\t    ----------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\t\t\t\t    Locatie: ");
        printf("%s", locatie[ID].numeLocatie);

        printf("\t\t\t\t\t\t\t\t    Nume Hotel: ");
        printf("%s", locatie[ID].numeHotel);

        printf("\t\t\t\t\t\t\t\t    ID: ");
        printf("%i\n", locatie[ID].id);

        printf("\t\t\t\t\t\t\t\t    Pret: ");
        printf("%f\n", locatie[ID].pret);

        printf("\t\t\t\t\t\t\t\t    Locuri Ramase: ");
        printf("%i\n", locatie[ID].locuriRamase);

        printf("\t\t\t\t\t\t\t\t    Numar de stele: ");
        printf("%i\n", locatie[ID].evaluare);

        printf("\t\t\t\t\t\t\t\t    Medie Review-uri: ");
        printf("%f\n", locatie[ID].mediePareri);

        printf("\t\t\t\t\t\t\t\t    Numar de Review-uri: ");
        printf("%i\n", locatie[ID].numarPareri);

        printf("\t\t\t\t\t\t\t\t    Disponibilitate: ");
        printf(locatie[ID].disponibilitate == 0 ? "Nu mai este disponibil\n\n" : "Este disponibil\n\n");

        printf("\t\t\t\t\t\t\t\t    ----------------------------------------------------------------------\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t    Directionam catre meniul de introducere a persoanelor...");
        Sleep(10000);
        NumarDePersoane = utility_getPersonsNumber();
        poz = utility_findHotelByID(ID);
        check = utility_checkLocuriRamase(NumarDePersoane, poz);

        if (check == 0)
        {
            printf("\t\t\t\t\t\t\t\t    Nu sunt destule locuri disponibile\n");
            printf("\t\t\t\t\t\t\t\t    Verificati din nou locurile disponibile, veti fi directionat la meniul principal");
            Sleep(13000);
            return;
        }

        int i = 1;

        while (i <= NumarDePersoane)
        {
            utility_adaugaPersoana();
            i++;
        }
        printf("\t\t\t\t\t\t\t    Scrieti data in format calendaristic: "); scanf("%s", dataCazare);
        printf("\n");
        printf("\t\t\t\t\t\t\t\t    Pregatim raportul de cazare...");
        Sleep(5500); system("cls");
        utility_vizualizare_raport_cazare(poz, NumarDePersoane);
    }
}


int utility_getIDForBooking()
{
    char id[100];
    Sleep(0.016666); system("cls");

    printf("********************************************************* MENIU DE REZERVARE A LOCULUI - SOLICITARE ID HOTEL*****************************************************************\n\n\n\n\n");


    printf("\t\t\t\t\t\t\t\t    Scrieti ID-ul hotelului: \n\n");
    printf("\t\t\t\t\t\t\t\t    ID: "); scanf("%s", &id);

    int num = (log10(atoi(id)) + 1);

    if (num != strlen(id))
    {
        printf("\n\n");
        printf("\t\t\t\t\t\t\t    EROARE: Acesta nu este un ID valid !\n\n");
        printf("\t\t\t\t\t\t\t    [1] Revino la meniul principal\n");
        printf("\t\t\t\t\t\t\t    [2] Opreste Programul\n");
        printf("\t\t\t\t\t\t\t    [3] Reintrodu ID-ul\n\n");

        int option = utility_readUserOptionIDHotel();

        if (option == 1)
        {
            main();
        }

        else if (option == 2) utility_exit();

        else
        {
            printf("\t\t\t\t\t\t\t   Reincepem procesul...");

            Sleep(3500);
            rezerva_loc();
        }
    }

    return (atoi(id));
}


int utility_readUserOptionGetIDReview()
{
    int option;
    printf("\t\t\t\t\t\t\t\t\t    Numarul actiunii: ");
    scanf("%i", &option);

    return option;
}


int utility_receiveIDForReview()
{
    char id[100];

    printf("\t\t\t\t\t\t    Scrieti ID-ul hotelului pentru care vreti sa faceti review-ul\n\n");
    printf("\t\t\t\t\t\t    ID: "); scanf("%s", &id);

    getchar();

    int num = (log10(atoi(id)) + 1);

    if (num != strlen(id))
    {
        system("cls");
        printf("\t\t\t\t\t\t    Acesta nu este un ID valid !\n\n");
        printf("\t\t\t\t\t\t    [1] Revino la meniul principal\n");
        printf("\t\t\t\t\t\t    [2] Opreste Programul\n");
        printf("\t\t\t\t\t\t    [3] Reintrodu ID-ul\n\n");

        int option = utility_readUserOptionGetIDReview();

        if (option == 1)
        {
            main();
        }

        else if (option == 2) utility_exit();

        else
        {
            printf("\t\t\t\t\t\t    Reincepem procesul...\n\n");

            Sleep(3500);
            adauga_parere();
        }
    }

    return atoi(id);
}


int utility_checkAvailabilityAndExistanceForBookingByID(int ID)
{

    int i = 0;

    while (locatie[i].id != ID && i < cntHoteluri) i++;


    if (i < cntHoteluri)
    {
        if (locatie[i].disponibilitate == 1) return 1;
        else return 2;
    }

    return 3;
}


int utility_checkIDExistanceForReview(int ID)
{

    int i = 0;

    while (locatie[i].id != ID && i < cntHoteluri) i++;

    if (i < cntHoteluri) return 1;

    return 2;

}


int utility_readUserOptionAnuleazaCazare()
{
    int option;
    printf("\t\t\t\t\t\t\t\t    Numarul actiunii: ");
    scanf("%i", &option);

    return option;
}


void anuleaza_rezervare()
{
    Sleep(0.016666); system("clS");

    printf("\n\n\n************************************************************************ MENIUL DE ANULAT REZERVAREA ************************************************************************\n\n\n\n\n");

    char ptr[101];

    strcpy(ptr, NumePersoana);
    strcat(ptr, ".txt");

    FILE* cazari = fopen(ptr, "r");
    char txt[250];

    if (NULL == cazari) {
        printf("\t\t\t\t\t\t\t\t    Nu aveti nicio cazare facuta\n");
        printf("\t\t\t\t\t\t\t\t    Redirectionam spre meniul principal...");
        Sleep(9000);
        fclose(cazari);
        return;

    }

    fgets(txt, 248, cazari);
    if (txt[0] == ' ')
    {
        printf("\t\t\t\t\t\t\t\t    Nu aveti nicio rezervare facuta\n\n");
        printf("\t\t\t\t\t\t\t\t    Redirectionam spre meniul principal...");
        Sleep(9000);
        fclose(cazari);
        return;
    }


    fseek(cazari, 0, SEEK_END);
    int size = ftell(cazari);

    if (0 == size) {
        printf("\t\t\t\t\t\t\t\t    Nu aveti nicio rezervare facuta\n\n");
        printf("\t\t\t\t\t\t\t\t    Redirectionam catre pagina principala...");
        Sleep(9000);
        fclose(cazari);
        return;
    }  

    printf("\n");

    fclose(cazari);
    
    printf("\t\t\t\t\t\t\t\t    [1] Revino la meniul principal\n");
    printf("\t\t\t\t\t\t\t\t    [2] Opreste Programul\n");
    printf("\t\t\t\t\t\t\t\t    [3] Continua anularea rezervarii\n\n");

    int option = utility_readUserOptionAnuleazaCazare();
    getchar();

    if (option == 1)
    {
        Sleep(0.016666);  system("cls");
        return;
    }

    if (option == 2) utility_exit();

    else
    {
        Sleep(0.016666);  system("cls");
        int ID = utility_getIDForBooking();
        int poz = utility_findHotelByID(ID);

        locatie[poz].locuriRamase += NumarDePersoane;
        locatie[poz].disponibilitate = 1;

        char ptr[101];

        strcpy(ptr, NumePersoana);
        strcat(ptr, ".txt");

        FILE* cazare = fopen(ptr, "w");

        fprintf(cazare, " ");

        fclose(cazare);

        printf("\t\t\t\t\t\t\t\t    Cazarea a fost anulata, banii vor fi restituti cat de curand\n");
        printf("\t\t\t\t\t\t\t\t    Redirectionam catre meniul principal...\n");
        Sleep(3500);
        return;

    }

}


int utility_readUserOptionFiltrare()
{
    int option;
    printf("\t\t\t\t\t\t\t\t    Numarul actiunii: ");
    scanf("%i", &option);

    return option;
}


void filtrare_optiuni()
{
    Sleep(0.016666);  system("cls");
    fflush(stdin);
    printf("\n\n\n************************************************************************** MENIU - CAUTARE LOCATII **************************************************************************\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t    [1] Revino la meniul principal\n");
    printf("\t\t\t\t\t\t\t\t    [2] Opreste Programul\n");
    printf("\t\t\t\t\t\t\t\t    [3] Cauta dupa locatie\n");
    printf("\t\t\t\t\t\t\t\t    [4] Cauta dupa numar de review-uri\n");
    printf("\t\t\t\t\t\t\t\t    [5] Cauta de la o anumita medie in sus\n\n");

    int option = utility_readUserOptionFiltrare();
    getchar();

    if (option == 1)
    {
        Sleep(0.016666);  system("cls");
        return;
    }

    else if (option == 2) utility_exit();

    else if (option == 3)
    {
        char name[150];
        printf("\t\t\t\t\t\t\t\t    Numele Locatiei: ");  scanf("%s", name);
        printf("\n\n");
        utility_printLocationsByLocationName(name);
        printf("\n\n");

        printf("*****************************************************************************************************************************************************\n\n");


        printf("\t\t\t\t\t\t\t\t    [1] Revino la meniul principal\n");
        printf("\t\t\t\t\t\t\t\t    [2] Opreste Programul\n");
        printf("\t\t\t\t\t\t\t\t    [3] Inapoi la criteriile de cautare\n\n");

        int option = utility_readUserOptionFiltrare();
        printf("\n\n");

        if (option == 1)
        {
            Sleep(0.016666);  system("cls");
            return;
        }

        else if (option == 2) utility_exit();

        else if (option == 3) filtrare_optiuni();
    }

    else if (option == 4)
    {
        int num;
        printf("\t\t\t\t\t\t\t\t    Numarul minim de review-uri: "); scanf("%i", &num);

        printf("\n\n");
        utility_printLocationsByReviewsNumber(num);
        printf("\n\n");
        printf("*****************************************************************************************************************************************************\n\n");


        printf("\t\t\t\t\t\t\t\t    [1] Revino la meniul principal\n");
        printf("\t\t\t\t\t\t\t\t    [2] Opreste Programul\n");
        printf("\t\t\t\t\t\t\t\t    [3] Inapoi la criteriile de cautare\n\n");

        int option = utility_readUserOptionFiltrare();

        if (option == 1)
        {
            Sleep(0.016666);  system("cls");
            return;
        }

        else if (option == 2) utility_exit();

        else if (option == 3) filtrare_optiuni();

    }

    else if (option == 5)
    {
        int medie;
        printf("\t\t\t\t\t\t\t\t    Media minima: "); scanf("%i", &medie);
        printf("\n\n");
        utility_printLocationsByMean(medie);
        printf("\n\n");

        printf("*****************************************************************************************************************************************************\n\n");


        printf("\t\t\t\t\t\t\t\t    [1] Revino la meniul principal\n");
        printf("\t\t\t\t\t\t\t\t    [2] Opreste Programul\n");
        printf("\t\t\t\t\t\t\t\t    [3] Inapoi la criteriile de cautare\n\n");

        int option = utility_readUserOptionFiltrare();

        if (option == 1)
        {
            Sleep(0.016666);  system("cls");
            return;
        }

        else if (option == 2) utility_exit();

        else if (option == 3) filtrare_optiuni();

    }
}


int utility_readUserOptionCazarileMele()
{
    int option;
    printf("\t\t\t\t\t\t\t\t    Numarul actiunii: ");
    scanf("%i", &option);

    return option;
}


void vezi_cazarileMele()
{

    Sleep(0.016666);  system("cls");
    fflush(stdin);
    printf("\n\n\n\n\n\n************************************************************************* MENIU - CAZARILE MELE *****************************************************************************\n\n");
    
    char Numeprs[101];

    strcpy(Numeprs, NumePersoana);
    strcat(Numeprs, ".txt");

    FILE* cazari = fopen(Numeprs, "r");
    char txt[250];

    if (NULL == cazari) {
        printf("\t\t\t\t\t\t\t\t    Nu aveti nicio rezervare facuta\n\n");
    }

    else
    {
        while (fgets(txt, 248, cazari)) {
            if (txt[0] == ' ')
            {
                printf("\t\t\t\t\t\t\t\t    Nu aveti nicio rezervare facuta\n\n");
                break;
            }
            printf("%s\n", txt);
        }

        printf("\n");

        fclose(cazari);
    }

    printf("\n\n");

    printf("\t\t\t\t\t\t\t\t    [1] Revino la meniul principal\n");
    printf("\t\t\t\t\t\t\t\t    [2] Opreste Programul\n\n");

    int option = utility_readUserOptionCazarileMele();

    if (option == 1)
    {
        Sleep(0.016666);  system("cls");
        return;
    }

    if (option == 2) utility_exit();
}
