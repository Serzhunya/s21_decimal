#include "s21_decimal.h"

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_decimal val_1 = value_1;
  s21_decimal val_2 = value_2;
  int bit = 0;
  int sign_1 = get_sign(&value_1);
  set_0_bit(&val_1.bits[3], 31);
  set_0_bit(&val_2.bits[3], 31);

  s21_decimal val_og = val_2;
  while (!(s21_is_greater_or_equal(val_2, val_1)) && (bit == 0)) {
    s21_shift(&val_2);
    bit = test_bit(val_2.bits[2], 31);
  }
  while (s21_is_greater_or_equal(val_2, val_og) ||
         s21_is_greater_or_equal(val_1, val_og)) {
    s21_shift(result);
    if (s21_is_greater(val_2, val_1)) {
      set_0_bit(&result->bits[0], 0);
    } else {
      s21_sub(val_1, val_2, &val_1);
      set_1_bit(&result->bits[0], 0);
    }
    s21_unshift(&val_2);
  }
  *result = val_1;
  if (sign_1 == 1) {
    set_1_bit(&result->bits[3], 31);
  } else {
    set_0_bit(&result->bits[3], 31);
  }
  return 0;
}
