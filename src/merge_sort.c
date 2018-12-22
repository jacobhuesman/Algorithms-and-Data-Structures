#include <stdio.h>
#include <stdlib.h>
#include <eval.h>

// Definitions
#define bool int
#define true 1
#define false 0


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



// Test cases
void merge_test()
{
    // Setup
    int unsorted[] = {1,3,5,2,4,6};
    int *sorted;
    cloneArray(unsorted, &sorted, 6);
    
    // Test
    printf("merge_test:\n");
    int expected[] = {1,2,3,4,5,6};
    merge(sorted, 0, 2, 5);
    PRINT_ARRAYS(unsorted, sorted, 6);
    ASSERT_ARRAY_EQ(sorted,expected,6)
    printf("\n");
    
    free(sorted);
}

void mergeSort_test()
{
    // Setup
    int unsorted[] = {5,2,4,6,1,3};
    int *sorted;
    cloneArray(unsorted, &sorted, 6);
    
    // Test
    printf("mergeSort_test:\n");
    int expected[] = {1,2,3,4,5,6};
    mergeSort(sorted, 0, 5);
    PRINT_ARRAYS(unsorted, sorted, 6);
    ASSERT_ARRAY_EQ(sorted,expected,6)
    printf("\n");
    
    free(sorted);
}

// Run
void main()
{
    printf("Running %s\n\n", __FILE__);
    merge_test();
    mergeSort_test();
}