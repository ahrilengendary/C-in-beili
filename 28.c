//idea: record the frequency of each letter(using structure),and minus the frequency one by one

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define maxsize 10000

typedef struct letter
{
    char letter_record;
    int times;
} letter, letter_array;

void record_init(letter record[]);
void record_times(char ch, letter *record);
void show(letter *record);
void print_record(letter *record);
void sort_decending(letter *record);

int main()
{
    char str[10000] = {0};
    letter record[26];
    record_init(record);
    if (scanf("%s", str))
    {

        for (int i = 0; str[i]; i++)
        {
            str[i] = toupper(str[i]);
            record_times(str[i], record);
        }
    }
    //for checking
    show(record);
    printf("\n");
    print_record(record);

    system("pause"); //delete for passing
    return 0;
}

void record_init(letter record[])
{
    for (int i = 0; i < 26; i++)
    {
        record[i].letter_record = i + 65;
        record[i].times = 0;
    }
}

void record_times(char ch, letter *record)
{
    for (int i = 65; i < 91; i++)
    {
        if (i == ch)
        {
            record[i - 65].times++;
        }
    }
}

void show(letter *record)
{
    for (int i = 0; i < 26; i++)
    {
        printf("%c,%d\n", record[i].letter_record, record[i].times);
    }
}

void print_record(letter *record)
{
    sort_decending(record);
    //for checking
    //show(record);
    int max_times = record[0].times;
    for (int i = max_times; i; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            if (record[j].times == i)
            {
                record[j].times--;
                printf("# ");
            }
        }
        printf("\n");
    }
    for (int k = 0; k < 26; k++)
    {
        printf("%c ", record[k].letter_record);
    }
    /*****************/
    printf("\n"); //delete for not passing
    /*****************/
}

void sort_decending(letter *record)
{
    int k, j, i;
    for (i = 0; i < 26 - 1; i++) //select sort for times
    {
        k = i;
        for (j = i + 1; j < 26; j++)
        {
            if (record[j].times > record[k].times)
            {
                k = j;
            }
        }
        if (k != i)
        {
            letter temp;
            temp = record[k];
            record[k] = record[i];
            record[i] = temp;
        }
    }

    for (i = 0; i < 26 - 1; i++) //select sort for letters
    {
        k = i;
        for (j = i + 1; j < 26; j++)
        {
            if (record[j].times == record[k].times && record[j].letter_record < record[k].letter_record)
            {
                k = j;
            }
        }
        if (k != i)
        {
            letter temp;
            temp = record[k];
            record[k] = record[i];
            record[i] = temp;
        }
    }
}