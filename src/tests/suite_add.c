#include "tests_suitcases.h"

START_TEST(add_test_1) {
  int num1 = 42;
  int num2 = 30;
  int sum_int = 72;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
  ck_assert_int_eq(s21_add(a, b, &res_dec), 0);
}
END_TEST

START_TEST(add_test_2) {
  int num1 = 1000;
  int num2 = 2000;
  int sum_int = 3000;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_3) {
  int num1 = 0;
  int num2 = 0;
  int sum_int = 0;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_4) {
  int num1 = -15;
  int num2 = 5;
  int sum_int = -10;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_5) {
  int num1 = 11115;
  int num2 = 5;
  int sum_int = 11120;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_6) {
  int num1 = -1;
  int num2 = -10;
  int sum_int = -11;
  s21_decimal a, b;
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, sum_int);
}
END_TEST

START_TEST(add_test_7) {
  s21_decimal src1, src2;
  int a = -1234;
  int b = 234;
  int res_origin = -1000;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_8) {
  s21_decimal src1, src2;
  int a = -9403;
  int b = 234;
  int res_origin = -9169;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_9) {
  s21_decimal src1, src2;
  int a = 9403;
  int b = 202;
  int res_origin = 9605;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_10) {
  s21_decimal src1, src2;
  int a = 450;
  int b = -50;
  int res_origin = 400;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(add_test_11) {
  s21_decimal src1, src2;
  float num1 = 7.25;
  float num2 = 9.5;
  float res_origin = 16.75;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_12) {
  s21_decimal src1, src2;
  int num1 = -1234;
  float num2 = 1.234;
  float res_origin = -1232.766;
  s21_from_int_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_13) {
  s21_decimal src1, src2;
  int num1 = -1234;
  float num2 = -1.234;
  float res_origin = -1235.234;
  s21_from_int_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_14) {
  s21_decimal src1, src2;
  float num1 = -94;
  float num2 = 0.00234;
  float res_origin = num1 + num2;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_15) {
  s21_decimal src1, src2;
  float num1 = -940.3;
  float num2 = 0.000234;
  float res_origin = -940.299766;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_16) {
  s21_decimal src1, src2;
  float num1 = -0.9403;
  float num2 = 0.000234;
  float res_origin = -0.940066;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_17) {
  s21_decimal src1, src2;
  float num1 = -0.9403;
  float num2 = 2.0234;
  float res_origin = num1 + num2;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_18) {
  s21_decimal src1, src2;
  float num1 = -0.9403;
  float num2 = -112.0234;
  float res_origin = -112.9637;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_19) {
  s21_decimal src1, src2;
  float num1 = -0.94e03;
  float num2 = -112.0234;
  float res_origin = -1052.0234;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(add_test_20) {
  s21_decimal src1, src2;
  float num1 = -0.94e03;
  float num2 = -112.0e2;
  float res_origin = -12140;
  s21_from_float_to_decimal(num1, &src1);
  s21_from_float_to_decimal(num2, &src2);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_add(src1, src2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(s21_add_int_21) {
  s21_decimal dec1, dec2;
  int tmp1 = 100;
  int tmp2 = 99999;
  int res_s21 = 0;
  int res = 100099;
  s21_decimal res1;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_add(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_add_int_22) {
  s21_decimal dec1, dec2;
  int tmp1 = -100;
  int tmp2 = -99999;
  int res_s21 = 0;
  int res = -100099;
  s21_decimal res1;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_add(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_add_int_23) {
  s21_decimal dec1, dec2;
  int tmp1 = 2147483647;
  int tmp2 = -2147483647;
  int res_s21 = 0;
  int res = 0;
  s21_decimal res1;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_add(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_add_int_24) {
  s21_decimal dec1, dec2;
  dec1.bits[3] = 0x300000;
  dec1.bits[2] = 0;
  dec1.bits[1] = 0xF;
  dec1.bits[0] = 0x67E4FEEF;
  dec2.bits[3] = 0x300000;
  dec2.bits[2] = 0;
  dec2.bits[1] = 0xFF;
  dec2.bits[0] = 0x67E4FFFF;
  s21_decimal res;
  res.bits[3] = 0x300000;
  res.bits[2] = 0;
  res.bits[1] = 0x10E;
  res.bits[0] = 0xCFC9FEEE;
  s21_decimal res1;
  s21_add(dec1, dec2, &res1);
  ck_assert_int_eq(res.bits[3], res1.bits[3]);
  ck_assert_int_eq(res.bits[2], res1.bits[2]);
  ck_assert_int_eq(res.bits[1], res1.bits[1]);
  ck_assert_int_eq(res.bits[0], res1.bits[0]);
}
END_TEST

START_TEST(s21_add_int_25) {
  s21_decimal dec1, dec2;
  int tmp1 = -2147483647;
  int tmp2 = 2147483647;
  int res_s21 = 0;
  int res = 0;
  s21_decimal res1;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_add(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_add_inf_26) {
  int tmp1 = 4294967295;
  s21_decimal dec1 = {{tmp1, tmp1, tmp1, 0}};
  s21_decimal dec2 = {{1, 0, 0, 0}};
  s21_decimal res1;
  int ret_s21 = s21_add(dec1, dec2, &res1);
  ck_assert_int_eq(1, ret_s21);
}
END_TEST

START_TEST(s21_add_neg_inf_27) {
  int tmp1 = 4294967295;
  float tmp2 = pow(2, 31);
  s21_decimal dec1 = {{tmp1, tmp1, tmp1, tmp2}};
  s21_decimal dec2 = {{1, 0, 0, tmp2}};
  s21_decimal res1;
  int ret_s21 = s21_add(dec1, dec2, &res1);
  ck_assert_int_eq(2, ret_s21);
}
END_TEST

START_TEST(target_float) {
  float float_a = -10758.218750;
  float float_b = 6268.843750;

  float float_res = float_a + float_b;

  s21_decimal expected = {0};
  s21_from_float_to_decimal(float_res, &expected);

  s21_decimal dec_a = {0};
  s21_from_float_to_decimal(float_a, &dec_a);
  s21_decimal dec_b = {0};
  s21_from_float_to_decimal(float_b, &dec_b);

  s21_decimal result = {0};
  int code = s21_add(dec_a, dec_b, &result);

  float got_float = 0;
  s21_from_decimal_to_float(result, &got_float);

  ck_assert_int_eq(code, 0);
  ck_assert_float_eq_tol(got_float, float_res, 1e-06);
}


START_TEST(add_test_too_big) {
  s21_decimal src1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};
  s21_decimal src2= {0};
  float a = 0.01448;
  s21_from_float_to_decimal(a, &src2);
  s21_decimal res_dec = {0};
  s21_add(src1, src2, &res_dec);
  ck_assert_int_eq(s21_add(src1, src2, &res_dec), 1);
}
END_TEST


START_TEST(add_test_too_small) {
  s21_decimal src1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(INT_MAX)}};
  s21_decimal src2 = {0};
  float a = 0.01448;
  s21_from_float_to_decimal(a, &src2);
  s21_decimal res_dec = {0};
  s21_add(src1, src2, &res_dec);
  ck_assert_int_eq(s21_add(src1, src2, &res_dec), 2);
}
END_TEST

START_TEST(add_0) {
    s21_decimal val1 = {{15, 0, 0, ~(S21_MAX_UINT / 2)}};
    s21_decimal val2 = {{2, 0, 0, 0}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_1) {
    s21_decimal val1 = {{15, 0, 0, 0}};
    s21_decimal val2 = {{15, 0, 0, ~(S21_MAX_UINT / 2)}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_2) {
    s21_decimal val1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};
    s21_decimal val2 = {{1, 0, 0, 0}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(1, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_3) {
    s21_decimal val1 = {
        {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(S21_MAX_UINT / 2)}};
    s21_decimal val2 = {{2, 0, 0, ~(S21_MAX_UINT / 2)}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(2, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_4) {
    s21_decimal val1 = {{8, 0, 0, 0}};
    s21_decimal val2 = {{2, 0, 0, 0}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_5) {
    s21_decimal val1 = {{2, 0, 0, 0}};
    s21_decimal val2 = {{8, 0, 0, 0}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_6) {
    s21_decimal val1 = {{8, 0, 0, ~(S21_MAX_UINT / 2)}};
    s21_decimal val2 = {{2, 0, 0, 0}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_7) {
    s21_decimal val1 = {{2, 0, 0, ~(S21_MAX_UINT / 2)}};
    s21_decimal val2 = {{8, 0, 0, 0}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_8) {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_9) {
    s21_decimal val1 = {{4, 0, 0, 0}};
    s21_decimal val2 = {{8, 0, 0, ~(S21_MAX_UINT / 2)}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_10) {
    s21_decimal val1 = {{8, 0, 0, ~(S21_MAX_UINT / 2)}};
    s21_decimal val2 = {{0}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_11) {
    s21_decimal val1 = {
        {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(S21_MAX_UINT / 2)}};
    s21_decimal val2 = {{4, 0, 0, 0}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_12) {
    s21_decimal val1 = {
        {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(S21_MAX_UINT / 2)}};
    s21_decimal val2 = {{4, 0, 0, ~(S21_MAX_UINT / 2)}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(2, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_13) {
    s21_decimal val1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};
    s21_decimal val2 = {{4, 0, 0, ~(S21_MAX_UINT / 2)}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_14) {
    s21_decimal val1 = {{4, 0, 0, 0}};
    s21_decimal val2 = {
        {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(S21_MAX_UINT / 2)}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_15) {
    s21_decimal val1 = {{4, 0, 0, ~(S21_MAX_UINT / 2)}};
    s21_decimal val2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_16) {
    s21_decimal val1 = {{4, 0, 0, ~(S21_MAX_UINT / 2)}};
    s21_decimal val2 = {
        {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(S21_MAX_UINT / 2)}};
    s21_decimal res = {{0}};
    ck_assert_int_eq(2, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_17) {
    s21_decimal val1 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};
    s21_decimal val2 = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};
    set_scale(&val1, 5);
    set_scale(&val2, 3);
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_18) {
    s21_decimal val1 = {
        {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(S21_MAX_UINT / 2)}};
    s21_decimal val2 = {
        {S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, ~(S21_MAX_UINT / 2)}};
    set_scale(&val1, 5);
    set_scale(&val2, 3);
    s21_decimal res = {{0}};
    ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(s21_test_decimal_add_0) {
    s21_decimal c = {5, 0, 0, 0};
    s21_decimal d = {5, 0, 0, 0};
    s21_decimal etalon = {10, 0, 0, 0};
    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;
    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(add, 0);
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_1) {
    s21_decimal c = {100, 0, 0, 0};
    s21_decimal d = {100, 0, 0, 0};
    s21_decimal etalon = {100, 0, 0, 0};
    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;
    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    // Возвращаемое значение: 0 - FALSE 1 - TRUE
    int equal = s21_is_equal(res, etalon);
    ck_assert_int_eq(add, 0);
    ck_assert_int_eq(equal, S21_FALSE);
}
END_TEST

START_TEST(s21_test_decimal_add_2) {
    s21_decimal c = {2147483647, 0, 0, 0};
    s21_decimal d = {2147483647, 0, 0, 0};
    s21_decimal etalon = {4294967294, 0, 0, 0};
    s21_decimal result = {0, 0, 0, 0};
    s21_decimal* p_result = &result;
    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_result);
    ck_assert_int_eq(add, 0);
    // Возвращаемое значение: 0 - FALSE 1 - TRUE
    int equal = s21_is_equal(result, etalon);
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_3) {
    s21_decimal c = {1000, 0, 0, 0};
    s21_decimal d = {1000, 0, 0, 0};
    s21_decimal etalon = {2000, 0, 0, 0};
    s21_decimal result = {0, 0, 0, 0};
    s21_decimal* p_result = &result;
    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_result);
    ck_assert_int_eq(add, 0);
    // Возвращаемое значение: 0 - FALSE 1 - TRUE
    int equal = s21_is_equal(result, etalon);
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_4) {
    s21_decimal c = {1000, 0, 0, ~(INT_MAX)};
    s21_decimal d = {1000, 0, 0, 0};
    s21_decimal etalon = {0, 0, 0, 0};
    s21_decimal result = {0, 0, 0, 0};
    s21_decimal* p_result = &result;
    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_result);
    ck_assert_int_eq(add, 0);
    // Возвращаемое значение: 0 - FALSE 1 - TRUE
    int equal = s21_is_equal(result, etalon);
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_5) {
    s21_decimal c = {1, 0, 0, ~(INT_MAX)};
    s21_decimal d = {1, 0, 0, ~(INT_MAX)};
    s21_decimal etalon = {2, 0, 0, 0};
    s21_decimal result = {0, 0, 0, 0};
    s21_decimal* p_result = &result;
    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_result);
    ck_assert_int_eq(add, 0);
    // Возвращаемое значение: 0 - FALSE 1 - TRUE
    int equal = s21_is_equal(result, etalon);
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST


START_TEST(s21_test_decimal_add_6) {
    s21_decimal c = {0, 0, 0, 0};
    s21_decimal d = {0, 0, 0, 0};
    s21_decimal etalon = {0, 0, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_7) {
    s21_decimal c = {1, 0, 0, 0};
    s21_decimal d = {1, 0, 0, 0};
    s21_decimal etalon = {2, 0, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_8) {
    s21_decimal c = {1000, 0, 0, 0};
    s21_decimal d = {1000, 0, 0, 0};
    s21_decimal etalon = {2000, 0, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_8_1) {
    s21_decimal c = {INT_MAX, 0, 0, 0};
    s21_decimal d = {INT_MAX, 0, 0, 0};
    s21_decimal etalon = {4294967294, 0, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_9) {
    s21_decimal c = {INT_MAX, 0, 0, 0};
    s21_decimal d = {INT_MAX, 0, 0, 0};
    s21_decimal etalon = {UINT32_MAX - 1, 0, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_10) {
    s21_decimal c = {UINT32_MAX, 0, 0, 0};
    s21_decimal d = {1, 0, 0, 0};
    s21_decimal etalon = {0, 1, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[3], etalon.bits[3]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[0], etalon.bits[0]);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_11) {
    s21_decimal c = {0, S21_MAX_UINT - 1, 0, 0};
    s21_decimal d = {0, 1, 0, 0};
    s21_decimal etalon = {0, S21_MAX_UINT, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_12) {
    s21_decimal c = {0, 0, S21_MAX_UINT - 1, 0};
    s21_decimal d = {0, 0, 1, 0};
    s21_decimal etalon = {0, 0, S21_MAX_UINT, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_13) {
    s21_decimal c = {0, 0, 0, ~(INT_MAX)};
    s21_decimal d = {0, 0, 0, ~(INT_MAX)};
    s21_decimal etalon = {0, 0, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_14) {
    s21_decimal c = {1, 0, 0, ~(INT_MAX)};
    s21_decimal d = {1, 0, 0, 0};
    s21_decimal etalon = {0, 0, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_15) {  // -1 + (-1) = -2
    s21_decimal c = {1, 0, 0, ~(INT_MAX)};
    s21_decimal d = {1, 0, 0, ~(INT_MAX)};
    s21_decimal etalon = {2, 0, 0, ~(INT_MAX)};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[3], etalon.bits[3]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[0], etalon.bits[0]);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_16) {
    s21_decimal c = {11, 0, 0, EXPONENT_PLUS_1};
    s21_decimal d = {0, 0, 0, 0};
    s21_decimal etalon = {11, 0, 0, EXPONENT_PLUS_1};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_17) {
    s21_decimal c = {11, 0, 0, EXPONENT_PLUS_1};
    s21_decimal d = {1, 0, 0, 0};
    s21_decimal etalon = {21, 0, 0, EXPONENT_PLUS_1};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_18) {
    s21_decimal c = {111, 0, 0, EXPONENT_PLUS_1};
    s21_decimal d = {1, 0, 0, 0};
    s21_decimal etalon = {211, 0, 0, EXPONENT_PLUS_1};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_19) {
    s21_decimal c = {111, 0, 0, EXPONENT_PLUS_2};
    s21_decimal d = {1, 0, 0, 0};
    s21_decimal etalon = {121, 0, 0, EXPONENT_PLUS_2};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_20) {
    s21_decimal c = {UINT32_MAX, 0, 0, 0};
    s21_decimal d = {1, 0, 0, 0};
    s21_decimal etalon = {UINT32_MAX, 1, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_21) {
    s21_decimal c = {UINT32_MAX, UINT32_MAX, 0, 0};
    s21_decimal d = {1, 0, 0, 0};
    s21_decimal etalon = {UINT32_MAX, UINT32_MAX, 1, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_22) {
    s21_decimal c = {UINT32_MAX, UINT32_MAX, 0, 0};
    s21_decimal d = {UINT32_MAX, 0, 0, 0};
    s21_decimal etalon = {UINT32_MAX, UINT32_MAX, UINT32_MAX, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_23) {
    s21_decimal c = {1, 0, 0, 0};
    s21_decimal d = {UINT32_MAX, 0, 0, 0};
    s21_decimal etalon = {UINT32_MAX + 1, 0, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_24) {
    s21_decimal c = {1, 0, 0, 0};
    s21_decimal d = {UINT32_MAX, UINT32_MAX, 0, 0};
    s21_decimal etalon = {UINT32_MAX, UINT32_MAX, 1, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST


START_TEST(s21_test_decimal_add_25) {
    s21_decimal c = {0b00000000000000000001100101111001, 0, 0, 0};
    s21_decimal d = {0b00000000000000010010000110001001, 0, 0, 0};
    s21_decimal etalon = {0b00000000000000010011101100000010, 0, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_26) {
    s21_decimal c = {0b10001001111001111111111111111111, 0b10001010110001110010001100000100, 0, 0};
    s21_decimal d = {0b00000000000000000000000000000001, 0, 0, 0};
    s21_decimal etalon = {0b10001001111010000000000000000000, 0b10001010110001110010001100000100, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_27) {
    s21_decimal c = {S21_MAX_UINT, S21_MAX_UINT, 0, 0};
    s21_decimal d = {0b00000000000000000000000000000001, 0, 0, 0};
    s21_decimal etalon = {0, 0, 1, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_28) {
    s21_decimal c = {0b10000010111000100101101011101101,
                     0b11111001111010000010010110101101,
                     0b10110000001111101111000010010100,
                     0b10000000000011100000000000000000};
    s21_decimal d = {0b00000011010000001001011100101110, 0, 0, 0};
    s21_decimal etalon = {0b01110001001010101101101011101101,
                          0b00101110001111001110000111111000,
                          0b10110000001111101110111101101101,
                          0b10000000000011100000000000000000};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_29) {
    s21_decimal c = {0b10000010111000100101101011101101,
                     0b11111001111010000010010110101101,
                     0b10110000001111101111000010010100,
                     0b10000000000011100000000000000000};
    s21_decimal d = {0b01001000000110110001111110011000,
                     0b11111011111111011000100101101101,
                     0b00000000000001000110110101110111,
                     0b10000000000110000000000000000000};
    s21_decimal etalon = {0b10110110001010011011010111011010,
                          0b11111001111010100000110001111111,
                          0b10110000001111101111000010010100,
                          0b10000000000011100000000000000000};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);

}
END_TEST

START_TEST(s21_test_decimal_add_30) {
    s21_decimal src1, src2, origin;
    src1.bits[0] = 0b01001110111001000011100101110110;
    src1.bits[1] = 0b01001011001101011010000111011001;
    src1.bits[2] = 0b00011001101110010111010010111111;
    src1.bits[3] = 0b00000000000011110000000000000000;
    src2.bits[0] = 0b00000000000000000000000000000000;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    origin.bits[0] = 0b01001110111001000011100101110110;
    origin.bits[1] = 0b01001011001101011010000111011001;
    origin.bits[2] = 0b00011001101110010111010010111111;
    origin.bits[3] = 0b00000000000011110000000000000000;

    s21_decimal result = {0, 0, 0, 0};
    s21_decimal* p_res = &result;



    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(src1, src2, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(origin.bits[0], result.bits[0]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);

    int equal = s21_is_equal(result, origin);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
    

}
END_TEST

START_TEST(s21_test_decimal_add_31) {
    s21_decimal src1, src2, origin;
    src1.bits[0] = 0b10010001000010101111010011001010;
    src1.bits[1] = 0b11000000010001011101010111110010;
    src1.bits[2] = 0b00100111111001000001101100000000;
    src1.bits[3] = 0b10000000000101010000000000000000;
    src2.bits[0] = 0b00010001110011011101000110000101;
    src2.bits[1] = 0b11110101101111000110111111000000;
    src2.bits[2] = 0b00000010110101010000111100111111;
    src2.bits[3] = 0b00000000000100000000000000000000;
    origin.bits[0] = 0b10010010000001100111100010100101;
    origin.bits[1] = 0b10001011011010100100100011011111;
    origin.bits[2] = 0b00011100010100011001001100010001;
    origin.bits[3] = 0b00000000000100010000000000000000;

    s21_decimal result = {0, 0, 0, 0};
    s21_decimal* p_res = &result;



    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(src1, src2, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(origin.bits[0], result.bits[0]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);

    int equal = s21_is_equal(result, origin);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);


}
END_TEST

START_TEST(s21_test_decimal_add_32) {
    s21_decimal src1, src2, origin;
    src1.bits[0] = 0b10010001000010101111010011001010;
    src1.bits[1] = 0b11000000010001011101010111110010;
    src1.bits[2] = 0b00100111111001000001101100000000;
    src1.bits[3] = 0b00000000000101010000000000000000;
    src2.bits[0] = 0b00010001110011011101000110000101;
    src2.bits[1] = 0b11110101101111000110111111000000;
    src2.bits[2] = 0b00000010110101010000111100111111;
    src2.bits[3] = 0b10000000000100000000000000000000;
    origin.bits[0] = 0b10010010000001100111100010100101;
    origin.bits[1] = 0b10001011011010100100100011011111;
    origin.bits[2] = 0b00011100010100011001001100010001;
    origin.bits[3] = 0b10000000000100010000000000000000;

    s21_decimal result = {0, 0, 0, 0};
    s21_decimal* p_res = &result;



    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(src1, src2, p_res);
    ck_assert_int_eq(add, 0);


    int equal = s21_is_equal(result, origin);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);

}
END_TEST

START_TEST(s21_test_decimal_add_33) {
    s21_decimal src1, src2, origin;
    src1.bits[0] = 0b10010001000010101111010011001010;
    src1.bits[1] = 0b11000000010001011101010111110010;
    src1.bits[2] = 0b00100111111001000001101100000000;
    src1.bits[3] = 0b10000000000101010000000000000000;
    src2.bits[0] = 0b00010001110011011101000110000101;
    src2.bits[1] = 0b11110101101111000110111111000000;
    src2.bits[2] = 0b00000010110101010000111100111111;
    src2.bits[3] = 0b10000000000100000000000000000000;
    origin.bits[0] = 0b11010010000011011110010110111111;
    origin.bits[1] = 0b10100111010011100111001000100001;
    origin.bits[2] = 0b00011100010100111001110111101101;
    origin.bits[3] = 0b10000000000100010000000000000000;

    s21_decimal result = {0, 0, 0, 0};
    s21_decimal* p_res = &result;



    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_add(src1, src2, p_res);
    ck_assert_int_eq(add, 0);
    
    ck_assert_int_eq(origin.bits[0], result.bits[0]);
    ck_assert_int_eq(origin.bits[1], result.bits[1]);
    ck_assert_int_eq(origin.bits[2], result.bits[2]);
    ck_assert_int_eq(origin.bits[3], result.bits[3]);

    int equal = s21_is_equal(result, origin);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);

}
END_TEST

START_TEST(s21_test_decimal_add_simple_0) {
    s21_decimal c = {0, 0, 0, 0};
    s21_decimal d = {0, 0, 0, 0};
    s21_decimal etalon = {0, 0, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_1) {
    s21_decimal c = {1, 0, 0, 0};
    s21_decimal d = {1, 0, 0, 0};
    s21_decimal etalon = {2, 0, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_2) {
    s21_decimal c = {1000, 0, 0, 0};
    s21_decimal d = {1000, 0, 0, 0};
    s21_decimal etalon = {2000, 0, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_3) {
    s21_decimal c = {INT_MAX, 0, 0, 0};
    s21_decimal d = {INT_MAX, 0, 0, 0};
    s21_decimal etalon = {4294967294, 0, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_4) {
    s21_decimal c = {INT_MAX, 0, 0, 0};
    s21_decimal d = {INT_MAX, 0, 0, 0};
    s21_decimal etalon = {UINT32_MAX - 1, 0, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_5) {
    s21_decimal c = {S21_MAX_UINT, 0, 0, 0};
    s21_decimal d = {1, 0, 0, 0};
    s21_decimal etalon = {0, 1, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[3], etalon.bits[3]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[0], etalon.bits[0]);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_6) {
    s21_decimal c = {0, S21_MAX_UINT - 1, 0, 0};
    s21_decimal d = {0, 1, 0, 0};
    s21_decimal etalon = {0, S21_MAX_UINT, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_7) {
    s21_decimal c = {0, 0, S21_MAX_UINT - 1, 0};
    s21_decimal d = {0, 0, 1, 0};
    s21_decimal etalon = {0, 0, S21_MAX_UINT, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_8) {
    s21_decimal c = {0, 0, 0, ~(INT_MAX)};
    s21_decimal d = {0, 0, 0, ~(INT_MAX)};
    s21_decimal etalon = {0, 0, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_9) {
    s21_decimal c = {1, 0, 0, ~(INT_MAX)};
    s21_decimal d = {1, 0, 0, 0};
    s21_decimal etalon = {0, 0, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_10) {  // -1 + (-1) = -2
    s21_decimal c = {1, 0, 0, ~(INT_MAX)};
    s21_decimal d = {1, 0, 0, ~(INT_MAX)};
    s21_decimal etalon = {2, 0, 0, ~(INT_MAX)};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_11) {
    s21_decimal c = {11, 0, 0, EXPONENT_PLUS_1};
    s21_decimal d = {0, 0, 0, 0};
    s21_decimal etalon = {11, 0, 0, EXPONENT_PLUS_1};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_12) {
    s21_decimal c = {11, 0, 0, EXPONENT_PLUS_1};
    s21_decimal d = {1, 0, 0, 0};
    s21_decimal etalon = {21, 0, 0, EXPONENT_PLUS_1};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_13) {
    s21_decimal c = {111, 0, 0, EXPONENT_PLUS_1};
    s21_decimal d = {1, 0, 0, 0};
    s21_decimal etalon = {211, 0, 0, EXPONENT_PLUS_1};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_14) {
    s21_decimal c = {111, 0, 0, EXPONENT_PLUS_2};
    s21_decimal d = {1, 0, 0, 0};
    s21_decimal etalon = {121, 0, 0, EXPONENT_PLUS_2};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_15) {
    s21_decimal c = {UINT32_MAX, 0, 0, 0};
    s21_decimal d = {1, 0, 0, 0};
    s21_decimal etalon = {UINT32_MAX, 1, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_16) {
    s21_decimal c = {UINT32_MAX, UINT32_MAX, 0, 0};
    s21_decimal d = {1, 0, 0, 0};
    s21_decimal etalon = {UINT32_MAX, UINT32_MAX, 1, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_17) {
    s21_decimal c = {UINT32_MAX, UINT32_MAX, 0, 0};
    s21_decimal d = {UINT32_MAX, 0, 0, 0};
    s21_decimal etalon = {UINT32_MAX, UINT32_MAX, UINT32_MAX, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_18) {
    s21_decimal c = {1, 0, 0, 0};
    s21_decimal d = {UINT32_MAX, 0, 0, 0};
    s21_decimal etalon = {UINT32_MAX+1, 0, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_19) {
    s21_decimal c = {1, 0, 0, 0};
    s21_decimal d = {UINT32_MAX, UINT32_MAX, 0, 0};
    s21_decimal etalon = {UINT32_MAX, UINT32_MAX, 1, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_20) {
    s21_decimal c = {0b00000000000000000001100101111001, 0, 0, 0};
    s21_decimal d = {0b00000000000000010010000110001001, 0, 0, 0};
    s21_decimal etalon = {0b00000000000000010011101100000010, 0, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_21) {
    s21_decimal c = {0b10001001111001111111111111111111, 0b10001010110001110010001100000100, 0, 0};
    s21_decimal d = {0b00000000000000000000000000000001, 0, 0, 0};
    s21_decimal etalon = {0b10001001111010000000000000000000, 0b10001010110001110010001100000100, 0, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_22) {
    s21_decimal c = {S21_MAX_UINT, S21_MAX_UINT, 0, 0};
    s21_decimal d = {0b00000000000000000000000000000001, 0, 0, 0};
    s21_decimal etalon = {0, 0, 1, 0};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(s21_test_decimal_add_simple_23) {
    s21_decimal c = {0b10000010111000100101101011101101, 
                    0b11111001111010000010010110101101, 
                    0b10110000001111101111000010010100, 
                    0b10000000000011100000000000000000};
    s21_decimal d = {0b00000011010000001001011100101110, 0, 0, 0};
    s21_decimal etalon = {0b01110001001010101101101011101101,
                          0b00101110001111001110000111111000,
                          0b10110000001111101110111101101101,
                          0b10000000000011100000000000000000};

    s21_decimal res = {0, 0, 0, 0};
    s21_decimal* p_res = &res;

    ck_assert_int_eq(res.bits[0], etalon.bits[0]);
    ck_assert_int_eq(res.bits[1], etalon.bits[1]);
    ck_assert_int_eq(res.bits[2], etalon.bits[2]);
    ck_assert_int_eq(res.bits[3], etalon.bits[3]);

    // 0 - OK 1 - число слишком велико или равно бесконечности 2 - число слишком мало или равно отрицательной бесконечности 3 - деление на 0
    int add = s21_decimal_add_simple(c, d, p_res);
    ck_assert_int_eq(add, 0);

    int equal = s21_is_equal(res, etalon);  // Возвращаемое значение: 0 - FALSE 1 - TRUE
    ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

Suite *suite_add(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_add");
  tc = tcase_create("case_add");

  tcase_add_test(tc, add_test_1);
  tcase_add_test(tc, add_test_2);
  tcase_add_test(tc, add_test_3);
  tcase_add_test(tc, add_test_4);
  tcase_add_test(tc, add_test_5);
  tcase_add_test(tc, add_test_6);
  tcase_add_test(tc, add_test_7);
  tcase_add_test(tc, add_test_8);
  tcase_add_test(tc, add_test_9);
  tcase_add_test(tc, add_test_10);
  // начинаются тесты с плавающей точкой
  tcase_add_test(tc, add_test_11);
  tcase_add_test(tc, add_test_12);
  tcase_add_test(tc, add_test_13);
  tcase_add_test(tc, add_test_14);
  tcase_add_test(tc, add_test_15);
  tcase_add_test(tc, add_test_16);
  tcase_add_test(tc, add_test_17);
  tcase_add_test(tc, add_test_18);
  tcase_add_test(tc, add_test_19);
  tcase_add_test(tc, add_test_20);
  tcase_add_test(tc, s21_add_int_21);
  tcase_add_test(tc, s21_add_int_22);
  tcase_add_test(tc, s21_add_int_23);
  tcase_add_test(tc, s21_add_int_24);
  tcase_add_test(tc, s21_add_int_25);
  tcase_add_test(tc, s21_add_inf_26);
  tcase_add_test(tc, s21_add_neg_inf_27);
  tcase_add_test(tc, target_float);
  tcase_add_test(tc, add_test_too_big);
  tcase_add_test(tc, add_test_too_small);

  tcase_add_test(tc, s21_test_decimal_add_0);
  tcase_add_test(tc, s21_test_decimal_add_1);
  tcase_add_test(tc, s21_test_decimal_add_2);
  tcase_add_test(tc, s21_test_decimal_add_3);
  tcase_add_test(tc, s21_test_decimal_add_4);
  tcase_add_test(tc, s21_test_decimal_add_5);
  tcase_add_test(tc, s21_test_decimal_add_6);
  tcase_add_test(tc, s21_test_decimal_add_7);
  tcase_add_test(tc, s21_test_decimal_add_8);
  tcase_add_test(tc, s21_test_decimal_add_8_1);
  tcase_add_test(tc, s21_test_decimal_add_9);
  tcase_add_test(tc, s21_test_decimal_add_10);
  tcase_add_test(tc, s21_test_decimal_add_11);
  tcase_add_test(tc, s21_test_decimal_add_12);
  tcase_add_test(tc, s21_test_decimal_add_13);
  tcase_add_test(tc, s21_test_decimal_add_14);
  tcase_add_test(tc, s21_test_decimal_add_15);
  tcase_add_test(tc, s21_test_decimal_add_16);
  tcase_add_test(tc, s21_test_decimal_add_17);
  tcase_add_test(tc, s21_test_decimal_add_18);
  tcase_add_test(tc, s21_test_decimal_add_19);
  tcase_add_test(tc, s21_test_decimal_add_20);
  tcase_add_test(tc, s21_test_decimal_add_21);
  tcase_add_test(tc, s21_test_decimal_add_22);
  tcase_add_test(tc, s21_test_decimal_add_23);
  tcase_add_test(tc, s21_test_decimal_add_25);
  tcase_add_test(tc, s21_test_decimal_add_26);
  tcase_add_test(tc, s21_test_decimal_add_27);
  tcase_add_test(tc, s21_test_decimal_add_28);
  tcase_add_test(tc, s21_test_decimal_add_29);
  tcase_add_test(tc, s21_test_decimal_add_30);
  tcase_add_test(tc, s21_test_decimal_add_31);
  tcase_add_test(tc, s21_test_decimal_add_32);
  tcase_add_test(tc, s21_test_decimal_add_33);

  tcase_add_test(tc, add_0);
  tcase_add_test(tc, add_1);
  tcase_add_test(tc, add_2);  //-
  tcase_add_test(tc, add_3);  //-
  tcase_add_test(tc, add_4);
  tcase_add_test(tc, add_5);
  tcase_add_test(tc, add_6);
  tcase_add_test(tc, add_7);
  tcase_add_test(tc, add_8);
  tcase_add_test(tc, add_9);
  tcase_add_test(tc, add_10);
  tcase_add_test(tc, add_11);
  tcase_add_test(tc, add_12);  //-
  tcase_add_test(tc, add_13);
  tcase_add_test(tc, add_14);
  tcase_add_test(tc, add_15);
  tcase_add_test(tc, add_16);  //-
  tcase_add_test(tc, add_17);
  tcase_add_test(tc, add_18);


  tcase_add_test(tc, s21_test_decimal_add_simple_0);
  tcase_add_test(tc, s21_test_decimal_add_simple_1);
  tcase_add_test(tc, s21_test_decimal_add_simple_2);
  tcase_add_test(tc, s21_test_decimal_add_simple_3);
  tcase_add_test(tc, s21_test_decimal_add_simple_4);
  tcase_add_test(tc, s21_test_decimal_add_simple_5);  //-
  tcase_add_test(tc, s21_test_decimal_add_simple_6);
  tcase_add_test(tc, s21_test_decimal_add_simple_7);
  tcase_add_test(tc, s21_test_decimal_add_simple_8);
  tcase_add_test(tc, s21_test_decimal_add_simple_9);   //-
  tcase_add_test(tc, s21_test_decimal_add_simple_10);  //-
  tcase_add_test(tc, s21_test_decimal_add_simple_11);
  tcase_add_test(tc, s21_test_decimal_add_simple_12);  //-
  tcase_add_test(tc, s21_test_decimal_add_simple_13);  //-
  tcase_add_test(tc, s21_test_decimal_add_simple_14);  //-
  tcase_add_test(tc, s21_test_decimal_add_simple_15);  //-
  tcase_add_test(tc, s21_test_decimal_add_simple_16);  //-
  tcase_add_test(tc, s21_test_decimal_add_simple_17);  //-
  tcase_add_test(tc, s21_test_decimal_add_simple_18);  //-
  tcase_add_test(tc, s21_test_decimal_add_simple_19);  //-
  tcase_add_test(tc, s21_test_decimal_add_simple_20);  //-
  tcase_add_test(tc, s21_test_decimal_add_simple_21);  //-
  tcase_add_test(tc, s21_test_decimal_add_simple_22);  //-
  tcase_add_test(tc, s21_test_decimal_add_simple_23);  //-

  suite_add_tcase(s, tc);
  return s;
}
