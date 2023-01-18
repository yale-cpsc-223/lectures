#! /usr/bin/env python

def factorial(n):
    f = 1
    while n > 0:
        f *= n
        n -= 1
    return f

def main():
    print(factorial(int(input())))

if __name__ == "__main__":
    main()
