CC = gcc
FLAG_C = -c
FLAG_O = -o
#ASAN = -g -O0 -fanalyzer -fsanitize=address #-fsanitize=undefined
FLAG_COV = --coverage 
FLAG_ER = -Wall -Werror -Wextra #-std=c11 -pedantic
s21_decimal_C = s21_*.c 
s21_decimal_O = s21_*.o
SUITE_CASES_C = suite_*.c
SUITE_CASES_O = suite_*.o

all: clean s21_decimal.a test gcov_report
# --- СОЗДАНИЕ БИБЛИОТЕКИ ФУНКЦИЙ ---
s21_decimal.a:
	$(CC) $(ASAN) $(FLAG_C) $(FLAG_ER) $(s21_decimal_C)
	ar rc s21_decimal.a $(s21_decimal_O)
	ranlib s21_decimal.a
# --- СОЗДАНИЕ БИБЛИОТЕКИ ТЕСТОВ И ИСПОЛНЕНИЕ ---
test: s21_decimal.a
	$(CC) $(ASAN) $(FLAG_C) $(FLAG_ER) $(SUITE_CASES_C) -g main.c
	ar rc suite_cases.a $(SUITE_CASES_O)
	ranlib suite_cases.a
	$(CC) $(ASAN) $(FLAG_ER) $(FLAG_COV) $(FLAG_O) tests s21_decimal.a suite_cases.a $(s21_decimal_C) main.o -lcheck
	./tests
# --- ФОРМИРОВАНИЕ ОТЧЕТА О ПОКРЫТИИ ---
gcov_report: test
	gcov s21_*.gcda	
	gcovr -b 
	gcovr
	gcovr --html-details -o report.html

clean:
	-rm -rf *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt tests

check:
	cppcheck *.h *.c
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h
#	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./tests
	CK_FORK=no leaks --atExit -- ./tests
