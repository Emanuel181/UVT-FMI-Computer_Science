#include <iostream>

using namespace std;
// [PROGRAMUL FUNCTIONEAZA IN IPOTEZA CA DATELE DE INTRARE SUNT VALIDE SI MULTIMEA DATA SE POATE DESCOMPUNE]

int A[10000], rez[10000][10000], seq[10000], n, k = 1, sum;

int populare_matrice(int i, int j)
{
    if (j == 0)
        return 1;

    else if(i == 0)
        return 0;

    else if(j < A[i])
        populare_matrice(i-1, j);

    else return( populare_matrice(i-1, j) || populare_matrice(i-1, j - A[i]));

}

void find_subset()
{
    seq[k++] = A[n];
    int i = n - 1;
    int j = sum - 1 ;

    while(sum != 0 && i >= 0 && j >= 0)
    {
        if (rez[i][j] != rez[i-1][j])
        {
            seq[k++] = A[i];
            sum -= rez[i][j];
            j = sum;
            i-= 1;
        }

        else
            i -= 1;
    }

}

void citire()
{
    cout << "Numarul de elemente: "; cin >> n;
    cout << "Elementele sunt: ";

    for (int i = 1; i <= n; i++) cin >> A[i];

    cout << "Suma este: "; cin >> sum;

    sum /= 2;

    cout << endl;
}

void afisare_set()
{
    cout << "Prima multime este: { ";
    for(int i = 1; i < k ; i++) cout << seq[i] << ' ';
    cout << "}";

    cout << endl;

    cout << "A doua multime este: { ";
    for(int i = 1; i <= n ; i++)
    {
        bool ok = 1;
        for(int j = 1; j < k; j++)
        {
            if(A[i] == seq[j])
                ok = 0;
        }

        if(ok)
        cout << A[i] << ' ';

    }
    cout << "}";


    cout << endl;

}

int main()
{
    // [PROGRAMUL FUNCTIONEAZA IN IPOTEZA CA DATELE DE INTRARE SUNT VALIDE SI MULTIMEA DATA SE POATE DESCOMPUNE]
    // Exemplu: n = 4, A = {2, 6, 5, 1}, iar suma sa fie 14

    citire();

    for (int i = 0; i <= n ; i++)
        for(int j = 0; j <= 7 ; j++)
            rez[i][j] = populare_matrice(i,j);

    find_subset();

    cout << endl ;

    afisare_set();

    return 0;
}
