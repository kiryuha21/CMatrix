#include "unit_tests.h"

double get_rand(double min, double max) {
  double val = (double)rand() / RAND_MAX;
  return min + val * (max - min);
}

int main() {
  Suite *suites[SUITES_COUNT] = {
      get_allocation_suite(), get_comparisons_suite(), get_arithmetics_suite(),
      get_matrix_specials_suite()};

  for (int i = 0; i < SUITES_COUNT; ++i) {
    SRunner *srunner = srunner_create(suites[i]);
    srunner_run_all(srunner, CK_NORMAL);
    srunner_free(srunner);
  }

  return 0;
}
