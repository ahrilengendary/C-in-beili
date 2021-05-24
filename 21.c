#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 225

void delete (char *str, int a);

int main()
{
    int size = 0;
    char str[MAXSIZE] = {0};
    size = strlen(str);

    if (gets(str))
    {
        while (isspace(str[0]))
        {
            delete (str, 0);
        }
        if (str[0] >= 97 && str[0] <= 122)
        {
            str[0] -= 32;
        }
        for (int i = 1; str[i]; i++)
        {
            if (str[i] >= 65 && str[i] <= 90)
            {
                str[i] += 32;
            }
        }
        for (int i = 0; str[i]; i++)
        {
            if (!isalpha(str[i]))
            {
                while ((isspace(str[i]) && ispunct(str[i + 1])) ||
                       (isspace(str[i]) && isspace(str[i + 1])))
                {
                    delete (str, i);
                }
            }
        }
        while (isspace(str[size - 1]))
        {
            delete (str, size - 1);
        }
        printf("%s\n", str);
    }

    system("pause");
    return 0;
}

void delete (char *str, int a)
{
    for (int i = a; str[i]; i++)
    {
        str[i] = str[i + 1];
    }
}