#include <stdlib.h>

#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (result == NULL || rows <= 0 || columns <= 0) {
    return ERR;
  }

  result->rows = rows;
  result->columns = columns;

  result->matrix = (double **)calloc(rows, sizeof(double *));
  if (result->matrix == NULL) {
    return ERR;
  }

  for (int i = 0; i < rows; ++i) {
    result->matrix[i] = (double *)calloc(columns, sizeof(double));
    if (result->matrix[i] == NULL) {
      remove_nrows_matrix(result, i);
      return ERR;
    }
  }
  return OK;
}

void s21_remove_matrix(matrix_t *A) { remove_nrows_matrix(A, A->rows); }
