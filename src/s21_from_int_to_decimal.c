#include "s21_decimal.h"

/*
    function s21_from_int_to_decimal
    Перевод переменной src из типа int в тип s21_decimal
*/

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  memset(&(dst->bits), 0, sizeof(dst->bits));
  if (is_int_negative(src)) {
    set_1_bit(&(dst->bits[3]), 31);
    src = -src;
  }
  dst->bits[0] = src;
  return 0;
}
