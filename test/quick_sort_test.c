#include <quick_sort.h>
#include <eval.h>

// Test cases
void partition_test()
{
    // Setup
    int unsorted[] = {1,3,5,2,4,6};
    int *partitioned;
    cloneArray(6, unsorted, &partitioned);
    
    // Test
    printf("partition_test:\n");
    int expected[] = {1,3,5,2,4,6};
    int q = partition(partitioned, 0, 5);
    PRINT_ARRAYS(6, unsorted, partitioned);
    //printf("q = %i\n", q);
    ASSERT(q == 5);
    ASSERT_ARRAY_EQ(6, partitioned, expected)
    putchar('\n');
    
    // Free memory
    free(partitioned);
}

void quickSort_test()
{
    // Setup
    int unsorted[] = {5,2,4,6,1,3};
    int *sorted;
    cloneArray(6, unsorted, &sorted);
    
    // Test
    printf("quickSort_test:\n");
    int expected[] = {1,2,3,4,5,6};
    quickSort(sorted, 0, 5);
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
    partition_test();
    quickSort_test();
}