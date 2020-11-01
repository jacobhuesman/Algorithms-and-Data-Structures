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