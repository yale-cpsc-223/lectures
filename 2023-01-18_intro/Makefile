# C Compiler and Flags
CC =     gcc
CFLAGS = -std=c17 -Wall -pedantic -g

# C++ Compiler and Flags
CXX =      g++
CXXFLAGS = -std=c++17 -Wall -pedantic -g

.PHONY: clean

Factorial: main.o factorial.o
	${CC} ${CFLAGS}	-o $@ $^

Factorial: factorial.c
	${CC} ${CFLAGS} -o $@ $^

clean:
	rm -rf *.o
	rm -rf Factorial
