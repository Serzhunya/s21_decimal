# CC = gcc
# FLAG_C = -c
# FLAG_O = -o
# #ASAN = -g -O0 -fanalyzer -fsanitize=address #-fsanitize=undefined
# FLAG_COV = --coverage 
# FLAG_ER = -Wall -Werror -Wextra #-std=c11 -pedantic
# s21_decimal_C = s21_*.c 
# s21_decimal_O = s21_*.o
# SUITE_CASES_C = suite_*.c
# SUITE_CASES_O = suite_*.o

# all: clean s21_decimal.a test gcov_report
# # --- СОЗДАНИЕ БИБЛИОТЕКИ ФУНКЦИЙ ---
# s21_decimal.a:
# 	$(CC) $(ASAN) $(FLAG_C) $(FLAG_ER) $(s21_decimal_C)
# 	ar rc s21_decimal.a $(s21_decimal_O)
# 	ranlib s21_decimal.a
# # --- СОЗДАНИЕ БИБЛИОТЕКИ ТЕСТОВ И ИСПОЛНЕНИЕ ---
# test: s21_decimal.a
# 	$(CC) $(ASAN) $(FLAG_C) $(FLAG_ER) $(SUITE_CASES_C) -g main.c
# 	ar rc suite_cases.a $(SUITE_CASES_O)
# 	ranlib suite_cases.a
# 	$(CC) $(ASAN) $(FLAG_ER) $(FLAG_COV) $(FLAG_O) tests s21_decimal.a suite_cases.a $(s21_decimal_C) main.o -lcheck
# 	./tests
# # --- ФОРМИРОВАНИЕ ОТЧЕТА О ПОКРЫТИИ ---
# gcov_report: test
# 	gcov s21_*.gcda	
# 	gcovr -b 
# 	gcovr
# 	gcovr --html-details -o report.html

# clean:
# 	-rm -rf *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt tests

# check:
# 	cppcheck *.h *.c
# 	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
# 	python3 ../materials/linters/cpplint.py --extension=c *.c *.h
# #	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./tests
# 	CK_FORK=no leaks --atExit -- ./tests






#===================================================================================================

# - ПЕРЕМЕННЫЕ - 

#ASAN = -fsanitize=address 
#UBSAN = -fsanitize=undefined
FLAGS = -g -c -Wall -Wextra -std=c11 #-pedantic -O0 $(ASAN) $(UBSAN) -fanalyzer -Werror

OBJ_DIR = ./funcs/funcs_objs
TEST_OBJ_DIR = ./tests/test_objs

# нохождение папки src:													\
shell 		  															\
find   		  															\
. 			  															\
-type d       															\
-v		      															\
-E 
MODULES = $(shell find . -type d | grep -v -E "tests")
SRC_DIR = $(MODULES)
# нахождение папки tests
TEST_MODULES = $(shell find . -type d | grep -v -E "funcs")
TEST_SRC_DIR = $(TEST_MODULES)

# поиск всех сишных файлов проекта \
notdir \
-maxdepth \
-name
SRC 			 =  $(notdir $(shell find $(SRC_DIR) -maxdepth 1 -name "s21_*.c"))
TEST_SRC 	     =  $(notdir $(shell find $(TEST_SRC_DIR) -maxdepth 1 -name "*.c"))
# поиск хедера для сишных файлов библиотеки децимал
INC 			 =	$(shell find $(SRC_DIR) -maxdepth 1 -name "s21_*.h")
TEST_INC		 =	$(shell find $(TEST_SRC_DIR) -maxdepth 1 -name "*.h")

# переменная OBJS сохдает текстовый запрос который: 			   								   \
					1) формирует текстовую строку из имен всех файлов ".c" 						   \
					2) меняет их расширение на ".o" 	 				   						   \
					3) и убирает из их названий путь	
OBJS = $(notdir $(SRC:.c=.o))
TEST_OBJS = $(notdir $(TEST_SRC:.c=.o))

# задаем основному правилу компиляции путь для поиска сишных файлов
vpath %.c $(MODULES) : $(TEST_MODULES)

vpath %.o $(OBJ_DIR) : $(TEST_OBJ_DIR)

all					: s21_decimal.a test_s21_decimal.a
# основное правило компиляции \
addprefix \
$@ \
$< \
%
%.o 				: %.c $(INC)
					@mkdir -p $(OBJ_DIR)
					@gcc $(FLAGS) -o $(addprefix $(OBJ_DIR)/, $@) -c $<
# создание статической библиотеки децимал \
ar rc \
ranlib 
s21_decimal.a 		: $(OBJS)
					@ar rc s21_decimal.a $(addprefix $(OBJ_DIR)/, $(OBJS))
					ranlib s21_decimal.a


# создание статической библиотеки тестов

test_s21_decimal.a  : OBJ_DIR=$(TEST_OBJ_DIR)
test_s21_decimal.a	: $(TEST_OBJS)
					@ar rc test_s21_decimal.a $(addprefix $(OBJ_DIR)/, $(TEST_OBJS))
					ranlib test_s21_decimal.a

test				:
gcov_report    		:
clean				: 
					rm -rf ./funcs/objs
					rm -rf ./tests/objs
					rm -f s21_decimal.a test_s21_decimal.a
