CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic -g

CXX=g++
CXXFLAGS="-std=c++17 -Wall -Werror -pedantic -g"

Hello: hello.c
	${CC} ${CFLAGS} -o $@ $^

Factorial: factorial.o libfactorial.o
	${CC} ${CFLAGS}	-o $@ $^

factorial.o: factorial.c

libfactorial.o: libfactorial.c

clean:
	rm -f *.o
	rm -f Factorial Hello
