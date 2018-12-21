#include <eval.h>

// Test cases
void test_suite_1()
{
    printf("\nTest suite 1:\n");
    ASSERT(5 == 1 + 4);
    ASSERT(5 == 1 + 4 * 200);
    printf("\n");
}

// Run
void main()
{
    printf("Running %s\n", __FILE__);
    test_suite_1();
}