#include "factorial.h"

long factorial(int n)
{
    long fac = 1;
    while (n > 0)
    {
        fac *= n;
        n--;
    }
    return fac;
}
