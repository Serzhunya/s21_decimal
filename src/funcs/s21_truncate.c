#include "s21_dec_lib.h"

#define S21_MAX_UINT 4294967295


int s21_truncate(s21_decimal value, s21_decimal *result) {
  int err_code = 0;
  float res = 0.0;                                   // объявление кода ошибки
  int scale = get_scale(&value);                     // получаем степень
  if (scale) {                                       // пока степень положительная
    s21_decimal tmp = {0};                           // зануляем темп децимал
    s21_copy(value, &tmp);                           // копируем валуе по адресу темпа
    s21_scale_decrease(&tmp, scale);                 // 
    s21_copy(tmp, result);
  } else {
    s21_copy(value, result);
  }
  // printf("это результат из функции:\n");
  // print_2(result);
  
  // s21_from_decimal_to_float(*result, &res);
  // printf("\n");
  // printf("печатаем результат из функции = %f\n", res);
  return err_code;
}

int get_scale(s21_decimal *d) { return (char)(d->bits[3] >> 16); }    // получаем интовое значение экспоненты

void s21_copy(s21_decimal from, s21_decimal *to) {                    // копируем децималы
  to->bits[0] = from.bits[0];
  to->bits[1] = from.bits[1];
  to->bits[2] = from.bits[2];
  to->bits[3] = from.bits[3];
}


// первым параметром - указатель на децимал, вторым параметров интовый шифт ака скейл из функции

void s21_scale_decrease(s21_decimal *value, int shift) {              // уменьшение степени
  int i, tmp, j = 0;                      // три переменные i j - счетчики и tmp - буфер
  unsigned long long overflow;            // беззнаковый лонг лонг для переполнения

  printf("shift = %d\n", shift);

  while (j < shift) {                     // пока счетчик равный 0 меньше значения степени (и увеличивается)

    overflow = value->bits[2];            // в переполнение присваиваем значение из 3 инта децимался валуе
    // printf("overflow1 = %llu\n", overflow);
    i = 2;                                // и присваиваем второму счетчику i = 2
  
    while (i > 0) {                       // пока i больше нуля (и умеьншается) 

      tmp = overflow % 10;                // присваиваем буферу остаток от деления значения переполения на 10
      // printf("tmp1 = %d\n", tmp);

      value->bits[i] = overflow / 10;
      // printf("value->bits[%d] = %d\n", i, value->bits[i]);     // инт из структуры децимала равный по номеру i присваиваем переполнение деленное на 10 без остатка


      i--;                                                  
      overflow = tmp * (S21_MAX_UINT + 1) + value->bits[i]; // в переполнение присваивается буфер умноженный на (макс юинт + 1) + итый инт децимала
      // printf("overflow2 = %llu\n", overflow);
      //printf("value->bits[0] = %d\n", value->bits[0]);

      if (i == 0) value->bits[i] = overflow / 10; // если и станет 0  в итый инт децимала присваиваем переполнение деленное на 10
    } 
    j++;
  }

//1111111111111111111111111111111
//10000000000000000000000000000000
  s21_set_scale(value, (s21_get_scale(*value) - shift)); // выставляем степень через получение интового значения разницы валуе и шифта

}

void s21_set_scale(s21_decimal *value, int size) {       // выставляем степень
  value->bits[3] &= ~(S21_MAX_UINT / 2);                 // 
  value->bits[3] >>= 16;
  value->bits[3] |= size;
  value->bits[3] <<= 16;
}

int s21_get_scale(s21_decimal value) { return (255 & (value.bits[3] >> 16)); }
