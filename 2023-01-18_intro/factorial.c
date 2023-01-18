#include <stdio.h>

long factorial(int n)
{
  long f = 1;
  while (n > 0)
  {
      f *= n;
      n--;
  }
  return f;
}

int main()
{
  int n;
  scanf("%d", &n);
  printf("%ld\n", factorial(n));
  return 0;
}
