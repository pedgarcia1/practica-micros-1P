#include<stdio.h>
size_t strlen(const char *s);
void main()
{
    char *s = "EMIT";
    char r[100];
    int n,c,d;
    n = strlen(s);

    for (c = n-1,d=0; c >= 0 ; c--,d++)
    {
        r[d] = s[c];
    }
    r[d] = '\0';
    printf("%s\n",r);
}
size_t strlen(const char *s)
{
    size_t n = 0;

    while (*s++)
        n++;
    return n;
}