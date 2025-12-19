#include <stdio.h>
#include "matrix_op.h"

void print_matrix(const char* name, int mat[SIZE][SIZE]) {
    printf("Matrix %s:\n", name);
    for (int i = 0; i < SIZE; i++) {
        printf("[ ");
        for (int j = 0; j < SIZE; j++) printf("%4d ", mat[i][j]);
        printf("]\n");
    }
    printf("\n");
}

// 專門印出小數點矩陣 (給反矩陣用)
void print_double_matrix(const char* name, double mat[SIZE][SIZE]) {
    printf("Matrix %s (double):\n", name);
    for (int i = 0; i < SIZE; i++) {
        printf("[ ");
        for (int j = 0; j < SIZE; j++) printf("%6.2f ", mat[i][j]);
        printf("]\n");
    }
    printf("\n");
}

int main() {
    int A[SIZE][SIZE] = { {1, 2, 3}, {0, 1, 4}, {5, 6, 0} }; // 選這個矩陣是因為它有反矩陣
    int B[SIZE][SIZE] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
    int res[SIZE][SIZE];
    double res_inv[SIZE][SIZE]; // 存反矩陣結果

    printf("=== Basic ===\n");
    matrix_add(A, B, res); print_matrix("Addition (A+B)", res);
    matrix_sub(A, B, res); print_matrix("Subtraction (A-B)", res);
    matrix_elementwise_mul(A, B, res); print_matrix("Element-wise Mul", res);

    printf("=== Linear ===\n");
    matrix_mul(A, B, res); print_matrix("Matrix Mul (A*B)", res);
    matrix_transpose(A, res); print_matrix("Transpose (A)", res);

    printf("=== Advanced ===\n");
    int det = matrix_det(A);
    printf("Determinant of A = %d\n\n", det);
    
    matrix_adjoint(A, res); print_matrix("Adjoint (A)", res);

    printf("=== Inverse ===\n");
    if (matrix_inverse(A, res_inv)) {
        print_double_matrix("Inverse (A^-1)", res_inv);
    }

    return 0;
}