#include "s21_dec_lib.h"

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
  // индекс указывающий какого знака поданные числа value_1 и value_2
  // соответственно
  // 1 : + и +
  // 2 : - и -
  // 3 : + и -
  // 4 : - и +
  int sign_index = 0;
  //проверка знаков чисел и выставление sign_index
  if (test_bit(value_1.bits[3], 31) == 0 &&
      test_bit(value_2.bits[3], 31) == 0) {
    sign_index = 1;
  } else if (test_bit(value_1.bits[3], 31) && test_bit(value_2.bits[3], 31)) {
    sign_index = 2;
  } else if (test_bit(value_1.bits[3], 31) == 0 &&
             test_bit(value_2.bits[3], 31)) {
    sign_index = 3;
  } else if (test_bit(value_1.bits[3], 31) &&
             test_bit(value_2.bits[3], 31) == 0) {
    sign_index = 4;
  }
  //если sign_index = 3 или 4 то нужно определить максимальное по модулю из двух
  //чисел. Это необходимо для выставления правильного знака результата
  int greater = -1;
  // printf("\nsign_index output: %d\n", sign_index);
  if (sign_index == 3 || sign_index == 4) {
    //если greater = 1 то value_1 > value_2
    //если greater = 0 то либо они равны либо value_1 < value_2
    greater = s21_is_greater_num(value_1, value_2, greater);
  }
  // printf("\ngreater output: %d\n", greater);
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
  //если error = 123 значит переполнение мантисы и в зависимости от знаков двух
  //чисел возвращаем ошибку 1 или 2
  error = add_mul_1010(value_1_arr, value_2_arr, &exp_1, &exp_2);
  // printf("add error: %d\n", error);
  if (error == 123 && sign_index == 1) {
    return 1;
  } else if (error == 123 && sign_index == 2) {
    return 2;
  }
  //переменные для подсчета и контроля количества битов. Это необходимо для
  //отлавливания переполнения и банковского округления
  int count_bit_1 = 0;
  int count_bit_2 = 0;
  // count_bit = количество битов в большем числе
  int count_bit = 0;
  int index_1 = 0;
  int index_2 = 0;
  // printf("value_1_arr\n");
  for (int i = 254; i >= 0; i--) {
    if (value_1_arr[i] == 1) index_1 = 1;
    if (value_2_arr[i] == 1) index_2 = 1;
    if (index_1) {
      count_bit_1++;
      // printf("%d", value_1_arr[i]);
    }
    if (index_2) count_bit_2++;
  }

  for (int i = 0; i < NUM_255; i++) {
    if (value_2_arr[i] == 2) value_2_arr[i] = 0;
  }
  // printf("\nvalue_2_arr\n");
  // for (int i = 103; i >= 0; i--) {
  //   printf("%d", value_2_arr[i]);
  // }

  if (count_bit_1 > count_bit_2) {
    count_bit = count_bit_1;
  } else if (count_bit_1 < count_bit_2) {
    count_bit = count_bit_2;
  } else {
    count_bit = count_bit_1;
  }
  // printf("\ncount_bit_1 %d\n", count_bit_1);
  // printf("count_bit_2 %d\n", count_bit_2);
  // printf("count_bit %d\n", count_bit);
  //производим сложение до count_bit бита если знаки двух чисел + и + или - и -
  if (exp_1 == exp_2 && (sign_index == 1 || sign_index == 2)) {
    for (; index < count_bit; index++) {
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
    //проверяем остался ли неучтенный разряд в memory
    //формально я не должен складывать дальше а должен вывести ошибку что
    //число слишком велико и не помещается в decimal
    if (memory) {
      result_arr[index] = 1;
      count_bit++;
      memory = 0;
    } else {
      //возвращаю index значение (count_bit - 1) тк после цикла он равен
      // count_bit
      index--;
    }
  } else if (exp_1 == exp_2 && (sign_index == 3 || sign_index == 4)) {
    //вычитание из большего меньшего (по модулю)
    if (greater == 1) {
      for (; index < count_bit; index++) {
        if (value_1_arr[index] == 0 && value_2_arr[index] == 0) {
          result_arr[index] = 0;
        } else if (value_1_arr[index] == 1 && value_2_arr[index] == 0) {
          result_arr[index] = 1;
        } else if (value_1_arr[index] == 0 && value_2_arr[index] == 1) {
          //цикл для реализации ситуации когда (10000 - 1010) и 1 нужно брать не
          //из соседнего разряда
          for (int j = index + 1; j >= 0; j++) {
            if (value_1_arr[j] == 0) {
              value_1_arr[j] = 1;
            } else if (value_1_arr[j] == 1) {
              value_1_arr[j] = 0;
              break;
            }
          }
          result_arr[index] = 1;
        } else if (value_1_arr[index] == 1 && value_2_arr[index] == 1) {
          result_arr[index] = 0;
        }
      }
    } else if (greater == 0) {
      for (; index < count_bit; index++) {
        if (value_2_arr[index] == 0 && value_1_arr[index] == 0) {
          result_arr[index] = 0;
        } else if (value_2_arr[index] == 1 && value_1_arr[index] == 0) {
          result_arr[index] = 1;
        } else if (value_2_arr[index] == 0 && value_1_arr[index] == 1) {
          //цикл для реализации ситуации когда (10000 - 1010) и 1 нужно брать не
          //из соседнего разряда
          for (int j = index + 1; j >= 0; j++) {
            if (value_2_arr[j] == 0) {
              value_2_arr[j] = 1;
            } else if (value_2_arr[j] == 1) {
              value_2_arr[j] = 0;
              break;
            }
          }
          result_arr[index] = 1;
        } else if (value_2_arr[index] == 1 && value_1_arr[index] == 1) {
          result_arr[index] = 0;
        }
      }
    }
  }
  // printf("result_arr:\n");
  // for (int i = count_bit; i >= 0; i--) {
  //   printf("%d", result_arr[i]);
  // }
  // printf("\n");
  //вторая проверка переполняемости decimal. Добавлена для случая когда
  //складываются 2 больших числа, не близких к максимальному, но дающие
  //результат, больше максимального

  // банковское округление
  //делим результат на 10 пока он не поместиться в децимал
  //занулим индекс начала result_arr (для этого будем использовать старый
  // index_1) index_2 используем для понимания сколько раз нужно поделить на
  // 1010, чтобы выделить целую часть числа
  index_2 = exp_1;
  if (count_bit > 96) {
    while (count_bit > 96) {
      index_1 = 0;
      //если выделили целую часть числа и оно больше 96 бит, значит переполнение
      if (!index_2) {
        count_bit = 0;
        for (int i = 254; i >= 0; i--) {
          if (result_arr[i] == 1) index_1 = 1;
          if (index_1) {
            count_bit++;
          }
        }
        if (count_bit > 96) {
          error = 123;
          break;
        }
      }
      add_div_10(result_arr, &exp_1, &count_bit);
      //обновление count_bit
      count_bit = 0;
      for (int i = 254; i >= 0; i--) {
        if (result_arr[i] == 1) index_1 = 1;
        if (index_1) {
          count_bit++;
        }
      }
      // printf("\ncount_bit %d\n", count_bit);
      index_2--;
    }
    // printf("\n");
  }
  //еще раз проверяем на переполнение
  // printf("add error: %d\n", error);
  if (error == 123 && sign_index == 1) {
    return 1;
  } else if (error == 123 && sign_index == 2) {
    return 2;
  }
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
  //ставим 31 бит отвечающий за знак в 1 если sign_index == 2 (то есть сложили
  //два отрицательных числа)
  if (sign_index == 2) {
    set_1_bit(&(result->bits[3]), 31);
  }
  //случай когда + и - (- больше) число должно быть отрицательным, но если числа
  //были равны, то может быть 0, а значит нужно проверить result_arr. Если там
  //не будет 1, значит это 0 и ставить отрицательный знак не нужно. За это будет
  //отвечать переменная check_equal
  int check_equal = 0;
  if (sign_index == 3 && greater == 0) {
    for (int i = 0; i < NUM_255; i++) {
      if (result_arr[i] == 1) {
        check_equal = 1;
        break;
      }
    }
    if (check_equal) set_1_bit(&(result->bits[3]), 31);
  } else if (sign_index == 4 && greater == 1) {
    //когда - и + (- больше)
    set_1_bit(&(result->bits[3]), 31);
  }
  return 0;
}
