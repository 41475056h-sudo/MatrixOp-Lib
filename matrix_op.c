#include "matrix_op.h"
#include <stdio.h>

// 1. 矩陣加法
void matrix_add(const int matA[SIZE][SIZE], const int matB[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

// 2. 矩陣減法
void matrix_sub(const int matA[SIZE][SIZE], const int matB[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = matA[i][j] - matB[i][j];
        }
    }
}

// 3. 元素對應乘法 (Element-wise Multiplication)
// 這是對應位置直接相乘，跟矩陣乘法不同
void matrix_elementwise_mul(const int matA[SIZE][SIZE], const int matB[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = matA[i][j] * matB[i][j];
        }
    }
}

// 4. 矩陣乘法 (Matrix Multiplication)
void matrix_mul(const int matA[SIZE][SIZE], const int matB[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0; // 初始化
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

// 5. 轉置矩陣 (Transpose)
// 行變列，列變行
void matrix_transpose(const int matA[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = matA[i][j];
        }
    }
}

// 6. 行列式 (Determinant)
// 針對 3x3 矩陣的公式展開
int matrix_det(const int mat[SIZE][SIZE]) {
    return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
           mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
           mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}

// 7. 伴隨矩陣 (Adjoint)
// 公式：Adj[i][j] = (-1)^(i+j) * Minor(j, i)  <-- 注意這裡是 (j, i) 因為要轉置
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

// 8. 反矩陣 (Inverse)
// 公式：Inverse = Adjoint / Determinant
// 回傳 1 代表成功，回傳 0 代表失敗 (行列式為 0，不可逆)
int matrix_inverse(const int mat[SIZE][SIZE], double result[SIZE][SIZE]) {
    int det = matrix_det(mat);
    if (det == 0) {
        printf("Error: Determinant is 0, inverse matrix does not exist.\n");
        return 0; // 失敗
    }

    int adj[SIZE][SIZE];
    matrix_adjoint(mat, adj); // 先算伴隨矩陣

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = (double)adj[i][j] / det; // 每個元素除以行列式
        }
    }
    return 1; // 成功
}