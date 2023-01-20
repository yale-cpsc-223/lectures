#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"

int main(int argc, char *argv[])
{
    FILE *in, *out;
    if (argc > 1)
    {
        in = fopen(argv[1], "r");
    }
    else
    {
        in = stdin;
    }

    if (argc > 2)
    {
        out = fopen(argv[2], "w");
    }
    else
    {
        out = stdout;
    }
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
