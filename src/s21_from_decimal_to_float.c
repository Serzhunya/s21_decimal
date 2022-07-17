#include "s21_decimal.h"

/*
    function s21_from_decimal_to_float
    Перевод переменной src из типа s21_decimal в тип float
*/

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  double result = 0;
  int off = 0;
  for (int i = 0; i < 96; i++) {
    if ((src.bits[i / 32] & (1 << i % 32)) != 0) {
      result += pow(2, i);
    }
  }
  if ((off = (src.bits[3] & ~0x80000000) >> 16) > 0) {
    for (int i = off; i > 0; i--) {
      result /= 10.0;
    }
  }
  *dst = (float)result;
  *dst *= src.bits[3] >> 31 ? -1 : 1;
  return 0;
}
