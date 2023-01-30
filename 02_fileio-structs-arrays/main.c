#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"

#define N1 0
#define N2 11
#define N3 8
#define N4 27
#define N5 35
#define N6 1992

int main(int argc, char *argv[])
{
    int n = N1;
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
