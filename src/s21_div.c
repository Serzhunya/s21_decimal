#include "s21_decimal.h"

int set_1_bit(int *value, int BitNumber);
int set_0_bit(int *value, int BitNumber);
int test_bit(int value, int BitNumber);
// s21_decimal s21_div_10(s21_decimal value_1, s21_decimal *result);
s21_decimal s21_truncate(s21_decimal value, s21_decimal *result);
int s21_sub(s21_decimal dec1, s21_decimal dec2, s21_decimal *result);
int s21_add(s21_decimal dec1, s21_decimal dec2, s21_decimal *result);
int get_sign(s21_decimal *num);
int set_sign(s21_decimal dec);
void handle_exponent_div(s21_decimal value_1, s21_decimal value_2,
                         s21_decimal *result, int *code);
int s21_addiction_logic(s21_decimal value_1, s21_decimal value_2,
                        s21_decimal *result);
void s21_invert_mantisa(s21_decimal *value);
s21_decimal s21_superior_10(int power, s21_decimal *value);
void print_2(s21_decimal *dst);
int s21_is_greater(s21_decimal num1, s21_decimal num2);
void mult_10(s21_decimal value, s21_decimal *result);
int s21_shift(s21_decimal *number);
void s21_unshift(s21_decimal *number);
int s21_10_conv(s21_decimal value);
int s21_is_equal(s21_decimal num1, s21_decimal num2);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int is_int_negative(int value);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int exp_decimal_bin2dec(s21_decimal dst);
int s21_zero(s21_decimal value);

int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2) {
  return (s21_is_greater(num1, num2) || s21_is_equal(num1, num2));
}

int s21_is_equal(s21_decimal num1, s21_decimal num2) {
  int sign_num1 = get_sign(&num1);
  int sign_num2 = get_sign(&num2);
  int result = -1;
  if (sign_num1 == sign_num2) {
    if (num1.bits[3] == num2.bits[3]) {
      if (num1.bits[2] == num2.bits[2]) {
        if (num1.bits[1] == num2.bits[1]) {
          if (num1.bits[0] == num2.bits[0]) {
            result = 1;
          } else {
            result = 0;
          }
        } else {
          result = 0;
        }
      } else {
        result = 0;
      }
    } else {
      int exp1;
      int exp2;
      exp1 = s21_10_conv(num1);
      exp2 = s21_10_conv(num2);
      if (exp1 > exp2) {
        num2 = s21_superior_10(exp1, &num2);
      } else if (exp2 > exp1) {
        num1 = s21_superior_10(exp2, &num1);
      }
      if (num1.bits[3] == num2.bits[3]) {
        if (num1.bits[2] == num2.bits[2]) {
          if (num1.bits[1] == num2.bits[1]) {
            if (num1.bits[0] == num2.bits[0]) {
              result = 1;
            } else {
              result = 0;
            }
          } else {
            result = 0;
          }
        } else {
          result = 0;
        }
      } else {
        result = 0;
      }
    }
  } else {
    result = 0;
  }
  return result;
}

void invert_bit(int *value, int BitNumber) { *value ^= (1 << BitNumber); }

void s21_unshift(s21_decimal *number) {
  int vault_1 = 0;  // Хранит значение предыдущего бита
  int vault_2 = 0;  // Сохраняет нынешний бит
  for (int i = 2; i >= 0; i--) {
    for (int j = 31; j >= 0; j--) {
      vault_2 = test_bit((number->bits[i]), j);
      if (vault_1)
        set_1_bit(&number->bits[i], j);
      else
        set_0_bit(&number->bits[i], j);
      vault_1 = vault_2;
    }
  }
}

/* Данная функция делает смещение числа типа decimal
вперёд на один символ. Нужна при выполнении операции умножения */
int s21_shift(s21_decimal *number) {
  int vault_1 = 0;  // Хранит значение предыдущего бита
  int vault_2 = 0;  // Сохраняет нынешний бит
  int error = test_bit(number->bits[2], 31);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 32; j++) {
      vault_2 = test_bit((number->bits[i]), j);
      if (vault_1)
        set_1_bit(&number->bits[i], j);
      else
        set_0_bit(&number->bits[i], j);
      vault_1 = vault_2;
    }
  }
  return error;
}

int test_bit(int value, int BitNumber) {
  int result = value & (1 << BitNumber);
  return result;
}

int set_1_bit(int *value, int BitNumber) {
  *value = *value | (1 << BitNumber);
  return 0;
}

int set_0_bit(int *value, int BitNumber) {
  *value = *value | (0 << BitNumber);
  return 0;
}

int get_sign(s21_decimal *num) {
  int res = -1;
  if (test_bit(num->bits[3], 31) == 0) {
    res = 0;  // если num положительный
  } else {
    res = 1;  // если num отрицательный
  }
  return res;
}

int set_sign(s21_decimal dec) {
  if (test_bit(dec.bits[3], 31)) {
    set_0_bit(&dec.bits[3], 31);
  }
  return 0;
}

void s21_invert_mantisa(s21_decimal *value) {
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 32; i++) {
      invert_bit(&value->bits[j], i);
    }
  }
}

int s21_addiction_logic(s21_decimal value_1, s21_decimal value_2,
                        s21_decimal *result) {
  int a = 0;     // бит первого числа
  int b = 0;     // бит второго числа
  int prev = 0;  // была ли единица в уме
  int next = 0;  // будем ли мы передавать единицу в след разряд
  int res;  // бит который мы запишем в результат

  int error = 0;
  a = test_bit(value_1.bits[2], 31);
  b = test_bit(value_2.bits[2], 31);

  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 32; i++) {
      /*  int test_bit(int value, int BitNumber) { return value & (1 <<
       * BitNumber); }  */
      // проверка бита
      a = test_bit(value_1.bits[j], i);
      b = test_bit(value_2.bits[j], i);
      if (a == 0) {
        if (b == 0 && prev == 0) {
          res = 0;
          next = 0;
        } else if (b == 0 || prev == 0) {
          res = 1;
          next = 0;
        } else {
          res = 0;
          next = 1;
        }
      } else {
        if (b == 0 && prev == 0) {
          res = 1;
          next = 0;
        } else if (b == 0 || prev == 0) {
          res = 0;
          next = 1;
        } else {
          res = 1;
          next = 1;
        }
      }
      prev = next;
      /*  посе того как получили res - выставляем в num3 */
      if (res) {
        set_1_bit(&(result->bits[j]), i);
      } else {
        set_0_bit(&(result->bits[j]), i);
      }
    }
  }
  return error;
}

int s21_10_conv(s21_decimal value) {
  int result = 0;
  int power = 1;
  for (int i = 16; i < 21; i++, power = power * 2)
    if (test_bit(value.bits[3], i)) {
      result = result + power;
    }
  return result;
}

void s21_rev_10_conv(s21_decimal *value, int result) {
  int power = 16;
  for (int i = 20; i > 15; i--, power /= 2)
    if (result >= power) {
      result -= power;
      set_1_bit(&value->bits[3], i);
    } else {
      set_0_bit(&value->bits[3], i);
    }
}

s21_decimal s21_superior_10(int power, s21_decimal *value) {
  int inferior = s21_10_conv(*value);

  s21_rev_10_conv(value, power);
  for (int i = 0; i < (power - inferior); i++) {
    mult_10(*value, value);
  }
  return (*value);
}

int s21_zero(s21_decimal value) {
  int bit = 0;
  int error = 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 32; j++) {
      bit = test_bit(value.bits[i], j);
      if (bit == 1) error = 0;
    }
  }
  return error;
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int exp1;
  int exp2;
  exp1 = s21_10_conv(value_1);
  exp2 = s21_10_conv(value_2);
  if (exp1 > exp2) {
    value_2 = s21_superior_10(exp1, &value_2);
    s21_rev_10_conv(result, exp1);
  } else if (exp2 > exp1) {
    value_1 = s21_superior_10(exp2, &value_1);
    s21_rev_10_conv(result, exp2);
  }

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

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int erCode = 0;

  s21_decimal value_2_inv = value_2;
  invert_bit(&(value_2_inv.bits[3]), 31);

  erCode = s21_add(value_1, value_2_inv, result);

  return erCode;
}

int s21_is_greater_num(s21_decimal num1, s21_decimal num2, int result) {
  if (num1.bits[3] == num2.bits[3]) {
    if (num1.bits[2] == num2.bits[2]) {
      if (num1.bits[1] == num2.bits[1]) {
        if (num1.bits[0] == num2.bits[0]) {
          result = 0;
        } else if (num1.bits[0] > num2.bits[0]) {
          result = 1;
        } else {
          result = 0;
        }
      } else if (num1.bits[1] > num2.bits[1]) {
        result = 1;
      } else {
        result = 0;
      }
    } else if (num1.bits[2] > num2.bits[2]) {
      result = 1;
    } else {
      result = 0;
    }
  } else {
    int exp1;
    int exp2;
    exp1 = s21_10_conv(num1);
    exp2 = s21_10_conv(num2);
    if (exp1 > exp2) {
      num2 = s21_superior_10(exp1, &num2);
    } else if (exp2 > exp1) {
      num1 = s21_superior_10(exp2, &num1);
    }
    if (num1.bits[3] == num2.bits[3]) {
      if (num1.bits[2] == num2.bits[2]) {
        if (num1.bits[1] == num2.bits[1]) {
          if (num1.bits[0] == num2.bits[0]) {
            result = 0;
          } else if (num1.bits[0] > num2.bits[0]) {
            result = 1;
          } else {
            result = 0;
          }
        } else if (num1.bits[1] > num2.bits[1]) {
          result = 1;
        } else {
          result = 0;
        }
      } else if (num1.bits[2] > num2.bits[2]) {
        result = 1;
      } else {
        result = 0;
      }
    }
  }
  return result;
}

int s21_is_greater(s21_decimal num1, s21_decimal num2) {
  int result = -1;
  int sign_num1 = get_sign(&num1);
  int sign_num2 = get_sign(&num2);
  if (sign_num1 == sign_num2 && sign_num1 == 0) {  // оба положительные
    result = s21_is_greater_num(num1, num2, result);
  } else if (sign_num1 == 1 &&
             sign_num2 == 0) {  // num1 - отрицательный, num2 - положительный
    result = 0;
  } else if (sign_num1 == 0 &&
             sign_num2 == 1) {  // num1 - положительный, num2 - отрицательный
    result = 1;
  } else if (sign_num1 == sign_num2 && sign_num1 == 1) {  // оба отрицательный
    if (num1.bits[3] == num2.bits[3]) {
      if (num1.bits[2] == num2.bits[2]) {
        if (num1.bits[1] == num2.bits[1]) {
          if (num1.bits[0] == num2.bits[0]) {
            result = 0;
          } else {
            result = !s21_is_greater_num(num1, num2, result);  // не зашло
          }
        } else {
          result = !s21_is_greater_num(num1, num2, result);  // не зашло
        }
      } else {
        result = !s21_is_greater_num(num1, num2, result);
      }
    } else {
      result = !s21_is_greater_num(num1, num2, result);
    }
  }
  return result;
}

void mult_10(s21_decimal value, s21_decimal *result) {
  s21_decimal ins_val = value;
  s21_shift(&ins_val);
  *result = ins_val;
  s21_shift(&ins_val);
  s21_shift(&ins_val);
  s21_addiction_logic(*result, ins_val, result);
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  memset(&(dst->bits), 0, sizeof(dst->bits));
  if (is_int_negative(src)) {
    set_1_bit(&(dst->bits[3]), 31);
    src = -src;
  }
  dst->bits[0] = src;
  return 0;
}

int is_int_negative(int value) {
  int sign = 0;
  if (value < 0) sign = 1;
  return sign;
}

// Временная
void print_2(s21_decimal *dst) {
  for (int i = 0; i < 4; i++) {
    printf("bits[%d]\n", i);
    for (int j = 1; j <= 32; j++) {
      if (test_bit(dst->bits[i], (j - 1))) {
        printf("1");
      } else {
        printf("0");
      }
      if ((j % 4) == 0) printf(" ");
    }
    printf("\n");
  }
}

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_decimal val_1 = value_1;
  s21_decimal val_2 = value_2;
  int bit = 0;
  int sign_1 = get_sign(&value_1);
  set_0_bit(&val_1.bits[3], 31);
  set_0_bit(&val_2.bits[3], 31);

  s21_decimal val_og = val_2;
  while (!(s21_is_greater_or_equal(val_2, val_1)) && (bit == 0)) {
    s21_shift(&val_2);
    bit = test_bit(val_2.bits[2], 31);
  }
  while (s21_is_greater_or_equal(val_2, val_og) ||
         s21_is_greater_or_equal(val_1, val_og)) {
    s21_shift(result);
    if (s21_is_greater(val_2, val_1)) {
      set_0_bit(&result->bits[0], 0);
    } else {
      s21_sub(val_1, val_2, &val_1);
      set_1_bit(&result->bits[0], 0);
    }
    s21_unshift(&val_2);
  }
  *result = val_1;
  if (sign_1 == 1) {
    set_1_bit(&result->bits[3], 31);
  } else {
    set_0_bit(&result->bits[3], 31);
  }
  return 0;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  *dst = src.bits[0];
  if (test_bit(src.bits[3], 31)) {
    *dst *= -1;
  }
  *dst /= (int)pow(10, exp_decimal_bin2dec(src));
  return 0;
}

int exp_decimal_bin2dec(s21_decimal dst) {
  int exp_int = 0;
  int index = 23;
  int exp_2 = 7;
  while (index >= 16) {
    if (test_bit(dst.bits[3], index)) {
      exp_int += pow(2, exp_2);
    }
    index--;
    exp_2--;
  }
  return exp_int;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_decimal val_1 = value_1;
  s21_decimal val_2 = value_2;
  int bit = 0;
  int sign_1 = get_sign(&value_1);
  int sign_2 = get_sign(&value_2);
  int error = s21_zero(value_2);
  if (sign_1 != sign_2)
    set_1_bit(&result->bits[3], 31);
  else
    set_0_bit(&result->bits[3], 31);
  set_0_bit(&val_1.bits[3], 31);
  set_0_bit(&val_2.bits[3], 31);
  s21_decimal val_og = val_2;
  while (!(s21_is_greater_or_equal(val_2, val_1)) && (bit == 0)) {
    s21_shift(&val_2);
    bit = test_bit(val_2.bits[2], 31);
  }
  while (s21_is_greater_or_equal(val_2, val_og) ||
         s21_is_greater_or_equal(val_1, val_og)) {
    s21_shift(result);
    if (s21_is_greater(val_2, val_1)) {
      set_0_bit(&result->bits[0], 0);
    } else {
      s21_sub(val_1, val_2, &val_1);
      set_1_bit(&result->bits[0], 0);
    }
    s21_unshift(&val_2);
  }
  return error;
}

s21_decimal s21_div_10(s21_decimal value_1, s21_decimal *result) {
  memset(result, 0, sizeof(*result));
  int exp = s21_10_conv(value_1);
  s21_rev_10_conv(&value_1, 0);
  s21_decimal ten;
  s21_decimal count;
  s21_decimal one;
  s21_decimal res;
  ten.bits[0] = 0b00000000000000000000000000001010;  // 10
  ten.bits[1] = 0b00000000000000000000000000000000;
  ten.bits[2] = 0b00000000000000000000000000000000;
  ten.bits[3] = 0b00000000000000000000000000000000;

  count.bits[0] = 0b00000000000000000000000000000000;  // 0
  count.bits[1] = 0b00000000000000000000000000000000;
  count.bits[2] = 0b00000000000000000000000000000000;
  count.bits[3] = 0b00000000000000000000000000000000;

  res.bits[0] = 0b00000000000000000000000000000000;  // 0
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  one.bits[0] = 0b00000000000000000000000000000001;  // 1
  one.bits[1] = 0b00000000000000000000000000000000;
  one.bits[2] = 0b00000000000000000000000000000000;
  one.bits[3] = 0b00000000000000000000000000000000;
  int sign1 = get_sign(&value_1);

  set_0_bit(&value_1.bits[3], 31);
  int i = 1;
  while (s21_is_greater_or_equal(value_1, ten) == 1) {
    memset(result, 0, sizeof(*result));
    s21_sub(value_1, ten, result);
    value_1 = *result;
    printf("\n%d\n", i++);
    s21_add(count, one, &res);
    count = res;
  }

  if (sign1 == 1) {
    set_1_bit(&result->bits[3], 31);
  }
  return res;
}

// s21_decimal s21_truncate(s21_decimal value, s21_decimal *result) {
//   int exp = s21_10_conv(value);
//   int check = 0;
//   int sign = 0;
//   s21_decimal buffer = {0};
//   s21_decimal ten = {0};
//   s21_decimal one = {0};
//   s21_decimal count;
//   s21_decimal res;

//   ten.bits[0] = 0b00000000000000000000000000001010;
//   ten.bits[1] = 0b00000000000000000000000000000000;
//   ten.bits[2] = 0b00000000000000000000000000000000;
//   ten.bits[3] = 0b00000000000000000000000000000000;

//   one.bits[0] = 0b00000000000000000000000000000001;
//   one.bits[1] = 0b00000000000000000000000000000000;
//   one.bits[2] = 0b00000000000000000000000000000000;
//   one.bits[3] = 0b00000000000000000000000000000000;

//   count.bits[0] = 0b00000000000000000000000000000000;
//   count.bits[1] = 0b00000000000000000000000000000000;
//   count.bits[2] = 0b00000000000000000000000000000000;
//   count.bits[3] = 0b00000000000000000000000000000000;

//   res.bits[0] = 0b00000000000000000000000000000000;
//   res.bits[1] = 0b00000000000000000000000000000000;
//   res.bits[2] = 0b00000000000000000000000000000000;
//   res.bits[3] = 0b00000000000000000000000000000000;

//   int i = 1;
//   s21_rev_10_conv(&value, 0);

//   if (test_bit(value.bits[3], 31)) {
//     set_0_bit(&value.bits[3], 31);
//     sign = 1;
//   }
//   for (int i = 0; i < exp - 1; i++) {
//     s21_div(value, ten, &buffer);
//     value = buffer;
//     s21_from_int_to_decimal(0, &buffer);
//   }

//   // while (s21_is_greater_or_equal(value, ten) == 1) {
//   //   memset(result, 0, sizeof(*result));
//   //   s21_sub(value, ten, result);
//   //   value = *result;
//   //   s21_add(count, one, &res);
//   //   count = res;
//   // }

//   s21_mod(value, ten, &buffer);
//   s21_from_decimal_to_int(buffer, &check);
//   s21_from_int_to_decimal(0, &buffer);
//   s21_div(value, ten, &buffer);
//   value = buffer;
//   *result = value;
//   // if (check >= 5) s21_add(*result, one, result);
//   if (sign == 1) {
//     set_1_bit(&(result->bits[3]), 31);
//   }
//   return res;
// }

int main(void) {
  s21_decimal dec1;
  s21_decimal result;
  dec1.bits[0] = 0b00000000000000000000000000110010;
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000000000000000000000;
  printf("\nresult:\n");

  s21_decimal res = s21_div_10(dec1, &result);
  print_2(&res);
  print_2(&result);
  return 0;
}
