#include <randomized_quick_sort.h>
#include <eval.h>

// Test cases
void randomizedQuickSort_test()
{
    // Setup
    int unsorted[] = {5,2,4,6,1,3};
    int *sorted;
    CLONE_ARRAY(6, unsorted, sorted);
    
    // Test
    printf("randomizedQuickSort_test:\n");
    int expected[] = {1,2,3,4,5,6};
    randomizedQuickSort(6, sorted);
    PRINT_ARRAYS(6, unsorted, sorted);
    ASSERT_ARRAY_EQ(6, sorted, expected)
    putchar('\n');
    
    // Free memory
    free(sorted);
}

// Run test cases
void main()
{
    printf("\nRunning %s\n\n", __FILE__);
    randomizedQuickSort_test();
}