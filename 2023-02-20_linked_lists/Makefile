CC = gcc
CFLAGS = -std=c99 -Wall -pedantic -Werror -g

.PHONY: clean

main : main.o
	${CC} ${CFLAGS} -o $@ $^

main_list : main_list.o list/linked_list_1.o
	${CC} ${CFLAGS} -o $@ $^

clean : 
	rm -rf *.{o,a}
	rm -rf list/*.{o,a}
