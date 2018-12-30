#include <eval.h>

// Test cases
void stringLength_tests()
{
    printf("stringLength_tests:\n");
    char test[] = "test";
    char numbers_string[] = "1234567890";
    char empty_string[] = "";
    ASSERT(STRING_LENGTH(test) == 4);
    ASSERT(STRING_LENGTH(numbers_string) == 10);
    ASSERT(STRING_LENGTH(empty_string) == 0);
    putchar('\n');
}

void intLength_tests()
{
    printf("intLength_tests:\n");
    ASSERT(INT_LENGTH(123456) == 6);
    ASSERT(INT_LENGTH(9) == 1);
    ASSERT(INT_LENGTH(1234567890) == 10);
    putchar('\n');
}

void max_tests()
{
    printf("max_tests:\n");
    ASSERT(MAX(2,3) == 3);
    ASSERT(MAX(6,4) == 6);
    ASSERT(MAX(0,1) == 1);
    ASSERT(MAX(-2,4) == 4);
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