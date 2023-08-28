#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
} node;
node *getnode(int key)
{
    node *newn = (node *)malloc(sizeof(node));
    newn->data = key;
    newn->next = NULL;
    return newn;
}
node *create(node *head)
{
    int key;
    cin >> key;
    node *newn = getnode(key);
    if (head == NULL)
    {
        head = newn;
    }
    else
    {
        node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newn;
    }
    return head;
}
void display(node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void del(node **head, int pos)
{
    node *temp = *head;
    if (pos == 1)
    { 
        *head = (*head)->next;
        temp->next=0;
        free(temp);
    }
    else
    {
        int i = 2;
        temp=temp->next;
        node *prev=*head;
        while (i++ != pos)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
}
void reverse(node *head)
{
    node *curr = head, *prev = 0, *next;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    display(prev);
}
int main()
{
    node *head = NULL;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter data :\n";
        head = create(head);
    }
    display(head);
    //reverse(head);
    cout << "Posititon" << endl;
    int pos;
    cin >> pos;
    del(&head, pos);
    display(head);
    return 0;
}