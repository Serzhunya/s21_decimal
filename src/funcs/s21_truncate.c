#include "s21_dec_lib.h"

// int s21_truncate(s21_decimal value, s21_decimal *result) {
//   int exp = s21_10_conv(value);
//   int check = 0;
//   int sign = 0;
//   s21_decimal buffer = {0};
//   s21_decimal ten = {0};
//   s21_decimal one = {0};
//   s21_from_int_to_decimal(10, &ten);
//   s21_from_int_to_decimal(1, &one);
//   s21_rev_10_conv(&value, 0);
//   if (test_bit(value.bits[3], 31)) {
//     set_0_bit(&value.bits[3], 31);
//     sign = 1;
//   }
//   for (int i = 0; i < exp - 1; i++) {
//     s21_div(value, ten, &buffer);
//     value = buffer;
//     s21_from_int_to_decimal(0, &buffer);
//   }
//   s21_mod(value, ten, &buffer);
//   s21_from_decimal_to_int(buffer, &check);
//   s21_from_int_to_decimal(0, &buffer);
//   s21_div(value, ten, &buffer);
//   value = buffer;
//   *result = value;
//   if (check >= 5)
//     s21_add(*result, one, result);
//   if (sign == 1) {
//     set_1_bit(&(result->bits[3]), 31);
//   }
//   return 0;
// }

int s21_truncate(s21_decimal value, s21_decimal *result) {
  s21_decimal *res_value;
  s21_decimal ten;

  ten.bits[0] = 0b00000000000000000000000000001010;  // 13.4217727
  ten.bits[1] = 0b00000000000000000000000000000000;
  ten.bits[2] = 0b00000000000000000000000000000000;
  ten.bits[3] = 0b00000000000000000000000000000000;  //

  memset(result, 0, sizeof(*result));  // зануляем result
  int exp = s21_10_conv(value);        // получаем степень
  s21_decimal copy = {0};

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 32; j++) {
      int z = test_bit((value.bits[i]), j);
      if (z) {
        set_1_bit(&copy.bits[i], j);
      } else {
        set_0_bit(&copy.bits[i], j);
      }
    }
  }

  for (int i = 0; i < 32; i++) {
    set_0_bit(&copy.bits[3], i);
  }

  // printf("\n copy: \n");
  // print_2(&copy);

  int sign = get_sign(&value);    // получаем знак
  set_0_bit(&value.bits[3], 31);  // обнуляем знак
  while (exp--) {
    memset(result, 0, sizeof(*result));

    // *res_value = *s21_div_ten(copy, &result);
    // copy = *res_value;
    // print_2(&copy);
  }
  *result = *res_value;
  return 0;
}
