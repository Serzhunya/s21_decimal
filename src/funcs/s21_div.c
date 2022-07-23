#include "s21_dec_lib.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_decimal val_1 = value_1;
  s21_decimal val_2 = value_2;

  int bit = 0;
  int sign_1 = get_sign(&value_1);  // получаем знак
  int sign_2 = get_sign(&value_2);

  int error = s21_zero(value_2);

  if (sign_1 != sign_2) {
    set_1_bit(&result->bits[3], 31);
  } else {
    set_0_bit(&result->bits[3], 31);
  }


  set_0_bit(&val_1.bits[3], 31);  // зануляем знак
  set_0_bit(&val_2.bits[3], 31);

  s21_decimal val_og = val_2;

  // while (!(s21_is_greater_or_equal(val_2, val_1)) && (bit == 0)) { // чето смещает, а понял смещает второй валуе для чего? что бы уравнять мантисы
  //   s21_shift(&val_2);
  //   bit = test_bit(val_2.bits[2], 31);
  // }


  while (s21_is_greater_or_equal(val_2, val_og) || s21_is_greater_or_equal(val_1, val_og)) {
    // s21_shift(result);

    // if (s21_is_greater(val_2, val_1)) {
    //   set_0_bit(&result->bits[0], 0);

    // } else {

      s21_sub(val_1, val_2, &val_1); // непосредственно производим вычитание

      // set_1_bit(&result->bits[0], 0);
    // }

    // s21_unshift(&val_2);
  }
  return error;
}
