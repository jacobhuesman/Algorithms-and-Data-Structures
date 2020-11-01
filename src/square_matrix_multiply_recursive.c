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

#include <square_matrix_multiply_strassen.h>
#include <stdlib.h>

void squareMatrixMultiplyRecursive(int on, int n, double A[n][on], double B[n][on], double C[n][n])
{
    if (n == 1)
    {
        C[0][0] = A[0][0]*B[0][0];
    }
    else
    {
        double (*A_11)[n/2][on] = (double(*)[n/2][on])&A[  0][  0], 
               (*A_12)[n/2][on] = (double(*)[n/2][on])&A[  0][n/2], 
               (*A_21)[n/2][on] = (double(*)[n/2][on])&A[n/2][  0], 
               (*A_22)[n/2][on] = (double(*)[n/2][on])&A[n/2][n/2],
               (*B_11)[n/2][on] = (double(*)[n/2][on])&B[  0][  0], 
               (*B_12)[n/2][on] = (double(*)[n/2][on])&B[  0][n/2], 
               (*B_21)[n/2][on] = (double(*)[n/2][on])&B[n/2][  0], 
               (*B_22)[n/2][on] = (double(*)[n/2][on])&B[n/2][n/2];
        double K1[n/2][n/2], K2[n/2][n/2];
        squareMatrixMultiplyRecursive(on, n/2, *A_11, *B_11, K1);
        squareMatrixMultiplyRecursive(on, n/2, *A_12, *B_21, K2);
        for (int i = 0; i < n/2; i++)
        {
            for (int j = 0; j < n/2; j++)
            {
                C[i][j] = K1[i][j] + K2[i][j];
            }
        }
        squareMatrixMultiplyRecursive(on, n/2, *A_11, *B_12, K1);
        squareMatrixMultiplyRecursive(on, n/2, *A_12, *B_22, K2);
        for (int i = 0; i < n/2; i++)
        {
            for (int j = 0; j < n/2; j++)
            {
                C[i][j + n/2] = K1[i][j] + K2[i][j];
            }
        }
        squareMatrixMultiplyRecursive(on, n/2, *A_21, *B_11, K1);
        squareMatrixMultiplyRecursive(on, n/2, *A_22, *B_21, K2);
        for (int i = 0; i < n/2; i++)
        {
            for (int j = 0; j < n/2; j++)
            {
                C[i + n/2][j] = K1[i][j] + K2[i][j];
            }
        }
        squareMatrixMultiplyRecursive(on, n/2, *A_21, *B_12, K1);
        squareMatrixMultiplyRecursive(on, n/2, *A_22, *B_22, K2);
        for (int i = 0; i < n/2; i++)
        {
            for (int j = 0; j < n/2; j++)
            {
                C[i + n/2][j + n/2] = K1[i][j] + K2[i][j];
            }
        }
    }
}