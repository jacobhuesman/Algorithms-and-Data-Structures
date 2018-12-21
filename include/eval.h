#include <stdio.h>
#include <stdlib.h>

// Helper functions
int intLength(int a)
{
    int test;
    int length, divisor;
    length = 1;
    divisor = 1;
    while ((a / divisor) > 0)
    {
        length++;
        divisor = divisor * 10;
    }
    return length; 
}

void cloneArray(const int *original, int **copy, int length)
{
    *copy = (int*)malloc(length*4);
    for (int i = 0; i < length; i++)
    {
        (*copy)[i] = original[i];
    }
}

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

#define ASSERT_ARRAY_EQ(A,B,length)                                       \
{                                                                         \
    int pass = 1;                                                         \
    for (int i = 0; i < length; i++)                                      \
    {                                                                     \
        if (A[i] != B[i])                                                 \
        {                                                                 \
            pass = 0;                                                     \
            FAIL(#A "[%i] = %i,!= " #B "[%i] = %i\n", i, A[i], i, B[i]);  \
            break;                                                        \
        }                                                                 \
    }                                                                     \
    if (pass)                                                             \
    {                                                                     \
        PASS(#A " == " #B "\n");                                          \
    }                                                                     \
}

#define STR(x) #x
#define PRINT_ARRAY(A,length,padding)      \
{                                          \
    printf("%" STR(padding) "s = {", #A);  \
    printf("%i", A[0]);                    \
    for (int i = 1; i < length; i++)       \
    {                                      \
        printf(",%i", A[i]);               \
    }                                      \
    printf("}\n");                         \
}

#define PRINT_ARRAYS(A,length,padding)      \
{                                           \
    printf("%" STR(padding) "s = {", #A);   \
    printf("%i", A[0]);                     \
    for (int i = 1; i < length; i++)        \
    {                                       \
        printf(",%i", A[i]);                \
    }                                       \
    printf("}\n");                          \
}


