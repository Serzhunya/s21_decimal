#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int erCode = 0;

  s21_decimal value_2_inv = value_2;
  invert_bit(&(value_2_inv.bits[3]), 31);

  erCode = s21_add(value_1, value_2_inv, result);

  return erCode;
}
