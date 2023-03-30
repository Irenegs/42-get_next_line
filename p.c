#include <stdio.h>

char *f(int n)
{
    static char *cache[FOPEN_MAX];

    cache[n] = "hi";
    return (cache[n]);
}

int main(void)
{
    char *s = f(3);

    printf("%s", s);
}