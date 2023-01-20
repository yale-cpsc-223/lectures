#include <stdio.h>
#include "factorial.h"

int main()
{
  int n;
  scanf("%d", &n);
  printf("%ld\n", factorial(n));
  return 0;
}
