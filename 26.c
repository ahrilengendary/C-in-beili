#include <stdio.h>
#include <stdlib.h>

void printleaves(int level, int mid);
void printstem(int stem, int mid);

int main()
{
    int sum = 0;
    scanf("%d", &sum);
    if (sum <= 3)
    {
        printf("***\n***\n***\n");
        return 0;
    }
    int level = 0;
    int stem = 0;
    int mid = 0;
    if (sum % 3 == 0)
    {
        level = sum / 3 - 1;
        stem = 3;
    }
    else
    {
        level = sum / 3;
        stem = sum - level * 3;
    }
    mid = (8 * level + 3) / 2 + 1;

    printleaves(level, mid);
    printstem(stem, mid);

    system("pause");
    return 0;
}

void printleaves(int level, int mid)
{
    if (level != 0)
    {
        printleaves(level - 1, mid);
        /*print first lay*/
        int first_sum = 3; //第一行个数
        for (int i = 1; i != mid + 2; i++)
        {
            if (i != mid - first_sum / 2)
            {
                printf(" ");
            }
            else
            {
                printf("***");
            }
        }
        printf("\n");
        /*print second lay*/
        int sec_sum = 4 * level + 3;
        for (int i = 1; i != mid + sec_sum / 2 + 1; i++)
        {
            if (i < mid - sec_sum / 2)
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
        /*print third lay*/
        int thr_sum = 8 * level + 3;
        for (int i = 1; i != mid + thr_sum / 2 + 1; i++)
        {
            if (i < mid - thr_sum / 2)
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }
}

void printstem(int stem, int mid)
{
    for (int i = 0; i < stem; i++)
    {
        for (int i = 1; i < mid + 2; i++)
        {
            if (i < mid - 1)
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }
}