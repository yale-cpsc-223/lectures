#include <stdio.h>

long long factorial(int n)
{
  long long f = 1;
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
  printf("\n%lld\n", factorial(n));
  return 0;
}
