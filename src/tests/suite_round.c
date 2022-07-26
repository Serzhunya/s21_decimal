#include "tests_suitcases.h"

START_TEST(s21_round_1) {
  s21_decimal dec1;
  dec1.bits[0] = 0b10010011111100000001110001010010;
  dec1.bits[1] = 0b00000000000000000000000100100000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000010100000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000001111100;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_2) {
  s21_decimal dec1;
  dec1.bits[0] = 0b00000000000000000000000010100101;  // -16.5
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b10000000000000010000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000000010001;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_3) {
  s21_decimal dec1;
  dec1.bits[0] = 0b11111111111111111111111111111111;  // 18014398509481.983
  dec1.bits[1] = 0b00000000001111111111111111111111;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000110000000000000000;
  s21_decimal result;

  result.bits[0] = 0b01001101110100101111000110101001;  // 18014398509481
  result.bits[1] = 0b00000000000000000001000001100010;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_4) {
  s21_decimal dec1;
  dec1.bits[0] = 0b00000000000011110111001001110100;  // -10123.40
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b10000000000000110000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000001111110100;  // -1012
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_5) {
  s21_decimal dec1;
  dec1.bits[0] = 0b10000000000000000000001111110100;  // 112590205.4327284
  dec1.bits[1] = 0b00000000000001000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b10000000000001110000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00000110101101011111110101111101;  // 112590205
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_6) {
  s21_decimal dec1;
  dec1.bits[0] = 0b10000000000000000000001111110100;  // 2147484660
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result;
  result.bits[0] = 0b10000000000000000000001111110100;  // 2147484660
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_7) {
  s21_decimal dec1;

  dec1.bits[0] = 0b01100011000011111111111111111111;
  dec1.bits[1] = 0b01101011110001110101111000101101;
  dec1.bits[2] = 0b00000000000000000000000000000101;
  dec1.bits[3] = 0b10000000000010100000000000000000;
  s21_decimal result;
  result.bits[0] = 0b01010100000010111110010000000000;
  result.bits[1] = 0b00000000000000000000000000000010;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_8) {
  s21_decimal dec1;

  dec1.bits[0] = 0b01010101001110101110101110110001;
  dec1.bits[1] = 0b00001101101101001101101001011111;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b10000000000100100000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000000000001;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_9) {
  s21_decimal dec1;

  dec1.bits[0] = 0b10010011111100000001110001010010;
  dec1.bits[1] = 0b00000000000000000000000100100000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000010100000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000001111100;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_10) {
  s21_decimal dec1;

  dec1.bits[0] = 0b11001101110001110111110001000000;
  dec1.bits[1] = 0b00111110001001010000001001100000;
  dec1.bits[2] = 0b00100000010011111100111001011110;
  dec1.bits[3] = 0b10000000000001000000000000000000;
  s21_decimal result;
  result.bits[0] = 0b10100000111111100100111000000100;
  result.bits[1] = 0b00011011110011101100110011101101;
  result.bits[2] = 0b00000000000000001101001111000010;
  result.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_11) {
  s21_decimal dec1;

  dec1.bits[0] = 0b10100000111111100100111000000100;
  dec1.bits[1] = 0b00011011110011101100110011101101;
  dec1.bits[2] = 0b00000000000000001101001111000010;
  dec1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  s21_decimal result;
  result.bits[0] = 0b10100000111111100100111000000100;
  result.bits[1] = 0b00011011110011101100110011101101;
  result.bits[2] = 0b00000000000000001101001111000010;
  result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_12) {
  s21_decimal dec1;

  dec1.bits[0] = 0b10010111011100111001111111111111;
  dec1.bits[1] = 0b00111100000010000011000110001101;
  dec1.bits[2] = 0b00000000000000000000000000000001;
  dec1.bits[3] = 0b00000000000001110000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  s21_decimal result;
  result.bits[0] = 0b00110110101101101000110001000000;
  result.bits[1] = 0b00000000000000000000001000010010;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_13) {
  s21_decimal dec1;

  dec1.bits[0] = 0b10010111011100111001111111111111;
  dec1.bits[1] = 0b00111100000010000011000110001101;
  dec1.bits[2] = 0b00000000000000000000000000000001;
  dec1.bits[3] = 0b10000000000001110000000000000000;
  s21_decimal res1;
  s21_round(dec1, &res1);
  s21_decimal result;
  result.bits[0] = 0b00110110101101101000110001000000;
  result.bits[1] = 0b00000000000000000000001000010010;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;

  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

Suite *suite_round(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_round");
  tc = tcase_create("case_round");
  tcase_add_test(tc, s21_round_1);
  tcase_add_test(tc, s21_round_2);
  tcase_add_test(tc, s21_round_3);
<<<<<<< HEAD
=======
  tcase_add_test(tc, s21_round_4);
  tcase_add_test(tc, s21_round_5);
  tcase_add_test(tc, s21_round_6);
  tcase_add_test(tc, s21_round_7);
  tcase_add_test(tc, s21_round_8);
  tcase_add_test(tc, s21_round_9);
  tcase_add_test(tc, s21_round_10);
  tcase_add_test(tc, s21_round_11);
  tcase_add_test(tc, s21_round_12);
  tcase_add_test(tc, s21_round_13);
>>>>>>> 6ce18e6cfdb8318e109b4f8ce36351a8fe85ca3d
  suite_add_tcase(s, tc);
  return s;
}
