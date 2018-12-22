#include <square_matrix_multiply.h>
#include <eval.h>

// Test cases
#define M_PI 3.14159265359
void squareMatrixMultiply_test()
{
    /*
    // Setup
    int unsorted[] = {5,2,4,6,1,3};
    int *sorted;
    cloneArray(unsorted, &sorted, 6);
    
    // Test
    printf("\ninsertionSort_test:\n");
    int expected[] = {1,2,3,4,5,6};
    insertionSort(sorted, 6);
    PRINT_ARRAYS(unsorted, sorted, 6);
    ASSERT_ARRAY_EQ(sorted,expected,6)
    printf("\n");
    
    free(sorted);
    */
    double A[2][2] = {{M_PI,M_PI/2},{M_PI*4,1}};
    PRINT_SQUARE_MATRIX(A,2,6);
}

// Run test cases
void main()
{
    printf("\nRunning %s\n", __FILE__);
    squareMatrixMultiply_test();
}