#include "s21_dec_lib.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  // s21_decimal res_value;
  // s21_decimal result;
  memset(result, 0, sizeof(*result));  // зануляем result
  int exp = s21_10_conv(value);        // получаем степень
  s21_decimal copy = value;            // делаем копию
  s21_decimal ten;

  ten.bits[0] = 0b00000000000000000000000000001010;  // 10
  ten.bits[1] = 0b00000000000000000000000000000000;
  ten.bits[2] = 0b00000000000000000000000000000000;
  ten.bits[3] = 0b10000000000000000000000000000000;

  // printf("\n value: \n");
  // print_2(&value);

  // printf("\n copy1: \n");
  // print_2(&copy);

  for (int i = 0; i < 32; i++) {      // убираем в ней степень
    set_0_bit(&copy.bits[3], i);
  }

  // printf("\n copy2: \n");
  // print_2(&copy);

  // int sign = get_sign(&value);        // получаем знак

  set_0_bit(&value.bits[3], 31);      // обнуляем знак

  while (exp--) {
    memset(result, 0, sizeof(*result));
    
    
    // тут надо реализовать деление на двоичную десятку
    // res_value - decimal
    // надо в него записать результат деления на десять


    // value - это то что надо поделить

    // ten - это двоичная десятка 

    // 

    s21_div(value, ten, &result);

    // print_2(&result);

    // res_value = division_in_10(copy, result);    // записываем в результат на каждой итерации

    // copy = res_value;                            // присваиваем копии результат
    // print_2(&copy);
  }

  //*result = res_value;                           // кладем в резал
  return 0;
}