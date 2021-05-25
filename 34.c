#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const double e = 2.71828;
const double miu = 2.00000;
const double differ = 1e-6; //double类型之间相等不是相等，是误差小于这个值

double calc_tao_x(int x);
void calc_kexi(int c1, int c2, int c3, int c4);

int count = 0; //全局变量

int main()
{

    int c1, c2, c3, c4;
    scanf("%d %d %d %d", &c1, &c2, &c3, &c4);
    calc_kexi(c1, c2, c3, c4);
    printf("%d\n", count);
    system("pause");
    return 0;
}

double calc_tao_x(int x)
{
    double ln_x = log10(x) / log10(e);
    return pow(x, 2) + floor(pow(ln_x, 2)) / miu; //看准公式
}

void calc_kexi(int c1, int c2, int c3, int c4)
{
    double kexi;
    for (int x1 = 1; x1 <= 100; x1++)
    {
        for (int x2 = 1; x2 <= 100; x2++)
        {
            for (int x3 = 1; x3 <= 100; x3++)
            {
                for (int x4 = 1; x4 <= 100; x4++)
                {
                    kexi = c1 * calc_tao_x(x1) + c2 * x2 + 0.5 * c3 * x3 + c4 * calc_tao_x(x4);
                    if (kexi < 0 && -kexi < differ)
                    {
                        count++;
                    }
                    else if (kexi >= 0 && kexi < differ)
                    {
                        count++;
                    }
                }
            }
        }
    }
}