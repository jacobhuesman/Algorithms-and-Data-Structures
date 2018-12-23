#include <square_matrix_multiply_direct.h>
#include <eval.h>

// Test cases
#define M_PI 3.14159265359
void squareMatrixMultiplyDirect_test()
{
    // Setup
    double A[2][2] = {{1,2},{3,4}};
    double B[2][2] = {{5,6},{7,8}};
    double C[2][2];
    double E[2][2] = {{19,22},{43,50}}; // expected
    
    // Test
    squareMatrixMultiplyDirect(2,A,B,C);
    PRINT_SQUARE_MATRIX(A,2,2);
    PRINT_SQUARE_MATRIX(B,2,2);
    PRINT_SQUARE_MATRIX(C,2,2);
    PRINT_SQUARE_MATRIX(E,2,2);
    ASSERT_SQUARE_MATRIX_EQ(2,C,E); 

}

// Run test cases
void main()
{
    printf("\nRunning %s\n", __FILE__);
    squareMatrixMultiplyDirect_test();
}