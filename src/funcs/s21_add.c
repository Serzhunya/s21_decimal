#include "s21_dec_lib.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {

  int erCode = 0;  // код ошибки
                   /*  0 - OK
                       1 - число слишком велико или равно положительной бесконечности
                       2 - число слишком мало или равно отрицательной бесконечности
                       3 - деление на ноль  */
  /* 1) узнаем 31 бит bits[3] обоих чисел и запоминаем */

  int sign_op_1 = 0;
  int sign_op_2 = 0;
  sign_op_1 = test_bit(value_1.bits[3], 31);
  sign_op_2 = test_bit(value_2.bits[3], 31);

  if (sign_op_1 == sign_op_2) {  // если знаки равны
    erCode = s21_addiction_logic(value_1, value_2, result);
    if (sign_op_1) {  // если отрицательный знак
      set_1_bit(&result->bits[3], 31);
    }

  } else {

    set_0_bit(&value_1.bits[3], 31);
    set_0_bit(&value_2.bits[3], 31);

    if (s21_is_greater(value_1, value_2) == 1) {
      // то инвертируем value_1 и складываем с value_2
      s21_invert_mantisa(&value_1);
      s21_addiction_logic(value_1, value_2, result);
      if (sign_op_1) {
        set_1_bit(&result->bits[3], 31);
      }
    } else {
      // то инвертируем value_2 и складываем с value_1
      s21_invert_mantisa(&value_2);
      s21_addiction_logic(value_1, value_2, result);
      if (sign_op_2) {
        set_1_bit(&result->bits[3], 31);
      }
    }

    s21_invert_mantisa(result);
  }
  return (erCode);
}
