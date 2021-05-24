#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, p;
    while (scanf("%d %d", &n, &p) != EOF)
    {
        double indepen_arr[n]; //自变量
        double depen_arr[n];   //因变量
        double indepen_sum = 0, depen_sum = 0, indepen_mean, depen_mean;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &indepen_arr[i]);
            getchar(); //我也不知道为什么就可以连续输入了，之前是错误的。。。
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &depen_arr[i]);
            getchar();
        }
        for (int i = 0; i < n; i++)
        {
            indepen_sum += indepen_arr[i];
            depen_sum += depen_arr[i];
        }
        indepen_mean = indepen_sum / n;
        depen_mean = depen_sum / n;
        double b_numerator = 0, b_denominator = 0;
        for (int i = 0; i < n; i++)
        {
            b_numerator += (indepen_arr[i] - indepen_mean) * (depen_arr[i] - depen_mean);
        }
        for (int i = 0; i < n; i++)
        {
            b_denominator += (indepen_arr[i] - indepen_mean) * (indepen_arr[i] - indepen_mean);
        }
        double b = b_numerator / b_denominator;
        double a = depen_mean - b * indepen_mean;
        double result = b * p + a;
        if (b == 0)
        {
            printf("y=%.2f predict=%.2f\n", a, result);
        }
        else if (a == 0)
        {
            printf("y=%.2fx predict=%.2f\n", b, result);
        }
        else
        {
            printf("y=%.2fx+%.2f predict=%.2f\n", b, a, result);
        }
    }
    system("pause"); //delete for passing
    return 0;
}