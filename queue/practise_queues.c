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
    if ((q->r + 1) % q->size == q->f || (q->f == -1 && q->r == q->size - 1))
        return 1;
    return 0;
}
int isempty(queue *q)
{
    if (q->f == q->r)
        return 1;
    return 0;
}
void enqueue(queue *q)
{
    if (isfull(q))
        printf("Queue overflow\n");
    else
    {
        int data;
        scanf("%d", &data);
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = data;
    }
}
void dequeue(queue *q)
{
    if (isempty(q))
        printf("Queue underflow\n");
    else
    {
        q->f = (q->f + 1) % q->size;
        printf("Deleted element:%d\n", q->arr[q->f]);
    }
}
void display(queue *q)
{
    int i=q->f;
    i+=1;
    while(i!=q->r)
    {
        printf("%d ",q->arr[i]);
        i=(i+1)%q->size;
    }
    printf("%d ",q->arr[i]);
}
void main()
{
    queue q;
    printf("Size\n");
    q.f = q.r =-1;
    scanf("%d", &q.size);
    q.arr = (int *)malloc(q.size * sizeof(int));
    while (1)
    {
        int ch;
        printf("\n1.Enqueue\n2.Dequeue\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue(&q);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
           display(&q);
           break;
        }
    }
}