#include <stdio.h>
#include <stdlib.h>
typedef struct queues
{
    int f;
    int r;
    int size;
    int *arr;
} queue;
int isfull(queue *q)
{
    if ((q->r + 1) % q->size == q->f || (q->r == q->size - 1 && q->f == -1))
        return 1;
    return 0;
}
int isempty(queue *q)
{
    if (q->r == q->f)
        return 1;
    return 0;
}
void Enqueue(queue *q)
{
    if (isfull(q))
        printf("Queues overflow\n");
    else
    {
        int data;
        printf("Data\n");
        scanf("%d", &data);
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = data;
    }
}
void Dequeue(queue *q)
{
    if (isempty(q))
        printf("Queues underflow\n");
    else
    {
        q->f = (q->f + 1) % q->size;
        int data = q->arr[q->f];
        printf("DELETED ELEMENT:%d", data);
    }
}
void display(queue *q)
{
    int i = q->f;
    i += 1;
    while (i != q->r)
    {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("%d ", q->arr[i]);
}
void main()
{
    queue q;
    q.f = q.r = -1;
    printf("size\n");
    scanf("%d", &q.size);
    q.arr = (int *)malloc(q.size * sizeof(int));
    int ch;
    while (1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Enqueue(&q);
            break;
        case 2:
            Dequeue(&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice!\n");
        }
    }
}