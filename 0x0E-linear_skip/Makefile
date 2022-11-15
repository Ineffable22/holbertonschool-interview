all:
	cp files/0-main.c .
	cp files/create_skiplist.c .
	cp files/free_skiplist.c .
	cp files/print_skiplist.c .
	gcc -Wall -Wextra -Werror -pedantic *.c -lm -o 0-linear_skip
	./0-linear_skip
	rm 0-linear_skip 0-main.c create_skiplist.c free_skiplist.c print_skiplist.c

gdb:
	cp files/0-main.c .
	cp files/create_skiplist.c .
	cp files/free_skiplist.c .
	cp files/print_skiplist.c .
	gcc -Wall -Wextra -Werror -pedantic *.c -g -lm -o 0-linear_skip
	gdb ./0-linear_skip

betty:
	betty files/*.c 0-linear_skip.c search.h

clean:
	rm -f 0-linear_skip 0-main.c create_skiplist.c free_skiplist.c print_skiplist.c
