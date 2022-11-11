CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
CFILES = 0-sorted_array_to_avl.c
SUP = binary_tree_print.c
HEADER = binary_trees.h
NAME = 0-sorted_array_to_avl
FILE = 0-main.c
GDB = gdb
BETTY = betty


all: *.c *.h betty 0 clean

0:
	cp files/$(FILE) .
	cp files/$(SUP) .
	$(CC) $(CFLAGS) $(CFILES) $(SUP) $(FILE) -o $(NAME)
	./$(NAME)

gdb:
	cp files/$(FILE) .
	$(CC) $(CFLAGS) $(CFILES) -g $(FILE) -o $(NAME)
	gdb ./$(NAME)

betty:
	betty $(CFILES) $(HEADER) files/$(FILE) files/$(SUP)

clean:
	rm $(FILE) $(NAME) $(SUP)
