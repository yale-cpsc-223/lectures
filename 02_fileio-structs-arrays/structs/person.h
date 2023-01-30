#ifndef __PERSON__H__
#define __PERSON__H__

#include <stdio.h>

struct address
{
    char *line1;
    char *line2;
    char *city;
    char *state;
    char *zip;
};

struct person
{
    char *fname;
    char *lname;
    unsigned age;
    struct address addr;
};

// struct person person_from_file(FILE *fp);

void print_full_name(struct person p);

void print_address(struct person p);

#endif
