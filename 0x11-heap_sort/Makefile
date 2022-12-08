CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
OFLAG = -o
CFILE = 0-heap_sort.c
BETTY = betty

DIR = files/
TEST = 0-main.c
PRINT = print_array.c
NEW = 0-heap

all:
	cp $(DIR)$(TEST) $(DIR)$(PRINT) .
	$(CC) $(CFLAGS) $(TEST) $(CFILE) $(PRINT) $(OFLAG) $(NEW)
	./$(NEW)
	rm $(NEW) $(TEST) $(PRINT)

betty:
	$(BETTY) $(CFILE) $(DIR)$(TEST) $(DIR)$(PRINT)
