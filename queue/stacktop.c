#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct queue
{
    int r,f,size,*arr;
}queue;
bool isempty(queue *q)
{
    return q->f==q->r;
}
bool isfull(queue *q)
{
    return (q->r+1)%q->size==q->f;
}
void enqueue(queue *q)
{
    if(isfull(q))
    printf("Queue Overflow\n");
    else 
    {
        q->r=(q->r+1)%q->size;
        printf("Data\n");
        scanf("%d",&q->arr[q->r]);
    }
}

void dequeue(queue *q)
{
    if(isempty(q))
    printf("Queue Underflow\n");
    else 
    {
       q->f=(q->f+1)%q->size;
       printf("%d",q->arr[q->f]);
    }
}
void main()
{
    queue q;
    q.r=q.f=0;
    printf("Size\n");
    scanf("%d",&q.size);
    q.size++;
    q.arr=(int*)malloc(q.size*sizeof(int));
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n");
        int ch;
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:enqueue(&q);
            break;
            case 2:dequeue(&q);
            break;
            case 3:exit(0);
            default:
            printf("Wrong choice!\n");
        }
    }
}
