#include <quick_sort.h>

int partition(int *A, int p, int r)
{
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

void quickSort(int n, int *A)
{
    _quickSort(A, 0, n - 1);
}

void _quickSort(int *A, int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p, r);
        _quickSort(A, p, q - 1);
        _quickSort(A, q + 1, r);
    }
    
}