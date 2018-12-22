#include <square_matrix_multiply.h>
#include <stdlib.h>

double* squareMatrixMultiply(const double *A, const double *B, int n)
{
    double (*C)[n][n] = (double(*)[n][n])malloc(64*n*n);
    C = (double(*)[n][n])A;
    //return (int*)Am;
    /*int C = (int*)malloc(16*n*n); // (4*n)*(4*n) = number of bytes
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int c_ij = 0;
            for (int k = 0; k < n; k++)
            {
                c_ij
            }
        }
    }*/
}