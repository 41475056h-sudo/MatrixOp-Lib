#include "matrix_op.h"
#include <stdio.h>

void matrix_add(const int matA[SIZE][SIZE], const int matB[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < SIZE; i++) {       
        for (int j = 0; j < SIZE; j++) {   
            for (int k = 0; k < SIZE; k++) { 
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

void matrix_sub(const int matA[SIZE][SIZE], const int matB[SIZE][SIZE], int result[SIZE][SIZE]) {
}

void matrix_mul(const int matA[SIZE][SIZE], const int matB[SIZE][SIZE], int result[SIZE][SIZE]) {
}

void matrix_transpose(const int matA[SIZE][SIZE], int result[SIZE][SIZE]) {
}

void matrix_element_wise_mul(const int matA[SIZE][SIZE], const int matB[SIZE][SIZE], int result[SIZE][SIZE]) {
}

int matrix_det(const int matA[SIZE][SIZE]) {
    return 0; 
}

void matrix_adjoint(const int matA[SIZE][SIZE], int result[SIZE][SIZE]) {
}

void matrix_inverse(const int matA[SIZE][SIZE], double result[SIZE][SIZE]) {
}