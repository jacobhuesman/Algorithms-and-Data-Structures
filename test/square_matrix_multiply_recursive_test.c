#include <square_matrix_multiply_recursive.h>
#include <eval.h>

// Test cases
#define M_PI 3.14159265359
void squareMatrixMultiplyRecursive_2x2_test()
{
    // Setup
    double A[2][2] = {{1,2},{3,4}};
    double B[2][2] = {{5,6},{7,8}};
    double C[2][2];
    double E[2][2] = {{19,22},{43,50}}; // expected
    
    // Test
    printf("\nsquareMatrixMultiplyRecursive_2x2_test()\n");
    squareMatrixMultiplyRecursive(2,2,A,B,C);
    PRINT_SQUARE_MATRIX(A,2,2);
    PRINT_SQUARE_MATRIX(B,2,2);
    PRINT_SQUARE_MATRIX(C,2,2);
    PRINT_SQUARE_MATRIX(E,2,2);
    ASSERT_SQUARE_MATRIX_EQ(2,C,E); 
}

void squareMatrixMultiplyRecursive_4x4_test()
{
    // Setup
    double A[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    double B[4][4] = {{17,18,19,20},{21,22,23,24},{25,26,27,28},{29,30,31,32}};
    double C[4][4];
    double E[4][4] = {{250,260,270,280},{618,644,670,696},{986,1028,1070,1112},{1354,1412,1470,1528}}; // expected
    
    // Test
    printf("\nsquareMatrixMultiplyRecursive_4x4_test()\n");
    squareMatrixMultiplyRecursive(4,4,A,B,C);
    PRINT_SQUARE_MATRIX(A,4,4);
    PRINT_SQUARE_MATRIX(B,4,4);
    PRINT_SQUARE_MATRIX(C,4,4);
    PRINT_SQUARE_MATRIX(E,4,4);
    ASSERT_SQUARE_MATRIX_EQ(4,C,E); 
}

// Run test cases
void main()
{
    printf("\nRunning %s\n", __FILE__);
    squareMatrixMultiplyRecursive_2x2_test();
    squareMatrixMultiplyRecursive_4x4_test();
}