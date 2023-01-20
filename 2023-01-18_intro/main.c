#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"

int main(int argc, char *argv[])
{
    FILE *in = fopen(argv[1], "r");
    int n;
    while (fscanf(in, "%d", &n) == 1)
    {
        long answer = factorial(n);
        fprintf(stdout, "%ld\n", answer);
    }
    return 0;
}
