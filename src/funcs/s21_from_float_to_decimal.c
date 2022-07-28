#include "s21_dec_lib.h"


/*
    in Header File s21_decimal.h MUST BE THIS UNION:
    typedef union {
    float flt;
    unsigned int bits;
    } lens_t;
    Check it before testing
*/

/*
    function s21_from_float_to_decimal
    Перевод переменной src из типа float в тип s21_decimal
*/
int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  memset(&(dst->bits), 0, sizeof(dst->bits));
  //проверка, что число не NAN и не бесконечность
  if (is_inf(src) || is_nan(src)) return 1;
  // Получаем битовое представление float
  int float_bits = float_2_bits(src);
  //Проверяем знак
  if (test_bit(float_bits, 31)) {
    set_1_bit(&(dst->bits[3]), 31);
    src = -src;
  }
  //Получаем степень экспоненты из float с 30 до 23 бита
  int exp_shift = exp_float_bin2dec(float_bits);
  //Убираем сдвиг экспоненты
  //Получаем десятичное значение степени, в которое нужно возвести 10
  int exp = exp_shift - 127;
  // printf("\n\nexp: %d\n\n", exp);
  int error = float2decimal_main(float_bits, exp, dst);
  //магическое отлавливание ошибки большого числа, которое не помещается в
  //децимал
  if (error == 123) {
    memset(&(dst->bits), 0, sizeof(dst->bits));
    return 1;
  }
  //здесь отлавливаем ошибку если подано число меньше 1e-28. В этом случае dst
  //будет нулевым (bits[0-2] == 0), а dst->bits[3] != 0 (то есть умножение
  //происходило) => зануляем dst и возвращаем ошибку
  if (dst->bits[0] == 0 && dst->bits[1] == 0 && dst->bits[2] == 0 &&
      dst->bits[3] != 0 && src != 0) {
    memset(&(dst->bits), 0, sizeof(dst->bits));
    return 1;
  }
  //если src  == 0
  if (src == 0) {
    memset(&(dst->bits), 0, sizeof(dst->bits));
  }
  return 0;
}










