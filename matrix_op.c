#include "matrix_op.h"
#include <stdio.h>

void matrix_add(const int matA[SIZE][SIZE], const int matB[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

void matrix_sub(const int matA[SIZE][SIZE], const int matB[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = matA[i][j] - matB[i][j];
        }
    }
}

void matrix_elementwise_mul(const int matA[SIZE][SIZE], const int matB[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = matA[i][j] * matB[i][j];
        }
    }
}


void matrix_mul(const int matA[SIZE][SIZE], const int matB[SIZE][SIZE], int result[SIZE][SIZE]) {
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

void matrix_transpose(const int matA[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = matA[i][j];
        }
    }
}

int matrix_det(const int mat[SIZE][SIZE]) {
    return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
           mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
           mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}

void matrix_adjoint(const int mat[SIZE][SIZE], int result[SIZE][SIZE]) {
    result[0][0] = +(mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2]);
    result[0][1] = -(mat[0][1] * mat[2][2] - mat[2][1] * mat[0][2]);
    result[0][2] = +(mat[0][1] * mat[1][2] - mat[1][1] * mat[0][2]);

    result[1][0] = -(mat[1][0] * mat[2][2] - mat[2][0] * mat[1][2]);
    result[1][1] = +(mat[0][0] * mat[2][2] - mat[2][0] * mat[0][2]);
    result[1][2] = -(mat[0][0] * mat[1][2] - mat[1][0] * mat[0][2]);

    result[2][0] = +(mat[1][0] * mat[2][1] - mat[2][0] * mat[1][1]);
    result[2][1] = -(mat[0][0] * mat[2][1] - mat[2][0] * mat[0][1]);
    result[2][2] = +(mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1]);
}

int matrix_inverse(const int mat[SIZE][SIZE], double result[SIZE][SIZE]) {
    int det = matrix_det(mat);
    if (det == 0) {
        printf("Error: Determinant is 0, inverse matrix does not exist.\n");
        return 0; 
    }

    int adj[SIZE][SIZE];
    matrix_adjoint(mat, adj); 

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = (double)adj[i][j] / det; 
        }
    }
    return 1; 
}