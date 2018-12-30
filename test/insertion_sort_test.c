#include <insertion_sort.h>
#include <eval.h>

// Test cases
void insertionSort_test()
{
    // Setup
    int unsorted[] = {5,2,4,6,1,3};
    int *sorted;
    CLONE_ARRAY(6, unsorted, sorted);
    
    // Test
    printf("\ninsertionSort_test:\n");
    int expected[] = {1,2,3,4,5,6};
    insertionSort(sorted, 6);
    PRINT_ARRAYS(6, unsorted, sorted);
    ASSERT_ARRAY_EQ(6, sorted, expected)
    printf("\n");
    
    free(sorted);
}

// Run test cases
void main()
{
    printf("\nRunning %s\n", __FILE__);
    insertionSort_test();
}