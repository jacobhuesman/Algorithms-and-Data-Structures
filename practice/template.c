#include <stdio.h>

// Unit testing framework
#define ANSI_RED     "\x1b[31m"
#define ANSI_GREEN   "\x1b[32m"
#define ANSI_RESET   "\x1b[0m"
#define PASS(FORMAT, ...) printf("[" ANSI_GREEN "PASS" ANSI_RESET "] " FORMAT, ##__VA_ARGS__);
#define FAIL(FORMAT, ...) printf("[" ANSI_RED   "FAIL" ANSI_RESET "] " FORMAT, ##__VA_ARGS__);
#define ASSERT(ASSERTION)       \
{                               \
    if (ASSERTION)              \
    {                           \
        PASS(#ASSERTION "\n");  \
    }                           \
    else                        \
    {                           \
        FAIL(#ASSERTION "\n");  \
    }                           \
}

// Definitions and implementation


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