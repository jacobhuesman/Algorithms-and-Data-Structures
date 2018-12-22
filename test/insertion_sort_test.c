#include <insertion_sort.h>
#include <eval.h>

// Test cases
void insertionSort_test()
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

// Run test cases
void main()
{
    printf("\nRunning %s\n", __FILE__);
    insertionSort_test();
}