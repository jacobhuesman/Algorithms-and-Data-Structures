#include <bubble_sort.h>

void bubbleSort(int *A, int length)
{
    for (int i = 0; i < (length - 2); i++)
    {
        for (int j = (length - 1); j > i; j--)
        {
            if (A[j] < A[j-1])
            {
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;  
            }
        }
    }
}