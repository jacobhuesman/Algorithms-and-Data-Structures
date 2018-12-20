#include <stdio.h>
#include <stdlib.h>

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


// Definitions and implementation
#define bool int
#define true 1
#define false 0

void cloneArray(const int *original, int **copy, int length)
{
    *copy = (int*)malloc(length*4);
    for (int i = 0; i < length; i++)
    {
        (*copy)[i] = original[i];
    }
}

void insertionSort(int *A, int length)
{
    for (int j = 1; j < length; j++)
    {
        int key, i;
        key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i = i - 1;
        }
        A[i+1] = key;
    }
}

// Test cases
void test_suite_1()
{
    // Setup
    int unsorted[] = {5,2,4,6,1,3};
    int *sorted;
    cloneArray(unsorted, &sorted, 6);
    
    // Test
    printf("\nTest suite 1:\n");
    int expected[] = {1,2,3,4,5,6};
    insertionSort(sorted, 6);
    PRINT_ARRAY(unsorted, 6, 10);
    PRINT_ARRAY(sorted, 6, 10);
    ASSERT_ARRAY_EQ(sorted,expected,6)
    ASSERT(5 == 1 + 4);
    printf("\n");
    
    free(sorted);
}

// Run
void main()
{
    printf("Running %s\n", __FILE__);
    test_suite_1();
}