#include <stdio.h>
#include <stdlib.h>
typedef struct queues
{
    int f;
    int r;
    int size;
    int *arr;
    int *priority;
} queue;
int isfull(queue *q)
{
    if (q->r == q->size - 1)
        return 1;
    return 0;
}
int isempty(queue *q)
{
    if (q->r == -1)
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
        printf("Data and its priority\n");
        scanf("%d", &data);
        q->r++;
        scanf("%d", &q->priority[q->r]);
        q->arr[q->r] = data;
    }
}
void Dequeue(queue *q)
{
    if (isempty(q))
        printf("Queues underflow\n");
    else
    {
        q->f++;
        int data = q->arr[q->f];
        printf(":%d ", data);
    }
}
void priority(queue *q)
{
    int min;
    int min1;
    //int count = 0;
    for (int i = 1; i <= q->r; i++)
    {
        min = q->priority[q->f + 1];
        min1 = q->arr[q->f + 1];
        if (min > q->priority[i])
        {

            int temp = min;
            min = q->priority[i];
            q->priority[i] = temp;

            int temp1 = min1;
            min1 = q->arr[i];
            q->arr[i] = temp1;

            Dequeue(q);
            //count++;
        }
        else
        {
            Dequeue(q);
        }
    }
    /*while (count <= q->r)
    {
        Dequeue(q);
        count++;
    }*/
}
void main()
{
    queue q;
    q.f = q.r = -1;
    printf("size\n");
    scanf("%d", &q.size);
    q.arr = (int *)malloc(q.size * sizeof(int));
    q.priority = (int *)malloc(q.size * sizeof(int));
    for (int i = 0; i < q.size; i++)
    {
        Enqueue(&q);
    }
    for (int i = 0; i < q.size; i++)
    {
        priority(&q);
    }
}