#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 50

int min(int a, int b, int c);

int main()
{
    int size_a, size_b, size_c;
    int minsize = 0;
    char a[MAXSIZE], b[MAXSIZE], c[MAXSIZE];
    if (scanf("%s %s %s ", a, b, c))
    {
        size_a = strlen(a);
        size_b = strlen(b);
        size_c = strlen(c);
        minsize = min(size_a, size_b, size_c);
        if (minsize == size_a)
        {
            if (size_a != size_c && size_a != size_b)
                printf("%s\n", a);
            else
            {
                if (size_b == size_a)
                {
                    int flag = strcmp(a, b);
                    if (flag > 0)
                    {
                        printf("%s\n", a);
                    }
                    else if (flag < 0)
                    {
                        printf("%s\n", b);
                    }
                }
                else
                {
                    int flag = strcmp(a, c);
                    if (flag > 0)
                    {
                        printf("%s\n", a);
                    }
                    else if (flag < 0)
                    {
                        printf("%s\n", c);
                    }
                }
            }
        }
        else if (size_b == minsize)
        {
            if (size_b != size_c && size_a != size_b)
                printf("%s\n", b);
            else
            {
                if (size_b == size_a)
                {
                    int flag = strcmp(a, b);
                    if (flag > 0)
                    {
                        printf("%s\n", a);
                    }
                    else if (flag < 0)
                    {
                        printf("%s\n", b);
                    }
                }
                else
                {
                    int flag = strcmp(b, c);
                    if (flag > 0)
                    {
                        printf("%s\n", b);
                    }
                    else if (flag < 0)
                    {
                        printf("%s\n", c);
                    }
                }
            }
        }
        else
        {
            if (size_a != size_c && size_c != size_b)
                printf("%s\n", c);
            else
            {
                if (size_c == size_a)
                {
                    int flag = strcmp(a, c);
                    if (flag > 0)
                    {
                        printf("%s\n", a);
                    }
                    else if (flag < 0)
                    {
                        printf("%s\n", c);
                    }
                }
                else
                {
                    int flag = strcmp(a, c);
                    if (flag > 0)
                    {
                        printf("%s\n", a);
                    }
                    else if (flag < 0)
                    {
                        printf("%s\n", c);
                    }
                }
            }
        }
    }
    system("pause");
    return 0;
}

int min(int a, int b, int c)
{
    if (a <= c)
    {
        if (a <= b)
        {
            return a; //c>b>a or b>c>a
        }
        else
            return b; //c>a>b
    }
    else
    {
        if (c <= b)
            return c; //a>b>c or b>a>c
        else
        {
            return b; //a>c>b
        }
    }
}