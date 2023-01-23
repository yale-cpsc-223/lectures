#include "factorial.h"

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
