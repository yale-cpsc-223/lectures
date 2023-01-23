#ifndef __PERSON__H__
#define __PERSON__H__

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

#endif
