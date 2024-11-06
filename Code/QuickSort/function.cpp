#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include <ctime>

#include "function.h"

using namespace std;

void CountingSort(int *A, int *B, int n, int k) // n è la dim di A e B, k è la dim di C
{
    int *C;
    C = new int[k + 1]; // devo mettere k+1 perch� sono k+1 elementi

    for (int i = 0; i <= k; i++)
    {
        C[i] = 0;
    }

    for (int j = 0; j < n; j++)
    { // uso convenzione indici dei linguaggi di programmazione
        C[A[j]] = C[A[j]] + 1;
    }
    /*cout << "C_CS_occ: ";
    stampa(C, k + 1);*/

    for (int i = 1; i <= k; i++)
    {
        C[i] = C[i] + C[i - 1];
    }
    /*cout << "C_CS_somma: ";
    stampa(C, k + 1);*/

    for (int j = n - 1; j >= 0; j--) // uso convenzione indici dei linguaggi di programmazione
    {
        B[C[A[j]] - 1] = A[j]; // mettendo B[C[A[j]]-1] si risolve il problema -> fallo su carta e capisci
        C[A[j]] = C[A[j]] - 1;
    }
    /*cout << "B_CS: ";
    stampa(B, n);*/

    delete[] C;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition(int *A, int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    { // nello pseudocodice arriva fino a r-1, anche qua fa così, infatti j<r (ultima iterazione la fa con j=r-1)
        if (A[j] <= x)
        {
            i = i + 1;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

void QuickSort(int *A, int p, int r)
{
    if (p < r)
    {
        int q = Partition(A, p, r);
        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
    }
}

int Randomized_Partition(int *A, int p, int r)
{
    int x = p + rand() % (r - p + 1);
    swap(A[x], A[r]);
    return Partition(A, p, r);
}

void Randomized_QuickSort(int *A, int p, int r)
{
    if (p < r)
    {
        int q = Randomized_Partition(A, p, r);
        Randomized_QuickSort(A, p, q - 1);
        Randomized_QuickSort(A, q + 1, r);
    }
}

void stampa(int *vett, int dim)
{
    for (int i = 0; i < dim; i++)
    {
        if (i < dim - 1)
        {
            cout << vett[i] << ",";
        }
        else
        {
            cout << vett[i];
        }
    }
    cout << endl;
}