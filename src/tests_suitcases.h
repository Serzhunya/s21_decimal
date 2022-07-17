#ifndef SRC_TESTS_SUITCASES_H_
#define SRC_TESTS_SUITCASES_H_

#define RESET "\033[0m"
#define RED "\e[0;91m"
#define GREEN "\033[32m"
#define BLUE "\e[0;94m"

#include <check.h>

#include "s21_decimal.h"

Suite *suite_add(void);
Suite *suite_sub(void);
Suite *suite_div(void);
Suite *suite_mod(void);
Suite *suite_mul(void);
Suite *suite_from_decimal_to_float(void);
Suite *suite_from_decimal_to_int(void);
Suite *suite_from_float_to_decimal(void);
Suite *suite_from_int_to_decimal(void);
Suite *suite_is_equal(void);
Suite *suite_is_not_equal(void);
Suite *suite_is_greater(void);
Suite *suite_is_greater_or_equal(void);
Suite *suite_is_less(void);
Suite *suite_is_less_or_equal(void);
Suite *suite_truncate(void);
Suite *suite_negate(void);
Suite *suite_floor(void);
Suite *suite_round(void);
void run_tests(void);
void run_testcase(Suite *testcase);

#endif  // SRC_TESTS_SUITCASES_H_
