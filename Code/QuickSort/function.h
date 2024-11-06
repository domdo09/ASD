// function.h
#ifndef FUNCTION_H_2
#define FUNCTION_H_2

// CS
void CountingSort(int *A, int *B, int n, int k);

// QuickSort
void QuickSort(int *A, int p, int r);
int Partition(int *A, int p, int r);

// QuickSort Randomizzato
void Randomized_QuickSort(int *A, int p, int r);
int Randomized_Partition(int *A, int p, int r);

// funzioni di utilità
void swap(int *a, int *b);
void stampa(int *vett, int dim);

#endif