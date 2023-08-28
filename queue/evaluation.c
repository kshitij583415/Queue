#include <stdio.h>
#include <stdlib.h>
typedef struct queues
{
    int f;
    int r;
    int size;
    int *amt;
    int *dist;
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
void enqueue(queue *q)
{
    if (isfull(q))
        printf("Queue overflow\n");
    else
    {
        q->r++;
        printf("Enter the amount of petrol and distance\n");
        scanf("%d", &q->amt[q->r]);
        scanf("%d", &q->dist[q->r]);
    }
}
void dequeue(queue *q, int *data1, int *data2)
{
    if (isempty(q))
        printf("Queue underflow\n");
    else
    {
        q->f++;
        *data1 += q->amt[q->f];
        *data2 += q->dist[q->f];
    }
}
void main()
{
    queue q;
    printf("Size\n");
    scanf("%d", &q.size);
    int start;
    printf("Staring point\n");
    scanf("%d", &start);
    q.f = q.r = -1;
    q.amt = (int *)malloc(q.size * sizeof(int));
    q.dist = (int *)malloc(q.size * sizeof(int));
    int data1 = 0, data2 = 0;
    for (int i = 0; i < q.size; i++)
    {
        enqueue(&q);
    }
    for (int i = 0; i < q.size; i++)
    {
        dequeue(&q, &data1, &data2);
    }
    if (data1 >= data2)
    {
        printf("Start from petrol pump %d\n", start);
        printf("Remaining petrol after completing the circle is %d ltrs\n", data1 - data2);
    }
    else
        printf("Not possible to complete the circle\n");
}