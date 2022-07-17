#include "s21_dec_lib.h"

/*
    function s21_from_float_to_decimal
    Перевод переменной src из типа float в тип s21_decimal
*/

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  memset(&(dst->bits), 0, sizeof(dst->bits));
  if (0 < fabs(src) && fabs(src) < 1e-28) return 1;
  if (/*fabs(src) > MAX_S21_DECIMAL ||*/ is_inf(src) || is_nan(src)) return 1;
  // Получаем битовое представление float
  // uint32_t float_bits = float_2_bits(src);
  int float_bits = float_2_bits(src);
  // Проверяем знак
  if (test_32_bit(float_bits, 31)) {
    set_1_bit(&(dst->bits[3]), 31);
    src = -src;
  }
  // Получаем степень экспоненты из float с 30 до 23 бита
  int exp_shift = exp_float_bin2dec(float_bits);
  // Убираем сдвиг экспоненты
  // Получаем десятичное значение степени, в которое нужно возвести 10
  int exp = exp_shift - 127;
  // printf("\n\nexp: %d\n\n", exp);
  float2decimal_main(float_bits, exp, dst);
  return 0;
}
