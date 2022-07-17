#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int exp = s21_10_conv(value);
  int check = 0;
  int sign = 0;
  s21_decimal buffer = {0};
  s21_decimal ten = {0};
  s21_decimal one = {0};
  s21_from_int_to_decimal(10, &ten);
  s21_from_int_to_decimal(1, &one);
  s21_rev_10_conv(&value, 0);
  if (test_bit(value.bits[3], 31)) {
    set_0_bit(&value.bits[3], 31);
    sign = 1;
  }
  for (int i = 0; i < exp - 1; i++) {
    s21_div(value, ten, &buffer);
    value = buffer;
    s21_from_int_to_decimal(0, &buffer);
  }
  s21_mod(value, ten, &buffer);
  s21_from_decimal_to_int(buffer, &check);
  s21_from_int_to_decimal(0, &buffer);
  s21_div(value, ten, &buffer);
  value = buffer;
  *result = value;
  if (check >= 5)
    s21_add(*result, one, result);
  if (sign == 1) {
    set_1_bit(&(result->bits[3]), 31);
  }
  return 0;
}
