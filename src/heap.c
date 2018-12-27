#include <heap.h>

void maxHeapify(int size, int *A, int i)
{
    int l, r, largest;
    l = LEFT(i);
    r = RIGHT(i); 
    if (l <= size && A[l] > A[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if (r <= size && A[r] > A[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        int tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
        maxHeapify(size, A, i);
    }
}