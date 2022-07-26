#include "s21_dec_lib.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int error = 0;
  int sign_op = 0;

  s21_decimal *res = result;

  sign_op = test_bit(value.bits[3], 31);

  if (sign_op) {
    s21_truncate(value, res);

    s21_decimal one;
    one.bits[0] = 0b00000000000000000000000000000001;
    one.bits[1] = 0b00000000000000000000000000000000;
    one.bits[2] = 0b00000000000000000000000000000000;
    one.bits[3] = 0b00000000000000000000000000000000;

    s21_add(*res, one, res);

    set_1_bit(&res->bits[3], 31);

    *res = *result;

  } else {
    s21_truncate(value, res);
    *res = *result;
  }
  return error;
}
