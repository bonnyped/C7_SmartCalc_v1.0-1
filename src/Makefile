СС			= gcc 
LM			= -lm
GFLAGS		= -fno-stack-protector -Wall -Werror -Wextra -std=c11
TARGET		= s21_smart_calc.a
CLEAN		= rm -rf
CLANG		= clang-format --style=google
TO_CLANG	= *.c *.h
SRC			= $(wildcard *.c)
OBJ			= $(patsubst %.c, %.o, $(SRC))
TEST_FLAGS	= $(shell pkg-config --cflags --libs check)
OS		   := $(shell uname -s)

PREF_TEST	= ./tests/
PREF_GCOV	= ./gcov/
PREF_QT		= ./s21_calc/

all: clean $(TARGET) test clang gcov_report open install

$(TARGET): $(OBJ)
	ar rc $(TARGET) *.o
	$(CLEAN) *.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(PREF_TEST)test.o $(TARGET)
	$(CC) $(PREF_TEST)test.o $(TARGET) $(LM) -o $(PREF_TEST)test -L. $(TEST_FLAGS) 
	$(CLEAN) $(PREF_TEST)*.o *.o
	$(PREF_TEST)test

$(PREF_TEST)test.o: $(PREF_TEST)test.c
	$(CC) -o $(PREF_TEST)test.o -g -c $(PREF_TEST)test.c  

$(PREF_TEST)test.c:
	$(CLEAN) $(PREF_TEST)test $(PREF_TEST)*.c
	checkmk clean_mode=1 $(PREF_TEST)include.file $(PREF_TEST)*.check > $(PREF_TEST)test.c 
	$(CLANG) $(PREF_TEST)$(TO_CLANG) -i

gcov_report: clean $(PREF_TEST)test.c
	mkdir $(PREF_GCOV)
	$(CC) -fprofile-arcs -ftest-coverage $(PREF_TEST)test.c $(SRC) -o $(PREF_GCOV)gcov_report $(TEST_FLAGS) $(LM)
	$(PREF_GCOV)gcov_report
	lcov -t "test" -o $(PREF_GCOV)test.info -c -d .
	genhtml -o report $(PREF_GCOV)test.info
	$(CLEAN) ./*.gcda  ./*.gcno $(PREF_GCOV)*.gcda  $(PREF_GCOV)*.gcno
ifeq ($(OS),Darwin)
	open -a "Google Chrome" report/index.html
else
	xdg-open report/index.html
endif

open:
ifeq ($(OS),Darwin)
	open -a "Google Chrome" report/index.html
else
	xdg-open report/index.html
endif

install:
	cd $(PREF_QT) && qmake6 && make && make clean

uninstall:
	cd $(PREF_QT) && make distclean

exe:
	cd $(PREF_QT) && ./s21_calc

allinstall:
	cd $(PREF_QT) && make distclean && qmake6 && make && make clean && ./s21_calc

.dvi:
ifeq ($(OS),Darwin)
	open -a "Google Chrome" dvi/doc.txt
else
	xdg-open dvi/doc.txt
endif

leak: test
ifeq ($(OS),Darwin)
	leaks -atExit -- $(PREF_TEST)test
else
	valgrind -s --leak-check=full --log-file=leak.log $(PREF_TEST)test 
endif 

clang:
	$(CLANG) $(TO_CLANG) -n
	$(CLANG) $(TO_CLANG) -i

clean:
	$(CLEAN) *.o *.out *.a $(PREF_TEST)test.o $(PREF_TEST)test.c report *.log $(PREF_TEST)*.info $(PREF_TEST)test $(PREF_GCOV) ./dvi/*.swp
