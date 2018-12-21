#include <eval.h>

// Test cases
void test_suite_1()
{
    printf("\nTest suite 1:\n");
    ASSERT(intLength(123456) == 6);
    ASSERT(intLength(9) == 1);
    ASSERT(intLength(1234567890) == 10);
    printf("\n");
}

// Run
void main()
{
    printf("Running %s\n", __FILE__);
    test_suite_1();
}