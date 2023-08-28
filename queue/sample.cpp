#include<iostream>
using namespace std;
typedef struct queue
{
    int f,r,size,*arr;
}queue;
bool isfull(queue *q)
{
    return q->r==q->size-1;
}
bool isempty(queue *q)
{
    return q->r==q->f;
}
void enqueue(queue *q)
{
    if(isfull(q))
    return;
    else
    {
        q->r++;
        cout<<"Data"<<endl;
        cin>>q->arr[q->r];
    }
}
void dequeue(queue *q)
{
    if(isempty(q))
    return;
    else
    {
        q->f++;
        cout<<q->arr[q->f]<<" ";
    }
}
int main()
{
    queue q;
    q.r=q.f=-1;
    cout<<"Size"<<endl;
    cin>>q.size;
    q.arr=new int;
    for(int i=0;i<q.size;i++)
    enqueue(&q);
    dequeue(&q);
    return 0;
}