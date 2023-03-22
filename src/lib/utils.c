#include <stdlib.h>

#include "../s21_matrix.h"

void minus_row_col(const matrix_t *origin_matrix, matrix_t *temp_matrix,
                   int row, int col) {
  int miss_row = 0;

  for (int i = 0; i < origin_matrix->rows - 1; ++i) {
    if (i == row) {
      miss_row = 1;
    }
    int miss_col = 0;
    for (int j = 0; j < origin_matrix->rows - 1; ++j) {
      if (j == col) {
        miss_col = 1;
      }
      temp_matrix->matrix[i][j] =
          origin_matrix->matrix[i + miss_row][j + miss_col];
    }
  }
}

double recursive_det(const matrix_t *origin_matrix) {
  double temp_det = 0;

  if (origin_matrix->rows >= 1) {
    if (origin_matrix->rows == 1) {
      temp_det = origin_matrix->matrix[0][0];
    } else {
      if (origin_matrix->rows == 2) {
        temp_det = origin_matrix->matrix[0][0] * origin_matrix->matrix[1][1] -
                   origin_matrix->matrix[1][0] * origin_matrix->matrix[0][1];
      } else {
        matrix_t *temp_matrix = NULL;
        s21_create_matrix(origin_matrix->rows - 1, origin_matrix->columns - 1,
                          temp_matrix);
        if (temp_matrix != NULL) {
          int sign = 1;

          for (int i = 0; i < origin_matrix->rows; ++i) {
            minus_row_col(origin_matrix, temp_matrix, i, 0);
            temp_det = temp_det + sign * origin_matrix->matrix[i][0] *
                                      recursive_det(temp_matrix);
            sign = -sign;
          }

          s21_remove_matrix(temp_matrix);
        }
      }
    }
  }
  return (temp_det);
}
