#include <eval.h>

// Test cases
void stringLength_tests()
{
    printf("stringLength_tests:\n");
    char test[] = "test";
    char numbers_string[] = "1234567890";
    char empty_string[] = "";
    ASSERT(stringLength(test) == 4);
    ASSERT(stringLength(numbers_string) == 10);
    ASSERT(stringLength(empty_string) == 0);
    putchar('\n');
}

void intLength_tests()
{
    printf("intLength_tests:\n");
    ASSERT(intLength(123456) == 6);
    ASSERT(intLength(9) == 1);
    ASSERT(intLength(1234567890) == 10);
    putchar('\n');
}

void max_tests()
{
    printf("max_tests:\n");
    ASSERT(max(2,3) == 3);
    ASSERT(max(6,4) == 6);
    ASSERT(max(0,1) == 1);
    ASSERT(max(-2,4) == 4);
    putchar('\n');
}

void print_arrays_tests()
{
    printf("print_arrays_tests:\n");
    int A[] = {1,2,3};
    int B[] = {4,5,6};
    PRINT_ARRAYS(3,A,B);
    putchar('\n');
}

// Run test cases
void main()
{
    printf("\nRunning %s\n\n", __FILE__);
    stringLength_tests();
    intLength_tests();
    max_tests();
    print_arrays_tests();
}