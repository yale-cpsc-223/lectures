#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"

int main(int argc, char *argv[])
{
    int n;
    while (scanf("%d", &n) > 0)
    {
        long fac = factorial(n);
        printf("%d! = %ld\n", n, fac);
    }
    return 0;
}
