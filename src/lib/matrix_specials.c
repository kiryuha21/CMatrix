#include <float.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (A == NULL || result != NULL) {
    return ERR;
  }

  s21_create_matrix(A->columns, A->rows, result);
  if (result == NULL) {
    return ERR;
  }

  for (int i = 0; i < A->columns; ++i) {
    for (int j = 0; j < A->rows; ++j) {
      result->matrix[i][j] = A->matrix[j][i];
    }
  }
  return OK;
}

int s21_determinant(matrix_t *A, double *result) {
  if (A == NULL || result == NULL) {
    return ERR;
  }

  if (A->rows != A->columns) {
    return CALC_ERR;
  }

  *result = recursive_det(A);
  return OK;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (A == NULL || result != NULL) {
    return ERR;
  }

  if (A->rows != A->columns) {
    return CALC_ERR;
  }

  matrix_t *temp_matrix = NULL;
  s21_create_matrix(A->rows, A->columns, temp_matrix);
  if (temp_matrix == NULL) {
    return ERR;
  }

  int sign = 1;
  for (int i = 0; i < temp_matrix->rows; ++i) {
    for (int j = 0; j < temp_matrix->columns; ++j) {
      matrix_t *additions_matrix = NULL;
      s21_create_matrix(temp_matrix->rows - 1, temp_matrix->columns - 1,
                        additions_matrix);
      if (additions_matrix == NULL) {
        return ERR;
      }
      minus_row_col(A, additions_matrix, j, i);
      if ((i + j) % 2 == 0) {
        sign = 1;
      } else {
        sign = -1;
      }
      temp_matrix->matrix[i][j] = sign * recursive_det(additions_matrix);
      s21_remove_matrix(additions_matrix);
    }
  }
  return OK;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (A == NULL) {
    return ERR;
  }

  if (A->rows != A->columns) {
    return CALC_ERR;
  }

  double temp_det = recursive_det(A);
  if (fabs(temp_det) < DBL_EPSILON) {
    return ERR;
  }

  if (A->columns == 1) {
    s21_create_matrix(1, 1, result);
    if (result == NULL) {
      return ERR;
    }
    if (A->matrix[0][0] == 0) {
      return ERR;
    }
    result->matrix[0][0] = 1 / A->matrix[0][0];
  } else {
    matrix_t *adj_temp = NULL;
    int complements_return = s21_calc_complements(A, adj_temp);
    if (complements_return != OK) {
      return complements_return;
    }

    int mult_return = s21_mult_number(adj_temp, (1.0 / temp_det), result);
    if (mult_return != OK) {
      s21_remove_matrix(adj_temp);
      return ERR;
    }
    s21_remove_matrix(adj_temp);
  }
  return OK;
}
