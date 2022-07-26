#include "tests_suitcases.h"

START_TEST(s21_trun_1) {
  s21_decimal dec1;
  dec1.bits[0] = 0b00000000000000000000000011010011;  // 21.1
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000000010101;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_trun_2) {
  s21_decimal dec1;
  dec1.bits[0] = 0b00000000000000000000000010100101;
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000000010000;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_trun_3) {
  s21_decimal dec1;
  dec1.bits[0] =
      0b11111111111111111111111111111111;  // 7922816251426433759354395033.5
  dec1.bits[1] = 0b11111111111111111111111111111111;
  dec1.bits[2] = 0b11111111111111111111111111111111;
  dec1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal result;
  result.bits[0] = 0b10011001100110011001100110011001;
  result.bits[1] = 0b10011001100110011001100110011001;
  result.bits[2] = 0b00011001100110011001100110011001;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_trun_4) {
  s21_decimal dec1;
  dec1.bits[0] = 0b10000000000000000000000010100101;  // 214.7483813
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000001110000000000000000;
  float num = 0.0;
  s21_from_decimal_to_float(dec1, &num);
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000011010110;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_1) {
  s21_decimal dec1;

  dec1.bits[3] = 0x000A0000;
  dec1.bits[2] = 0x0;
  dec1.bits[1] = 0xFFFFFFFF;
  dec1.bits[0] = 0xFFFFFFFF;
  s21_decimal result;
  result.bits[3] = 0x0;
  result.bits[2] = 0x0;
  result.bits[1] = 0x0;
  result.bits[0] = 0x6DF37F67;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_2) {
  s21_decimal dec1;

  dec1.bits[3] = 0b10000000000011000000000000000000;
  dec1.bits[2] = 0x0;
  dec1.bits[1] = 0xFFFFFFFF;
  dec1.bits[0] = 0xFFFFFFFF;
  s21_decimal result;
  result.bits[3] = 0b10000000000000000000000000000000;
  result.bits[2] = 0x0;
  result.bits[1] = 0x0;
  result.bits[0] = 0x1197998;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_3) {
  s21_decimal dec1;

  dec1.bits[3] = 0x80000000;
  dec1.bits[2] = 0x0;
  dec1.bits[1] = 0xFFFFFFFF;
  dec1.bits[0] = 0xFFFFFFFF;
  s21_decimal result;
  result.bits[3] = 0x80000000;
  result.bits[2] = 0x0;
  result.bits[1] = 0xFFFFFFFF;
  result.bits[0] = 0xFFFFFFFF;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_4) {
  s21_decimal dec1;

  dec1.bits[0] = 0b00000000000000000000000001101101;
  dec1.bits[1] = 0b00000000000011000110010101011011;
  dec1.bits[2] = 0b00000000000000000011000000111001;
  dec1.bits[3] = 0b00000000000011100000000000000000;
  s21_decimal result;
  result.bits[0] = 0b10000111101111000001011000011110;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_5) {
  s21_decimal dec1;

  dec1.bits[0] = 0b11011110101001001000000010110110;
  dec1.bits[1] = 0b01011111101001011101111110100000;
  dec1.bits[2] = 0b00011111111010011010111101100000;
  dec1.bits[3] = 0b00000000000010010000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00110100101011011100000100111110;
  result.bits[1] = 0b10001001000100001000011110111001;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_6) {
  s21_decimal dec1;

  dec1.bits[3] = 0x80090000;
  dec1.bits[2] = 0;
  dec1.bits[1] = 0xFFFFEA34;
  dec1.bits[0] = 0xFF837E4F;
  s21_decimal result;
  s21_truncate(dec1, &result);
  s21_decimal res1;

  res1.bits[3] = 0x80000000;
  res1.bits[2] = 0;
  res1.bits[1] = 0x4;
  res1.bits[0] = 0x4B829C70;
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_truncate_7) {
  s21_decimal dec1;

  dec1.bits[0] = 0b11010000101000110011000001101101;
  dec1.bits[1] = 0b00011111100110100110101101011000;
  dec1.bits[2] = 0;
  dec1.bits[3] = 0b00000000000010010000000000000000;
  s21_decimal result;
  s21_truncate(dec1, &result);
  s21_decimal result_origin;
  result_origin.bits[3] = 0;
  result_origin.bits[2] = 0;
  result_origin.bits[1] = 0;
  result_origin.bits[0] = 0b10000111101111000001011000011110;
  ck_assert_int_eq(result_origin.bits[3], result.bits[3]);
  ck_assert_int_eq(result_origin.bits[2], result.bits[2]);
  ck_assert_int_eq(result_origin.bits[1], result.bits[1]);
  ck_assert_int_eq(result_origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_truncate_8) {
  s21_decimal dec1;

  dec1.bits[0] = 0b01111000101001111011110011000110;
  dec1.bits[1] = 0b10011111111111001111101010000100;
  dec1.bits[2] = 0b00011111111010011010111101101101;
  dec1.bits[3] = 0b00000000000111000000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000000000000;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

Suite *suite_truncate(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_truncate");
  tc = tcase_create("case_truncate");
  tcase_add_test(tc, s21_trun_1);
  tcase_add_test(tc, s21_trun_2);
  tcase_add_test(tc, s21_trun_3);
  tcase_add_test(tc, s21_trun_4);
  tcase_add_test(tc, s21_truncate_1);
  tcase_add_test(tc, s21_truncate_2);
  tcase_add_test(tc, s21_truncate_3);
  tcase_add_test(tc, s21_truncate_4);
  tcase_add_test(tc, s21_truncate_5);
  tcase_add_test(tc, s21_truncate_6);
  tcase_add_test(tc, s21_truncate_7);
  tcase_add_test(tc, s21_truncate_8);
  suite_add_tcase(s, tc);
  return s;
}
