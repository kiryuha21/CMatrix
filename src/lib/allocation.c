#include <stdlib.h>

#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  result = (matrix_t *)malloc(sizeof(matrix_t));
  if (result == NULL) {
    return ERR;
  }
  result->rows = rows;
  result->columns = columns;

  result->matrix = (double **)malloc(rows * sizeof(double *));
  if (result->matrix == NULL) {
    free(result);
    return ERR;
  }

  for (size_t i = 0; i < rows; ++i) {
    result->matrix[i] = (double *)malloc(columns * sizeof(double));
    if (result->matrix[i] == NULL) {
      for (size_t j = 0; j < i; ++j) {
        free(result->matrix[j]);
      }
      free(result->matrix);
      free(result);
      return ERR;
    }
  }
  return OK;
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    for (size_t i = 0; i < A->rows; ++i) {
      free(A->matrix[i]);
    }

    free(A->matrix);

    free(A);
  }
}
