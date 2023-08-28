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
        newn->next = newn;
    }
    else
    {
        node *temp = head;
        while (temp->next != temp)
            temp = temp->next;
        temp->next = newn;
        newn->next = head;
    }
    return head;
}
void display(node *head)
{
    node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    node *head = NULL;
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter data :\n";
        head = create(head);
    }
    display(head);
    return 0;
}