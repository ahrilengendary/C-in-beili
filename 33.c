#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxsize 3000

typedef int elemtype; //attention

typedef enum operation
{
    push,
    pop,
    sequence
} oper;

typedef struct Stack
{
    elemtype *stack;
    int top;
} Stack, *Stack_p;

oper operation_judgement(char *str, elemtype *data); //判断要做的事情
void stack_init(Stack_p s);                          //栈的初始化
void stack_push(Stack_p s, elemtype elem);           //入栈
void stack_pop(Stack_p s, Stack_p pop_store);        //出栈
void stack_sequence(Stack_p s);                      //栈底到栈顶的输出
void stack_sequence_for_last(Stack_p s);             //最后的输出
void stack_output(Stack_p s);                        //栈顶到栈底的输出
int stack_is_empty(Stack_p s);                       //判断栈是否为空
int stack_is_full(Stack_p s);                        //判断栈是否满

int main()
{
    char str[10] = {0};
    Stack s;
    stack_init(&s);
    elemtype data = 0;
    Stack pop_store; //用来储存之前出栈的元素,最后再输出
    stack_init(&pop_store);

    while (1)
    {
        ungetc('q', stdin); //我一直不知道如何输入不知道个数的命令，
                            //这应该算是一种旁门左道，不建议学习
                            //到最后还是要打一个回车才能结束这个程序，我觉得大概率过不了了。
        for (int i = 0; i < 10; i++)
        {
            str[i] = 0; //初始化str
        }
        gets(str);
        if (strlen(str) == 1)
        {
            break;
        }
        int execution = operation_judgement(str, &data);
        switch (execution)
        {
        case 0:
            if (!stack_is_full(&s))
            {
                stack_push(&s, data);
                printf("\n"); //它说没有输出就输出一个空行是这个意思吗？
            }
            break;
        case 1:
            if (!stack_is_empty(&s))
            {
                stack_pop(&s, &pop_store);
                printf("\n"); //它说没有输出就输出一个空行是这个意思吗？
            }
            break;
        case 2:
            stack_sequence(&s);
            break;
        }
    }
    if (!stack_is_empty(&s))
    {
        stack_sequence_for_last(&pop_store);
        stack_output(&s);
    }
    system("pause"); //delete for passing
    return 0;
}

oper operation_judgement(char *str, elemtype *data)
{
    if (str[2] == 'o')
    {
        return pop; //1
    }
    else if (str[2] == 'u')
    {
        *data = atoi(str + 6); //又是泛型局限
        return push;           //0
    }
    else
    {
        return sequence; //2
    }
}

void stack_init(Stack_p s)
{
    s->stack = (elemtype *)malloc(sizeof(elemtype) * maxsize);
    memset(s->stack, 0, maxsize * sizeof(elemtype));
    s->top = -1;
}

int stack_is_empty(Stack_p s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int stack_is_full(Stack_p s)
{
    if (s->top == maxsize - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void stack_push(Stack_p s, elemtype elem)
{
    s->top++;
    s->stack[s->top] = elem;
}

void stack_pop(Stack_p s, Stack_p pop_store)
{
    stack_push(pop_store, s->stack[s->top]);
    s->top--;
}

void stack_sequence(Stack_p s)
{
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->stack[i]); //我的题外话：用C果然还是不能泛型啊，输出这一块就限制地死死地，但是也可以做个switch进行处理，但写的东西太多，不如C++的template来的快啊
    }
    printf("\n");
}

void stack_output(Stack_p s)
{
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}

void stack_sequence_for_last(Stack_p s)
{
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->stack[i]);
    }
}
