#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"

#define C1 0
#define C2 11
#define C3 8
#define C4 27
#define C5 35
#define C6 1992

int main(int argc, char *argv[])
{
    int n = C1;
    char name[] = {'A', 'W'};
    char *exe_name = argv[0];
    printf("[%s]\n", name);
    printf("%s\n", exe_name);
    while (scanf("%d", &n) > 0)
    {
        long fac = factorial(n);
        printf("%d! = %ld\n", n, fac);
    }
    return 0;
}
