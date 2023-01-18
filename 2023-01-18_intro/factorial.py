#! /usr/bin/env python

def factorial(n):
    f = 1
    while n > 0:
        f *= n
        n -= 1
    return f

print(factorial(int(input())))
