#include "person.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

person person_from_file(FILE *fp)
{
    person p;
    p.fname = malloc(sizeof(char) * 65);
    p.lname = malloc(sizeof(char) * 65);
    p.addr.line1 = malloc(sizeof(char) * 65);
    p.addr.line2 = malloc(sizeof(char) * 65);
    p.addr.city = malloc(sizeof(char) * 65);
    p.addr.state = malloc(sizeof(char) * 3);
    p.addr.zip = malloc(sizeof(char) * 11);
    scanf("%64s %64s %d %64[^\n]s %64[^\n]s %64[^\n]s %2[^\n]s %10[^\n]s", p.fname, p.lname, &(p.age), p.addr.line1, p.addr.line2, p.addr.city, p.addr.state, p.addr.zip);
    return p;
}

void print_full_name(person p)
{
    printf("%s %s\n", p.fname, p.lname);
}

void print_address(person p)
{
    address addr = p.addr;
    printf("%s\n%s\n%s, %s %s\n", addr.line1, addr.line2, addr.city, addr.state, addr.zip);
}
