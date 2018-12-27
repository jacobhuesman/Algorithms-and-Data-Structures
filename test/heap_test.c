#include <heap.h>
#include <eval.h>

// Test cases
void maxHeapify_test()
{
    // Initialize
    int heap[] = {16,4,10,14,7,9,3,2,8,1};
    int expected[] = {16,14,10,8,7,9,3,2,4,1};
    
    // Test
    printf("\nmaxHeapify_test:\n");
    maxHeapify(10, heap, 1);
    ASSERT_ARRAY_EQ(10, heap, expected)

}

// Run test cases
void main()
{
    printf("\nRunning %s\n", __FILE__);
    maxHeapify_test();
}