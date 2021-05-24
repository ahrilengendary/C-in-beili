#include <stdio.h>
#include <stdlib.h>

void print(int n);
void print_wel(int n);
void print_max_triangle(int n);
void print_out_of_tri(int n);

int count_level;

int main()
{
    int n;
    scanf("%d", &n);
    print(n);

    system("pause");
    return 0;
}

void print(int n)
{
    print_wel(n);
    print_max_triangle(n);
    print_out_of_tri(n);
}

void print_wel(int n)
{
    char wel[] = "Welcome";
    if (n < 8)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%c", wel[i]);
        }
    }

    if (n > 6)
    {
        int right = n - 7;
        printf("Welcome");
        for (int i = 0; i < right; i++)
        {
            printf("#");
        }
    }
    printf("\n");
    count_level++;
}

void print_max_triangle(int n)
{
    int outside_per_level = n / 2 - 2;
    if (outside_per_level <= 0)
    {
        return;
    }
    int inside_per_level;
    do
    {
        inside_per_level = n - 4 - outside_per_level * 2;
        printf("#");
        for (int i = 0; i < outside_per_level; i++)
        {
            printf("*");
        }
        printf("/");
        while (inside_per_level)
        {
            printf(".");
            inside_per_level--;
        }
        printf("\\");
        for (int i = 0; i < outside_per_level; i++)
        {
            printf("*");
        }
        printf("#\n");
        outside_per_level--;
        count_level++;
    } while (outside_per_level != -1);
    printf("#");
    for (int i = 0; i < n - 2; i++)
    {
        printf("-");
    }
    printf("#\n");
}

void print_out_of_tri(int n)
{
    int out_level = n - 2 - count_level;
    if (out_level <= 0)
    {
        return;
    }
    for (int i = 0; i < out_level; i++)
    {
        printf("#");
        for (int j = 0; j < n - 2; j++)
        {
            printf("*");
        }
        printf("#");
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}