#include "s21_decimal.h"

/*
    function s21_from_decimal_to_int
    Перевод переменной src из типа s21_decimal в тип int
*/

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  *dst = src.bits[0];
  if (test_bit(src.bits[3], 31)) {
    *dst *= -1;
  }
  *dst /= (int)pow(10, exp_decimal_bin2dec(src));
  return 0;
}
