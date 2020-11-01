/*
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

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

int heapMaximum(int *A)
{
    return A[0];
}

int heapExtractMax(int *size, int *A)
{
    // TODO should implement some form of error handling for underflow
    int max = A[0];
    A[0] = A[--(*size)];
    maxHeapify(*size, A, 0);
    return max;
}

void heapIncreaseKey(int size, int *A, int i, int key)
{
    // TODO error if new key is smaller than current key
    A[i] = key;
    while (i > 0 && A[PARENT(i)] < A[i])
    {
        int tmp = A[i];
        A[i] = A[PARENT(i)];
        A[PARENT(i)] = tmp;
        i = PARENT(i);
    }
}

void maxHeapInsert(int *n, int **A, int key)
{
    int *copy = (int*)malloc(((*n)+1)*4);
    for (int i = 0; i < (*n); i++)
    {
        copy[i] = (*A)[i];
    }
    int *tmp = *A;
    (*A) = copy;
    free(tmp);
    (*A)[(*n)++] = -1000; // TODO find actual integer minimum
    heapIncreaseKey(*n, *A, (*n)-1, key);
}














