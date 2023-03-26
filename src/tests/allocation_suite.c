#include <limits.h>

#include "unit_tests.h"

START_TEST(s21_create_matrix_01) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_02) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_03) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 2, &A);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_04) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(2, 4, &A);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_05) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(10, 15, &A);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_06) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(res, ERR);
}
END_TEST

START_TEST(s21_create_matrix_07) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(1, 0, &A);
  ck_assert_int_eq(res, ERR);
}
END_TEST

START_TEST(s21_create_matrix_08) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(0, 1, &A);
  ck_assert_int_eq(res, ERR);
}
END_TEST

START_TEST(s21_create_matrix_09) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(-1, 1, &A);
  ck_assert_int_eq(res, ERR);
}
END_TEST

START_TEST(create_1) {
  srand(time(NULL));
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = 0;
      ck_assert_ldouble_eq_tol(0, m.matrix[i][j], 1e-07);
    }
  }
  ck_assert_int_eq(m.rows, rows);
  ck_assert_int_eq(m.columns, cols);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_2) {
  const int rows = 0;
  const int cols = 10;
  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), ERR);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_3) {
  const int rows = 10;
  const int cols = 0;

  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), ERR);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_4) {
  const int rows = INT_MAX;
  const int cols = INT_MAX;

  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), ERR);
}
END_TEST

START_TEST(s21_remove_matrix_01) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(2, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = ERR;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(s21_remove_matrix_02) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(1, 1, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = ERR;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(s21_remove_matrix_03) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = ERR;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(s21_remove_matrix_04) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 4, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = ERR;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(s21_remove_matrix_05) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = ERR;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

Suite *get_allocation_suite() {
  Suite *s = suite_create("allocation_suite");

  TCase *create_case = tcase_create("case_create_matrix");
  tcase_add_test(create_case, s21_create_matrix_01);
  tcase_add_test(create_case, s21_create_matrix_02);
  tcase_add_test(create_case, s21_create_matrix_03);
  tcase_add_test(create_case, s21_create_matrix_04);
  tcase_add_test(create_case, s21_create_matrix_05);
  tcase_add_test(create_case, s21_create_matrix_06);
  tcase_add_test(create_case, s21_create_matrix_07);
  tcase_add_test(create_case, s21_create_matrix_08);
  tcase_add_test(create_case, s21_create_matrix_09);
  tcase_add_test(create_case, create_1);
  tcase_add_test(create_case, create_2);
  tcase_add_test(create_case, create_3);
  tcase_add_test(create_case, create_4);

  TCase *remove_case = tcase_create("suite_remove_matrix");
  tcase_add_test(remove_case, s21_remove_matrix_01);
  tcase_add_test(remove_case, s21_remove_matrix_02);
  tcase_add_test(remove_case, s21_remove_matrix_03);
  tcase_add_test(remove_case, s21_remove_matrix_04);
  tcase_add_test(remove_case, s21_remove_matrix_05);

  suite_add_tcase(s, create_case);
  suite_add_tcase(s, remove_case);

  return s;
}
