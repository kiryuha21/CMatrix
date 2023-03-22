#include <math.h>

#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int return_code = SUCCESS;
  if (A->columns != B->columns || A->rows != B->rows) {
    return_code = FAILURE;
  } else {
    int stop = 0;
    for (int i = 0; i < A->rows && !stop; ++i) {
      for (int j = 0; j < A->columns && !stop; ++j) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= DELTA) {
          stop = 1;
          return_code = FAILURE;
        }
      }
    }
  }
  return return_code;
}
