#include <bubble_sort.h>
#include <eval.h>

// Test cases
void bubbleSort_test()
{
    // Setup
    int unsorted[] = {5,2,4,6,1,3};
    int *sorted;
    cloneArray(6, unsorted, &sorted);
    
    // Test
    printf("\nbubbleSort_test:\n");
    int expected[] = {1,2,3,4,5,6};
    bubbleSort(sorted, 6);
    PRINT_ARRAYS(6,unsorted, sorted);
    ASSERT_ARRAY_EQ(6,sorted,expected)
    printf("\n");
    
    free(sorted);
}

// Run test cases
void main()
{
    printf("\nRunning %s\n", __FILE__);
    bubbleSort_test();
}