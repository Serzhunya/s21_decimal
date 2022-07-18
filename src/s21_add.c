#include "s21_decimal.h"

/*
    function test_bit
    Проверяет бит под номером BitNumber в переменной value
    Возвращается значение 0 (если бит = 0) или любое ненулевое значение
    (если бит = 1)
*/
int test_bit(int value, int BitNumber) { return value & (1 << BitNumber); }

/*
    function set_1_bit
    Установить бит под номером BitNumber в значение 1 в переменной value
*/
void set_1_bit(int *value, int BitNumber) { *value |= (1 << BitNumber); }

/*
    function set_0_bit
    Установить бит под номером BitNumber в значение 0 в переменной value
*/
void set_0_bit(int *value, int BitNumber) { *value &= ~(1 << BitNumber); }

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
      if ((j % 4) == 0 && j != 0) printf(" ");
    }
    printf("\n");
  }
}

/*
    function print_2_32
    Печать всех битов большой структуры
*/
void print_2_32(int *bit) {
  for (int j = 1; j <= 32; j++) {
    if (test_bit(*bit, (j - 1))) {
      printf("1");
    } else {
      printf("0");
    }
    if ((j % 4) == 0 && j != 0) printf(" ");
  }
  printf("\n");
}
//===============================================

/*
    function s21_add
    Функция сложения двух чисел типа decimal
*/
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  //обнуление result
  memset(&(result->bits), 0, sizeof(result->bits));
  //получение десятичных степеней 10 из чисел decimal
  int exp_1 = exp_decimal_bin2dec(value_1);
  int exp_2 = exp_decimal_bin2dec(value_2);
  int error = add_main(value_1, exp_1, value_2, exp_2, result);
  return error;
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
  printf("result_arr:\n");
  for (int i = 95; i >= 0; i--) {
    printf("%d", result_arr[i]);
  }
  printf("\n");
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