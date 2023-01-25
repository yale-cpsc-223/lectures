# C Compiler and Flags
CC =     gcc
CFLAGS = -std=c17 -Wall -pedantic -g

.PHONY: clean

Factorial: main.o ifactorial.o
	${CC} ${CFLAGS}	-o $@ $^

arrays/Factorial: arrays/main.o arrays/factorial.o
	${CC} ${CFLAGS} -o $@ $^

structs/Person: structs/main.o structs/person.o
	${CC} ${CFLAGS} -o $@ $^

clean:
	rm -f *.o
	rm -f Factorial Hello
