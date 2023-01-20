CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic -g

.PHONY: clean

Factorial: main.c factorial.o
	${CC} ${CFLAGS} -o $@ $^

Hello: hello.c
	${CC} ${CFLAGS} -o $@ $^

clean:
	rm -rf *.o
	rm -rf Factorial
	rm -rf Hello
