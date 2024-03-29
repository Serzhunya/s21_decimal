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

# Compiler config
CC 				 =	gcc

# Compilation flags configuration
ALL_TARGETS 	 = $(TARGET) $(TEST_EXE) gcov_report
ASAN 			 = 	#-fsanitize=address
UBSAN			 =	#-fsanitize=undefined
STDFLAGS 		 =	-g -c -Wall -Wextra #-std=c11 -pedantic $(C_OPTIMIZATION) #-fanalyzer #-Werror 

# Optimizaiton (https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html):
# C_OPTIMIZATION	 = -O0

# Linking flags configuration
LIBS 			 =	$(CHECK_LIB)
CHECK_LIB 		 = 	$(shell pkg-config --libs --cflags check)

# DevTools config
VG 				 = valgrind $(VG_FLAGS)
VG_FLAGS 		 = --leak-check=full --show-leak-kinds=all \
				   --track-origins=yes --verbose --log-file=$(VG_LOG)
LEAKS 			 = leaks -atExit --
VG_LOG 			 = valgrind-report.txt

# Names config
TARGET 			 =	s21_decimal.a
TEST_TARGET		 =	test_s21_decimal.a
TEST_EXE 		 =	test
TEST_GCOV_EXE	 =	test_gcov
GCOV_TARGET		 =	./coverage
GCOV_INFO		 =	coverage.info

# Modules - dirs with source code. Grep'ed dirs are excluded from search.
MODULES 		 =	$(shell find . -type d | grep -v -E "docker|objs|tests|st_test")
TEST_MODULES 	 =	$(shell find tests -type d | grep -v -E "objs")

# Dirs configuration
SRC_DIR 		 =	$(MODULES)
TEST_SRC_DIR	 =	$(TEST_MODULES)
OBJ_DIR 		 =	./objs
GCOV_OBJ_DIR	 =	./tests/gcov_obj

# Source code files configuration
SRC 			 =	$(notdir $(shell find $(SRC_DIR) -maxdepth 1 -name "s21_*.c"))
TEST_SRC 		 =  $(notdir $(shell find $(TEST_SRC_DIR) -maxdepth 1 -name "*.c"))
INC 			 =	$(shell find $(SRC_DIR) -maxdepth 1 -name "s21_*.h")
TEST_INC		 =	$(shell find $(TEST_SRC_DIR) -maxdepth 1 -name "*.h")

# Objects configuration
ALL_OBJS		 =	$(shell find . -name "*.o")
OBJS 			 =	$(notdir $(SRC:.c=.o))
TEST_OBJS 		 =	$(notdir $(TEST_SRC:.c=.o))

# GCOV-specific objects configuration
GCOV_OBJS		 =	$(addprefix $(GCOV_OBJ_DIR)/gcov_, $(notdir $(SRC:.c=.o)))
# ":=" is used here, because (1) later obj_dir changes; (2) we need objs from ./objs
GCOV_TEST_OBJS 	:=	$(addprefix $(OBJ_DIR)/, $(notdir $(TEST_SRC:.c=.o)))

# GCOV configuration
GCDA 			 = 	$(shell find . -name "*.gcda")
GCNO 			 = 	$(shell find . -name "*.gcno")
GCOV_FLAGS 		 =	-fprofile-arcs -ftest-coverage

# VPath configuration. Order of args is their priority.
vpath %.c $(MODULES) : $(TEST_MODULES)
vpath %.o $(OBJ_DIR) : $(GCOV_OBJ_DIR)

# Default system utilities
AR 	 =	ar rc
RAN  =	ranlib
RM 	 = 	rm -f
MK 	 =	mkdir -p

# Assignment of configured flags
CFLAGS 			= 	$(STDFLAGS) $(ASAN) $(UBSAN)

all 			: 	s21_decimal.a test #gcov_report

# General compilation rule
%.o 			: %.c $(INC)
				@$(MK) $(OBJ_DIR)
				@$(CC) $(CFLAGS) -o $(addprefix $(OBJ_DIR)/, $@) -c $<

# Building static library
$(TARGET) 		: $(OBJS) Makefile
				$(AR) $(TARGET) $(addprefix $(OBJ_DIR)/, $(OBJS))
				$(RAN) $(TARGET)

$(TEST_TARGET)	: $(GCOV_OBJS) $(INC)
				$(AR) $(TEST_TARGET) $(GCOV_OBJS)
				$(RAN) $(TEST_TARGET)

$(TEST_EXE) 	: $(TARGET) $(TEST_OBJS) $(TEST_INC) Makefile
				$(CC) $(addprefix $(OBJ_DIR)/, $(TEST_OBJS)) $(ASAN) $(UBSAN) $(GCOV_FLAGS) -o $(TEST_EXE) $(LIBS) -L. $(TARGET)
				./test
# GCOV stage
gcov_report 	: $(GCOV_TARGET)

# GCOV sets GCOV-specific variables & generates separate set of objects
$(GCOV_TARGET) 	: OBJ_DIR=$(GCOV_OBJ_DIR)
$(GCOV_TARGET) 	: CFLAGS += $(GCOV_FLAGS)
$(GCOV_TARGET) 	: $(GCOV_INFO)
				genhtml $(GCOV_INFO) -o $(GCOV_TARGET)

# GCOV objects compilation rule
$(GCOV_OBJ_DIR)/gcov_%.o : %.c $(INC)
				@$(MK) $(OBJ_DIR)
				@$(CC) $(CFLAGS) -o $@ -c $<

# Linking of GCOV objects
$(TEST_GCOV_EXE): $(TEST_TARGET) $(GCOV_OBJS) $(GCOV_TEST_OBJS) Makefile
				$(CC) $(GCOV_OBJS) $(GCOV_TEST_OBJS) $(GCOV_FLAGS) -o $(TEST_GCOV_EXE) $(LIBS) -L. $(TEST_TARGET)

# Launching of executable & generating HTML report
$(GCOV_INFO) 	: $(TEST_GCOV_EXE)
				./$(TEST_GCOV_EXE)
#				geninfo $(GCOV_OBJ_DIR) -b . -o ./$(GCOV_INFO)

# Utility targets
open 			:
				open coverage/index.html

clean 			:
				$(RM) $(ALL_OBJS)
				$(RM) $(GCDA)
				$(RM) $(GCNO)

fclean 			: clean
				$(RM) $(TARGET)
				$(RM) $(TEST_TARGET)
				$(RM) $(TEST_EXE)
				$(RM) $(TEST_GCOV_EXE)
				$(RM) $(GCOV_INFO)
				$(RM) $(VG_LOG)
				$(RM) -r $(GCOV_TARGET)
				$(RM) -r $(OBJ_DIR)


# DevTools
# vg				: $(TEST_EXE)
# 				$(VG) ./$(TEST_EXE)

# leaks			: $(TEST_EXE)
# 				$(LEAKS) ./$(TEST_EXE)

# Configures clangd language server for VSCode, provides jump tp implementation feature
# clangd			: fclean
# 				bear -- make

# lint 			: Makefile
# 				-cp ../materials/linters/CPPLINT.cfg .
# 				-find . -type f -name "*.c" | xargs python3 ../materials/linters/cpplint.py --extensions=c
# 				-find . -type f -name "*.h" | xargs python3 ../materials/linters/cpplint.py --extensions=c
# 				-find . -type f -name "*.c" | xargs cppcheck --enable=all --suppress=missingIncludeSystem
# 				rm -f CPPLINT.cfg

re 				: fclean all

.PHONY 			: all clean fclean re open lint vg leaks clangd