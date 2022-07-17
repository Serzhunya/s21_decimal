#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int errCode = 0;
  if (result == NULL) {
    return errCode = 1;
  }
  if (get_sign(&value)) {
    set_0_bit(&value.bits[3], 31);
  } else {
    set_1_bit(&value.bits[3], 31);
  }
  // invert_bit(&value.bits[3], 31);
  *result = value;
  return errCode;
}
