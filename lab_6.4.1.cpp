#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(double* a, const int size, double Low, double High)
{
    for (int i = 0; i < size; i++)
        a[i] = (High - Low) * rand() / RAND_MAX + Low;
}

void Print(double* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << fixed << setprecision(2) << setw(6) << a[i];
    cout << endl;
}

double SumOdd(double* a, const int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        if ((i + 1) % 2 == 1)
            sum += a[i];
    }
    return sum;
}

int iFirstNeg(double* a, const int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] < 0)
            return i;
    }
    return -1;
}

int iLastNeg(double* a, const int size) {
    for (int i = size - 1; i > 1; i--) {
        if (a[i] < 0)
            return i;
    }
    return -1;
}

double SumBetween(double* a, const int size) {
    int first = iFirstNeg(a, size),
        last = iLastNeg(a, size);

    double sum = 0;

    if (first == -1 || last == -1 || first == last) return sum;

    for (int i = first + 1; i < last; i++) {
        sum += a[i];
    }

    return sum;
}

void Сompress(double* a, const int size)
{
    int i = 0, k = 0;
    while (i < size - k)
    {
        if (fabs(a[i]) > 0 && fabs(a[i]) < 1)
        {
            for (int j = i; j < size - k - 1; j++)
                a[j] = a[j + 1];
            ++k;
        }
        else
            ++i;
    }
    for (i = size - 1; k != 0; a[i] = 0, k--, i--);
}

int main()
{
    srand((unsigned)time(NULL));
    int n = 0;
    cout << "N = "; cin >> n;
    double* a = new double[n];

    double Low = -2.;
    double High = 2.;
    Create(a, n, Low, High);
    Print(a, n);

    cout << "Sum Odd = " << SumOdd(a, n) << endl;
    cout << "Sum Between = " << SumBetween(a, n) << endl;

    Сompress(a, n);
    cout << "Compress:" << endl; Print(a, n);

    delete[] a;

    return 0;
}