0:
	cp files/0-main.c .
	gcc -Wall -Wextra -Werror -pedantic -o 0-menger 0-menger.c 0-main.c -lm
	./0-menger -1
	./0-menger -0
	./0-menger 0
	./0-menger 1
	./0-menger 2
	./0-menger 3
	./0-menger 4
	rm 0-main.c

betty:
	betty *.c files/*.c

clean:
	rm -f 0-menger
