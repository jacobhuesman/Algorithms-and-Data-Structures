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
    printf("\n" "maxHeapify_test:\n");
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
    printf("\n" "buildMaxHeap_test:\n");
    buildMaxHeap(10, heap);
    printf("\n");
    ASSERT_ARRAY_EQ(10, heap, expected)
}

void heapSort_test()
{
    // Initialize
    int heap[] = {4,1,3,2,16,9,10,14,8,7};
    int expected[] = {1,2,3,4,7,8,9,10,14,16};
    
    // Test
    printf("\n" "heapSort_test:\n");
    heapSort(10, heap);
    printf("\n");
    PRINT_ARRAYS(10, heap, expected);
    ASSERT_ARRAY_EQ(10, heap, expected)
}

void heapMaximum_test()
{
    // Initialize
    int heap[] = {4,1,3,2,16,9,10,14,8,7};
    
    // Test
    printf("\n" "heapMaximum_test:\n");
    buildMaxHeap(10, heap);
    printf("\n");
    ASSERT(heapMaximum(heap) == 16);
}

void heapExtractMax_test()
{
    // Initialize
    int heap[] = {4,1,3,2,16,9,10,14,8,7};
    int expected[] = {14,8,10,4,7,9,3,2,1};
    
    // Test
    printf("\nbuildMaxHeap_test:\n");
    int size = 10, result = -1;
    buildMaxHeap(size, heap);
    result = heapExtractMax(&size, heap);
    printf("\n");
    ASSERT(result == 16);
    ASSERT(size == 9);
    ASSERT_ARRAY_EQ(size, heap, expected);
}

void heapIncreaseKey_test()
{
    // Initialize
    int heap[] = {16,4,10,14,7,9,3,2,8,1};
    int expected[] = {16,15,10,8,14,9,3,2,4,1};
    
    // Test
    printf("\n" "heapIncreaseKey_test:\n");
    maxHeapify(10, heap, 1);
    heapIncreaseKey(10, heap, 4, 15);
    printf("\n");
    PRINT_ARRAYS(10, heap, expected);
    ASSERT_ARRAY_EQ(10, heap, expected);
}

void maxHeapInsert_test()
{
    // Initialize
    int heap_values[] = {16,4,10,14,7,9,3,2,8,1};
    int *heap;
    CLONE_ARRAY(10, heap_values, heap);
    int expected[] = {16,15,10,8,14,9,3,2,4,1,7};
    
    // Test
    printf("\n" "heapIncreaseKey_test:\n");
    int size = 10;
    maxHeapify(size, heap, 1);
    maxHeapInsert(&size, &heap, 15);
    printf("\n");
    PRINT_ARRAYS(size, heap, expected);
    ASSERT(size == 11);
    ASSERT_ARRAY_EQ(size, heap, expected)
}

// Run test cases
void main()
{
    printf("\nRunning %s\n", __FILE__);
    macro_tests();
    maxHeapify_test();
    buildMaxHeap_test();
    heapSort_test();
    heapMaximum_test();
    heapExtractMax_test();
    heapIncreaseKey_test();
    maxHeapInsert_test();
}