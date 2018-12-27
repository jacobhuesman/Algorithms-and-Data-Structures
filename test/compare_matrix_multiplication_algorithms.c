#include <square_matrix_multiply_direct.h>
#include <square_matrix_multiply_recursive.h>
#include <square_matrix_multiply_strassen.h>
#include <eval.h>
#include <time.h>

int main(int argc, char *argv[])
{
    // Read Trial n
    int n = 512;
    if (argc > 1)
    {
        n = atoi(argv[1]);
    }
    printf("Trial n = %i\n", n);
    
    // Create matrices of random numbers
    double A[n][n], B[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = ((double)rand())/((double)(RAND_MAX));
            B[i][j] = ((double)rand())/((double)(RAND_MAX));
        }
    }
    
    // Timing
    clock_t start, end;
    
    // Direct matrix multiplication
    double C_direct[n][n], t_direct;
    start = clock();
    squareMatrixMultiplyDirect(n, A, B, C_direct);
    end = clock();
    t_direct = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Recursive matrix multiplication
    double C_recursive[n][n], t_recursive;
    start = clock();
    squareMatrixMultiplyRecursive(n, n, A, B, C_recursive);
    end = clock();
    t_recursive = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Recursive strassen approach
    double C_strassen[n][n], t_strassen;
    start = clock();
    squareMatrixMultiplyStrassen(n, A, B, C_strassen);
    end = clock();
    t_strassen = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Display results
    //n = 512,  direct =  0.719000s,  recursive =   2.359000s, strassen =  1.438000s
    //n = 1024, direct = 10.640000s,  recursive =  19.172000s, strassen = 11.015000s
    //n = 2048, direct = 174.235000s, recursive = 150.797000s, strassen = 70.329000s
    //direct = 176.063000, recursive = 161.078000, strassen = 75.579000
    ASSERT_SQUARE_MATRIX_DLEQ(n, C_direct,    C_recursive, 1.0e-8); 
    ASSERT_SQUARE_MATRIX_DLEQ(n, C_recursive, C_strassen,  1.0e-8); 
    ASSERT_SQUARE_MATRIX_DLEQ(n, C_strassen,  C_direct,    1.0e-8); 
    printf("n = %i, direct = %fs, recursive = %fs, strassen = %fs\n", n, t_direct, t_recursive, t_strassen);
    
    return 0;
}