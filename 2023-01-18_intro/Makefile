# C Compiler and Flags
CC =     gcc
CFLAGS = -std=c17 -Wall -pedantic -g

# C++ Compiler and Flags
CXX =      g++
CXXFLAGS = -std=c++17 -Wall -pedantic -g

Factorial: factorial.c
	${CC} ${CFLAGS} -o $@ $^

Factorial: factorial.o libfactorial.o
	${CC} ${CFLAGS}	-o $@ $^

factorial.o:

libfactorial.o:

clean:
	rm -f *.o
	rm -f Factorial Hello
