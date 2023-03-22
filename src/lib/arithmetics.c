#include <stdlib.h>

#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result != NULL) {
    return ERR;
  }

  if (A->rows != B->rows || A->columns != B->columns) {
    return CALC_ERR;
  }

  s21_create_matrix(A->rows, A->columns, result);
  if (result == NULL) {
    return ERR;
  }

  for (size_t i = 0; i < A->rows; ++i) {
    for (size_t j = 0; j < A->columns; ++j) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
  return OK;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result != NULL) {
    return ERR;
  }

  if (A->rows != B->rows || A->columns != B->columns) {
    return CALC_ERR;
  }

  s21_create_matrix(A->rows, A->columns, result);
  if (result == NULL) {
    return ERR;
  }

  for (size_t i = 0; i < A->rows; ++i) {
    for (size_t j = 0; j < A->columns; ++j) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
  return OK;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (A == NULL || result != NULL) {
    return ERR;
  }

  s21_create_matrix(A->rows, A->columns, result);
  if (result == NULL) {
    return ERR;
  }

  for (size_t i = 0; i < A->rows; ++i) {
    for (size_t j = 0; j < A->columns; ++j) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
  return OK;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result != NULL) {
    return ERR;
  }

  if (A->columns != B->rows) {
    return CALC_ERR;
  }

  s21_create_matrix(A->rows, B->columns, result);
  if (result == NULL) {
    return ERR;
  }

  for (size_t i = 0; i < A->rows; ++i) {
    for (size_t j = 0; j < B->columns; ++j) {
      result->matrix[i][j] = 0;
      for (size_t k = 0; k < A->columns; ++k) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
  return OK;
}
