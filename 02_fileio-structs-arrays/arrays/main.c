#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    int nums[n];
    for (size_t i = 0; i < n; i++)
    {
        nums[i] = i;
    }

    long factorials[n];
    factorials[0] = 1;
    for (int i = 1; i < n; i++)
    {
        factorials[i] = nums[i] * factorials[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        printf("%2d! = %ld\n", nums[i], factorials[i]);
    }
    return 0;
}
