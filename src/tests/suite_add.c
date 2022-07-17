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

// START_TEST(s21_add_int_21) {
//   s21_decimal dec1, dec2;
//   int tmp1 = 100;
//   int tmp2 = 99999;
//   int res_s21 = 0;
//   int res = 100099;
//   s21_decimal res1;
//   s21_from_int_to_decimal(tmp1, &dec1);
//   s21_from_int_to_decimal(tmp2, &dec2);
//   s21_add(dec1, dec2, &res1);
//   s21_from_decimal_to_int(res1, &res_s21);
//   ck_assert_int_eq(res_s21, res);
// }
// END_TEST

// START_TEST(s21_add_int_22) {
//   s21_decimal dec1, dec2;
//   int tmp1 = -100;
//   int tmp2 = -99999;
//   int res_s21 = 0;
//   int res = -100099;
//   s21_decimal res1;
//   s21_from_int_to_decimal(tmp1, &dec1);
//   s21_from_int_to_decimal(tmp2, &dec2);
//   s21_add(dec1, dec2, &res1);
//   s21_from_decimal_to_int(res1, &res_s21);
//   ck_assert_int_eq(res_s21, res);
// }
// END_TEST

// START_TEST(s21_add_int_23) {
//   s21_decimal dec1, dec2;
//   int tmp1 = 2147483647;
//   int tmp2 = -2147483647;
//   int res_s21 = 0;
//   int res = 0;
//   s21_decimal res1;
//   s21_from_int_to_decimal(tmp1, &dec1);
//   s21_from_int_to_decimal(tmp2, &dec2);
//   s21_add(dec1, dec2, &res1);
//   s21_from_decimal_to_int(res1, &res_s21);
//   ck_assert_int_eq(res_s21, res);
// }
// END_TEST

// START_TEST(s21_add_int_24) {
//   s21_decimal dec1, dec2;
//   dec1.bits[3] = 0x300000;
//   dec1.bits[2] = 0;
//   dec1.bits[1] = 0xF;
//   dec1.bits[0] = 0x67E4FEEF;
//   dec2.bits[3] = 0x300000;
//   dec2.bits[2] = 0;
//   dec2.bits[1] = 0xFF;
//   dec2.bits[0] = 0x67E4FFFF;
//   s21_decimal res;
//   res.bits[3] = 0x300000;
//   res.bits[2] = 0;
//   res.bits[1] = 0x10E;
//   res.bits[0] = 0xCFC9FEEE;
//   s21_decimal res1;
//   s21_add(dec1, dec2, &res1);
//   ck_assert_int_eq(res.bits[3], res1.bits[3]);
//   ck_assert_int_eq(res.bits[2], res1.bits[2]);
//   ck_assert_int_eq(res.bits[1], res1.bits[1]);
//   ck_assert_int_eq(res.bits[0], res1.bits[0]);
// }
// END_TEST

// START_TEST(s21_add_int_25) {
//   s21_decimal dec1, dec2;
//   int tmp1 = -2147483647;
//   int tmp2 = 2147483647;
//   int res_s21 = 0;
//   int res = 0;
//   s21_decimal res1;
//   s21_from_int_to_decimal(tmp1, &dec1);
//   s21_from_int_to_decimal(tmp2, &dec2);
//   s21_add(dec1, dec2, &res1);
//   s21_from_decimal_to_int(res1, &res_s21);
//   ck_assert_int_eq(res_s21, res);
// }
// END_TEST

// START_TEST(s21_add_inf_26) {
//   int tmp1 = 4294967295;
//   s21_decimal dec1 = {{tmp1, tmp1, tmp1, 0}};
//   s21_decimal dec2 = {{1, 0, 0, 0}};
//   s21_decimal res1;
//   int ret_s21 = s21_add(dec1, dec2, &res1);
//   ck_assert_int_eq(1, ret_s21);
// }
// END_TEST

// START_TEST(s21_add_neg_inf_27) {
//   int tmp1 = 4294967295;
//   float tmp2 = pow(2, 31);
//   s21_decimal dec1 = {{tmp1, tmp1, tmp1, tmp2}};
//   s21_decimal dec2 = {{1, 0, 0, tmp2}};
//   s21_decimal res1;
//   int ret_s21 = s21_add(dec1, dec2, &res1);
//   ck_assert_int_eq(2, ret_s21);
// }
// END_TEST

// START_TEST(random_negative_float) {
//   float float_a = get_random_float(-85818.51851, 85818.51851);

//   float float_b = get_random_float(-85818.51851, 85818.51851);

//   float float_res = float_a + float_b;
//   // float_a = fabsf(float_a);
//   // float_b = fabsf(float_b);

//   // float_res = fabsf(float_res);

//   s21_decimal expected = {0};
//   s21_from_float_to_decimal(float_res, &expected);

//   s21_decimal dec_a = {0};
//   s21_from_float_to_decimal(float_a, &dec_a);
//   s21_decimal dec_b = {0};
//   s21_from_float_to_decimal(float_b, &dec_b);

//   s21_decimal result = {0};
//   /* NOTE: SOMETIMES CODE IS INFINITY FOR UNKNOWN REASON */
//   int code = s21_add(dec_a, dec_b, &result);
//   float got_float = 0;
//   s21_from_decimal_to_float(result, &got_float);

//   // static int test_n = 0;
//   // printf("\nTEST#%d\n", test_n++);
//   // printf("float_a = %f\n", float_a);
//   // printf("float_b = %f\n", float_b);
//   // printf("float_sum (expected) = %f\n", float_res);
//   // printf("GOT: = %f\n", got_float);

//   ck_assert_int_eq(code, 0);
//   ck_assert_float_eq_tol(got_float, float_res, 1e-6);
// }
// END_TEST

// START_TEST(random_positive_float) {
//   float float_a = get_random_float(0, 85818.51851);

//   float float_b = get_random_float(0, 85818.51851);

//   float_a = fabsf(float_a);
//   float_b = fabsf(float_b);

//   float float_res = float_a + float_b;

//   float_res = fabsf(float_res);

//   s21_decimal expected = {0};
//   s21_from_float_to_decimal(float_res, &expected);

//   s21_decimal dec_a = {0};
//   s21_from_float_to_decimal(float_a, &dec_a);
//   s21_decimal dec_b = {0};
//   s21_from_float_to_decimal(float_b, &dec_b);

//   s21_decimal result = {0};
//   /* NOTE: SOMETIMES CODE IS INFINITY FOR UNKNOWN REASON */
//   int code = s21_add(dec_a, dec_b, &result);

//   float got_float = 0;
//   s21_from_decimal_to_float(result, &got_float);

//   ck_assert_int_eq(code, 0);
//   ck_assert_float_eq_tol(got_float, float_res, 1e-6);
// }

// START_TEST(random_signed_floats) {
//   float float_a = get_random_float(-85818.51851, 85818.51851);

//   float float_b = get_random_float(-85818.51851, 85818.51851);

//   float_a = fabsf(float_a);
//   float_b = fabsf(float_b);

//   float float_res = float_a + float_b;

//   float_res = fabsf(float_res);

//   s21_decimal expected = {0};
//   s21_from_float_to_decimal(float_res, &expected);

//   s21_decimal dec_a = {0};
//   s21_from_float_to_decimal(float_a, &dec_a);
//   s21_decimal dec_b = {0};
//   s21_from_float_to_decimal(float_b, &dec_b);

//   s21_decimal result = {0};
//   /* NOTE: SOMETIMES CODE IS INFINITY FOR UNKNOWN REASON */
//   int code = s21_add(dec_a, dec_b, &result);

//   float got_float = 0;
//   s21_from_decimal_to_float(result, &got_float);
//   ck_assert_int_eq(code, 0);
//   ck_assert_float_eq_tol(got_float, float_res, 1e-6);
// }

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
  // tcase_add_test(tc, s21_add_int_21);
  // tcase_add_test(tc, s21_add_int_22);
  // tcase_add_test(tc, s21_add_int_23);
  // tcase_add_test(tc, s21_add_int_24);
  // tcase_add_test(tc, s21_add_int_25);
  // tcase_add_test(tc, s21_add_inf_26);
  // tcase_add_test(tc, s21_add_neg_inf_27);
  // tcase_add_test(tc, random_negative_float);
  // tcase_add_test(tc, random_positive_float);
  // tcase_add_test(tc, random_signed_floats);
  tcase_add_test(tc, target_float);

  suite_add_tcase(s, tc);
  return s;
}
