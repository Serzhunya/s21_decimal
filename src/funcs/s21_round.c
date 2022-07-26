#include "s21_dec_lib.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int error = 0;
  int sign_op = 0;
  int exp = s21_10_conv(value);
  int last_digit = 0;
  s21_decimal *res = result;

  sign_op = test_bit(value.bits[3], 31);

  if (exp != 0) {
    s21_decimal buf = {0};
    buf = value;
    s21_truncate_buf(&buf, exp - 1);
    last_digit = return_last_digit_and_truncate_buf_by_it(&buf);
    *res = buf;
    if (last_digit >= 5) {
      s21_decimal one = {{1, 0, 0, 0}};
      s21_add(*res, one, res);
    }   
    *result = *res;
    if (sign_op) {
      set_1_bit(&result->bits[3], 31);
    }
  } else {
    *result = value;
  }

  return error;
}

int return_last_digit_and_truncate_buf_by_it(s21_decimal *buf) {
  unsigned long long u_num;
  int tmp_int = 0;
  u_num = buf->bits[2];
  int j = 2;
  for (; j >= 0; j--) {
    if (j == 0) {
      tmp_int = u_num % 10;
      buf->bits[j] = u_num / 10;
    } else {
      tmp_int = u_num % 10;
      buf->bits[j] = u_num / 10;
      u_num = tmp_int * (S21_MAX_UINT + 1) + buf->bits[j - 1];
    }
  }
  return tmp_int;
}