#include <square_matrix_multiply_strassen.h>
#include <stdlib.h>

void _squareMatrixMultiplyStrassen(int n, int an, double A[n][an], int bn, double B[n][bn], double C[n][n])
{
    if (n == 1)
    {
        C[0][0] = A[0][0]*B[0][0];
    }
    else
    {
        double (*A_11)[n/2][an] = (double(*)[n/2][an])&A[  0][  0], 
               (*A_12)[n/2][an] = (double(*)[n/2][an])&A[  0][n/2], 
               (*A_21)[n/2][an] = (double(*)[n/2][an])&A[n/2][  0], 
               (*A_22)[n/2][an] = (double(*)[n/2][an])&A[n/2][n/2],
               (*B_11)[n/2][bn] = (double(*)[n/2][bn])&B[  0][  0], 
               (*B_12)[n/2][bn] = (double(*)[n/2][bn])&B[  0][n/2], 
               (*B_21)[n/2][bn] = (double(*)[n/2][bn])&B[n/2][  0], 
               (*B_22)[n/2][bn] = (double(*)[n/2][bn])&B[n/2][n/2];
        double S[10][n/2][n/2];
        for (int i = 0; i < n/2; i++)
        {
            for (int j = 0; j < n/2; j++)
            {
                S[0][i][j] = (*B_12)[i][j] - (*B_22)[i][j];
                S[1][i][j] = (*A_11)[i][j] + (*A_12)[i][j];
                S[2][i][j] = (*A_21)[i][j] + (*A_22)[i][j];
                S[3][i][j] = (*B_21)[i][j] - (*B_11)[i][j];
                S[4][i][j] = (*A_11)[i][j] + (*A_22)[i][j];
                S[5][i][j] = (*B_11)[i][j] + (*B_22)[i][j];
                S[6][i][j] = (*A_12)[i][j] - (*A_22)[i][j];
                S[7][i][j] = (*B_21)[i][j] + (*B_22)[i][j];
                S[8][i][j] = (*A_11)[i][j] - (*A_21)[i][j];
                S[9][i][j] = (*B_11)[i][j] + (*B_12)[i][j];
            }
        }
        double P[9][n/2][n/2];
        _squareMatrixMultiplyStrassen(n/2,  an, *A_11, n/2,  S[0], P[0]);
        _squareMatrixMultiplyStrassen(n/2, n/2,  S[1],  bn, *B_22, P[1]);
        _squareMatrixMultiplyStrassen(n/2, n/2,  S[2],  bn, *B_11, P[2]);
        _squareMatrixMultiplyStrassen(n/2,  an, *A_22, n/2,  S[3], P[3]);
        _squareMatrixMultiplyStrassen(n/2, n/2,  S[4], n/2,  S[5], P[4]);
        _squareMatrixMultiplyStrassen(n/2, n/2,  S[6], n/2,  S[7], P[5]);
        _squareMatrixMultiplyStrassen(n/2, n/2,  S[8], n/2,  S[9], P[6]);
        for (int i = 0; i < n/2; i++)
        {
            for (int j = 0; j < n/2; j++)
            {
                C[i][j] = P[4][i][j] + P[3][i][j] - P[1][i][j] + P[5][i][j];
                C[i][j + n/2] = P[0][i][j] + P[1][i][j];
                C[i + n/2][j] = P[2][i][j] + P[3][i][j];
                C[i + n/2][j + n/2] = P[4][i][j] + P[0][i][j] - P[2][i][j] - P[6][i][j];
            }
        }
        
    }
}

void squareMatrixMultiplyStrassen(int n, double A[n][n], double B[n][n], double C[n][n])
{
    _squareMatrixMultiplyStrassen(n, n, A, n, B, C);
}

