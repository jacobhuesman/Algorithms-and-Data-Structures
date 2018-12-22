#include <stdio.h>
#include <stdlib.h>
#include <eval.h>

// Definitions
#define bool int
#define true 1
#define false 0


void insertionSort(int *A, int length)
{
    for (int j = 1; j < length; j++)
    {
        int key, i;
        key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i = i - 1;
        }
        A[i+1] = key;
    }
}

// Test cases
void test_suite_1()
{
    // Setup
    int unsorted[] = {5,2,4,6,1,3};
    int *sorted;
    cloneArray(unsorted, &sorted, 6);
    
    // Test
    printf("\nTest suite 1:\n");
    int expected[] = {1,2,3,4,5,6};
    insertionSort(sorted, 6);
    PRINT_ARRAYS(unsorted, sorted, 6);
    ASSERT_ARRAY_EQ(sorted,expected,6)
    ASSERT(5 == 1 + 4);
    printf("\n");
    
    free(sorted);
}

// Run
void main()
{
    printf("Running %s\n", __FILE__);
    test_suite_1();
}