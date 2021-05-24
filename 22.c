#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_triangle = 0;             //普通三角形，要不要计数无所谓，可以从下面三个得出来总数
int count_equicrural_triangle = 0;  //等腰
int count_equilateral_triangle = 0; //等边
int count_rectangle = 0;            //直角

void triangle(int n, int r, int l);
void equicrural_triangle(int a, int b, int c); //等腰
void rectangle(int a, int b, int c);           //直角
int istriangle(int a, int b, int c);

int main()
{
    int total = 0;
    int n, r, l;
    scanf("%d ", &total);
    for (int i = 0; i < total; i++)
    {
        scanf("%d %d %d ", &n, &r, &l);
        triangle(n, r, l);
    }

    system("pause");
    return 0;
}

void triangle(int n, int r, int l)
{
    int a = r, b = r, c = r;
    int flag = 0;
    for (a = r; a + b + c <= n && a <= l; a++)
    {
        for (b = r; a + b + c <= n && b <= l; b++)
        {
            for (c = r; a + b + c <= n && c <= l; c++)
            {
                if (a + b + c == n)
                {
                    flag = istriangle(a, b, c);
                    if (flag)
                    {
                        equicrural_triangle(a, b, c);
                        rectangle(a, b, c);
                    }
                }
            }
            c = r; //复位
        }
        b = r, c = r; //复位
    }
    printf("%d %d %d\n",
           count_equicrural_triangle / 3 + count_rectangle / 6 + count_equilateral_triangle, count_equicrural_triangle / 3 + count_equilateral_triangle,
           count_rectangle / 6);
    //直角三角形会重复算6次，等腰三角形会重复算3次，等边三角形不重复，可以举例
    count_equilateral_triangle = count_rectangle = count_triangle = count_equicrural_triangle = 0;
}

int istriangle(int a, int b, int c)
{
    if (a + b > c && a + c > b && b + c > a)
    {
        count_triangle++;
        return 1;
    }
    else
    {
        return 0;
    }
}

void equicrural_triangle(int a, int b, int c)
{
    if (a == c || a == b || b == c)
    {
        if (a == b && a == c && c == b)
        {
            count_equilateral_triangle++;
        }
        else
        {
            count_equicrural_triangle++;
        }
    }
}

void rectangle(int a, int b, int c)
{
    if (pow(a, 2) == (pow(b, 2) + pow(c, 2)) || pow(b, 2) == (pow(a, 2) + pow(c, 2)) || pow(c, 2) == (pow(a, 2) + pow(b, 2)))
    {
        count_rectangle++;
    }
}