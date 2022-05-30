#include <iostream>
using namespace std;

template <typename T, unsigned long long n, unsigned long long m>
class Matrix
{
private:
    T mat[n][m];
public:
    Matrix();
    void print();
    template <typename U>
    void operator += (const Matrix<U, n, m>&);
    void operator *= (const unsigned long long);
    T getNumber(int i, int j)const { return mat[i][j]; }
};


template <typename T, unsigned long long n, unsigned long long m> Matrix <T, n, m>::Matrix()
{
    for (unsigned long long i = 0; i < n; ++i)
    {
        for (unsigned long long j = 0; j < m; ++j) cin >> mat[i][j];
    }
}


template <typename T, unsigned long long n, unsigned long long m>
void Matrix <T, n, m>::print()
{
    for (unsigned long long i = 0; i < n; ++i, cout << '\n')
    {
        for (unsigned long long j = 0; j < m; ++j) cout << mat[i][j] << ' ';
    }
}


template <typename T, unsigned long long n, unsigned long long m> template <typename U>
void Matrix<T, n, m>::operator += (const Matrix<U, n, m>& obj)
{
    for (unsigned long long i = 0; i < n; ++i)
    {
        for (unsigned long long j = 0; j < m; ++j) this->mat[i][j] += obj.getNumber(i, j);
    }
}


template <typename T, unsigned long long n, unsigned long long m>
void Matrix <T, n, m>:: operator *= (const unsigned long long scalar)
{
    for (unsigned long long i = 0; i < n; ++i)
    {
        for (unsigned long long j = 0; j < m; ++j) this->mat[i][j] *= scalar;
    }
}


int main()
{
    /*

    Exemplu 3 linii si 4 coloane

    Matrice 1:
    1 2 4 8
    3 5 7 9
    1 5 4 9

    Matrice 2:
    1.1 5.4 4.2 9.7
    3.1 5.4 7.6 9.8
    1.3 2.3 4.9 8.1

    */

    Matrix <int, 3, 4> m1;
    Matrix <double, 3, 4> m2;


    cout << "Matricea 1:\n";
    m1.print();
    cout << "\n\n";

    cout << "Matricea 2:\n";
    m2.print();
    cout << "\n\n";

    cout << "Rezultat adunare matrici:\n";
    m2 += m1;
    m2.print();
    cout << "\n\n";

    unsigned long long number; cout << "Numarul cu care se va inmulti matricea 1: "; cin >> number;
    cout << "Rezultat:\n";
    m1 *= 2;
    m1.print();
    cout << "\n\n";

    return 0;
}