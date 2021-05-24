#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct num
{
    char str[9];    //读入字符串
    int num_in_ten; //10进制下的数值
    int scale;      //进制
} num, *array;

void tranformtoten(array arr, int sum);
void sort_print(array arr, int sum);
void swap(array arr, int k, int i);

int main()
{
    int sum = 0;
    scanf("%d ", &sum);
    array arr = (array)malloc(sizeof(struct num) * sum);
    for (int i = 0; i < sum; ++i)
    {
        scanf("%s %d ", arr[i].str, &arr[i].scale);
        arr[i].num_in_ten = 0;
    }
    tranformtoten(arr, sum);
    //for checking
    //printf("%d\n", arr[0].num_in_ten);
    sort_print(arr, sum);

    system("pause");
    return 0;
}

void tranformtoten(array arr, int sum)
{
    for (int i = 0; i < sum; ++i)
    {
        int size = 0;
        int temp[8]; //临时储存数组.一个位置储存一个数字,十六进制可能是10到16
        for (int i = 0; i < 8; i++)
        {
            temp[i] = 0;
        }
        for (; arr[i].str[size]; ++size)
        {
            if (arr[i].str[size] > 96)
            {
                temp[size] = arr[i].str[size] - 87; //如果是字母a到f,就根据ansic码转换成数字
            }
            else
            {
                temp[size] = arr[i].str[size] - 48; //如果是数字,则根据ansic继续转换
            }
        }
        for (int j = 0; j < size; j++)
        {
            arr[i].num_in_ten += temp[j] * pow(arr[i].scale, size - j - 1); //根据进制转换公式
        }
    }
}

void sort_print(array arr, int sum)
{
    int k;
    for (int i = 0; i < sum - 1; i++) //选择排序，先对进制排序
    {
        k = i;
        for (int j = i + 1; j < sum; j++)
        {
            if (arr[j].scale > arr[k].scale)
            {
                k = j;
            }
        }
        if (k != i)
        {
            swap(arr, k, i);
        }
    }

    int s = 0;
    int begin = 0, end = 0;
    do
    {
        begin = end;
        for (s = begin + 1; s < sum; s++) //再根据大小在进制内部排序，此时要确定起点和终点
        {
            if (arr[s].scale != arr[s - 1].scale) //如果和上一个不同,那么就从这里断开
            {
                break;
            }
        }
        end = s;
        for (int i = begin; i < end; i++) //选择排序法
        {
            k = i;
            for (int j = i + 1; j < end; j++)
            {
                if (arr[j].num_in_ten > arr[k].num_in_ten)
                {
                    k = j;
                }
            }
            if (k != i)
            {
                swap(arr, k, i);
            }
        }
    } while (s < sum);

    for (int i = 0; i < sum; i++)
    {
        printf("%d %d\n", arr[i].num_in_ten, arr[i].scale); //打印函数
    }
}

void swap(array arr, int k, int i) //辅助交换函数
{
    num temp;
    temp = arr[k];
    arr[k] = arr[i];
    arr[i] = temp;
    return;
}