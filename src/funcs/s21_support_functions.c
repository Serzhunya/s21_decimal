#include <stdint.h>

#include "s21_dec_lib.h"

/* Данная функция - shift наоборот, смещает мантису decimal влево */
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
        /*  set_1_bit(int *value, int BitNumber) { *value = *value | (1 <<
         * BitNumber); } */
        set_1_bit(&(result->bits[j]), i);
      } else {
        /*  set_0_bit(int *value, int BitNumber) { *value = *value & ~(1 <<
         * BitNumber); } */ // ЧТО ТАКОЕ "~" И КАК ОНА РАБОТАЕТ
        set_0_bit(&(result->bits[j]), i);
      }
    }
  }
  return error;
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
    // if (num1.bits[3] > num2.bits[3]) {
    //   result = 1;
    // } else {
    //   result = 0;
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
    // if (num1.bits[3] < num2.bits[3]) {
    //   result = 1;
    // } else {
    //   result = 0;
    // }
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

int get_sign(s21_decimal *num) {
  int res = -1;
  if (test_bit(num->bits[3], 31) == 0) {
    res = 0;  // если num положительный
  } else {
    res = 1;  // если num отрицательный
  }
  return res;
}

void mult_10(s21_decimal value, s21_decimal *result) {
  s21_decimal ins_val = value;
  s21_shift(&ins_val);
  *result = ins_val;
  s21_shift(&ins_val);
  s21_shift(&ins_val);
  s21_addiction_logic(*result, ins_val, result);
}
s21_decimal s21_superior_10(int power, s21_decimal *value) {
  int inferior = s21_10_conv(*value);

  s21_rev_10_conv(value, power);
  for (int i = 0; i < (power - inferior); i++) {
    mult_10(*value, value);
  }
  return (*value);
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

int test_bit(unsigned int value, int BitNumber) {
  return value & (1 << BitNumber);
}
int test_32_bit(/*uint32_t*/ int value, int BitNumber) {
  return value & (1 << BitNumber);
}

/*
    function set_1_bit
    Установить бит под номером BitNumber в значение 1 в переменной value
*/
void set_1_bit(unsigned int *value, int BitNumber) {
  *value |= (1 << BitNumber);
}
void set_1_32_bit(/*uint32_t*/ int *value, int BitNumber) {
  *value |= (1 << BitNumber);
}

/*
    function set_0_bit
    Установить бит под номером BitNumber в значение 0 в переменной value
*/
void set_0_bit(unsigned int *value, int BitNumber) { *value &= ~(1 << BitNumber); }
void set_0_32_bit(/*uint32_t*/ int *value, int BitNumber) {
  *value &= ~(1 << BitNumber);
}

/*
    function invert_bit
    Инвертировать бит под номером BitNumber (0 в 1, 1 в 0) в переменной value
*/
void invert_bit(unsigned int *value, int BitNumber) { *value ^= (1 << BitNumber); }

/*
    function is_int_negative
    Проверить знак переменной value
    Если >0 то вернет 0, а если <0 то 1
*/
int is_int_negative(int value) {
  int sign = 0;
  if (value < 0) sign = 1;
  return sign;
}

/*
    function is_float_negative
    Проверить знак переменной value
    Если >0 то вернет 0, а если <0 то 1
*/
int is_float_negative(float value) {
  int sign = 0;
  if (value < 0) sign = 1;
  return sign;
}

/*
    function first_bit_not_zero
    Возвращает индекс первого ненулевого бита для int
*/
int first_bit_not_zero_int(s21_decimal src) {
  int index = 31;
  for (; index > -1; index--) {
    if (test_bit(src.bits[0], index)) {
      break;
    }
  }
  return index;
}

//===============================================
/*
    function print_2
    Печать всех битов структуры
*/
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

/*
    function print_2_32
    Печать всех битов большой структуры
*/
void print_2_32_int(/*uint32_t*/ int *bit) {
  for (int j = 1; j <= 32; j++) {
    if (test_32_bit(*bit, (j - 1))) {
      printf("1");
    } else {
      printf("0");
    }
    if ((j % 4) == 0) printf(" ");
  }
  printf("\n");
}

//===============================================

/*
    function int_have_opposite_signs
    Если у переменных разные знаки, то вернется TRUE
*/
int int_have_opposite_signs(int valueA, int valueB) {
  return ((valueA ^ valueB) < 0);
}

/*
    function exp_decimal_bin2dec
    Перевод показателя экспоненты из двоичной в десятичную
    Необходима для получения показателя экспоненты из памяти float
    Возвращаем десятичное значение экспоненты со сдвигом относительно 127
*/
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

/*
    function float_2_bits
    Возвращает 32 битную область памяти
    в которой содержится побитовая копия числа float
*/
int float_2_bits(float src) { return ((lens_t){.flt = src}).bits; }

/*
    function exp_float_bin2dec
    Перевод показателя экспоненты из двоичной в десятичную
    Необходима для получения показателя экспоненты из памяти float
    Возвращаем десятичное значение экспоненты со сдвигом относительно 127
*/

int exp_float_bin2dec(/*uint32_t*/ int bits) {
  int exp_int = 0;
  int index = 30;
  int exp_2 = 7;
  while (index >= 23) {
    if (test_32_bit(bits, index)) {
      exp_int += pow(2, exp_2);
    }
    index--;
    exp_2--;
  }
  return exp_int;
}

/*
    function count10_to_bin
    Функция перевода степени 10 из десятичной системы в двоичную
*/
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

/*
    function get_N
    Получение N для функции float_mul_10
*/
// int get_N(int fractional_bits, int *all_bits_float) {
//   //количество 0 до первой 1 справа налево в дробной части числа
//   int N = 0;
//   //получаем N (количество 0 до первой 1 справа налево в дробной части
//   числа)
//   //идем с конца массива
//   for (int i = fractional_bits, j = 23; i > 0; i--, j--) {
//     if (all_bits_float[j] != 0) {
//       N = i;
//       break;
//     }
//   }
//   return N;
// }

/*
    function mantis_to_dec
    Перевод мантисы M без первой 1 в десятичный вид
*/
// int mantis_to_dec(int *all_bits_float) {
//   int mantis = 0;
//   for (int i = 1, index = 22; i <= 23; i++, index--) {
//     if (all_bits_float[i]) {
//       mantis += pow(2, index);
//     }
//   }
//   return mantis;
// }

/*
    function write_float_decimal_exp_less
    exp < 23
    Функция записи числа float в число типа decimal
    здесь записывается только целая часть числа без степени 10
*/
void write_float_decimal_exp_less(int *bits_copy, s21_decimal *dst, int index,
                                  int bit) {
  int i = 0;
  switch (bit) {
    case 0:
      for (; index >= 0; index--, i++) {
        if (bits_copy[i] == 1) set_1_bit(&(dst->bits[0]), index);
      }
    case 1:
      for (; index >= 32; index--, i++) {
        if (bits_copy[i] == 1) set_1_bit(&(dst->bits[1]), index);
      }
      for (; index >= 0; index--, i++) {
        if (bits_copy[i] == 1) set_1_bit(&(dst->bits[0]), index);
      }
    case 2:
      for (; index >= 64; index--, i++) {
        if (bits_copy[i] == 1) set_1_bit(&(dst->bits[2]), index);
      }
      for (; index >= 32; index--, i++) {
        if (bits_copy[i] == 1) set_1_bit(&(dst->bits[1]), index);
      }
      for (; index >= 0; index--, i++) {
        if (bits_copy[i] == 1) set_1_bit(&(dst->bits[0]), index);
      }
  }
}

/*
    function write_float_decimal_exp_more
    exp >= 23
    Функция записи числа float в число типа decimal
    здесь записывается только целая часть числа без степени 10
*/
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
    function exp_less_23
    Основная функция циклического умножения
    числа float на 10 и получении целой записи числа в двоичной системе
    счисления когда exp меньше 23 то есть есть дробная чатсь числа
*/
void exp_less_23(int *all_bits_float, int *count_10, int integer_bits,
                 int fractional_bits, s21_decimal *dst, int index_less_0) {
  // flag для нахождения целой части битовой записи и контроля не выхода за
  // диапазон 96 битов для малых чисел
  int flag = 0;
  // память для добавочных разрядов
  // при случае 1 + 1
  // сколько "1" находится в памяти над складываемыми разрядами
  int memory = 0;
  // массив куда пишем результат с конца массива
  int result[NUM_255];
  int bits_copy[NUM_255];
  // индексы массивов для цикла
  int index = 0;
  int j = NUM_255 - 3;
  int ind_help = 0;
  // инициализация
  if (!index_less_0) {
    for (int i = 0; i < NUM_255; i++) {
      result[i] = 2;
      if (i <= 23) {
        bits_copy[i] = all_bits_float[i];
      } else {
        bits_copy[i] = 2;
      }
    }
  } else {
    for (int i = 0; i < NUM_255; i++) {
      bits_copy[i] = all_bits_float[i];
    }
  }
  // printf("\nall_bits_float:\n");
  // for (int k = 0; k <= 23; k++) {
  //   printf("%d", all_bits_float[k]);
  //   if (k + 1 == integer_bits) printf(".");
  // }
  // printf("\nbits_copy init:\n");
  // for (int k = 0; k <= 23; k++) {
  //   printf("%d", bits_copy[k]);
  //   if (k + 1 == integer_bits) printf(".");
  // }
  // умножаем на 10 (1010 в двоичной) пока не избавимся от дробной части
  while (fractional_bits > 0) {
    // инициализация каждый цикл
    index = 0;
    j = NUM_255 - 3;
    for (int i = 0; i < NUM_255; i++) {
      result[i] = 2;
    }
    // нахождение
    for (int k = 0; k < NUM_255; k++) {
      if (bits_copy[k] == 2) {
        index = k - 1;
        break;
      }
    }
    // printf("\nindex bits_copy:%d\n", index);
    // последние 2 элемента всегда совпадают
    result[NUM_255 - 1] = bits_copy[index];
    result[NUM_255 - 2] = bits_copy[index - 1];
    index -= 2;
    // цикл сложения
    for (; index >= 0; index--, j--) {
      if (bits_copy[index] == 1 && bits_copy[index + 2] == 1) {
        // нет в памяти доп разряда
        if (memory == 0) {
          result[j] = 0;
          memory = 1;
        } else {
          result[j] = 1;
        }
      } else if ((bits_copy[index] == 0 && bits_copy[index + 2] == 1) ||
                 (bits_copy[index] == 1 && bits_copy[index + 2] == 0)) {
        // нет в памяти доп разряда
        if (memory == 0) {
          result[j] = 1;
        } else {
          result[j] = 0;
        }
      } else if (bits_copy[index] == 0 && bits_copy[index + 2] == 0) {
        // нет в памяти доп разряда
        if (memory == 0) {
          result[j] = 0;
        } else {
          result[j] = 1;
          memory = 0;
        }
      }
    }
    // сложение первых двух разрядов
    for (int k = 1; k >= 0; k--, j--) {
      if (bits_copy[k] == 1 && memory == 1) {
        result[j] = 0;
      } else if ((bits_copy[k] == 0 && memory == 1) ||
                 (bits_copy[k] == 1 && memory == 0)) {
        result[j] = 1;
        memory = 0;
      } else if (bits_copy[k] == 0 && memory == 0) {
        result[j] = 0;
      }
    }
    if (memory == 1) {
      result[j] = 1;
      memory = 0;
    }
    // поиск начала числа в result
    for (int k = 254; k >= 0; k--) {
      if (result[k] == 2) {
        ind_help = k + 1;
        // обновление integer_bits =
        // количество элементов в массиве (всего) - индекс начала числа (идем
        // с конца массива) - сколько осталось дробных битов - 1 (это из-за
        // того, что integer_bits не индекс, а количество)
        integer_bits = 255 - ind_help - fractional_bits + 1;
        break;
      }
    }
    // запись в правильном порядке в новый массив
    // обновляем bits_copy
    // printf("\niteration f_b: %d bits_copy:\n", fractional_bits);
    for (int k = 0; ind_help <= 254; ind_help++, k++) {
      bits_copy[k] = result[ind_help];
      // printf("%d", bits_copy[k]);
      // if (255 - ind_help == fractional_bits) {
      //   printf(".");
      // }
    }

    flag = 0;
    for (int k = 0, control_index = 0; k < integer_bits; k++) {
      // flag = 1 значит нашли ненулевое начало
      if (bits_copy[k] != 0) flag = 1;
      if (flag) control_index++;
      // перехват переполнения который либо уже есть сейчас либо произойдет на
      // следующем шаге итерации
      if (control_index == 95 || control_index + 3 > 95) {
        flag = 2;
        break;
      }
    }
    // если flag = 2 значит целая часть превышает 96 бит и нужно останавливать
    // цикл умножения и переходить к записи получившейся целой части числа в
    // decimal
    fractional_bits--;
    *count_10 = *count_10 + 1;
    if (flag == 2) break;
    if (*count_10 == 28) break;
  }
  // индекс конца bits_copy = сколько всего битов
  if (!index_less_0) {
    for (int k = 0; k <= 254; k++) {
      if (bits_copy[k] == 2) {
        index = k - 1;
        break;
      }
    }
  } else {
    // я потерял 1 десятку в малой записи числа (когда оно << 1 но > 0)
    // поэтому еще раз делаю сложение степени 10 этот костыль я уберу позже
    // *count_10 = *count_10 + 1;
    // обрезка первых нулевых битов в целой части если такие есть
    for (int k = 0; k < integer_bits; k++) {
      if (bits_copy[k] != 0) {
        // в целой части есть нулевые биты с начала числа и
        // они лишние => обрезаем их сдвигая массив влево на k элементов
        for (int q = 0; q < NUM_255 - k - 1; q++) {
          bits_copy[q] = bits_copy[q + k];
        }
        // уменьшаем integer_bits (убираем из него нули)
        // printf("\ninteger_bits: %d\n", integer_bits);
        // printf("k: %d\n", k);
        integer_bits -= k;
        break;
      }
      // если flag = 0 значит в целой части есть нулевые биты с начала числа и
      // они лишние => обрезаем их сдвигая массив на 1 элемент влево
    }
    for (int k = 0; k < 96 && k < integer_bits; k++) {
      index = k;
    }
  }
  // printf("\nresult bits_copy:\n");
  // for (int k = 0; k <= 100; k++) {
  //   printf("%d", bits_copy[k]);
  //   if (k == integer_bits - 1) printf(".");
  // }
  // printf("\n");
  // запись в decimal
  if (index < 32) {
    write_float_decimal_exp_less(bits_copy, dst, index, 0);
  } else if (32 < index && index < 64) {
    write_float_decimal_exp_less(bits_copy, dst, index, 1);
  } else if (64 < index && index < 96) {
    write_float_decimal_exp_less(bits_copy, dst, index, 2);
  }
}

/*
    function exp_more_23
    Запись float в decimal если нет дробных битов и exp >= 23
*/
void exp_more_23(int *all_bits_float, int exp, s21_decimal *dst) {
  int mantis_array[NUM_255];
  int result[NUM_255];
  int exp_2_array[NUM_255];
  int mantis_exp = exp - 23;
  // память для добавочных разрядов
  // при случае 1 + 1
  // сколько "1" находится в памяти над складываемыми разрядами
  int memory = 0;
  // инициализация
  for (int i = 0; i < 23; i++) {
    // заполнение мантисы без первой 1
    mantis_array[i] = all_bits_float[i + 1];
  }
  for (int i = 0; i < NUM_255; i++) {
    result[i] = 2;
    exp_2_array[i] = 2;
    if (i >= 23) {
      mantis_array[i] = 2;
    }
  }
  // начинаем заполнять нулями (сдвигать разряд в мантисе) с 23 индекса
  int index_mantis = 23;
  while (mantis_exp) {
    mantis_array[index_mantis] = 0;
    index_mantis++;
    mantis_exp--;
  }
  // for (int i = index_mantis - 1; i <= index_mantis; i++) {
  //   printf("mantis_array: %d \t index_mantis: %d\n", mantis_array[i], i);
  // }
  // получаем двоичную запись степени 2
  exp_2_array[0] = 1;
  int index_exp_2 = 1;
  while (exp) {
    exp_2_array[index_exp_2] = 0;
    index_exp_2++;
    exp--;
  }
  // for (int i = index_exp_2 - 1; i <= index_exp_2; i++) {
  //   printf("exp_2_array: %d \t index_exp_2: %d\n", exp_2_array[i], i);
  // }
  // складываем двоично exp_2_array и mantis_array
  // перед этим сопоставляем их по последнему элементу
  // последний элемент в mantis_array стоит на месте (index_mantis - 1)
  // последний элемент в exp_2_array стоит на месте (index_exp_2 - 1)
  // сложение записываем в result начиная с 0 индекса и двигаясь
  // поэлементно к 254
  int i = 0;
  while (index_mantis && index_exp_2) {
    if (exp_2_array[index_exp_2 - 1] == 1 &&
        mantis_array[index_mantis - 1] == 1) {
      if (memory) {
        result[i] = 1;
      } else {
        result[i] = 0;
        memory = 1;
      }
    } else if ((exp_2_array[index_exp_2 - 1] == 0 &&
                mantis_array[index_mantis - 1] == 1) ||
               (exp_2_array[index_exp_2 - 1] == 1 &&
                mantis_array[index_mantis - 1] == 0)) {
      if (memory) {
        result[i] = 0;
      } else {
        result[i] = 1;
      }
    } else if (exp_2_array[index_exp_2 - 1] == 0 &&
               mantis_array[index_mantis - 1] == 0) {
      if (memory) {
        result[i] = 1;
        memory = 0;
      } else {
        result[i] = 0;
      }
    }
    index_mantis--;
    index_exp_2--;
    i++;
  }
  // заканчиваем сложение если индексы не совпадали и мы не сложили разряды
  // какого то числа
  if (index_mantis) {
    while (index_mantis) {
      if (mantis_array[index_mantis - 1] == 1 && memory) {
        result[i] = 0;
      } else if (mantis_array[index_mantis - 1] == 0 && memory) {
        result[i] = 1;
        memory = 0;
      } else if (mantis_array[index_mantis - 1] == 1 && !memory) {
        result[i] = 1;
      } else if (mantis_array[index_mantis - 1] == 0 && !memory) {
        result[i] = 0;
      }
      index_mantis--;
      i++;
    }
  } else if (index_exp_2) {
    while (index_exp_2) {
      if (exp_2_array[index_exp_2 - 1] == 1 && memory) {
        result[i] = 0;
      } else if (exp_2_array[index_exp_2 - 1] == 0 && memory) {
        result[i] = 1;
        memory = 0;
      } else if (exp_2_array[index_exp_2 - 1] == 1 && !memory) {
        result[i] = 1;
      } else if (exp_2_array[index_exp_2 - 1] == 0 && !memory) {
        result[i] = 0;
      }
      index_exp_2--;
      i++;
    }
  }
  // вывод result
  // printf("\nresult\n");
  // for (int j = i - 1; j >= 0; j--) {
  //   printf("%d", result[j]);
  // }
  // printf("\n");
  // запись в decimal
  i--;
  if (i < 32) {
    write_float_decimal_exp_more(result, dst, i, 0);
  } else if (32 < i && i < 64) {
    write_float_decimal_exp_more(result, dst, i, 1);
  } else if (64 < i && i < 96) {
    write_float_decimal_exp_more(result, dst, i, 2);
  }
}

/*
    function exp_less_0
    Запись float в decimal если exp < 0
*/
void exp_less_0(int *all_bits_float, int *count_10, int exp, s21_decimal *dst) {
  int mantis_array[NUM_255];
  // создаем положительную экспоненту
  exp = -exp;
  // инициализация
  // целая часть = 0
  mantis_array[0] = 0;
  // заполняем сначала |-exp + 1| нулей, потом пишем 1
  // (2^{-exp}) и пишем остальные 23 нуля + записываем мантису (ее длина 23)
  for (int i = 1; i <= exp + 23; i++) {
    if (i == exp) {
      mantis_array[i] = 1;
    } else if (i > exp) {
      mantis_array[i] = all_bits_float[i - exp];
    } else {
      mantis_array[i] = 0;
    }
  }
  for (int i = 0; i < NUM_255; i++) {
    if (i > exp + 23) {
      mantis_array[i] = 2;
    }
  }
  // printf("\nmantis_array:\n");
  // for (int i = 0; i < NUM_255; i++) {
  //   printf("%d", mantis_array[i]);
  // }
  // printf("\n");
  int integer_bits = 1;
  int fractional_bits = exp + 23;
  exp_less_23(mantis_array, count_10, integer_bits, fractional_bits, dst, 1);
}

/*
    function float2decimal_main
    Основная функция перевода типа float в decimal
*/
void float2decimal_main(/*uint32_t*/ int float_bits, int exp,
                        s21_decimal *dst) {
  // счетчик количества умножения на 10
  int count_10 = 0;
  // массив копии битов + 1 от мантисы
  // заполнение от 0 до 23
  int all_bits_float[24] = {0};
  // количество битов целой части
  int integer_bits = exp + 1;
  // количество битов дробной части
  int fractional_bits = 23 - exp;
  // заполняем массив копии битов
  all_bits_float[0] = 1;
  for (int i = 1, index = 22; i <= 23; i++, index--) {
    if (test_32_bit(float_bits, index)) {
      all_bits_float[i] = 1;
    } else {
      all_bits_float[i] = 0;
    }
  }
  // умножаем на 10 пока не выделим целую часть без десятичной дроби
  if (exp < 0) {
    exp_less_0(all_bits_float, &count_10, exp, dst);
  } else if (exp < 23) {
    exp_less_23(all_bits_float, &count_10, integer_bits, fractional_bits, dst,
                0);
  } else {
    exp_more_23(all_bits_float, exp, dst);
  }

  // создаем массив в котором будет двоичная запись count_10
  int count_10_bit[8] = {0};
  count10_to_bin(&count_10, count_10_bit);
  // запись в decimal c 16 до 23 бита в формате
  // младшие биты ближе к 16 а старшие ближе к 23
  // запись похожа на запись типа int в decimal
  for (int i = 0, j = 16; i < 8; i++, j++) {
    if (count_10_bit[i]) {
      set_1_bit(&(dst->bits[3]), j);
    } else {
      set_0_bit(&(dst->bits[3]), j);
    }
  }
}

// float get_random_float(float min, float max) {
//   assert(max > min);
//   float random = ((float)rand()) / (float)RAND_MAX;
//   float range = max - min;
//   return random * range + min;
// }

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
