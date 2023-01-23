#include <stdio.h>
#include <stdlib.h>
#include "person.h"

int main(int argc, char *argv[])
{
    struct person me;
    me.fname = argv[1];
    me.lname = argv[2];
    me.age = atoi(argv[3]);
    me.addr.line1 = argv[4];
    me.addr.line2 = argv[5];
    me.addr.city = argv[6];
    me.addr.state = argv[7];
    me.addr.zip = argv[8];

    printf("%p", &me);

    return 0;
}
