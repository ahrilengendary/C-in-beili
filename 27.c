#include <stdio.h>
#include <stdlib.h>

#define maxsize 100

int main()
{
    int total = 0;
    int row = 0;
    scanf("%d ", &total);

    int book[maxsize][total];
    int remain[total];

    //initial
    for (int i = 0; i < total; i++)
    {
        remain[i] = 0;
    }
    for (int i = 0; i < maxsize; i++)
    {
        for (int j = 0; j < total; j++)
        {
            book[i][j] = 0;
        }
    }

    int i = 0;
    int j = 0;
    for (j = 0; scanf("%d ", &book[j][i]); j++, row++)
    {

        for (i = 1; i < total; i++)
        {
            scanf("%d ", &book[j][i]);
        }
        i = 0; //reset
    }

    //for checking
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < total; j++)
    //     {
    //         printf("%d ", book[i][j]);
    //     }
    //     printf("\n");
    // }

    int change[row][total];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < total; j++)
        {
            change[i][j] = 0;
        }
    }

    for (int i = 1; i < row; i++)
    {
        for (int j = 0; j < total; j++)
        {
            if (book[i][j] != book[0][j])
            {
                change[i][j] = book[i][j];
            }
        }
    }

    // for checking
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < total; j++)
    //     {
    //         printf("%d ", change[i][j]);
    //     }
    //     printf("\n");
    // }

    int s = 0;
    int count = 0;
    int flag = 0;

    while (s < total)
    {
        flag = 0;
        for (; !change[1][s] && s < total; s++)
        {
            ;
        }
        if (s == total)
            break;
        for (int i = 1; i < row; i++)
        {
            for (int j = 0; j < total; j++)
            {
                if (change[i][j] == change[1][s])
                {
                    flag += 1;
                    break;
                }
            }
        }
        if (flag == row - 1)
        {
            remain[count] = change[1][s];
            count++;
        }
        s++;
    }

    if (count > 1 || count == 0)
    {
        printf("-1\n");
    }
    else if (count == 1)
    {
        printf("%d\n", remain[0]);
    }

    //printf("%d %d\n", remain[0], remain[1]);

    /*for check the array*/
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < total; j++)
    //     {
    //         printf("%d ", book[i][j]);
    //     }
    //     printf("\n");
    // }

    system("pause");
    return 0;
}