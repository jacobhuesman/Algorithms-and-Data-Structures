#include <square_matrix_multiply_direct.h>
#include <stdlib.h>

void squareMatrixMultiplyDirect(int n, const double A[n][n], const double B[n][n], double C[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                C[i][j] = C[i][j] + A[i][k]*B[k][j];
            }
        }
    }
}