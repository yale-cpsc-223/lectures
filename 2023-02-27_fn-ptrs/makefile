CC = gcc
CFLAGS = -std=c99 -Wall -pedantic -Werror -g

.PHONY: clean

main : main.o list/array_list.a mergesort.o list_print.o
	${CC} ${CFLAGS} -o $@ $^

list/array_list.a : list/array_list.o list/array_helpers.o list/list.h list/array_helpers.h
	ar rcs $@ $(filter %.o,$^)

clean : 
	rm -rf *.{o,a}
	rm -rf list/*.{o,a}
