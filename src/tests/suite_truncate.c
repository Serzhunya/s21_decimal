#include "tests_suitcases.h"

START_TEST(s21_trun_1) {
  s21_decimal dec1;
                //31
  dec1.bits[0] = 0b10000000000000000000000000010001; 
  dec1.bits[1] = 0b00000000000000000000000000000000; // 214748366.5
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000001110000000000000000;
                //        |        <   <-9876543210  
  // float num = 0.0;
  // s21_from_decimal_to_float(dec1, &num);
  // printf("\n");
  // printf("печатаем цель из теста = %f\n", num);
  // s21_decimal result;
  // result.bits[0] = 0b10000011000100100110111010010111; // 18 446 744 073 709 551 , 617 
  // result.bits[1] = 0b10001101010011111101111000000000; 
  // result.bits[2] = 0b00000000000000000000000000000000;
  // result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  // ck_assert_int_eq(res1.bits[0], result.bits[0]);
  // ck_assert_int_eq(res1.bits[1], result.bits[1]);
  // ck_assert_int_eq(res1.bits[2], result.bits[2]);
  // ck_assert_int_eq(res1.bits[3], result.bits[3]);

  // print_2(&dec1);
  printf("\n");
  printf("res1\n");// 214748366.5
  print_2(&res1);  // 2362232014

}
END_TEST





// START_TEST(s21_trun_2) {
//   s21_decimal dec1; //
//   dec1.bits[0] = 0b00000000000000000000000010100101;
//   dec1.bits[1] = 0b00000000000000000000000000000000;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b00000000000000010000000000000000;
//   float num = 0.0;
//   s21_from_decimal_to_float(dec1, &num);
//   printf("\n");
//   printf("%f\n", num);
//   s21_decimal result;
//   result.bits[0] = 0b00000000000000000000000000010000;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal res1;
//   s21_truncate(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

Suite *suite_truncate(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_truncate");
  tc = tcase_create("case_truncate");
  tcase_add_test(tc, s21_trun_1);
  // tcase_add_test(tc, s21_trun_2);
  suite_add_tcase(s, tc);
  return s;
}
