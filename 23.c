#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int size = 0;
    char *a = NULL;
    if (scanf("%d ", &size))
    {
        a = (char *)malloc(sizeof(char) * (size + 1));
        scanf("%s ", a);
        for (int i = 0; a[i]; i++)
        {
            if (a[i] < 72) //special
            {
                a[i] = 90 - 6 + (a[i] - 65);
            }
            else if (a[i] < 104) //special
            {
                a[i] = 104 - 6 + (a[i] - 97);
            }
            else
            {
                a[i] -= 7; //key
            }
        }
        printf("%s\n", a);
    }
    system("pause");
    return 0;
}