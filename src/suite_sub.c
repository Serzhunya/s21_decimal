#include "tests_suitcases.h"

START_TEST(sub_test_1) {
  int num1 = -10;
  int num2 = -10;
  int dif_int = 0;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_2) {
  int num1 = 10;
  int num2 = 20;
  int dif_int = -10;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_3) {
  int num1 = -10;
  int num2 = 20;
  int dif_int = -30;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_4) {
  int num1 = 9403;
  int num2 = 202;
  int dif_int = 9201;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_5) {
  int num1 = 100;
  int num2 = -200;
  int dif_int = 300;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_6) {
  int num1 = 100;
  int num2 = -10;
  int dif_int = 110;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_7) {
  int num1 = -900;
  int num2 = -100;
  int dif_int = -800;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_8) {
  int num1 = 900;
  int num2 = 100;
  int dif_int = 800;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_9) {
  int num1 = 900;
  int num2 = -100;
  int dif_int = 1000;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_10) {
  int num1 = -900;
  int num2 = 100;
  int dif_int = -1000;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, dif_int);
}
END_TEST

START_TEST(sub_test_11) {
  int num1 = 123;
  float num2 = 12.5;
  float dif_float = 110.5;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_12) {
  int num1 = -123;
  float num2 = 12.5;
  float dif_float = num1 - num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

// START_TEST(sub_test_13) {
//   float num1 = 12.9;
//   float num2 = 12.5;
//   float original_res = num1 - num2;
//   s21_decimal a = {0};
//   s21_decimal b = {0};
//   s21_from_float_to_decimal(num1, &a);
//   s21_from_float_to_decimal(num2, &b);
//   s21_decimal res_dec = {0};
//   float our_res = 0.0;
//   s21_sub(a, b, &res_dec);
//   s21_from_decimal_to_float(res_dec, &our_res);
//   ck_assert_float_eq(our_res, original_res);
// }
// END_TEST

START_TEST(sub_test_14) {
  int num1 = 9403;
  float num2 = 202.098;
  float dif_float = 9200.902;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_15) {
  int num1 = -9403;
  float num2 = 202.098;
  float dif_float = num1 - num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_16) {
  float num1 = 9403.0;
  float num2 = 202.09e8;
  float dif_float = num1 - num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_17) {
  float num1 = 9403.0e2;
  float num2 = 202.09e8;
  float dif_float = num1 - num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_18) {
  float num1 = -9403.0e2;
  int num2 = -202;
  float dif_float = num1 - num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_19) {
  float num1 = -94;
  float num2 = -202;
  float dif_float = num1 - num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

// START_TEST(sub_test_20) {
//   float num1 = -1.0 / 0.0;
//   int num2 = 202;
//   double dif_float = num1 - num2;
//   s21_decimal a = {0};
//   s21_decimal b = {0};
//   s21_from_float_to_decimal(num1, &a);
//   s21_from_int_to_decimal(num2, &b);
//   s21_decimal res_dec = {0};
//   float res_float = 0.0;
//   s21_sub(a, b, &res_dec);
//   s21_from_decimal_to_float(res_dec, &res_float);
//   ck_assert_float_eq(res_float, dif_float);
// }
// END_TEST

// START_TEST(sub_test_21) {
//   float num1 = 1.0 / 0.0;
//   int num2 = 20;
//   double dif_float = num1 - num2;
//   s21_decimal a = {0};
//   s21_decimal b = {0};
//   s21_from_float_to_decimal(num1, &a);
//   s21_from_int_to_decimal(num2, &b);
//   s21_decimal res_dec = {0};
//   float res_float = 0.0;
//   s21_sub(a, b, &res_dec);
//   s21_from_decimal_to_float(res_dec, &res_float);
//   ck_assert_float_eq(res_float, dif_float);
// }
// END_TEST

// START_TEST(s21_sub_int_22) {
//   s21_decimal dec1;
//   s21_decimal dec2;
//   int tmp1 = 100;
//   int tmp2 = 99999;
//   int res_s21 = 0;
//   int res = -99899;
//   s21_decimal res1;
//   s21_from_int_to_decimal(tmp1, &dec1);
//   s21_from_int_to_decimal(tmp2, &dec2);
//   s21_sub(dec1, dec2, &res1);
//   s21_from_decimal_to_int(res1, &res_s21);
//   ck_assert_int_eq(res_s21, res);
// }
// END_TEST

// START_TEST(s21_sub_int_23) {
//   s21_decimal dec1;
//   s21_decimal dec2;
//   int tmp1 = -100;
//   int tmp2 = -99999;
//   int res_s21 = 0;
//   int res = 99899;
//   s21_decimal res1;
//   s21_from_int_to_decimal(tmp1, &dec1);
//   s21_from_int_to_decimal(tmp2, &dec2);
//   s21_sub(dec1, dec2, &res1);
//   s21_from_decimal_to_int(res1, &res_s21);
//   ck_assert_int_eq(res_s21, res);
// }
// END_TEST

// START_TEST(s21_sub_int_24) {
//   s21_decimal dec1;
//   s21_decimal dec2;
//   int tmp1 = -2147483647;
//   int tmp2 = -2147483647;
//   int res_s21 = 0;
//   int res = 0;
//   s21_from_int_to_decimal(tmp1, &dec1);
//   s21_from_int_to_decimal(tmp2, &dec2);
//   s21_decimal res1;
//   s21_sub(dec1, dec2, &res1);
//   s21_from_decimal_to_int(res1, &res_s21);
//   ck_assert_int_eq(res_s21, res);
// }
// END_TEST

// START_TEST(s21_sub_int_25) {
//   s21_decimal dec1;
//   s21_decimal dec2;
//   int tmp1 = -214748347;
//   int tmp2 = 217483647;
//   int res_s21 = 0;
//   int res = -214748347 - 217483647;
//   s21_from_int_to_decimal(tmp1, &dec1);
//   s21_from_int_to_decimal(tmp2, &dec2);
//   s21_decimal res1;
//   s21_sub(dec1, dec2, &res1);
//   s21_from_decimal_to_int(res1, &res_s21);
//   ck_assert_int_eq(res_s21, res);
// }
// END_TEST

// START_TEST(s21_sub_int_26) {
//   s21_decimal dec1;
//   s21_decimal dec2;
//   int tmp1 = 214748347;
//   int tmp2 = -217483647;
//   int res_s21 = 0;
//   int res = 214748347 - -217483647;
//   s21_from_int_to_decimal(tmp1, &dec1);
//   s21_from_int_to_decimal(tmp2, &dec2);
//   s21_decimal res1;
//   s21_sub(dec1, dec2, &res1);
//   s21_from_decimal_to_int(res1, &res_s21);
//   ck_assert_int_eq(res_s21, res);
// }
// END_TEST

// START_TEST(s21_sub_inf_27) {
//   float tmp = pow(2, 31);
//   s21_decimal dec1 = {{4294967295, 4294967295, 4294967295, 0}};
//   s21_decimal dec2 = {{1, 0, 0, tmp}};
//   s21_decimal res1;
//   int ret_s21 = s21_sub(dec1, dec2, &res1);
//   ck_assert_int_eq(1, ret_s21);
// }
// END_TEST

// START_TEST(s21_sub_neg_inf_28) {
//   float tmp = pow(2, 31);
//   s21_decimal dec1 = {{4294967295, 4294967295, 4294967295, tmp}};
//   s21_decimal dec2 = {{1, 0, 0, 0}};
//   s21_decimal res1;
//   int ret_s21 = s21_sub(dec1, dec2, &res1);
//   ck_assert_int_eq(2, ret_s21);
// }
// END_TEST

// START_TEST(sub_test_29) {
//   float num1 = 79228162514264337593543950335.0;
//   float num2 = 0.6;
//   float dif_float = num1 - num2;
//   s21_decimal a = {0};
//   s21_decimal b = {0};
//   s21_from_float_to_decimal(num1, &a);
//   s21_from_float_to_decimal(num2, &b);
//   s21_decimal res_dec = {0};
//   float res_float = 0.0;
//   s21_sub(a, b, &res_dec);
//   s21_from_decimal_to_float(res_dec, &res_float);
//   ck_assert_float_eq(res_float, dif_float);
// }
// END_TEST

Suite *suite_sub(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_sub");
  tc = tcase_create("case_sub");

  tcase_add_test(tc, sub_test_1);
  tcase_add_test(tc, sub_test_2);
  tcase_add_test(tc, sub_test_3);
  tcase_add_test(tc, sub_test_4);
  tcase_add_test(tc, sub_test_5);
  tcase_add_test(tc, sub_test_6);
  tcase_add_test(tc, sub_test_7);
  tcase_add_test(tc, sub_test_8);
  tcase_add_test(tc, sub_test_9);
  tcase_add_test(tc, sub_test_10);
  tcase_add_test(tc, sub_test_11);
  tcase_add_test(tc, sub_test_12);
  // tcase_add_test(tc, sub_test_13);
  tcase_add_test(tc, sub_test_14);
  tcase_add_test(tc, sub_test_15);
  tcase_add_test(tc, sub_test_16);
  tcase_add_test(tc, sub_test_17);
  tcase_add_test(tc, sub_test_18);
  tcase_add_test(tc, sub_test_19);
  // tcase_add_test(tc, sub_test_20);
  // tcase_add_test(tc, sub_test_21);
  // tcase_add_test(tc, s21_sub_int_22);
  // tcase_add_test(tc, s21_sub_int_23);
  // tcase_add_test(tc, s21_sub_int_24);
  // tcase_add_test(tc, s21_sub_int_25);
  // tcase_add_test(tc, s21_sub_int_26);
  // tcase_add_test(tc, s21_sub_inf_27);
  // tcase_add_test(tc, s21_sub_neg_inf_28);
  // tcase_add_test(tc, sub_test_29);
  suite_add_tcase(s, tc);
  return s;
}
