#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int bits[4];
} s21_decimal;

// int s21_div_10(s21_decimal dec1, s21_decimal *result);
int s21_sub(s21_decimal dec1, s21_decimal dec2, s21_decimal *result);
int s21_add(s21_decimal dec1, s21_decimal dec2, s21_decimal *result);
int get_sign(s21_decimal *num);
void handle_exponent_div(s21_decimal value_1, s21_decimal value_2,
                         s21_decimal *result, int *code);

#endif  // SRC_S21_DECIMAL_H_