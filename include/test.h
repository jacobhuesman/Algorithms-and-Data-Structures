/*
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdlib.h>

// Helper macros
#define STRING_LENGTH(s) (sizeof(s) - 1)

#define INT_LENGTH(value)          \
({                                 \
    int divisor = 10, length = 1;  \
    while ((value / divisor) > 0)  \
    {                              \
        length++;                  \
        divisor = divisor * 10;    \
    }                              \
	length;                        \
})

#define CLONE_ARRAY(n, original, copy) \
{                                      \
    copy = malloc(n*4);                \
    for (int i = 0; i < n; i++)        \
    {                                  \
        copy[i] = original[i];         \
    }                                  \
}

#define MAX(a, b) ((a > b) ? a : b)

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

#define ASSERT_ARRAY_EQ(n,A,B)       \
{                                    \
    int pass = 1;                    \
    for (int i = 0; i < n; i++)      \
    {                                \
        if (A[i] != B[i])            \
        {                            \
            pass = 0;                \
            FAIL(#A "[%i] = %i != "  \
			     #B "[%i] = %i\n",   \
				 i, A[i], i, B[i]);  \
            break;                   \
        }                            \
    }                                \
    if (pass)                        \
    {                                \
        PASS(#A " == " #B "\n");     \
    }                                \
}

#define ASSERT_SQUARE_MATRIX_EQ(n,A,B)               \
{                                                    \
    int pass = 1;                                    \
    for (int i = 0; i < n; i++)                      \
    {                                                \
        for (int j = 0; j < n; j++)                  \
        {                                            \
            if (A[i][j] != B[i][j])                  \
            {                                        \
                pass = 0;                            \
                FAIL(#A "[%i][%i] = %f,!= "          \
				     #B "[%i][%i] = %f\n",           \
					 i, j, A[i][j], i, j, B[i][j]);  \
                break;                               \
            }                                        \
        }                                            \
        if (!pass)                                   \
        {                                            \
            break;                                   \
        }                                            \
    }                                                \
    if (pass)                                        \
    {                                                \
        PASS(#A " == " #B "\n");                     \
    }                                                \
}

#define ASSERT_SQUARE_MATRIX_DLEQ(n,A,B,D)           \
{                                                    \
    int pass = 1;                                    \
    for (int i = 0; i < n; i++)                      \
    {                                                \
        for (int j = 0; j < n; j++)                  \
        {                                            \
            if ((A[i][j] - B[i][j]) > D)             \
            {                                        \
                pass = 0;                            \
                FAIL(#A "[%i][%i] = %f,!= "          \
					 #B "[%i][%i] = %f\n",           \
					 i, j, A[i][j], i, j, B[i][j]);  \
                break;                               \
            }                                        \
        }                                            \
        if (!pass)                                   \
        {                                            \
            break;                                   \
        }                                            \
    }                                                \
    if (pass)                                        \
    {                                                \
        PASS(#A " == " #B "\n");                     \
    }                                                \
}

#define TEST(x)                    \
{                                  \
    printf("\nTesting %s\n", #x);  \
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

#define PRINT_ARRAYS(n,A,B)                                         \
{                                                                   \
    /* find maximum character size   */                             \
    int max_size = MAX(sizeof(#A) - 1, sizeof(#B) - 1);             \
    for (int i = 0; i < n; i++)                                     \
    {                                                               \
        max_size = MAX(max_size, INT_LENGTH(A[i]));                 \
        max_size = MAX(max_size, INT_LENGTH(B[i]));                 \
    }                                                               \
    for (int i = 0; i < (max_size * 2 + 7); i++)                    \
    {                                                               \
        putchar('-');                                               \
    }                                                               \
    putchar('\n');                                                  \
    printf("| %*s | %*s |\n", max_size, #A, max_size, #B);          \
    for (int i = 0; i < (max_size * 2 + 7); i++)                    \
    {                                                               \
        putchar('-');                                               \
    }                                                               \
    putchar('\n');                                                  \
    for (int i = 0; i < n; i++)                                     \
    {                                                               \
        printf("| %*i | %*i |\n", max_size, A[i], max_size, B[i]);  \
    }                                                               \
    for (int i = 0; i < (max_size * 2 + 7); i++)                    \
    {                                                               \
        putchar('-');                                               \
    }                                                               \
    putchar('\n');                                                  \
}

// PRINT_SQUARE_MATRIX
// ----------------------------
// | 1.23e3 | 1.23e3 | 1.23e3 |
// ----------------------------
// | 1.23e3 | 1.23e3 | 1.23e3 |
// ----------------------------
// | 1.23e3 | 1.23e3 | 1.23e3 |
// ----------------------------
#define PRINT_SQUARE_MATRIX(n,A,p)            \
{                                             \
    printf("%s:\n", #A);                      \
    int length = (p+8)*n + 1;                 \
    for (int i = 0; i < n; i++)               \
    {                                         \
        for (int j = 0; j < length; j++)      \
        {                                     \
            putchar('-');                     \
        }                                     \
        putchar('\n');                        \
        putchar('|');                         \
        for (int j = 0; j < n; j++)           \
        {                                     \
            printf(" %.*e |", p-1, A[i][j]);  \
        }                                     \
        putchar('\n');                        \
    }                                         \
    for (int k = 0; k < length; k++)          \
    {                                         \
        putchar('-');                         \
    }                                         \
    putchar('\n');                            \
}

#endif // TEST_H
