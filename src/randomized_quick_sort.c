#include <randomized_quick_sort.h>
#include <quick_sort.h>
#include <stdlib.h>

int randomizedPartition(int *A, int p, int r)
{
    // Randomize
    {
        int i = (rand() % (r - p)) + p; // TODO double check this
        int tmp = A[r];
        A[r] = A[i];
        A[i] = tmp;
    }
    // Original quickSort implementation
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (A[j] <= x)
        {
            int tmp = A[++i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    int tmp = A[i+1];
    A[i+1] = A[r];
    A[r] = tmp;
    return i + 1;
}

void randomizedQuickSort(int n, int *A)
{
    _randomizedQuickSort(A, 0, n - 1);
}

void _randomizedQuickSort(int *A, int p, int r)
{
    if (p < r)
    {
        int q = randomizedPartition(A, p, r);
        _randomizedQuickSort(A, p, q - 1);
        _randomizedQuickSort(A, q + 1, r);
    }
    
}