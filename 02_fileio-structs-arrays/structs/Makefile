# C Compiler and Flags
CC =     gcc
CFLAGS = -std=c17 -Wall -pedantic -g

.PHONY: clean

Person: main.o person.o
	${CC} ${CFLAGS} -o $@ $^

clean:
	rm -f *.o
	rm -f Person
