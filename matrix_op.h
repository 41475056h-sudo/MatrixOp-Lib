#ifndef MATRIX_OP_H
#define MATRIX_OP_H

#define SIZE 3

// === Basic (基礎運算) ===
void matrix_add(const int matA[SIZE][SIZE], const int matB[SIZE][SIZE], int result[SIZE][SIZE]);
void matrix_sub(const int matA[SIZE][SIZE], const int matB[SIZE][SIZE], int result[SIZE][SIZE]);
void matrix_elementwise_mul(const int matA[SIZE][SIZE], const int matB[SIZE][SIZE], int result[SIZE][SIZE]); // 新增

// === Linear (線性運算) ===
void matrix_mul(const int matA[SIZE][SIZE], const int matB[SIZE][SIZE], int result[SIZE][SIZE]);
void matrix_transpose(const int matA[SIZE][SIZE], int result[SIZE][SIZE]); // 新增

// === Advanced (進階運算) ===
int matrix_det(const int matA[SIZE][SIZE]); // 新增：計算行列式值 (回傳數字)
void matrix_adjoint(const int matA[SIZE][SIZE], int result[SIZE][SIZE]); // 新增：伴隨矩陣

// === Inverse (反矩陣) ===
// 注意：反矩陣會有小數點，所以 result 用 double
int matrix_inverse(const int matA[SIZE][SIZE], double result[SIZE][SIZE]); // 新增

#endif