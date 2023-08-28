#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct stack
{
    int top, size, *arr;
} stack;
bool isfull(stack *sp)
{
    return sp->top == sp->size - 1;
}
bool isempty(stack *sp)
{
    return sp->top == -1;
}
void push(stack *sp)
{
    if (isfull(sp))
        printf("Stack Overflow\n");
    else
    {   
        int n;
        printf("Data\n");
        sp->top++;
        scanf("%d", &sp->arr[sp->top]);
    }
}
void pop(stack *sp)
{
    if (isempty(sp))
        printf("Stack underflow\n");
    else
    {
        printf("%d", sp->arr[sp->top]);
        sp->top--;
    }
}
void display(stack *sp)
{
    for (int i = 0; i < sp->top; i++)
    {
        printf("%d ", sp->arr[i]);
    }
}
void main()
{
    stack sp;
    sp.top = -1;
    printf("Size\n");
    scanf("%d", &sp.size);
    while (1)
    {
        int ch;
        printf("\n1.Push\n2.Pop\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push(&sp);
            break;
        case 2:
            pop(&sp);
            break;
        case 3:
            display(&sp);
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice!\n");
        }
    }
}