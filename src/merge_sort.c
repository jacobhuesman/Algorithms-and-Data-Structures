#include <merge_sort.h>

void merge(int *A, int p, int q, int r)
{
    int n1, n2;
    n1 = q - p + 1;
    n2 = r - q;
    int L[n1 + 1]; // Leave room for sentinel
    int R[n2 + 1]; // Leave room for sentinel
    for (int i = 0; i < n1; i++)
    {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = A[q + j + 1];
    }
    L[n1] = __INT_MAX__;
    R[n2] = __INT_MAX__;
    int i = 0, j = 0;
    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int *A, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}