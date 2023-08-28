#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
} queue;
queue *getnode(int key)
{
    queue *newn = new struct node;
    newn->data = key;
    newn->next = 0;
    return newn;
}
void enqueue(queue **f, queue **r)
{
    int key;
    cout << "Enter data" << endl;
    cin >> key;
    queue *newn = getnode(key);
    if (*r == 0)
    {
        *r = *f = newn;
        return;
    }
    (*r)->next = newn;
    *r = newn;
}
void dequeue(queue **f)
{
    cout << (*f)->data << " ";
    queue *q = *f;
    (*f) = (*f)->next;
    free(q);
}
int main()
{
    queue *f, *r = 0;
    for(int i=0;i<10;i++)
        enqueue(&f, &r);
    dequeue(&f);
    dequeue(&f);
    return 0;
}