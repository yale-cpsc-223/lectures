#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"

int main(int argc, char *argv[])
{
    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");
    int n;
    while (fscanf(in, "%d", &n) == 1)
    {
        long answer = factorial(n);
        fprintf(out, "%ld\n", answer);
    }
    fclose(in);
    fclose(out);
    return 0;
}
