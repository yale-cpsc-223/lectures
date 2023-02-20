#ifndef __PERSON__H__
#define __PERSON__H__

#include <stdio.h>

typedef struct
{
    char *line1;
    char *line2;
    char *city;
    char *state;
    char *zip;
} address;

typedef struct
{
    char *fname;
    char *lname;
    unsigned age;
    address addr;
} person;

person person_from_file(FILE *fp);

void print_full_name(person p);

void print_address(person p);

#endif
