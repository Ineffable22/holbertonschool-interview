CC = gcc
CFLAGS = -no-pie -Wall -pedantic -Werror -Wextra
LIB = libloop.a
TEST_FILES = main_0.c main_1.c main_2.c main_3.c main_4.c main_5.c main_6.c

all: 
	$(foreach var, $(TEST_FILES), cp test/$(var) . && $(CC) $(CFLAGS) $(var) 0-find_loop.c $(LIB) && echo && ./a.out && rm $(var) a.out;)

betty:
	betty test/*.c *.c *.h
