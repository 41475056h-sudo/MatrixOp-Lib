#include <stdio.h>
#include "matrix_op.h"

int main() {
    double A[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    double B[SIZE][SIZE] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    double result[SIZE][SIZE];

    printf("Addition:\n");
    add_matrix(A, B, result);
    print_matrix(result);

    printf("Subtraction:\n");
    sub_matrix(A, B, result);
    print_matrix(result);

    printf("Multiplication:\n");
    multiply_matrix(A, B, result);
    print_matrix(result);

    printf("Element-wise Multiplication:\n");
    element_wise_multiply(A, B, result);
    print_matrix(result);

    return 0;
}