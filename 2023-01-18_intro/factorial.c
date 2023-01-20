#include <stdio.h>
#include "libfactorial.c"

int main()
{
  int n;
  scanf("%d", &n);
  printf("%ld\n", factorial(n));
  return 0;
}
