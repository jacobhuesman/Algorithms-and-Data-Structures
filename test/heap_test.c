#include <heap.h>
#include <eval.h>

// Test cases
void macro_tests()
{
    printf("\nmacro_tests:\n\n");
    ASSERT(PARENT(1) == 0);
    ASSERT(PARENT(3) == 1);
    ASSERT(LEFT(0) == 1);
    ASSERT(LEFT(1) == 3);
    ASSERT(RIGHT(0) == 2);
    ASSERT(RIGHT(1) == 4);
}

void maxHeapify_test()
{
    // Initialize
    int heap[] = {16,4,10,14,7,9,3,2,8,1};
    int expected[] = {16,14,10,8,7,9,3,2,4,1};
    
    // Test
    printf("\nmaxHeapify_test:\n");
    printf("\n");
    maxHeapify(10, heap, 1);
    printf("\n");
    //PRINT_ARRAYS(10, heap, expected);
    ASSERT_ARRAY_EQ(10, heap, expected)
}

void buildMaxHeap_test()
{
    // Initialize
    int heap[] = {4,1,3,2,16,9,10,14,8,7};
    int expected[] = {16,14,10,8,7,9,3,2,4,1};
    
    // Test
    printf("\nbuildMaxHeap_test:\n");
    printf("\n");
    buildMaxHeap(10, heap);
    printf("\n");
    ASSERT_ARRAY_EQ(10, heap, expected)
}

// Run test cases
void main()
{
    printf("\nRunning %s\n", __FILE__);
    macro_tests();
    maxHeapify_test();
    buildMaxHeap_test();
}