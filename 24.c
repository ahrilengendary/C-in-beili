#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum type
{
    CNY,
    USD,
    JPY,
    EUR,
    GBP
};

#define SIZE 4

const double USD2CNY = 6.48;
const double JPY2CNY = 0.061;
const double EUR2CNY = 7.82;
const double GBP2CNY = 9.02;
const double CNY2CNY = 1;

int str2num(char *a);
void calc(int n, double p, double x, double c); //c代表汇率

int main()
{
    int n;
    double p, x;
    char str[SIZE] = {0};
    if (scanf("%d %lf %lf %s", &n, &p, &x, str))
    {
        int num = str2num(str);
        switch (num)
        {
        case 0:
            calc(n, p, x, CNY2CNY);
            break;
        case 1:
            calc(n, p, x, USD2CNY);
            break;
        case 2:
            calc(n, p, x, JPY2CNY);
            break;
        case 3:
            calc(n, p, x, EUR2CNY);
            break;
        case 4:
            calc(n, p, x, GBP2CNY);
            break;

        default:
            break;
        }
    }

    system("pause");
    return 0;
}

int str2num(char *a)
{
    if (!strcmp(a, "CNY"))
        return 0;
    else if (!strcmp(a, "USD"))
        return 1;
    else if (!strcmp(a, "JPY"))
        return 2;
    else if (!strcmp(a, "EUR"))
        return 3;
    else
        return 4;
}

void calc(int n, double p, double x, double c)
{
    double a = x / c;
    double rate = p + 1;
    for (int i = 0; i < n; i++)
    {
        a /= rate;
    }
    printf("%.2f\n", a);
}