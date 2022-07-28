#include "tests_suitcases.h"

START_TEST(s21_from_decimal_to_int_1) {
  s21_decimal src;
  int result = 0, number = 0;
  src.bits[0] = INT_MAX;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_float_eq(number, 2147483647);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_2) {
  s21_decimal src;
  int result = 0, number = 0;
  src.bits[0] = 133141;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 133141);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_3) {
  s21_decimal src;
  int result = 0, number = 0;
  src.bits[0] = 2147483647;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  set_1_bit(&(src.bits[3]), 31);
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -2147483647);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_4) {
  s21_decimal src;
  int result = 0, number = 0;
  long int c = 2147483648;
  src.bits[0] = 123451234;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -123451234);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_5) {
  s21_decimal src;
  int result = 0, number = 0;
  long int c = 2147483648;
  src.bits[0] = 18;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;  // 2147483648
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -18);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_6) {
  s21_decimal src;
  int result = 0, number = 0;
  long int c = 4294967295;
  src.bits[0] = c;
  src.bits[1] = c;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 0xFFFFFFFFFFFFFFFF);
  ck_assert_int_eq(result, 0);
}
END_TEST

int check, result, code;

START_TEST(s21_test_from_decimal_to_int_0) {
    s21_decimal a = {{100, 0, 0, 0}};
    check = 100;
    code = s21_from_decimal_to_int(a, &result);
    ck_assert_int_eq(result, check);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_1) {
    s21_decimal a = {{INT_MAX, 0, 0, 0}};
    check = INT_MAX;
    code = s21_from_decimal_to_int(a, &result);
    ck_assert_int_eq(result, check);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_2) {
    s21_decimal a = {{INT_MAX, INT_MAX, 0, 0}};
    check = 0;
    code = s21_from_decimal_to_int(a, &result);
    ck_assert_int_eq(result, check);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_3) {
    s21_decimal a = {{INT_MAX, INT_MAX, INT_MAX, 0}};
    check = 0;
    code = s21_from_decimal_to_int(a, &result);
    ck_assert_int_eq(result, check);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_4) {
    s21_decimal a = {{INT_MAX, INT_MAX, INT_MAX, INT_MAX}};
    check = 0;
    code = s21_from_decimal_to_int(a, &result);
    ck_assert_int_eq(result, check);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_5) {
    s21_decimal a = {{S21_MAX_UINT, 0, 0, 0}};
    check = 0;
    code = s21_from_decimal_to_int(a, &result);
    ck_assert_int_eq(result, check);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_6) {
    s21_decimal a = {{S21_MAX_UINT, S21_MAX_UINT, 0, 0}};
    check = 0;
    code = s21_from_decimal_to_int(a, &result);
    ck_assert_int_eq(result, check);
    ck_assert_int_eq(code, 1);
}
END_TEST
START_TEST(s21_test_from_decimal_to_int_7) {
    s21_decimal a = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};
    check = 0;
    code = s21_from_decimal_to_int(a, &result);
    ck_assert_int_eq(result, check);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_8) {
    s21_decimal a = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT}};
    check = 0;
    code = s21_from_decimal_to_int(a, &result);
    ck_assert_int_eq(result, check);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_9) {
    s21_decimal a = {{INT_MAX, 0, 0, MINUS}};
    check = -INT_MAX;
    code = s21_from_decimal_to_int(a, &result);
    ck_assert_int_eq(result, check);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_10) {
    s21_decimal a = {{INT_MAX, 0, 0, EXPONENT_MINUS_1}};
    check = -INT_MAX;
    code = s21_from_decimal_to_int(a, &result);
    ck_assert_int_eq(result, check);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_11) {
    s21_decimal a = {{INT_MAX, 0, 0, EXPONENT_PLUS_1}};
    check = INT_MAX;
    code = s21_from_decimal_to_int(a, &result);
    ck_assert_int_eq(result, check);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_12) {
    s21_decimal a = {{INT_MAX, 0, 0, EXPONENT_MINUS_28}};
    check = -INT_MAX;
    code = s21_from_decimal_to_int(a, &result);
    ck_assert_int_eq(result, check);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_14) {
    s21_decimal a = {{INT_MAX, 0, 0, EXPONENT_PLUS_28}};
    check = INT_MAX;
    code = s21_from_decimal_to_int(a, &result);
    ck_assert_int_eq(result, check);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_15) {
    s21_decimal a;
    a.bits[0] = 0b10000000000000000000000000000000;
    a.bits[1] = 0b00000000000000000000000000000000;
    a.bits[2] = 0b00000000000000000000000000000000;
    a.bits[3] = 0b00000000000000000000000000000001;
    check = 0;
    code = s21_from_decimal_to_int(a, &result);
    ck_assert_int_eq(result, check);
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_16) {
    s21_decimal a;
    a.bits[0] = 0b00000000000000000000000000000001;
    a.bits[1] = 0b00000000000000000000000000000000;
    a.bits[2] = 0b00000000000000000000000000000000;
    a.bits[3] = 0b00000000000000000000000000000000;
    check = 1;
    code = s21_from_decimal_to_int(a, &result);
    ck_assert_int_eq(result, check);
    ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_17) {
    s21_decimal a;
    a.bits[0] = 0b10000000000000000000000000000001;
    a.bits[1] = 0b00000000000000000000000000000000;
    a.bits[2] = 0b00000000000000000000000000000000;
    a.bits[3] = 0b00000000000000000000000000000000;
    check = 0;
    code = s21_from_decimal_to_int(a, &result);
    ck_assert_int_eq(result, check);
    ck_assert_int_eq(code, 1);
}
END_TEST


START_TEST(s21_from_decimal_to_intTest1) {
    // 6556
    s21_decimal src1;
    // src1 = 2;

    src1.bits[0] = 0b00000000000000000000000000000010;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    int result;
    int *res = &result;
    s21_from_decimal_to_int(src1, res);
    ck_assert_int_eq(result, 2);
}
END_TEST

START_TEST(s21_from_decimal_to_intTest2) {
    // 6570
    s21_decimal src1;
    // src1 = 0;

    src1.bits[0] = 0b00000000000000000000000000000000;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    int result;
    int *res = &result;
    s21_from_decimal_to_int(src1, res);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_intTest3) {
    // 6584
    s21_decimal src1;
    // src1 = 3.5;

    src1.bits[0] = 0b00000000000000000000000000100011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000010000000000000000;
    int result;
    int *res = &result;
    s21_from_decimal_to_int(src1, res);
    ck_assert_int_eq(result, 3);
}
END_TEST

START_TEST(s21_from_decimal_to_intTest4) {
    // 6598
    s21_decimal src1;
    // src1 = 4.5;

    src1.bits[0] = 0b00000000000000000000000000101101;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000010000000000000000;
    int result;
    int *res = &result;
    s21_from_decimal_to_int(src1, res);
    ck_assert_int_eq(result, 4);
}
END_TEST

START_TEST(s21_from_decimal_to_intTest5) {
    // 6612
    s21_decimal src1;
    // src1 = -4.5;

    src1.bits[0] = 0b00000000000000000000000000101101;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000010000000000000000;
    int result;
    int *res = &result;
    s21_from_decimal_to_int(src1, res);
    ck_assert_int_eq(result, -4);
}
END_TEST

START_TEST(s21_from_decimal_to_intTest6) {
    // 6626
    s21_decimal src1;
    // src1 = -5454.3526545;

    src1.bits[0] = 0b10110011000011000010101010010001;
    src1.bits[1] = 0b00000000000000000000000000001100;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000001110000000000000000;
    int result;
    int *res = &result;
    s21_from_decimal_to_int(src1, res);
    ck_assert_int_eq(result, -5454);
}
END_TEST

START_TEST(s21_from_decimal_to_intTest7) {
    // 6640
    s21_decimal src1;
    // src1 = -5.492654545456454545645464;

    src1.bits[0] = 0b00000111100110110001111110011000;
    src1.bits[1] = 0b01100110010010001001000110100011;
    src1.bits[2] = 0b00000000000001001000101100011101;
    src1.bits[3] = 0b10000000000110000000000000000000;
    int result;
    int *res = &result;
    s21_from_decimal_to_int(src1, res);
    ck_assert_int_eq(result, -5);
}
END_TEST

START_TEST(s21_from_decimal_to_intTest8) {
    // 6654
    s21_decimal src1;
    // src1 = 796132784.879754;

    src1.bits[0] = 0b00011011110101100011100010001010;
    src1.bits[1] = 0b00000000000000101101010000010100;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000001100000000000000000;
    int result;
    int *res = &result;
    s21_from_decimal_to_int(src1, res);
    ck_assert_int_eq(result, 796132784);
}
END_TEST

START_TEST(s21_from_decimal_to_intTest9) {
    // 6668
    s21_decimal src1;
    // src1 = -12345677.187654345678987654346;

    src1.bits[0] = 0b01111000100010101111010011001010;
    src1.bits[1] = 0b01100010000010101110010010000111;
    src1.bits[2] = 0b00100111111001000001101011010101;
    src1.bits[3] = 0b10000000000101010000000000000000;
    int result;
    int *res = &result;
    s21_from_decimal_to_int(src1, res);
    ck_assert_int_eq(result, -12345677);
}
END_TEST

START_TEST(s21_from_decimal_to_intTest10) {
    // 6682
    s21_decimal src1;
    // src1 = 2.5086531268974139743;

    src1.bits[0] = 0b01100101111011101101100101011111;
    src1.bits[1] = 0b01011100001001010100001101000110;
    src1.bits[2] = 0b00000000000000000000000000000001;
    src1.bits[3] = 0b00000000000100110000000000000000;
    int result;
    int *res = &result;
    s21_from_decimal_to_int(src1, res);
    ck_assert_int_eq(result, 2);
}
END_TEST

START_TEST(s21_from_decimal_to_intTest11) {
    // 6696
    s21_decimal src1;
    // src1 = 1;

    src1.bits[0] = 0b00000000000000000000000000000001;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    int result;
    int *res = &result;
    s21_from_decimal_to_int(src1, res);
    ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_intTest12) {
    // 6710
    s21_decimal src1;
    // src1 = 1.25;

    src1.bits[0] = 0b00000000000000000000000001111101;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000100000000000000000;
    int result;
    int *res = &result;
    s21_from_decimal_to_int(src1, res);
    ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_intTest13) {
    // 6724
    s21_decimal src1;
    // src1 = -1.25;

    src1.bits[0] = 0b00000000000000000000000001111101;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000100000000000000000;
    int result;
    int *res = &result;
    s21_from_decimal_to_int(src1, res);
    ck_assert_int_eq(result, -1);
}
END_TEST

START_TEST(s21_from_decimal_to_intTest14) {
    // 6738
    s21_decimal src1;
    // src1 = -12.25;

    src1.bits[0] = 0b00000000000000000000010011001001;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000100000000000000000;
    int result;
    int *res = &result;
    s21_from_decimal_to_int(src1, res);
    ck_assert_int_eq(result, -12);
}
END_TEST

START_TEST(s21_from_decimal_to_intTest15) {
    // 6752
    s21_decimal src1;
    // src1 = -3.5;

    src1.bits[0] = 0b00000000000000000000000000100011;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000010000000000000000;
    int result;
    int *res = &result;
    s21_from_decimal_to_int(src1, res);
    ck_assert_int_eq(result, -3);
}
END_TEST

Suite *suite_from_decimal_to_int(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_from_decimal_to_int");
  tc = tcase_create("case_from_decimal_to_int");

  tcase_add_test(tc, s21_from_decimal_to_int_1);
  tcase_add_test(tc, s21_from_decimal_to_int_2);
  tcase_add_test(tc, s21_from_decimal_to_int_3);
  tcase_add_test(tc, s21_from_decimal_to_int_4);
  tcase_add_test(tc, s21_from_decimal_to_int_5);
  tcase_add_test(tc, s21_from_decimal_to_int_6);

  tcase_add_test(tc, s21_test_from_decimal_to_int_0);
  tcase_add_test(tc, s21_test_from_decimal_to_int_1);
  tcase_add_test(tc, s21_test_from_decimal_to_int_2);
  tcase_add_test(tc, s21_test_from_decimal_to_int_3);
  tcase_add_test(tc, s21_test_from_decimal_to_int_4);
  tcase_add_test(tc, s21_test_from_decimal_to_int_5);
  tcase_add_test(tc, s21_test_from_decimal_to_int_6);
  tcase_add_test(tc, s21_test_from_decimal_to_int_7);
  tcase_add_test(tc, s21_test_from_decimal_to_int_8);
  tcase_add_test(tc, s21_test_from_decimal_to_int_9);
  tcase_add_test(tc, s21_test_from_decimal_to_int_10);
  tcase_add_test(tc, s21_test_from_decimal_to_int_11);
  tcase_add_test(tc, s21_test_from_decimal_to_int_12);
  tcase_add_test(tc, s21_test_from_decimal_to_int_14);
  tcase_add_test(tc, s21_test_from_decimal_to_int_15);
  tcase_add_test(tc, s21_test_from_decimal_to_int_16);
  tcase_add_test(tc, s21_test_from_decimal_to_int_17);
  tcase_add_test(tc, s21_from_decimal_to_intTest1);
  tcase_add_test(tc, s21_from_decimal_to_intTest2);
  tcase_add_test(tc, s21_from_decimal_to_intTest3);
  tcase_add_test(tc, s21_from_decimal_to_intTest4);
  tcase_add_test(tc, s21_from_decimal_to_intTest5);
  tcase_add_test(tc, s21_from_decimal_to_intTest6);
  tcase_add_test(tc, s21_from_decimal_to_intTest7);
  tcase_add_test(tc, s21_from_decimal_to_intTest8);
  tcase_add_test(tc, s21_from_decimal_to_intTest9);
  tcase_add_test(tc, s21_from_decimal_to_intTest10);
  tcase_add_test(tc, s21_from_decimal_to_intTest11);
  tcase_add_test(tc, s21_from_decimal_to_intTest12);
  tcase_add_test(tc, s21_from_decimal_to_intTest13);
  tcase_add_test(tc, s21_from_decimal_to_intTest14);
  tcase_add_test(tc, s21_from_decimal_to_intTest15);

  suite_add_tcase(s, tc);
  return s;
}
