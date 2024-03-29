#include "s21_dec_lib.h"

#define S21_MAX_UINT 4294967295

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int error = 0;
  int exp = s21_10_conv(value);
  int sign_op = test_bit(value.bits[3], 31);
  if (exp != 0) {
    s21_decimal buf = {0};
    buf = value;
    s21_truncate_buf(&buf, exp);
    *result = buf;
  } else {
    *result = value;
  }
  if (sign_op) {
    set_1_bit(&result->bits[3], 31);
  }
  return error;
}

void s21_truncate_buf(s21_decimal *buf, int exp) {
  unsigned long long u_num;  // 18,446,744,073,709,551,615
  int tmp_int = 0;
  for (int i = 0; i < exp; i++) {
    u_num = buf->bits[2];
    int j = 2;
    for (; j >= 0; j--) {
      if (j == 0) {
        buf->bits[j] = u_num / 10;
      } else {
        tmp_int = u_num % 10;  // запомнили первый разряд который мы отнимаем
        buf->bits[j] = u_num / 10;  // получили в последнем инте валуе получили
                                    // последний инт резалта
        u_num = tmp_int * (4294967296) + buf->bits[j - 1];

        /*
  1) iteration j = 2
  tmp_int = 4294967295 % 10 = 5
  buf->bits[j] = 4294967295 / 10 = 429496729
  u_num = 5 * (MAX_UINT + 1) + bits[j - 1]
  u_num = 5 * (4294967295 + 1) + 4294967295 = 25769803775
  u_num =
        1. 5 * 4294967296 = 21474836480 - это минимальный минт по модулю +
  десятичный разряд
        2. 21474836480 + 4294967295 = 25769803775 (u_num)

  как выглядит буф после первой итерации
  buf.bits[0] = 0b11111111111111111111111111111111;
  buf.bits[1] = 0b11111111111111111111111111111111;
  buf.bits[2] = 0b00011001100110011001100110011001;
  buf.bits[3] = 0b00000000000000000000000000000000;

  2) iteration j = 1
  tmp_int = 25769803775 % 10 = 5
  buf->bits[j] = 25769803775 / 10 = 2576980377
  u_num = 5 * (MAX_UINT + 1) + bits[j - 1] ---??????????? спросить у Вани или
  Саши u_num = 5 * (4294967295 + 1) + bits[0] = u_num =
        1. 5 * 4294967296 = 21474836480
        2. 21474836480 + 4294967295 = 25769803775 (u_num)
  как выглядит буф после буф итерации
  buf.bits[0] = 0b11111111111111111111111111111111;
  buf.bits[1] = 0b10011001100110011001100110011001;
  buf.bits[2] = 0b00011001100110011001100110011001;
  buf.bits[3] = 0b00000000000000000000000000000000;

  3) iteration j = 0

  идем по основной ветке

  buf->bits[j] = u_num / 10;
  buf->bits[j] = 25769803775 / 10 = 2576980377

  как выглядит буф после буф итерации
  buf.bits[0] = 0b10011001100110011001100110011001;
  buf.bits[1] = 0b10011001100110011001100110011001;
  buf.bits[2] = 0b00011001100110011001100110011001;
  buf.bits[3] = 0b00000000000000000000000000000000;


*/
      }
    }
  }
  buf->bits[3] = 0;
}
