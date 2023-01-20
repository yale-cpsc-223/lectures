#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1)
  {
    long answer = factorial(n);
    printf("%ld\n", answer);
  }
  return 0;
}
