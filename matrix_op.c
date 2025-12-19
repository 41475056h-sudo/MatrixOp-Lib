#include <stdio.h>
#include "matrix_op.h"

void add_matrix(double a[SIZE][SIZE], double b[SIZE][SIZE], double result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void sub_matrix(double a[SIZE][SIZE], double b[SIZE][SIZE], double result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiply_matrix(double a[SIZE][SIZE], double b[SIZE][SIZE], double result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void element_wise_multiply(double a[SIZE][SIZE], double b[SIZE][SIZE], double result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] * b[i][j];
        }
    }
}

void print_matrix(double matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        printf("[ ");
        for (int j = 0; j < SIZE; j++) {
            printf("%6.2f ", matrix[i][j]);
        }
        printf("]\n");
    }
    printf("\n");
}