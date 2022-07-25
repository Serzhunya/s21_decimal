#include "s21_dec_lib.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int error = 0;
  int exp = s21_10_conv(value);

  if (exp != 0) {
    s21_decimal buf = {0};
    buf = value;
    s21_truncate_buf(&buf, exp);
    *result = buf;
  } else {
    *result = value;
  }
  return error;
}

void s21_truncate_buf(s21_decimal *buf, int exp) {
  unsigned long long u_num;
  int tmp_int = 0;
  for (int i = 0; i < exp; i++) {
    u_num = buf->bits[2];
    int j = 2;
    for (; j >= 0; j--) {
      if (j == 0) {
        buf->bits[j] = u_num / 10;
      } else {
        tmp_int = u_num % 10;
        buf->bits[j] = u_num / 10;
        u_num = tmp_int * (4294967296) + buf->bits[j - 1];
      }
    }
  }
  buf->bits[3] = 0;
}