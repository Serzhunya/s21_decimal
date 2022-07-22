#include "s21_decimal.h"

int set_1_bit(int *value, int BitNumber);
int set_0_bit(int *value, int BitNumber);
int test_bit(int value, int BitNumber);
void count10_to_bin(int *count_10, int *count_10_bit);
int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2);
s21_decimal s21_sub_in_x(s21_decimal value_1, s21_decimal *result,
                         s21_decimal exp_result_dec);
int truncate(s21_decimal value, s21_decimal *result);
int s21_sub(s21_decimal dec1, s21_decimal dec2, s21_decimal *result);
int s21_add(s21_decimal dec1, s21_decimal dec2, s21_decimal *result);
int add_main(s21_decimal value_1, int exp_1, s21_decimal value_2, int exp_2,
             s21_decimal *result);
int add_mul_1010(int *value_1_arr, int *value_2_arr, int *exp_1, int *exp_2);
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
int s21_is_less(s21_decimal num1, s21_decimal num2);
int s21_10_conv(s21_decimal value);
int s21_is_equal(s21_decimal num1, s21_decimal num2);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int is_int_negative(int value);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int exp_decimal_bin2dec(s21_decimal dst);
int s21_zero(s21_decimal value);
void write_float_decimal_exp_more(int *result, s21_decimal *dst, int index,
                                  int bit);
s21_decimal division_in_10(s21_decimal value_1, s21_decimal *result,
                           s21_decimal exp_result_dec);

// для див
static s21_decimal s21_integer_div_private(s21_decimal dividend,
                                           s21_decimal divisor,
                                           s21_decimal *result);

// static void handle_exponent_div(s21_decimal value_1, s21_decimal value_2,
//                                 s21_decimal *result, int *code);

int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2) {
  return (s21_is_greater(num1, num2) || s21_is_equal(num1, num2));
}

int s21_is_less_num(s21_decimal num1, s21_decimal num2, int result) {
  if (num1.bits[3] == num2.bits[3]) {
    if (num1.bits[2] == num2.bits[2]) {
      if (num1.bits[1] == num2.bits[1]) {
        if (num1.bits[0] == num2.bits[0]) {
          result = 0;
        } else if (num1.bits[0] < num2.bits[0]) {
          result = 1;
        } else {
          result = 0;
        }
      } else if (num1.bits[1] < num2.bits[1]) {
        result = 1;
      } else {
        result = 0;
      }
    } else if (num1.bits[2] < num2.bits[2]) {
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
          } else if (num1.bits[0] < num2.bits[0]) {
            result = 1;
          } else {
            result = 0;
          }
        } else if (num1.bits[1] < num2.bits[1]) {
          result = 1;
        } else {
          result = 0;
        }
      } else if (num1.bits[2] < num2.bits[2]) {
        result = 1;
      } else {
        result = 0;
      }
    }
  }
  return result;
}

int s21_is_less(s21_decimal num1, s21_decimal num2) {
  int result = -1;
  int sign_num1 = get_sign(&num1);
  int sign_num2 = get_sign(&num2);
  if (sign_num1 == sign_num2 && sign_num1 == 0) {
    result = s21_is_less_num(num1, num2, result);
  } else if (sign_num1 == 1 && sign_num2 == 0) {
    result = 1;
  } else if (sign_num1 == 0 && sign_num2 == 1) {
    result = 0;
  } else if (sign_num1 == sign_num2 && sign_num1 == 1) {
    if (num1.bits[3] == num2.bits[3]) {
      if (num1.bits[2] == num2.bits[2]) {
        if (num1.bits[1] == num2.bits[1]) {
          if (num1.bits[0] == num2.bits[0]) {
            result = 0;
          } else {
            result = !s21_is_less_num(num1, num2, result);
          }
        } else {
          result = !s21_is_less_num(num1, num2, result);
        }
      } else {
        result = !s21_is_less_num(num1, num2, result);
      }
    } else {
      result = !s21_is_less_num(num1, num2, result);
    }
  }
  return result;
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  //обнуление result
  memset(&(result->bits), 0, sizeof(result->bits));
  //получение десятичных степеней 10 из чисел decimal
  int exp_1 = exp_decimal_bin2dec(value_1);
  int exp_2 = exp_decimal_bin2dec(value_2);
  int error = add_main(value_1, exp_1, value_2, exp_2, result);
  return error;
}

void count10_to_bin(int *count_10, int *count_10_bit) {
  int mod_2 = 0;
  int index = 0;
  while (*count_10) {
    mod_2 = *count_10 % 2;
    count_10_bit[index] = mod_2;
    *count_10 /= 2;
    index++;
  }
}

void write_float_decimal_exp_more(int *result, s21_decimal *dst, int index,
                                  int bit) {
  switch (bit) {
    case 0:
      for (; index >= 0; index--) {
        if (result[index] == 1) set_1_bit(&(dst->bits[0]), index);
      }
    case 1:
      for (; index >= 32; index--) {
        if (result[index] == 1) set_1_bit(&(dst->bits[1]), index);
      }
      for (; index >= 0; index--) {
        if (result[index] == 1) set_1_bit(&(dst->bits[0]), index);
      }
    case 2:
      for (; index >= 64; index--) {
        if (result[index] == 1) set_1_bit(&(dst->bits[2]), index);
      }
      for (; index >= 32; index--) {
        if (result[index] == 1) set_1_bit(&(dst->bits[1]), index);
      }
      for (; index >= 0; index--) {
        if (result[index] == 1) set_1_bit(&(dst->bits[0]), index);
      }
  }
}

/*
    function add_main
    Основная функция сложения двух чисел типа decimal
*/
int add_main(s21_decimal value_1, int exp_1, s21_decimal value_2, int exp_2,
             s21_decimal *result) {
  int error = 0;
  //для запоминания доп разрядов при сложении
  int memory = 0;
  //индекс в цикле сложения и еще он нужен для записи числа в decimal
  int index = 0;
  //массивы с битами
  int value_1_arr[NUM_255];
  int value_2_arr[NUM_255];
  int result_arr[NUM_255];
  //инициализация
  for (int i = 0; i < NUM_255; i++) {
    result_arr[i] = 2;
    value_1_arr[i] = 2;
    value_2_arr[i] = 2;
  }
  for (int i = 0; i < 96; i++) {
    if (test_bit(value_1.bits[i / 32], i % 32)) {
      value_1_arr[i] = 1;
    } else {
      value_1_arr[i] = 0;
    }
    if (test_bit(value_2.bits[i / 32], i % 32)) {
      value_2_arr[i] = 1;
    } else {
      value_2_arr[i] = 0;
    }
  }
  // какая степень меньше, такую будем домножать на 10 для "выравнивания"
  // порядка степеней в числах
  //если error = 1 значит возможно переполнение мантисыы -> будем делать
  //банковское округление
  error = add_mul_1010(value_1_arr, value_2_arr, &exp_1, &exp_2);
  if (error == 1) {
    // add_sub_1010(value_1_arr, value_2_arr, &exp_1, &exp_2, 1);
  } else if (error == 2) {
    // add_sub_1010(value_1_arr, value_2_arr, &exp_1, &exp_2, 2);
  }
  //производим сложение до 96 бита
  if (exp_1 == exp_2) {
    for (; index < 96; index++) {
      if (value_1_arr[index] == 1 && value_2_arr[index] == 1) {
        //нет в памяти доп разряда
        if (memory == 0) {
          result_arr[index] = 0;
          memory = 1;
        } else {
          result_arr[index] = 1;
        }
      } else if ((value_1_arr[index] == 0 && value_2_arr[index] == 1) ||
                 (value_1_arr[index] == 1 && value_2_arr[index] == 0)) {
        //нет в памяти доп разряда
        if (memory == 0) {
          result_arr[index] = 1;
        } else {
          result_arr[index] = 0;
        }
      } else if (value_1_arr[index] == 0 && value_2_arr[index] == 0) {
        //нет в памяти доп разряда
        if (memory == 0) {
          result_arr[index] = 0;
        } else {
          result_arr[index] = 1;
          memory = 0;
        }
      }
    }
  }
  //проверяем остался ли неучтенный разряд в memory
  //формально я не должен складывать дальше а должен вывести ошибку что сило
  //слишком велико и не помещается в decimal
  if (memory) {
    // result_arr[index] = 1;
    // memory = 0;
    return 1;
  } else {
    //возвращаю index значение 95 тк после цикла он равен 96
    index--;
  }
  // printf("result_arr:\n");
  // for (int i = 95; i >= 0; i--) {
  //   printf("%d", result_arr[i]);
  // }
  // printf("\n");
  write_float_decimal_exp_more(result_arr, result, index, 2);
  //создаем массив в котором будет двоичная запись count_10
  int count_10_bit[8] = {0};
  count10_to_bin(&exp_1, count_10_bit);
  //запись в decimal c 16 до 23 бита в формате
  //младшие биты ближе к 16 а старшие ближе к 23
  //запись похожа на запись типа int в decimal
  for (int i = 0, j = 16; i < 8; i++, j++) {
    if (count_10_bit[i]) {
      set_1_bit(&(result->bits[3]), j);
    } else {
      set_0_bit(&(result->bits[3]), j);
    }
  }
  return 0;
}

int add_mul_1010(int *value_1_arr, int *value_2_arr, int *exp_1, int *exp_2) {
  //флаг ошибки для переполнения
  int error = 0;
  //индекс для цикла умножения и массив где будет храниться промежуточный
  //результат
  int result[NUM_255];
  int index = 0;
  int j = 2;
  int memory = 0;
  //нужен чтобы понимать какая экспонента меньше чтобы в конце цикла увеличивать
  //ее значение
  int flag = 0;
  //определяем разность показателей степеней и создаем копию массива, который
  //имеет малую экспоненту. Далее этот массив и будем умножать на 10 пока
  //экспоненты не станут равными
  int exp_delta = abs(*exp_1 - *exp_2);
  int value_min_exp[NUM_255];
  if (*exp_1 < *exp_2) {
    for (int i = 0; i < NUM_255; i++) {
      value_min_exp[i] = value_1_arr[i];
    }
    flag = 1;
  } else {
    for (int i = 0; i < NUM_255; i++) {
      value_min_exp[i] = value_2_arr[i];
    }
    flag = 2;
  }
  //умножаем на 10 (1010 в двоичной) пока дельта не станет = 0
  while (exp_delta) {
    //инициализация каждый цикл
    index = 0;
    j = 2;
    for (int i = 0; i < NUM_255; i++) {
      result[i] = 2;
    }
    //счет количества занятых битов для понимания "а можно ли вообще наше число
    //умножать на 10? А вдруг оно уже занимает 92 бита и после умножения не
    //поместится в decimal"
    int count_bit = 1;
    for (int i = 254; i >= 0; i--) {
      if (value_min_exp[i] == 1) index = 1;
      if (index) count_bit++;
    }
    //вернули индекс в прежнее значение
    index = 0;
    //если ненулевых битов больше 92 то умножать нельзя -> будет переполнение
    //ставим error в 1 и завершаем цикл
    if (count_bit > 92) {
      if (flag == 1) error = 1;
      if (flag == 2) error = 2;
      break;
    }
    //нахождение
    // for (int k = 0; k < NUM_255; k++) {
    //   if (value_min_exp[k] == 2) {
    //     index = k - 1;
    //     break;
    //   }
    // }
    // printf("\nindex bits_copy:%d\n", index);

    //последний элемент всегда 0 при умножении на 10, а следующие два элемента
    //всегда копии
    result[index] = 0;
    index++;
    result[index] = value_min_exp[index - 1];
    index++;
    result[index] = value_min_exp[index - 1];
    index++;
    //цикл сложения
    while (value_min_exp[j] != 2) {
      if (value_min_exp[j] == 1 && value_min_exp[j - 2] == 1) {
        //нет в памяти доп разряда
        if (memory == 0) {
          result[index] = 0;
          memory = 1;
        } else {
          result[index] = 1;
        }
      } else if ((value_min_exp[j] == 0 && value_min_exp[j - 2] == 1) ||
                 (value_min_exp[j] == 1 && value_min_exp[j - 2] == 0)) {
        //нет в памяти доп разряда
        if (memory == 0) {
          result[index] = 1;
        } else {
          result[index] = 0;
        }
      } else if (value_min_exp[j] == 0 && value_min_exp[j - 2] == 0) {
        //нет в памяти доп разряда
        if (memory == 0) {
          result[index] = 0;
        } else {
          result[index] = 1;
          memory = 0;
        }
      }
      index++;
      j++;
    }
    //сложение первых двух разрядов
    for (int k = 0; k <= 1; k++, j++, index++) {
      if (value_min_exp[j - 2] == 1 && memory == 1) {
        result[index] = 0;
      } else if ((value_min_exp[j - 2] == 0 && memory == 1) ||
                 (value_min_exp[j - 2] == 1 && memory == 0)) {
        result[index] = 1;
        memory = 0;
      } else if (value_min_exp[j - 2] == 0 && memory == 0) {
        result[index] = 0;
      }
    }
    if (memory == 1) {
      result[index] = 1;
      memory = 0;
    }
    //поиск начала числа в result
    // for (int k = 0; k < NUM_255; k++) {
    //   if (result[k] == 2) {
    //     index = k - 1;
    //     break;
    //   }
    // }
    //запись в правильном порядке в новый массив
    //обновляем value_min_exp
    // printf("\niteration f_b: %d bits_copy:\n", fractional_bits);
    for (int k = 0; k < NUM_255; k++) {
      value_min_exp[k] = result[k];
      // printf("%d", bits_copy[k]);
      // if (255 - ind_help == fractional_bits) {
      //   printf(".");
      // }
    }
    // for (int k = 0, control_index = 0; k < integer_bits; k++) {
    //   // flag = 1 значит нашли ненулевое начало
    //   if (bits_copy[k] != 0) flag = 1;
    //   if (flag) control_index++;
    //   //перехват переполнения который либо уже есть сейчас либо произойдет на
    //   //следующем шаге итерации
    //   if (control_index == 95 || control_index + 3 > 95) {
    //     flag = 2;
    //     break;
    //   }
    // }
    //уменьшаем дельту и увеличиваем показатель экспоненты
    exp_delta--;
    if (flag == 1) {
      *exp_1 = *exp_1 + 1;
    } else if (flag == 2) {
      *exp_2 = *exp_2 + 1;
    }
  }
  if (!error) {
    if (flag == 1) {
      for (int k = 0; k < NUM_255; k++) {
        value_1_arr[k] = value_min_exp[k];
      }
    } else if (flag == 2) {
      for (int k = 0; k < NUM_255; k++) {
        value_2_arr[k] = value_min_exp[k];
      }
    }
  }
  return error;
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

int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2) {
  return (s21_is_less(num1, num2) || s21_is_equal(num1, num2));
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

// int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
//   // int exp1;
//   // int exp2;
//   // exp1 = s21_10_conv(value_1);
//   // exp2 = s21_10_conv(value_2);
//   // if (exp1 > exp2) {
//   //   value_2 = s21_superior_10(exp1, &value_2);
//   //   s21_rev_10_conv(result, exp1);
//   // } else if (exp2 > exp1) {
//   //   value_1 = s21_superior_10(exp2, &value_1);
//   //   s21_rev_10_conv(result, exp2);
//   // }

//   int erCode = 0;  // код ошибки
//                    /*  0 - OK
//                        1 - число слишком велико или равно положительной
//                        бесконечности 2 - число слишком мало или равно
//                        отрицательной бесконечности 3 - деление на ноль  */
//   /* 1) узнаем 31 бит bits[3] обоих чисел и запоминаем */
//   int sign_op_1 = 0;
//   int sign_op_2 = 0;
//   sign_op_1 = test_bit(value_1.bits[3], 31);
//   sign_op_2 = test_bit(value_2.bits[3], 31);

//   if (sign_op_1 == sign_op_2) {  // если знаки равны
//     erCode = s21_addiction_logic(value_1, value_2, result);
//     if (sign_op_1) {  // если отрицательный знак
//       set_1_bit(&result->bits[3], 31);
//     }
//   } else {
//     set_0_bit(&value_1.bits[3], 31);
//     set_0_bit(&value_2.bits[3], 31);
//     if (s21_is_greater(value_1, value_2) == 1) {
//       // то инвертируем value_1 и складываем с value_2
//       s21_invert_mantisa(&value_1);
//       s21_addiction_logic(value_1, value_2, result);
//       if (sign_op_1) {
//         set_1_bit(&result->bits[3], 31);
//       }
//     } else {
//       // то инвертируем value_2 и складываем с value_1
//       s21_invert_mantisa(&value_2);
//       s21_addiction_logic(value_1, value_2, result);
//       if (sign_op_2) {
//         set_1_bit(&result->bits[3], 31);
//       }
//     }
//     s21_invert_mantisa(result);
//   }
//   return (erCode);
// }

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

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  double result = 0;
  int off = 0;
  for (int i = 0; i < 96; i++)
    if ((src.bits[i / 32] & (1 << i % 32)) != 0) result += pow(2, i);
  if ((off = (src.bits[3] & ~0x80000000) >> 16) > 0) {
    for (int i = off; i > 0; i--) result /= 10.0;
  }
  *dst = (float)result;
  *dst *= src.bits[3] >> 31 ? -1 : 1;
  return 0;
}

s21_decimal s21_sub_in_x(s21_decimal value_1, s21_decimal *result,
                         s21_decimal exp_result_dec) {
  int a = 0;     // бит первого числа
  int b = 0;     // бит второго числа
  int prev = 0;  // была ли единица в уме
  int next = 0;  // будем ли мы передавать единицу в след разряд
  int res;  // бит который мы запишем в результат
  // s21_decimal ten;

  // ten.bits[0] = 0b00000000000000000000000000001010;  // 10
  // ten.bits[1] = 0b00000000000000000000000000000000;
  // ten.bits[2] = 0b00000000000000000000000000000000;
  // ten.bits[3] = 0b00000000000000000000000000000000;

  int error = 0;

  if (s21_is_greater_or_equal(value_1, exp_result_dec) == 1) {
    // то инвертируем value_1 и складываем с value_2
    s21_invert_mantisa(&value_1);
    // s21_addiction_logic(value_1, ten, result);
    // if (sign_op_1) {
    //   set_1_bit(&result->bits[3], 31);
    // }
  } else {
    // то инвертируем value_2 и складываем с value_1
    // s21_invert_mantisa(&exp_result_dec);
    set_1_bit(&(result->bits[3]), 31);
    // set_0_bit(&ten.bits[3], 31);
    // s21_addiction_logic(value_1, ten, result);
    // if (sign_op_2) {
    //   set_1_bit(&result->bits[3], 31);
    // }
  }

  // s21_invert_mantisa(&value_1);
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 32; i++) {
      a = test_bit(value_1.bits[j], i);
      b = test_bit(exp_result_dec.bits[j], i);
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
      if (res) {
        set_1_bit(&(result->bits[j]), i);
      } else {
        set_0_bit(&(result->bits[j]), i);
      }
    }
  }
  s21_invert_mantisa(result);
  return *result;
}

s21_decimal division_in_10(s21_decimal value_1, s21_decimal *result,
                           s21_decimal exp_result_dec) {
  memset(result, 0, sizeof(*result));
  // s21_decimal ten;
  s21_decimal one;
  s21_decimal res;
  s21_decimal count;

  // ten.bits[0] = 0b00000000000000000000000000001010;  // 10
  // ten.bits[1] = 0b00000000000000000000000000000000;
  // ten.bits[2] = 0b00000000000000000000000000000000;
  // ten.bits[3] = 0b10000000000000000000000000000000;

  res.bits[0] = 0b00000000000000000000000000000000;  // 0
  res.bits[1] = 0b00000000000000000000000000000000;
  res.bits[2] = 0b00000000000000000000000000000000;
  res.bits[3] = 0b00000000000000000000000000000000;

  one.bits[0] = 0b00000000000000000000000000000001;  // 1
  one.bits[1] = 0b00000000000000000000000000000000;
  one.bits[2] = 0b00000000000000000000000000000000;
  one.bits[3] = 0b00000000000000000000000000000000;

  count.bits[0] = 0b00000000000000000000000000000000;  // 0
  count.bits[1] = 0b00000000000000000000000000000000;
  count.bits[2] = 0b00000000000000000000000000000000;
  count.bits[3] = 0b00000000000000000000000000000000;

  while (!test_bit(value_1.bits[3], 31)) {
    *result = s21_sub_in_x(value_1, result, exp_result_dec);
    value_1 = *result;
    // if (sign1 == 1) {
    //   set_1_bit(&result->bits[3], 31);
    if (test_bit(value_1.bits[3], 31)) {
      break;
    }
    memset(result, 0, sizeof(*result));
    s21_add(count, one, &res);
    count = res;
    // printf("\n");
    // print_2(&count);
  }
  return res;
}

int truncate(s21_decimal value, s21_decimal *result) {
  s21_decimal res_value;
  memset(result, 0, sizeof(*result));  // зануляем result
  int exp = s21_10_conv(value);        // получаем степень
  s21_decimal copy;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 32; j++) {
      if (test_bit((value.bits[i]), j)) {
        set_1_bit(&copy.bits[i], j);
      } else {
        set_0_bit(&copy.bits[i], j);
      }
    }
  }
  for (int i = 0; i < 32; i++) {
    set_0_bit(&copy.bits[3], i);
  }
  int sign = get_sign(&value);    // получаем знак
  set_0_bit(&value.bits[3], 31);  // обнуляем знак
  int exp_result = pow(10, exp);
  s21_decimal exp_result_dec;
  exp_result_dec.bits[0] = 0b00000000000000000000000000000000;  // 0
  exp_result_dec.bits[1] = 0b00000000000000000000000000000000;
  exp_result_dec.bits[2] = 0b00000000000000000000000000000000;
  exp_result_dec.bits[3] = 0b00000000000000000000000000000000;
  s21_from_int_to_decimal(exp_result, &exp_result_dec);
  print_2(&exp_result_dec);
  while (exp--) {
    memset(result, 0, sizeof(*result));
    res_value = division_in_10(copy, result, exp_result_dec);
    copy = res_value;
  }
  *result = res_value;
  return 0;
}

int main(void) {
  s21_decimal dec1;
  s21_decimal result;
  dec1.bits[0] = 0b00000000000001001111001010001001;  // 32423.3 -> 32426
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000010000000000000000;  // 1
  print_2(&dec1);
  truncate(dec1, &result);
  print_2(&result);
  // s21_sub_in_10(dec1, &result);
  // res = division_in_10(dec1, &result);
  // division_in_10(dec1, &result);
  // truncate(dec1, &result);
  return 0;
}

// 10000 10011100010000
// 99999 11000011010011111
