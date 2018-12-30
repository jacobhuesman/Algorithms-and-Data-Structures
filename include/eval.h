#ifndef EVAL_H
#define EVAL_H

#include <stdio.h>
#include <stdlib.h>

// Helper functions
int stringLength(const char *s);
int intLength(int a);
void cloneArray(int n, const int *original, int **copy);
int max(int a, int b);

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

#define ASSERT_ARRAY_EQ(n,A,B)                                            \
{                                                                         \
    int pass = 1;                                                         \
    for (int i = 0; i < n; i++)                                           \
    {                                                                     \
        if (A[i] != B[i])                                                 \
        {                                                                 \
            pass = 0;                                                     \
            FAIL(#A "[%i] = %i != " #B "[%i] = %i\n", i, A[i], i, B[i]);  \
            break;                                                        \
        }                                                                 \
    }                                                                     \
    if (pass)                                                             \
    {                                                                     \
        PASS(#A " == " #B "\n");                                          \
    }                                                                     \
}

#define ASSERT_SQUARE_MATRIX_EQ(n,A,B)                                                            \
{                                                                                                 \
    int pass = 1;                                                                                 \
    for (int i = 0; i < n; i++)                                                                   \
    {                                                                                             \
        for (int j = 0; j < n; j++)                                                               \
        {                                                                                         \
            if (A[i][j] != B[i][j])                                                               \
            {                                                                                     \
                pass = 0;                                                                         \
                FAIL(#A "[%i][%i] = %f,!= " #B "[%i][%i] = %f\n", i, j, A[i][j], i, j, B[i][j]);  \
                break;                                                                            \
            }                                                                                     \
        }                                                                                         \
        if (!pass)                                                                                \
        {                                                                                         \
            break;                                                                                \
        }                                                                                         \
    }                                                                                             \
    if (pass)                                                                                     \
    {                                                                                             \
        PASS(#A " == " #B "\n");                                                                  \
    }                                                                                             \
}

#define ASSERT_SQUARE_MATRIX_DLEQ(n,A,B,D)                                                        \
{                                                                                                 \
    int pass = 1;                                                                                 \
    for (int i = 0; i < n; i++)                                                                   \
    {                                                                                             \
        for (int j = 0; j < n; j++)                                                               \
        {                                                                                         \
            if ((A[i][j] - B[i][j]) > D)                                                          \
            {                                                                                     \
                pass = 0;                                                                         \
                FAIL(#A "[%i][%i] = %f,!= " #B "[%i][%i] = %f\n", i, j, A[i][j], i, j, B[i][j]);  \
                break;                                                                            \
            }                                                                                     \
        }                                                                                         \
        if (!pass)                                                                                \
        {                                                                                         \
            break;                                                                                \
        }                                                                                         \
    }                                                                                             \
    if (pass)                                                                                     \
    {                                                                                             \
        PASS(#A " == " #B "\n");                                                                  \
    }                                                                                             \
}


#define STR(x) #x
#define PRINT_ARRAY(n,A,padding)              \
{                                             \
    printf("%s = {", #A);                     \
    printf("%" STR(padding) "i", A[0]);       \
    for (int i = 1; i < n; i++)               \
    {                                         \
        printf(",%" STR(padding) "i", A[i]);  \
    }                                         \
    printf(" }\n");                           \
}

// PRINT_ARRAYS
// ---------------------
// | array 1 | array 2 |
// ---------------------
// |      12 |      12 |

#define PRINT_ARRAYS(n,A,B)                                              \
{                                                                        \
    /* find maximum character size   */                                  \
    char A_str[] = #A;                                                   \
    char B_str[] = #B;                                                   \
    int max_size = max(stringLength(A_str), stringLength(B_str));        \
    for (int i = 0; i < n; i++)                                          \
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
    for (int i = 0; i < n; i++)                                          \
    {                                                                    \
        printf("| %*i | %*i |\n", max_size, A[i], max_size, B[i]);       \
    }                                                                    \
    for (int i = 0; i < (max_size * 2 + 7); i++)                         \
    {                                                                    \
        putchar('-');                                                    \
    }                                                                    \
    putchar('\n');                                                       \
}

// PRINT_SQUARE_MATRIX
// ----------------------------
// | 1.23e3 | 1.23e3 | 1.23e3 |
// ----------------------------
// | 1.23e3 | 1.23e3 | 1.23e3 |
// ----------------------------
// | 1.23e3 | 1.23e3 | 1.23e3 |
// ----------------------------
#define PRINT_SQUARE_MATRIX(n,A,p)                \
{                                                 \
    printf("%s:\n", #A);                          \
    int length = (p+8)*n + 1;                     \
    for (int i = 0; i < n; i++)                   \
    {                                             \
        for (int j = 0; j < length; j++)          \
        {                                         \
            putchar('-');                         \
        }                                         \
        putchar('\n');                            \
        putchar('|');                             \
        for (int j = 0; j < n; j++)               \
        {                                         \
            printf(" %.*e |", p-1, A[i][j]);      \
        }                                         \
        putchar('\n');                            \
    }                                             \
    for (int k = 0; k < length; k++)              \
    {                                             \
        putchar('-');                             \
    }                                             \
    putchar('\n');                                \
}

#endif // EVAL_H
