#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"

int main(int argc, char *argv[])
{
    int n = 1992;
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
