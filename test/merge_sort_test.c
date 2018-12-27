#include <merge_sort.h>
#include <eval.h>

// Test cases
void merge_test()
{
    // Setup
    int unsorted[] = {1,3,5,2,4,6};
    int *sorted;
    cloneArray(6, unsorted, &sorted);
    
    // Test
    printf("merge_test:\n");
    int expected[] = {1,2,3,4,5,6};
    merge(sorted, 0, 2, 5);
    PRINT_ARRAYS(6, unsorted, sorted);
    ASSERT_ARRAY_EQ(6, sorted, expected)
    putchar('\n');
    
    // Free memory
    free(sorted);
}

void mergeSort_test()
{
    // Setup
    int unsorted[] = {5,2,4,6,1,3};
    int *sorted;
    cloneArray(6, unsorted, &sorted);
    
    // Test
    printf("mergeSort_test:\n");
    int expected[] = {1,2,3,4,5,6};
    mergeSort(sorted, 0, 5);
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
    merge_test();
    mergeSort_test();
}