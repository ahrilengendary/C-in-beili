#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int calcdays_for_year(int year);
int calcdays_for_month(int year, int month);
int calcdays_for_day(int day);
int isleapyear(int year);
int switch_day(int *year, int *month, int *day);

int main()
{
    int year_s, month_s, day_s, year_e, month_e, day_e;
    while (scanf("%d %d %d %d %d %d ", &year_s, &month_s, &day_s, &year_e, &month_e, &day_e))
    {
        int days_p = 0; //开始日期到1900年的天数
        days_p = days_p + calcdays_for_year(year_s);
        days_p = days_p + calcdays_for_month(year_s, month_s);
        days_p = days_p + calcdays_for_day(day_s); //这样算会把日期间隔算少一天,要在后面加上

        int days_a = 0; //结束日期到1900年的天数
        days_a = days_a + calcdays_for_year(year_e);
        days_a = days_a + calcdays_for_month(year_e, month_e);
        days_a = days_a + calcdays_for_day(day_e) - 1 + 1; //最后一天不算,但是要把日子补上

        int record[7]; //用来记录各个星期的吻合日数
        int sum = 0;   //总的吻合日数
        for (int i = 0; i < 7; i++)
        {
            record[i] = 0; //初始化
        }

        int weekday_begin = days_p % 7; //注意0是星期天哦,要转换
        if (weekday_begin == 0)
        {
            weekday_begin = 7;
        }

        int s = day_s;
        for (int i = days_p, j = weekday_begin; i < days_a; i++, j = (j + 1) % 7)
        {
            if (j == 0)
            {
                j = 7; //将星期天对应的0转换为7
            }

            if (s % 10 == j)
            {
                record[j - 1]++; //因为物理结构与逻辑结构差一
                sum++;
            }
            s = switch_day(&year_s, &month_s, &day_s); //计算下一天日期
        }
        printf("%d ", sum);
        for (int i = 0; i < 6; i++)
        {
            printf("%d ", record[i]);
        }
        printf("%d\n", record[6]);
    }
    system("pause");
    return 0;
}

int calcdays_for_day(int day)
{
    return day;
}

int calcdays_for_year(int year)
{
    int differ = year - 1900; //年差，不算今年
    int count_leap_year = differ / 4;
    if (isleapyear(year))
    {
        return (count_leap_year - 1) * 366 + (differ - count_leap_year + 1) * 365;
        //year这一年不算
    }
    else
    {
        return count_leap_year * 366 + (differ - count_leap_year) * 365;
    }
}

int calcdays_for_month(int year, int month)
{
    int flag = isleapyear(year);
    switch (month) //别笑。。。。
    {
    case 1:
        return 0;
    case 2:
        return 31;
    case 3:
        if (flag)
        {
            return 31 + 28 + 1;
        }
        else
            return 31 + 28;
    case 4:
        if (flag)
        {
            return 31 + 28 + 1 + 31;
        }
        else
            return 31 + 28 + 31;
    case 5:
        if (flag)
        {
            return 31 + 28 + 31 + 30 + 1;
        }
        else
            return 31 + 28 + 31 + 30;
    case 6:
        if (flag)
        {
            return 31 + 28 + 1 + 31 + 30 + 31;
        }
        else
            return 31 + 28 + 31 + 30 + 31;
    case 7:
        if (flag)
        {
            return 31 + 28 + 1 + 31 + 30 + 31 + 30;
        }
        else
            return 31 + 28 + 31 + 30 + 31 + 30;
    case 8:
        if (flag)
        {
            return 31 + 28 + 1 + 31 + 30 + 31 + 30 + 31;
        }
        else
            return 31 + 28 + 31 + 30 + 31 + 30 + 31;
    case 9:
        if (flag)
        {
            return 31 + 28 + 1 + 31 + 30 + 31 + 30 + 31 + 31;
        }
        else
            return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
    case 10:
        if (flag)
        {
            return 31 + 28 + 1 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
        }
        else
            return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
    case 11:
        if (flag)
        {
            return 31 + 28 + 1 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
        }
        else
            return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
    case 12:
        if (flag)
        {
            return 31 + 28 + 1 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
        }
        else
            return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
    }
    return 0;
}

int isleapyear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int switch_day(int *year, int *month, int *day)
{
    switch (*month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (*day == 31)
        {
            if (*month == 12)
            {
                *year += 1;
                *month = 1;
                *day = 1;
                return 1;
            }
            else
            {
                *month += 1;
                *day = 1;
                return 1;
            }
        }
        else
        {
            *day += 1;
            return *day;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (*day == 30)
        {

            *month += 1;
            *day = 1;
            return 1;
        }
        else
        {
            *day += 1;
            return *day;
        }
        break;
    case 2:
        if (isleapyear(*year))
        {
            if (*day == 29)
            {
                *month += 1;
                *day = 1;
                return *day;
            }
            else
            {
                *day += 1;
                return *day;
            }
        }
        else
        {
            if (*day == 28)
            {
                *month += 1;
                *day = 1;
                return 1;
            }
            else
            {
                *day += 1;
                return *day;
            }
        }
    }
    return 0;
}