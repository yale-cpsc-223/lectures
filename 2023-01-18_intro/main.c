#include <stdio.h>
#include "factorial.h"

int main(int argc, char *argv[])
{
  int n = atoi(argv[1]);
  long answer = factorial(n);
  printf("%ld\n", answer);
  return 0;
}
