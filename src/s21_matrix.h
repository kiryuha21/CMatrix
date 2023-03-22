#ifndef C6_S21_MATRIX_1_S21_MATRIX_H
#define C6_S21_MATRIX_1_S21_MATRIX_H

#define OK 0
#define ERR 1
#define CALC_ERR 2

// for comparisons
#define SUCCESS 1
#define FAILURE 0
#define DELTA 1e-7

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

void minus_row_col(const matrix_t *origin_matrix, matrix_t *temp_matrix,
                   int row, int col);
double recursive_det(const matrix_t *origin_matrix);

#endif  // C6_S21_MATRIX_1_S21_MATRIX_H
