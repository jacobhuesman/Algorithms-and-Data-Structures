#include <heap.h>
#include <eval.h>

void maxHeapify(int size, int *A, int i)
{
    //PRINT_ARRAY(size, A, 3);
    int l, r, largest;
    l = LEFT(i);
    r = RIGHT(i); 
    if (l < size && A[l] > A[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if (r < size && A[r] > A[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        int tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
        maxHeapify(size, A, largest);
    }
}

void buildMaxHeap(int size, int *A)
{
    for (int i = size/2 - 1; i >= 0; i--)
    {
        maxHeapify(size, A, i);
    }
}

void heapSort(int size, int *A)
{
    buildMaxHeap(size, A);
    for (int i = size - 1; i > 0; i--)
    {
        int tmp = A[0];
        A[0] = A[i];
        A[i] = tmp;
        maxHeapify(--size, A, 0);
    }
}