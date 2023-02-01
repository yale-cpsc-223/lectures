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
    int *things = malloc(sizeof(int) * 256);
    int *other = things;
    free(things);
    things = calloc(129, sizeof(int));
    things = realloc(things, 256 * sizeof(int));
    things[0] = 42;
    *things = 67;
    things[16] = 99;
    *(things + 16) = 16;
    printf("%d\n", things[0]);
    printf("%d\n", things[16]);
    return 0;
}
