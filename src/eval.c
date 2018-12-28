#include <eval.h>

int stringLength(const char *s)
{
    for (int i = 0; i < 1e9; i++)
    {
        if (s[i] == '\0')
        {
            return i;
        }
    }
    return -1;
}

int intLength(int a)
{
    int test;
    int length, divisor;
    length = 0;
    divisor = 1;
    while ((a / divisor) > 0)
    {
        length++;
        divisor = divisor * 10;
    }
    return length; 
}

void cloneArray(int n, const int *original, int **copy)
{
    *copy = (int*)malloc(n*4);
    for (int i = 0; i < n; i++)
    {
        (*copy)[i] = original[i];
    }
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}