#ifndef C6_S21_MATRIX_1_UNIT_TESTS_H
#define C6_S21_MATRIX_1_UNIT_TESTS_H

#include <check.h>
#include <stdlib.h>
#include <time.h>

#include "../s21_matrix.h"

#define SUITES_COUNT 4

Suite* get_allocation_suite();
Suite* get_arithmetics_suite();
Suite* get_comparisons_suite();
Suite* get_matrix_specials_suite();

double get_rand(double min, double max);

#endif  // C6_S21_MATRIX_1_UNIT_TESTS_H
