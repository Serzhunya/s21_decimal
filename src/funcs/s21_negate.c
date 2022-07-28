#include "s21_dec_lib.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int errCode = 0;
  if (result == NULL) {
    return errCode = 1;
  }
  s21_decimal zero = {0};
  if (get_sign(&value)) {
    set_0_bit(&value.bits[3], 31);
  } else {
    set_1_bit(&value.bits[3], 31);
  }
  // invert_bit(&value.bits[3], 31);
  *result = value;
  if (s21_is_equal(value, zero)) {
    *result = zero;
  }
  return errCode;
}
