#ifndef EVAL_H
#define EVAL_H

#include <stdio.h>
#include <stdlib.h>

// Helper functions
int stringLength(const char *s)
{
    for (int i = 0; i < 1e9; i++)
    {
        if (s[i] == '\0')
        {
            return i;
        }
    }
    return -1;
}

int intLength(int a)
{
    int test;
    int length, divisor;
    length = 0;
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

int max(int a, int b)
{
    return (a > b) ? a : b;
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

// PRINT_ARRAYS
// ---------------------
// | array 1 | array 2 |
// ---------------------
// |      12 |      12 |

#define PRINT_ARRAYS(A,B,length)                                         \
{                                                                        \
    /* find maximum character size   */                                  \
    char A_str[] = #A;                                                   \
    char B_str[] = #B;                                                   \
    int max_size = max(stringLength(A_str), stringLength(B_str));        \
    for (int i = 0; i < length; i++)                                     \
    {                                                                    \
        max_size = max(max_size, intLength(A[i]));                       \
        max_size = max(max_size, intLength(B[i]));                       \
    }                                                                    \
    for (int i = 0; i < (max_size * 2 + 7); i++)                         \
    {                                                                    \
        putchar('-');                                                    \
    }                                                                    \
    putchar('\n');                                                       \
    printf("| %*s | %*s |\n", max_size, #A, max_size, #B);               \
    for (int i = 0; i < (max_size * 2 + 7); i++)                         \
    {                                                                    \
        putchar('-');                                                    \
    }                                                                    \
    putchar('\n');                                                       \
    for (int i = 0; i < length; i++)                                     \
    {                                                                    \
        printf("| %*i | %*i |\n", max_size, A[i], max_size, B[i]);       \
    }                                                                    \
    for (int i = 0; i < (max_size * 2 + 7); i++)                         \
    {                                                                    \
        putchar('-');                                                    \
    }                                                                    \
    putchar('\n');                                                       \
}

#endif // EVAL_H
